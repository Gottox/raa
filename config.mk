# version
VERSION = 0.0

# Customize below to fit your system

# paths
PREFIX = /usr/local
MANPREFIX = ${PREFIX}/share/man

# includes and libs
INCS = -I. -I/usr/include
LIBS = -L/usr/lib -lc

# flags
CFLAGS = -static -Os -ansi -g -Wall -Werror ${INCS} -DVERSION=\"${VERSION}\"
LDFLAGS = -g ${LIBS}

# compiler and linker
CC = cc
