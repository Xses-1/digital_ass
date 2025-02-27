# Computer Archnitecture and Organisation Lab assignment 2025

## Running the MIPS assignments on baremetal

We're supposed to run it in some MIPS emulator or something,
but Xses has a MIPS router,
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
and even if we 

## License

You should have received a copy of the CC0 Public Domain Dedication
along with this software.
If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.

COPYLEFT 🄯 2025 MAYBETREE AND XSES ALL WRONGS DESERVED.

