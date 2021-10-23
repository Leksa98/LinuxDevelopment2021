GENERATES = range
TRASH = *.o *.out
CFLAGS = -O0 -g
GDBFLAGS = --batch --quiet

test: range test1 test2

range: range.c

test%: script%.gdb
	gdb $(GDBFLAGS) --command=$< ./range | grep @@@ | cut -c 4- > $@.out
	cmp $@.answer $@.out

clean:
	rm -f $(TRASH) $(GENERATES)