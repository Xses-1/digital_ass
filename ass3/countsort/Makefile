compile:
	mipsel-linux-musl-as countsort.s -EL -o countsort.o
	mipsel-linux-musl-gcc countsort.o -EL -o countsort.out -static

compile-gnu:
	mipsel-linux-gnu-as countsort.s -EL -o countsort.o
	mipsel-linux-gnu-gcc countsort.o -EL -o countsort.out -static

run: compile
	qemu-mips ./countsort.out

scp:
	dd if=countsort.out | ssh tomato 'mkdir -p /tmp/home/root/grass ; cd /tmp/home/root/grass; dd of=countsort.out; chmod +x countsort.out; ./countsort.out'

clean:
	rm *.o *.out


#run: countsort
#	qemu-mips ./countsort
#
#test: countsort
#	echo -e '7\n6\n5\n3\n2\n4\n7\n1\n' | qemu-mips ./countsort
#
#countsort: countsort.o
#	mips-linux-musl-gcc countsort.o -o countsort -static 
#
#countsort.o: countsort.s
#	mips-linux-musl-as countsort.s -o countsort.o
#
#clean:
#	rm countsort.o
#
