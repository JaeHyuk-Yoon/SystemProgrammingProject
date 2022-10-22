/*my_perror*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void my_perror(const char *s)
{
	printf("%s: No such file or directory\n", s);
} 

main(int argc, char *argv[])
{
	FILE *f;
	
	if (argc < 2) {
		printf("Usage: my_perror file_name\n");
		exit(1);
	}
	
	if ( (f = fopen(argv[1], "r")) == NULL ) {
		my_perror("fopen");
		exit(1);
	}
	
	printf("Open a file \"%s\".\n", argv[1]);
	
	fclose(f);
}
		

