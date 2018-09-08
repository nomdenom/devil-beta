def rewrite_generic(l)
    if l =~ /^(\s*)(.*)\/\/\s*REPLACE:\s*(.*)$/
        l = $1 + $3
        $stderr.puts "REPLACE: #{$2} => #{$3}"
    end
    
    l
        .gsub(/__asm { xlat }/, "ASM_XLAT();")
        .gsub("C:\\\\Diablo\\\\Direct\\\\", "")
end


