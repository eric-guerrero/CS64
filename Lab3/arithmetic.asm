# hello.asm
# A "Hello World" program in MIPS Assembly for CS64
#
#  Data Area - allocate and initialize variables
.data
	# TODO: Write your string definitions here
intro:	.asciiz	"Choose an integer number betwen 0 and 1000:\n"
hell: .asciiz "Hello World!\n"
usr: .asciiz "User chose "
fin: .asciiz ". Truly a wise choice.\n"
#Text Area (i.e. instructions)
.text
main:
	#Print intoduction
	li $v0,4	#to print a string
	la $a0, intro 	#load string into a{0}
	syscall		#print to usr
	
	#Get usr number
	li $v0,5
	syscall
	move $t0, $v0	#temp{0} holds usr input
	
	#Print HelloWorld
	li $v0,4
	la $a0, hell
	syscall

	#Print before usr input
	li $v0,4
	la $a0, usr
	syscall

	#Print usr input
	li $v0,1
	move $a0, $t0
	syscall
	
	#Print rest of statement
	li $v0, 4
	la $a0,fin
	syscall

	# TODO: Write your code here

exit:
	# Exit
	li $v0, 10
	syscall

