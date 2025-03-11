# Computer Archnitecture and Organisation Lab assignment 2025

## Running the MIPS assignments on baremetal

We're supposed to run it in some MIPS emulator or something,
but Xses has a MIPS router
flashed with a linux-based firmware
called "freshtomato"
so we decided to run our programs on that.
This is a small writeup on getting it to work.

### Compiling for MIPS

We followed the tutorial at
<https://www.youtube.com/watch?v=5AN4Fo0GiBI>
to write a simple MIPS assembly program
that exists with a status code of `69`.
The tutorial shows how to run it with `qemu-mips`,
and it worked fine for us.
The only difference is that the guy used
`mips-linux-gnu-as`,
while we had `mips-linux-musl-as`.
This is because maybetree's distro packages the musl
mips toolchain but not the gcc one.
For the purpose of this assignment,
it doesn't matter, because we're
not using the libc,
and even if we were, we would be compiling it statically.

The next step is to put the file on
the router.
This is non-trivial -- it's running
some weirdly configured version of dropbear
that doesn't support `scp`.
So instead we can just pipe the compiled file through
the `ssh` command.
But in order to do that,
we need to set up key-based auth,
becuase we'd no longer be able to type the password to stdin.

On local: `ssh-keygen -t rsa -b 2048` and tell it to save the key
to `~/.ssh/id_tomato`.

Then, edit `~/.ssh/config` on local and add entry for the router:

```
Host tomato
	User root
	Hostname xxx.yyy.zzz.www
	IdentityFile ~/.ssh/id_tomato
```

Next, copy the contents of `~/.ssh/id_tomato.pub` on local
to `/tmp/home/root/.ssh/authorized_keys` on the router
(by opening the file in VI and pasting in the public key).

Now you should be able to `ssh tomato` without typing in a password.

Finally, transfer the executable
by running
`dd if=hello.out | ssh tomato 'dd of=/tmp/home/root/hello.out`.

you will see a very strange error if you try to run the executable:

```
./hello.out: line 1: syntax error: unexpected "("
```

It seems like the router isn't understanding that
it's a binary executable and trying to run it as a shell script.

Here we use our spidey-sense and figure out that
the format of the executable is not correct.
We need to know what is the correct format.
To do that, we can exfiltrate a known-good executable
from the router and analyse it.

Copy the busybox executable from router to local:
`ssh tomato 'dd if=/bin/busybox' | dd of=./busybox-from-router`

Run readelf:

`readelf -h ./busybox-fromrouter`

Output:

```
ELF Header:
  Magic:   7f 45 4c 46 01 01 01 00 00 00 00 00 00 00 00 00 
  Class:                             ELF32
  Data:                              2's complement, little endian
  Version:                           1 (current)
  OS/ABI:                            UNIX - System V
  ABI Version:                       0
  Type:                              EXEC (Executable file)
  Machine:                           MIPS R3000
  Version:                           0x1
  Entry point address:               0x4066b0
  Start of program headers:          52 (bytes into file)
  Start of section headers:          625944 (bytes into file)
  Flags:                             0x70001007, noreorder, pic, cpic, o32, mips32r2
  Size of this header:               52 (bytes)
  Size of program headers:           32 (bytes)
  Number of program headers:         8
  Size of section headers:           40 (bytes)
  Number of section headers:         27
  Section header string table index: 26
```

Now analyse our own executable.
Run readelf: `readelf -h hello.out`

Output:

```
ELF Header:
  Magic:   7f 45 4c 46 01 02 01 00 00 00 00 00 00 00 00 00 
  Class:                             ELF32
  Data:                              2's complement, big endian
  Version:                           1 (current)
  OS/ABI:                            UNIX - System V
  ABI Version:                       0
  Type:                              EXEC (Executable file)
  Machine:                           MIPS R3000
  Version:                           0x1
  Entry point address:               0x400110
  Start of program headers:          52 (bytes into file)
  Start of section headers:          680 (bytes into file)
  Flags:                             0x1000, o32, mips1
  Size of this header:               52 (bytes)
  Size of program headers:           32 (bytes)
  Number of program headers:         4
  Size of section headers:           40 (bytes)
  Number of section headers:         9
  Section header string table index: 8
```

Notice how the the known-good executable is little-endian,
while ours is big-endian?

Bu piping `mips-linux-musl-as --help` to `less` and
searching for `endian`,
we find out that the `-EL` flag can be used to tell gcc to produce
little-endian executables.

We add `-EL` to the `mips-linux-musl-as` and `mips-linux-musl-gcc`
invocations,
transfer the executable to the file again,
and success! it works!

`ass3/hello/Makefile`

has our final commands for building the esecutable
and copying it to the router and running it.

### Connecting to router

If you have both a wireless card and wired card in your laptop
it is easy to connect to the router while still having internet.
You just have to change the metrics of the routes
so that the wifi connection (internet)
gets priority over the wired connection (router)
(usually, the opposite is the default).
You can use the `ip` command for this.
Tab-complete really helps here also.

```
sudo ip route replace default via {IP} dev {DEVICE} metric {METRIC}

# Lower metric=higher prio. Set wifi to have small metric
sudo ip route replace default via 145.94.128.1 dev wlan0 metric 1

# Set wired to have high metric
sudo ip route replace default via 192.168.1.1 dev eth0 metric 600
```


## License

You should have received a copy of the CC0 Public Domain Dedication
along with this software.
If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.

COPYLEFT 🄯 2025 MAYBETREE AND XSES ALL WRONGS DESERVED.

