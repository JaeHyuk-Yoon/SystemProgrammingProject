/* ndmain.c */
#include <stdio.h>
#include "./lib/testlib.h"

int main()
{
	printf("add(3,4) = %d\n", add(3,4));
	printf("substract(4,2) = %d\n", substract(4,2));
	printf("multiply(3,3) = %d\n", multiply(3,3));
	printf("divide(8,2) = %f\n", divide(8,2));
}
