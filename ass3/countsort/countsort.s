.equ WORD_SIZE, 4


# Allocate `num_words` words onto the stack.
# As per book, stack "grows" downwards, hence
# the minus sign
.macro stalloc num_words
	addiu $sp, $sp, -(WORD_SIZE * \num_words)
.endm

# Free `num_words` words from the stack.
.macro stfree num_words
	addiu $sp, $sp, (WORD_SIZE * \num_words)
.endm

# Store register `reg` in the
# current stack frame at index `index`
.macro stackstore reg, index
	sw \reg, (WORD_SIZE * \index)($sp)
.endm

# Load into register `reg` the
# word stored in the current
# stack frame at index `index`
.macro stackload reg, index
	lw \reg, (WORD_SIZE * \index)($sp)
.endm

# Load address of stack element at `index`
# into register `reg`
.macro staddrload reg, index
	addiu \reg, $sp, (WORD_SIZE * \index)
.endm

# Exit with code `code`
.macro exit code
	li $v0, 4001  # 4001 is linux "exit" syscall
	li $a0, \code
	syscall
.endm

.section .text

.global main

main:
	# Prompt user for array size
	la $a0, hello_string
	jal puts
	jal scan_int

	# Quadruple the number to
	# get the size in bytes
	add $v0, $v0, $v0
	add $v0, $v0, $v0
	# Save size in bytes
	# to persistent register $s3
	addi $s3, $v0, 0

	# Allocate space for array
	addi $a0, $s3, 0
	jal malloc
	# If malloc return a null pointer, exit program
	beq $v0, $zero, malloc_fail

	# Print message
	la $a0, insert_string
	jal puts

	# Save address of array
	# to persistent register $s4
	addi $s4, $v0, 0

	# Read in array elements
	# let s1 be the upper bound of the loop
	# and s0 the variable of iteration
	# Remeber, s3 is size of array in bytes.
	addi $s0, $s4, 0
	addi $s1, $s3, 0
	add $s1, $s1, $s0

l_read:	
	beq $s0, $s1, lx_read
	jal scan_int
	sw $v0, 0($s0)
	addi $s0, $s0, WORD_SIZE
	j l_read
lx_read:	

	

	# Print array
	# let s1 be the upper bound of the loop
	# and s0 the variable of iteration
	addi $s0, $s4, 0
	addi $s1, $s3, 0
	add $s1, $s1, $s0
l_print:	
	beq $s0, $s1, lx_print
	lw $a0, 0($s0)
	jal print_int
	addi $s0, $s0, WORD_SIZE
	j l_print

lx_print:	

	exit 0

malloc_fail:	
	# If malloc failed, print an error message and exit
	la $a0, malloc_fail_string
	jal puts
	exit -1

selsrt:
	# $a0 = array
	# $a1 = array length (words)

	# let $s0 be the array
	# let $s1 be the array length
	# let $s2 be the loop variable
	# let $s3
	# let $s4 be the index of the minimum value

	# save all used regs
	stalloc 6
	stackstore $s0, 0
	stackstore $s1, 1
	stackstore $s2, 2
	stackstore $s3, 3
	stackstore $s4, 4
	stackstore $ra, 5

	# copy to persistent
	addi $s0, $a0, 0
	# subtract one index because we don't
	# have to loop up to the very last item
	addi $s1, $a1, -1

	# start loop
	addi $s2, $zero, 0
selsrt_l:
	beq $s2, $s1, selsrt_lx

	addi $a0, $s0, 0  # array
	addi $a1, $s2, 0  # first index
	addi $a2, $s1, 0  # last index
	jal index_min
	addi $s3, $v0, 0

	#addi $a0, $s0, 0
	#jal debug_int
	#addi $a0, $s2, 0
	#jal debug_int
	#addi $a0, $s1, 0
	#jal debug_int
	#addi $a0, $s3, 0
	#jal debug_int

	addi $a0, $s0, 0  # array
	addi $a1, $s2, 0  # first index
	addi $a2, $s3, 0  # second index
	jal swap_vals

	addi $s2, $s2, 1
	j selsrt_l
selsrt_lx:
	# recalll all used regs
	stackload $s0, 0
	stackload $s1, 1
	stackload $s2, 2
	stackload $s3, 3
	stackload $s4, 4
	stackload $ra, 5
	stfree 6
	jr $ra


