compile:
	mips-linux-musl-as hello.s -EL -o hello.o
	mips-linux-musl-gcc hello.o -EL -o hello.out -nostdlib -static

run: compile
	qemu-mips ./hello.out

scp:
	dd if=hello.out | ssh wiktom 'mkdir -p /tmp/home/root/grass ; cd /tmp/home/root/grass; dd of=hello.out; chmod +x hello.out; ./hello.out'

clean:
	rm *.o *.out

