.section .text

.global __start

__start:
	# Put "exit" syscall number into li0

	li $v0, 4001

	# Exit with exit code of 69
	li $a0, 69

	# Do the syscall
	syscall

.section .data