count_less_than:
	# $a0 = array
	# $a1 = length of array
	# $a2 = index of element we're interested in
	# $v0 = number of elements less than this element

	sll $a1, $a1, 2
	sll $a2, $a2, 2

	# according to calling convention,   
	# The t registers can be used
	# without saving them, so that's what we'll do
	# let $t0 be the outter loop variable
	# let $t1 be the outter loop end variable
	# let $t2 be the outter current inspected value

	# let $t3 be the element of interestingness
	# let $t4 be the register of the value of interegnissgnes

	add #
	lw $t3, 0($a2)

	# Start llop
	addi $t0, $a0, 0
	add $t1, $a0, $a1
count_less_than_l:
	beq $t0, $t1, count_less_than_lx
	lw $t2, 0($t0)





count_less_than_lx:






index_min:
	# $a0 = array
	# $a1 = first index (inclusive)
	# $a2 = last index (inclusive)
	# $v0 = index of minimum value

	# according to calling convention,
	# The t registers can be used
	# without saving them, so that's what we'll do
	# let $t0 be the loop variable
	# let $t1 be the loop end variable
	# let $t2 be the minimum value
	# let $t3 be the current inspected value

	# Quadruple indices to get byte offsets
	sll $a1, $a1, 2
	sll $a2, $a2, 2
	# Add one word to $a2 to make it exclusive index
	addi $a2, $a2, 4

	# set minimum value and address to first value
	add $v0, $a0, $a1
	lw $t2, 0($v0)

	# Start loop
	addi $t0, $v0, WORD_SIZE
	add $t1, $a0, $a2
index_min_l:
	beq $t0, $t1, index_min_lx
	lw $t3, 0($t0)
	bge $t3, $t2, index_min_else
	addi $t2, $t3, 0
	addi $v0, $t0, 0

index_min_else:
	addi $t0, $t0, WORD_SIZE
	j index_min_l
index_min_lx:
	# change v0 from address to index
	# by subtracting start addr and divifing by 4
	sub $v0, $v0, $a0
	srl $v0, $v0, 2
	jr $ra

swap_vals:
	# $a0 = array
	# $a1 = index 1
	# $a2 = index 2

	# Quadruple indices to get byte offsets
	add $a1, $a1, $a1
	add $a1, $a1, $a1
	add $a2, $a2, $a2
	add $a2, $a2, $a2

	# according to calling convention,
	# The t registers can be used
	# without saving them, so that's what we'll do
	# let $t0 be the address of the first value
	# let $t1 be the address of the second value
	# let $t2 be a temporary value
	# let $t3 be a temporary value
	add $t0, $a0, $a1
	add $t1, $a0, $a2
	lw $t2, 0($t0)
	lw $t3, 0($t1)
	sw $t2, 0($t1)
	sw $t3, 0($t0)

	jr $ra

scan_int:
	# scanf an int into $v0

	# Need two words:
	# one to remember $ra,
	# one to pass format argument to
	# scanf / read return value of scanf
	stalloc 2

	# store $ra
	stackstore $ra, 0

	# First argument: pointer to format string
	la $a0, scanf_fmt_int
	# Second argument: pointer to target string (what will be read)
	staddrload $a1, 1
	jal scanf 
	# Read return value from stack into return register
	stackload $v0, 1

	# recall $ra, free stack, and jump back to caller
	stackload $ra, 0
	stfree 2
	jr $ra

print_int:
	# printf an int from $a0

	# just one stack word needed to remember $ra
	stalloc 1
	stackstore $ra, 0

	# This function takes the int parameter at $a0,
	# but printf expects the format string at $a0
	# and the int at $a1
	move $a1, $a0
	la $a0, printf_fmt_int
	jal printf

	stackload $ra, 0
	stfree 1
	jr $ra

	stfree 1
debug_int:
	stalloc 1
	stackstore $ra, 0

	move $a1, $a0
	la $a0, debug_fmt_int
	jal printf

	stackload $ra, 0
	stfree 1
	jr $ra

	stfree 1


.section .data
	# CONSTANTS
	malloc_fail_string: .asciz "Malloc fun fukd, bye!"
	hello_string: .asciz "Insert the array size"
	insert_string: .asciz "Insert the array element, one per line"
	# scanf format code to read an int
	scanf_fmt_int: .asciz "%i"
	# printf format code to read an int
	printf_fmt_int: .asciz "%i\n"

	debug_fmt_int: .asciz "foo %i\n"

