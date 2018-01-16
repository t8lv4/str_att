#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	double x ;
	double y ;
	double z ;
} set;

void Lorenz(set*, double);

void Rossler(set*, double);
