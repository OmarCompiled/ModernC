#include <stdio.h>
#include <stdlib.h>

#include "my_strtod.h"

int
main(int argc, char** argv)
{
	if(argc != 2) {
		fprintf(stderr, "usage: strtod <number>\n");

		exit(EXIT_FAILURE);
	}

	const char* str = argv[1];
	printf("%.2f\n", my_strtod(str));

	return 0;
}
