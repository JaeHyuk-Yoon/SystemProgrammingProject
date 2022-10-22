libtest.so : libtest.so.1.0.1
	ln -s libtest.so.1.0.1 libtest.so
libtest.so.1.0.1 : add.o substract.o multiply.o divide.o
	gcc -shared -Wl,-soname,libtest.so -o libtest.so.1.0.1 add.o substract.o multiply.o divide.o
add.o : add.c
	gcc -c add.c
substract.o : substract.c
	gcc -c substract.c
multiply.o : multiply.c
	gcc -c multiply.c
divide.o : divide.c
	gcc -c divide.c
clean : 
	rm -f libtest.so libtest.so.1.0.1 add.o substract.o multiply.o divide.o
