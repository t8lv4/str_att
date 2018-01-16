#include <stdio.h>
#include <stdlib.h>

#include "str_att.h"


void Lorenz(set* pSet, double t){

	//constants
	double a = 10 ;
	double b = 28 ;
	double c = (8/3) ;

	//temp. values
	double tx = 0;
	double ty = 0;
	double tz = 0;


	tx = pSet->x + t * a * (pSet->y - pSet->x);
	ty = pSet->y + t * (pSet->x * (b - pSet->z) - pSet->y);
	tz = pSet->z + t * (pSet->x * pSet->y - c * pSet->z);

	pSet -> x = tx;
	pSet -> y = ty;
	pSet -> z = tz;

}

void Rossler(set* pSet, double t){

	//constants
	double a = 0.2 ;
	double b = 0.2 ;
	double c = 5.7 ;

	//temp. values
	double tx = 0;
	double ty = 0;
	double tz = 0;


	tx = pSet->x - (pSet->y+ pSet->z) * t;
	ty = pSet->y + (pSet->x + a * pSet->y) * t;
	tz = pSet->z + (b + pSet->z * (pSet->x - c)) * t;

	pSet -> x = tx;
	pSet -> y = ty;
	pSet -> z = tz;

}
