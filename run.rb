class String
	def colorize(color_code)
	"\e[#{color_code}m#{self}\e[0m"
	end

	def red
	colorize(31)
	end

	def green
	colorize(32)
	end

	def yellow
	colorize(33)
	end

	def blue
	colorize(34)
	end

	def pink
	colorize(35)
	end

	def light_blue
	colorize(36)
	end
end

len = ARGV.length
i = 0

cmd1 =  "./corewar"
cmd2 =  "./real_corewar"

if len > 0
	puts "1. Making binaries".light_blue
	`make`
	puts "Done".green
	while i < len do
		cmd1 += " " + ARGV[i]
		cmd2 += " " + ARGV[i]
		i += 1
	end
	puts "2. Creating both outputs".light_blue
	cmd1 += " > me"
	cmd2 += " > re"
	puts cmd1.red
	puts cmd2.red
	%x[ #{cmd1} ]
	%x[ #{cmd2} ]
	puts "Done".green
	puts "3. Calculating differences".light_blue
	`diff re me > diff`
	diff = `cat diff`
	if diff.length == 0
		puts "No diff :)".green
	else
		puts diff
	end
end
