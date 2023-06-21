.POSIX:
.SUFFIXES:

DEBUG	= 0

CC	= clang
CFLAGS	= -fsanitize=address -O1 -fno-omit-frame-pointer -g \
	  -I. -DDEBUG=$(DEBUG)

clean: ; @sh -c 'X=$$(ls | grep "^[0-9]*$$"); test -n "$$X" || exit 0; echo rm $$X; rm $$X;'
.DEFAULT: ; $(CC) $(CFLAGS) $(LDFLAGS) -o $@ main/$@.c && ./$@
