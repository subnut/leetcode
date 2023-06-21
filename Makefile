.POSIX:
.SUFFIXES:
.SUFFIXES: .c

DEBUG	= 0

CC	= clang
CFLAGS	= -fsanitize=address -O1 -fno-omit-frame-pointer -g \
	  -DDEBUG=$(DEBUG)

.c: ; $(CC) $(CFLAGS) $(LDFLAGS) -o $@ $< && ./$@
