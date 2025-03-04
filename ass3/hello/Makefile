compile:
	mips-linux-musl-as hello.s -EL -o hello.o
	mips-linux-musl-gcc hello.o -EL -o hello.out -nostdlib -static

run: compile
	qemu-mips ./hello.out

scp:https://www.youtube.com/watch?v=5AN4Fo0GiBIhttps://www.youtube.com/watch?v=5AN4Fo0GiBI
	dd if=hello.out | ssh tomato 'mkdir -p /tmp/home/root/grass ; cd /tmp/home/root/grass; dd of=hello.out; chmod +x hello.out; ./hello.out'

clean:
	rm *.o *.out

