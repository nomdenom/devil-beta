tests = [
    "predungeon[0][8 * (5 * v2 - 5) + 1 + v26]",
    "dungeon[0][8 * (5 * l - 5) + k]",
    "dungeon[0][8 * (5 * sx + 35) + 4 + sy]",
    "predungeon[-1][8 * (5 * i - 5) + 39 + j]",
    "dungeon[39][112 * (v4 - 1) + 39 + v3]", # invalid ref (needs target delta) in themes.cpp
    "BSTYPESL2[dungeon[j - 1][i + 39]]", 
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

re2 = to_re("I[I O N][I O N]")

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

def apply_op(n, op)
    op == "-" ? -n : n
end

has_args = !ARGV.empty?
input = has_args ? ARGF : tests
#$stderr.puts ARGV.inspect
DIMS = {
    "dungeon" => 40,
    "predungeon" => 40,
    "dflags" => 40,
    "dung_map" => 112,
    "dPiece" => 112,
    "dObject" => 112,
}

def arr_exp(id, id1, delta1, id2, delta2, mult = nil)
    dim1 = DIMS[id]
    if !dim1 || (mult && mult != dim1)
        $stderr.puts "Unknown: id=#{id} mult=#{mult}"
        return
    end

    dim1_delta = delta2 / dim1 + delta1
    dim2_delta = delta2 % dim1
    if dim2_delta > dim1 / 2
        dim1_delta += 1
        dim2_delta -= dim1
    end

    #p [id1, dim1_delta, id2, dim2_delta]
    "#{id}[#{addexp id1, dim1_delta}][#{addexp id2, dim2_delta}]"
end

input.each do |t|
    ts = t.gsub(re) { |m|
        captures = intify($~)
        #p captures
        _, id, delta_base, mult_out, mult_in, id_in, op, delta_in, add_out, id_add = captures
 
        delta_in = apply_op(delta_in, op)
        delta = mult_out * delta_in + delta_base + (add_out || 0)

        mult = mult_out * mult_in
        
        arr_exp(id, id_in, 0, id_add, delta, mult) || _
    }.gsub(re2) { |m|
        _, id, id1, op1, d1, id2, op2, d2 = intify($~)
        d1 = apply_op(d1, op1)
        d2 = apply_op(d2, op2)

        arr_exp(id, id1, d1, id2, d2) || _
    }

    $stderr.puts "#{t.ljust(50)} => #{ts}" if t != ts
    puts ts if has_args
end
