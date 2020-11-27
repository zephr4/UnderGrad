.data 
str0: .asciiz "Welcome to BobCat Candy, home to the famous BobCat Bars!"
# Declare any necessary data here

price: .asciiz "Enter the price for each Bobcat Bar: "
wrapper: .asciiz "Enter the number of wrappers need to exchange for a single Bobcat Bar: "
money: .asciiz "Enter the amount of money you have: "
str1: .asciiz "Good! Let me run the number..."
str2: .asciiz "You first buy "
str3: .asciiz "Then, you will get another "
str4: .asciiz " bars."
str5: .asciiz "With $"
str6: .asciiz ", you will receive a maximum of " 
str7: .asciiz " Bobcat Bars!"

.text

main:
		#This is the main program.
		#It first asks user to enter the price of each BobCat Bar.
		#It then asks user to enter the number of bar wrappers needed to exchange for a new bar.
		#It then asks user to enter how much money he/she has.
		#It then calls maxBars function to perform calculation of the maximum BobCat Bars the user will receive based on the information entered. 
		#It then prints out a statement about the maximum BobCat Bars the user will receive.
		
		addi $sp, $sp -12	# Feel free to change the increment if you need for space.
		sw $ra, 0($sp)
		# Implement your main here
		
		li $v0, 4		# prints introductory statement
		la $a0, str0
		syscall
		
		addi $a0, $zero, 0xA 	# ascii code for LF, if you have any trouble try 0xD for CR.
        	addi $v0, $zero, 0xB 	# syscall 11 prints the lower 8 bits of $a0 as an ascii character.
        	syscall			# recieved from https://stackoverflow.com/questions/9875468/printing-newline-in-mips
        
		li $v0, 4		# recieves user input for price
		la $a0, price
		syscall
		li $v0, 5
		syscall
		move $a1, $v0
		
		li $v0, 4		# recieves user input for number of wrappers to exchange
		la $a0, wrapper
		syscall
		li $v0, 5
		syscall
		move $a2, $v0
		
		li $v0, 4		# recieves user input for amount of money
		la $a0, money
		syscall
		li $v0, 5
		syscall
		move $a3, $v0
		
		li $v0, 4
		la $a0, str1
		syscall
		
		jal maxBars 	# Call maxBars to calculate the maximum number of BobCat Bars

		j end			# Jump to end of program



maxBars:
		# This function calculates the maximum number of BobCat Bars.
		# It takes in 3 arguments ($a0, $a1, $a2) as n, price, and money. It returns the maximum number of bars
		
		addi $sp, $sp -12
		sw $ra, 8($sp)
		
		div $a0, $a3, $a1	# numBars = money / price
		sw $a0, 0($sp)
		add $v1, $v1, $a0
		
		beq $v1, $zero, end
		
		addi $a0, $zero, 0xA
        	addi $v0, $zero, 0xB
        	syscall	
        	
		li $v0, 4
		la $a0, str2
		syscall
		
		li $v0, 1
		move $a0, $v1
		syscall
		
		li $v0, 4
		la $a0, str4
		syscall
		
		lw $a0, 0($sp)
		
		jal newBars 		# Call a helper function to keep track of the number of bars.
		
		lw $ra, 8($sp)
		jr $ra
		# End of maxBars

newBars:
		# This function calculates the number of BobCat Bars a user will receive based on n.
		# It takes in 2 arguments ($a0, $a1) as number of wrappers left so far and n.

		sw $ra, 12($sp)
		
		blt $a0, $a2, end		# if numBars >= wrapper
		
		div $t1, $a0, $a2		# bars = numBars / wrapper
		add $v1, $v1, $t1
		
		addi $a0, $zero, 0xA
        	addi $v0, $zero, 0xB
        	syscall	
        	
        	li $v0, 4
		la $a0, str3
		syscall
		
		li $v0, 1
		move $a0, $t1
		syscall
		
		li $v0, 4
		la $a0, str4
		syscall
		
		add $a0, $zero, $t1		# numbars = bars
		sw $a0, 4($sp)
		
		jal newBars
		
		lw $ra, 12($sp)
		
		jr $ra
		# End of newBars
		

		
end: 		
		addi $a0, $zero, 0xA
        	addi $v0, $zero, 0xB
        	syscall	
        	
		li $v0, 4
		la $a0, str5
		syscall
		
		li $v0, 1
		move $a0, $a3
		syscall
		
		li $v0, 4
		la $a0, str6
		syscall
		
		li $v0, 1
		move $a0, $v1
		syscall
		
		li $v0, 4
		la $a0, str7
		syscall
		
		# Terminating the program
		lw $ra, 0($sp)
		addi $sp, $sp 12
		li $v0, 10 
		syscall

# Worked with Spencer Tang
