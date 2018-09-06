def rewrite_generic(l)
    l
        .gsub(/__asm { xlat }/, "ASM_XLAT();")
        .gsub("C:\\\\Diablo\\\\Direct\\\\", "")
end


