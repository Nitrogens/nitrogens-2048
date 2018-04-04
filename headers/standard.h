#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#ifndef __cplusplus
	#include <stdbool.h>
#endif

#undef true
#undef false
#undef bool

#define true 1;
#define false 0;

typedef _Bool bool;

enum direction
{
	up,
	right,
	down,
	left
};
