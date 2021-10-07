GENERATES = prog prog-a prog-so liboutput.so liboutput_static.a README
TRASH = *.o *~ o.* *.test
ONE_PARAMETER = some_parameter
THREE_PARAMETERS = one two three
CFLAGS = -fPIC

all: README prog prog-a prog-so

prog: const.o fun.o prog.o

prog-a: prog.o liboutput_static.a
	$(CC) -L. $< -loutput_static -o $@

prog-so: prog.o liboutput.so
	$(CC) -L. $< -loutput -o $@

liboutput.so: fun.o const.o
	$(CC) -shared $^ -o $@

liboutput_static.a: fun.o const.o
	ar -rcs $@ $^

README: prog
	./$< 2> $@

fun.o: outlib.h

test: prog prog-a prog-so

	./prog 1> result1.test 2> error1.test
	./prog-a 1> result2.test 2> error2.test
	LD_LIBRARY_PATH=`pwd` ./prog-so 1> result3.test 2> error3.test

	cmp result1.test result2.test
	cmp result1.test result3.test
	cmp result2.test result3.test

	./prog $(ONE_PARAMETER) 1> result1.test 2> error1.test
	./prog-a $(ONE_PARAMETER) 1> result2.test 2> error2.test
	LD_LIBRARY_PATH=`pwd` ./prog-so $(ONE_PARAMETER) 1> result3.test 2> error3.test

	cmp result1.test result2.test
	cmp result1.test result3.test
	cmp result2.test result3.test
	cmp error1.test error2.test
	cmp error1.test error3.test
	cmp error2.test error3.test

	./prog $(THREE_PARAMETERS) 1> result1.test 2> error1.test
	./prog-a $(THREE_PARAMETERS) 1> result2.test 2> error2.test
	LD_LIBRARY_PATH=`pwd` ./prog-so $(THREE_PARAMETERS) 1> result3.test 2> error3.test

	cmp result1.test result2.test
	cmp result1.test result3.test
	cmp result2.test result3.test
	cmp error1.test error2.test
	cmp error1.test error3.test
	cmp error2.test error3.test


clean:
	rm -f $(TRASH)

distclean: clean
	rm -rf $(GENERATES)