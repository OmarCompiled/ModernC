#include <string.h>
#include <assert.h>

double
power(int base, unsigned int exp)
{
	assert(exp >= 0);
	if(!exp) return 1;
	if(!base) return 0;
	
	double result = 1;
	if(exp > 0) {
		int i;
		for(i = 0; i < exp; i++) {
			result *= base;
		}
	} 

	return result;
}

double
my_strtod(const char* nptr)
{
	assert(nptr != NULL);
	double sum = 0.0;
	int point_pos = strlen(nptr);
	bool has_point = (strstr(nptr, ".") != NULL ? true : false);

	int i, j;
	if(has_point) {
		for(i = 0; i < strlen(nptr); i++) {
			if(nptr[i] == '.') {
				point_pos = i;
				break;
			}
		}
	}
	
	for(i = point_pos - 1, j = 0; i >= 0; i--, j++) {
		sum += (nptr[i] - 48) * power(10, j);
	}

	if(has_point) {
		for(i = point_pos + 1, j = 1; i < strlen(nptr); i++, j++) {
			sum += (nptr[i] - 48) / power(10, j);
		}
	}

	return sum;
}
