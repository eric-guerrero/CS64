# Arithmetic.asm
# A simple calculator program in MIPS Assembly for CS64
#

.text
main:

	# TODO: Write your code here
	
	#Get arg 1 from usr and place it into a0
	li $v0,5
	syscall
	move $a0, $v0
	
	#move arg 1 to temp{0}
	move $t0,$a0
	
	#Get arg 2 from usr and place it into a0
	li $v0,5
	syscall
	move $a0, $v0

	#move arg 2 to temp{1}
	move $t1,$a0

	#Get arg 3 from usr and place it into a0
	li $v0,5
	syscall
	move $a0,$v0

	#move arg 3 to temp {4}
	move $t4,$a0
	
	#(a-b) = d
	sub $t3,$t0,$t1

	# 2(d) == d + d
	add $t3,$t3,$t3
	
	#3(c) = $t5
	li $s0,3
	mult $t4,$s0
	mflo $t5


	# (d + d) + 3*c
	add $t7,$t3,$t5
	move $a0,$t7

	#Print what's in a{0}
	li $v0,1
	#move $a0,$t0
	syscall


	

exit:
	# Exit
	li $v0, 10
	syscall

