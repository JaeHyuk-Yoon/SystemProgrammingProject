/*my_assert*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void my_assert(int num)
{
	if((num < 0) || (num > 100)) 
	{
		printf("%s: %s:%d: %s: Assertion '((num >= 0) && (num <= 100))' failed\n", __FILE__, __FILE__, __LINE__, __func__);
		exit(1);
	}
} 

void foo(int num)
{
	my_assert(num);
	
	printf("foo: num = %d\n", num);
}

main(int argc, char *argv[])
{
	int num;
	
	if (argc <2) {
		fprintf(stderr, "Usage: my_assert aNumber\n(0 <= aNumber <= 100)\n");
		exit(1);
	}
	
	num = atoi(argv[1]);
	foo(num);
}
		

