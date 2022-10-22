/* main.c */
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main()
{
	void * handle;
	int(*add)(int, int), (*substract)(int, int), (*multiply)(int, int);
	float(*divide)(float, float);
	char *error;
	
	handle = dlopen ("./lib/libtest.so", RTLD_LAZY);
	if(!handle) {
		fputs(dlerror(), stderr);
		exit(1);
	}
	add = dlsym(handle, "add");
	if((error =dlerror()) != NULL) {
		fprintf(stderr, "%s", error);
		exit(1);
	}
	substract = dlsym(handle, "substract");
	if((error = dlerror()) != NULL) {
		fprintf(stderr, "%s", error);
		exit(1);
	}
	multiply = dlsym(handle, "multiply");
	if((error = dlerror()) != NULL ) {
		fprintf(stderr, "%s", error);
		exit(1);
	}
	divide = dlsym(handle, "divide");
	if((error = dlerror()) != NULL ) {
		fprintf(stderr, "%s", error);
		exit(1);
	}
	printf("add(3,4) = %d\n", add(3,4));
	printf("substract(4,2) = %d\n", substract(4,2));
	printf("multiply(3,3) = %d\n", multiply(3,3));
	printf("divide(8,2) = %f\n", divide(8,2));
	dlclose(handle);
}
