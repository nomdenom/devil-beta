tests = [
    "predungeon[0][8 * (5 * v2 - 5) + 1 + v26]",
    "dungeon[0][8 * (5 * l - 5) + k]",
    "dungeon[0][8 * (5 * sx + 35) + 4 + sy]",
    "predungeon[-1][8 * (5 * i - 5) + 39 + j]",
    "dungeon[39][112 * (v4 - 1) + 39 + v3]",
]

# predungeon[0][40 * v2 - 40 + 1 + v26]
# predungeon[v2 - 1][1 + v26]

def to_re(match)
    repl = {
        "I" => %q{([a-zA-Z_][a-zA-Z_0-9]*)},
        "N" => %q{(-?\d+)},
        "O" => %q{([\+\-])},
        " " => %q{\s*},
        "{" => "(?:",
        "}" => ")?",
    }

    Regexp.new(match.gsub(/./) { |c|
        #p c
        re = repl[c]
        re || Regexp.escape(c)
    })
end

match = "I[N][N * ( N * I O N ) {+ N} + I]"
#match = "I"
re = to_re(match)

#p re

def intify(a)
    a.to_a.map { |e| e =~ /^-?\d+$/ ? e.to_i : e }
end

def addexp(id, b)
    if b == 0
        id
    elsif b > 0
        "#{id} + #{b}"
    else
        "#{id} - #{-b}"
    end
end

has_args = !ARGV.empty?
input = has_args ? ARGF : tests
#$stderr.puts ARGV.inspect
dims = {
    "dungeon" => 40,
    "predungeon" => 40,
    "dflags" => 40,
}

input.each do |t|
    ts = t.gsub(re) { |m|
        captures = intify($~)
        #p captures
        _, id, delta_base, mult_out, mult_in, id_in, op, delta_in, add_out, id_add = captures
 
        mult = mult_out * mult_in
        dim1 = dims[id]
        if !dim1 || mult != dim1
            $stderr.puts "Unknown: #{_}"
            _
        else
            delta_in = -delta_in if op == "-"
            delta = mult_out * delta_in + delta_base + (add_out || 0)
            dim1_delta = delta / dim1
            dim2_delta = delta % dim1
            if dim2_delta > dim1 / 2
                dim1_delta += 1
                dim2_delta -= dim1
            end

            #p [mult, delta]
            "#{id}[#{addexp id_in, dim1_delta}][#{addexp id_add, dim2_delta}]"
        end
    }
    $stderr.puts "#{t.ljust(50)} => #{ts}" if t != ts
    puts ts if has_args
end
