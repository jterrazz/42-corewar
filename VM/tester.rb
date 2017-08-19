cmd1 = "./real_corewar -d " + ARGV[0] + " " + ARGV[1]
cmd2 = "./a.out -dump " + ARGV[0] + " " + ARGV[1]
puts cmd1
res_real = %x(#{cmd1})
res_mine = %x(#{cmd2})

puts "----- REAL -----"
puts res_real.split("\n")[2]
# puts res_real

puts "----- MINE -----"
puts res_mine.split("\n")[2]
# puts res_mine

# require 'differ'
#
# Differ.format = :color
# puts Differ.diff_by_word(res_real, res_mine).to_s
