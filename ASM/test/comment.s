.name "zork"						#comment
.comment "just a basic living prog"	#comment
									#comment
l2:		sti r1,%:live,%1			#comment
		and r1,%0,r1				#comment
									#comment
live:	live %1						#comment
		zjmp %:live					#comment
