 .data

ask:	.asciiz "Please eneter an integer: "

        .text
main: 		addi $sp, $sp, -4	# Moving stack pointer to make room for storing local variables (push the stack frame)
		# display statement
		li $v0, 4
		la $a0, ask
		syscall
			
		# read user input
		li $v0, 5
		syscall
		move $a0, $v0
		addi $v0, $zero, 0
		
		jal recursion	# Call recursion(x)
		
		# read user input
		sw $v0, 0($sp)
		lw $a0, 0($sp)
		li $v0, 1
		syscall
		
		j end		# Jump to end of program


recursion:	addi $sp, $sp, -12	# Push stack frame for local storage
 
		sw $ra, 8($sp)		#return address to main
		
		#addi $t0, $a0, 1
		addi $t0, $zero, 10
		bne $a0, $t0, not_ten
		
		# update returned value
		addi $v0, $v0, 2
		
		j end_recur
			
not_ten:	addi $t0, $zero, 11
		bne $a0, $t0, not_eleven

		# update returned value
		addi $v0, $v0, 1
		
		j end_recur		

not_eleven:	sw $a0, 4($sp) 	
		# Prepare new input argument, i.e. m + 2
		addi $a0, $a0, 2
		
		
		jal recursion		# Call recursion(m + 2)
		
		lw $a0, 4($sp)
		
		# Prepare new input argument, i.e. m + 1
		addi $a0, $a0 1
		
		jal recursion		# Call recursion(m + 1)
		
		lw $a0, 4($sp)
		add $v0, $v0, $a0
		

		j end_recur
		
	
end_recur:	lw $ra, 8($sp)
		addi $sp, $sp, 12	# Pop stack frame 
		jr $ra

end:	addi $sp, $sp 4			# Moving stack pointer back (pop the stack frame)
		li $v0, 10 
		syscall
