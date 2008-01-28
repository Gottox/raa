# spiceman - suckless package management tools
# (c) 2007 Enno Boland

include config.mk

TARGET = roman arabic

all: options ${TARGET}

options:
	@echo roman and arabic build options:
	@echo "CFLAGS   = ${CFLAGS}"
	@echo "LDFLAGS  = ${LDFLAGS}"
	@echo "CC       = ${CC}"

${TARGET}: ${OBJ}
	@echo CC -o $@
	@${CC} -o $@ $@.c

clean:
	@echo cleaning
	@rm -f -- ${TARGET}

.PHONY: all options clean
