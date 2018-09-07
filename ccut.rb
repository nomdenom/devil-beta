
require 'fileutils'
require 'pathname'

require_relative 'idx'
require_relative 'rewrite'
require_relative 'term_colors'

OUTDIR = Pathname.new("Source")

FileUtils.mkdir_p OUTDIR

targets = [
    [0x410990, "appfat"],
    [0x4599E0, "automap"],
    [0x435DE0, "capture"],
    [0x47AFD0, "codec"],
    [0x414980, "control"],
    [0x485990, "cursor"],
    [0x466F10, "dead"],
    [0x44E3D0, "debug"],
    [0x490C20, "diablo"],
    [0x49AE30, "drlg_l1"],
    [0x47c790, "drlg_l2"],
    [0x43a370, "drlg_l3"],
    [0x4674C0, "effects"],
    [0x47AAE0, "encrypt"],
    [0x48E700, "engine"],
    [0x45C280, "error"],
    [0x466750, "gamemenu"],
    [0x4119D0, "gendung"],
    [0x479D70, "gmenu"],
    [0x44E5C0, "help"],
    [0x42D180, "init"],
    [0x41E310, "interfac"],
    [0x44EF20, "inv"],
    [0x420580, "items"],
    [0x437B50, "lighting"],
    [0x43ADB0, "loadsave"],
    [0x43A170, "mainmenu"],
    [0x4129D0, "minitext"],
    [0x43AE00, "missiles"],
    [0x401000, "monster"],
    [0x482290, "movie"],
    [0x41F97C, "mpqapi"],
    [0x494540, "msg"],
    [0x41C0B0, "multi"],
    [0x41B390, "nthread"],
    [0x45C890, "objects"],
    [0x468420, "pack"],
    [0x48DD10, "palette"],
    [0x413020, "path"],
    [0x436940, "pfile"],
    [0x468CD0, "player"],
    [0x41BBF0, "plrmsg"],
    [0x493F10, "portals"],
    [0x478720, "quests"],
    [0x4880B0, "scrollrt"],
    [0x4364A0, "setmaps"],
    [0x4846A0, "sha"],
    [0x413B70, "sound"],
    [0x45B6D0, "spells"],
    [0x42E330, "stores"],
    [0x484BF0, "sync"],
    [0x482730, "themes"],
    [0x44A530, "town"],
    [0x4579F0, "towners"],
    [0x468130, "track"],
    [0x47B670, "trigs"],
    [0x43AB00, "wave"],
    [0x4A048C, "render"],
    [0x4A6B50, nil],
    [0xFFFFFF, nil]
].sort_by { |d| d[0] }

#p targets

cur_target = -1
addr = nil
was_addr = false
outf = nil

init_target = Proc.new {
    outf.close if outf
    fn = targets[cur_target][1]
    outf = fn && (OUTDIR + "#{fn}.cpp").open("w")
}


ARGF.each_line do |l|
    no_comments = l.gsub(/\/\/.*$/, "")

    if !no_comments.strip.empty?
        if was_addr
            was_addr = false
            puts "#{addr.to_s(16)}: #{l}"
        end
    end

    if l =~ /^\/\/----- \(([A-F0-9]+)\)/
        addr = $1.to_i(16)
        was_addr = true
        if addr >= targets[cur_target + 1][0]
            cur_target += 1
            puts "--- Output to #{targets[cur_target]}".cyan
            init_target.call
        end
        #printf "addr = %08X\n", addr
    elsif l =~ /^\/\/ ([A-F0-9]+): using guessed type/
        next
    end
    
    if outf
        if l =~ /^(\s*)(.*)\/\/\s*REPLACE:\s*(.*)$/
            l = $1 + $3
            $stderr.puts "REPLACE: #{$2} => #{$3}"
        else
            l = rewrite_generic l
            l = rewrite_line_idx l
        end
        outf.puts l
    end
end