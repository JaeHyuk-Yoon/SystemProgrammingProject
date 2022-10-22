libtest.a : add.o substract.o multiply.o divide.o
	ar rcs libtest.a add.o substract.o multiply.o divide.o
add.o : add.c
	gcc -c add.c
substract.o : substract.c
	gcc -c substract.c
multiply.o : multiply.c
	gcc -c multiply.c
divide.o : divide.c
	gcc -c divide.c
clean : 
	rm -f libtest.a add.o substract.o multiply.o divide.o
