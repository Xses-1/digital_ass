CXX=g++
CFLAGS=-pedantic-errors --std=c++98 -g -Wfatal-errors -Wall -Wextra
#SPATH=./src
#OPATH=./bin
ONAME=mips.out

default:
	${CXX} ${CFLAGS} *.cpp -o ${ONAME}

run: default
	./${ONAME}

