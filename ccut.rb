
require 'fileutils'
require 'pathname'

require_relative 'idx'
require_relative 'rewrite'
require_relative 'term_colors'

OUTDIR = Pathname.new("Source")

FileUtils.mkdir_p OUTDIR

TARGETS = [
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
    [0x41f1a8, "mpqapi"],
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

cur_target = -1
addr = nil
was_addr = false

$out_file = nil

def set_out_file(fn)
    $out_file.close if $out_file
    $stderr.puts "--- Output to #{fn}".cyan
    $out_file = fn && (OUTDIR + "#{fn}").open("w")
end

init_target = Proc.new {
    target_name = TARGETS[cur_target][1]
    set_out_file target_name && "#{target_name}.cpp"
    if target_name
        $out_file.puts '#include "all.h"'
        $out_file.puts ''
    end
}

source_file = File.open(ARGV[0])
header_file = File.open(ARGV[1])

# Read source
stage = nil

source_file.each_line do |l|
    no_comments = l.gsub(/\s*\/\/.*$/, "")

    if !no_comments.strip.empty?
        if was_addr
            was_addr = false
            $stderr.puts "#{addr.to_s(16)}: #{l}"
        end
    end

    if l =~ /^\/\/----- \(([A-F0-9]+)\)/
        addr = $1.to_i(16)
        was_addr = true
        stage = :code

        if addr >= TARGETS[cur_target + 1][0]
            cur_target += 1
            init_target.call
        end
    elsif l =~ /^\/\/ ([A-F0-9]+): using guessed type/
        next
    else
        sl = l.strip
        if sl == "// Function declarations"
            set_out_file "functions.h"
            $out_file.puts '#include "types.h"'
            stage = :functions
        elsif sl == "// Data declarations"
            set_out_file "data.h"
            $out_file.puts '#include "types.h"'
            stage = :data
        end
    end

    if $out_file
        l = rewrite_generic l
        if stage == :code
            l = rewrite_line_idx l
        elsif stage == :data
            if l =~ /^[ {}}]/
                # Outputting initializers
                next
            end
            if no_comments =~ /^(.*?)\s*(?:=|;)/
                l = "extern #{$1};"
                $stderr.puts l
            end
        end

        $out_file.puts l
    end
end

# Read header
type_no = nil
types = []
names = {}

VALID_NAMES = /Struct\d*$|Data$|NODE$|Monster|^D[A-Z]|^T[A-Z]|^Inv|^_plr|^_ui|^Coord|^SHA1/
INVALID_NAMES = /^MACRO_/

header_file.each_line do |l|
    if l =~ /^\/\* (\d+) \*\//
        type_no = $1.to_i
    elsif l =~ /^#pragma/
        next
    elsif type_no
        l = l.gsub(/\b(__unaligned )?__declspec\(align\((\d+)\)\)\s*/, "")
        unaligned, align = $1, $2

        if l =~ /^(struct|enum)\s+([\w:$]+)\s*$/
           type,  name = $1, $2
            if name =~ INVALID_NAMES || (type == "struct" && name !~ VALID_NAMES)
                $stderr.puts "Skip #{name}".brown
                type_no = nil
                next
            else
                $stderr.puts "#{type} #{name}"
            end

            names[name] = [type, type_no]
        elsif l =~ /^typedef|union/
            type_no = nil
            next
        end

        # l = l.gsub(/\b_(BYTE|WORD|DWORD)\b/, "\\1")

        (types[type_no] ||= []) << l
    end
end

set_out_file "types.h"
$out_file.puts '#include "defs.h"'
$out_file.puts "// Forward declarations"
names.each do |name, data|
    $out_file.puts "#{data[0]} #{name};"
end

$out_file.puts "// Types"
types.each_with_index do |lines, num|
    next if !lines
    lines.each do |l|
        $out_file.puts l
    end
end
