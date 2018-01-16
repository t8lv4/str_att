#include <stdio.h>
#include <stdlib.h>

#include "str_att.h"
//#include "str_att.c"

int main(){

	//to get the function
	int f = 0;

	//continue or discrete behavior
	int b = 0;

	//delta
	double dt = 0;


	/*
	input functions, i.e. strange op settings in bees
	*/

	//get the strange attractor's function
	printf("which function (type a number between 0 and 1)\n");
	scanf("%d", &f);

	/*
	get the behavior :
	continuous = output contiguous set of values
	discrete = output a set of values at given index
	*/
	printf("continue or discrete (0 or 1)?\n");
	scanf("%d", &b);

	//get the delta
	printf("what's the delta ?\n");
	scanf("%lf", &dt);



	//initalize values, 'set' is the name of a struct of type set
	set val;
	set* pval;
	pval = &val;
	val.x = 0.1;
	val.y = 0;
	val.z = 0;

	//resetting '\n'
	char e = getchar();
	e = 0;

	switch (f) {
		//lorentz
		case 0 :
			if(b == 0){
				char e = 0;
				//in bees : it's a dynamic trigger from an op.
				printf("press enter to get a set of values\n");
				e = getchar();

				while(e == '\n'){
					Lorenz(pval, dt);
					/*
					output values, i.e. output function in bees
					*/
					printf("%.6lf\n%.6lf\n%.6lf\n", 100*val.x, 100*val.y, 100*val.z );

					//wait for trigger
					e = 0;
					printf("press enter to get the next set of values or q to quit\n");
					e = getchar();
				}

			} else {
				//in bees : dynamic input from an op.
				int r = 0;
				printf("choose an index number\n");
				scanf("%d", &r);

				while(r != 0){
					for(int i = 0; i < r; i++){
						Lorenz(pval, dt);
					}

					printf("%.6lf\n%.6lf\n%.6lf\n\n",100*val.x,100* val.y,100* val.z );
					//re-init values
					val.x = 0.1;
					val.y = 0;
					val.z = 0;

					//wait for trigger
					printf("index number ? (or 0 to quit)\n");
					scanf("%d", &r);
				}
			}

		break;
		//rossler
		case 1 :
				if(b == 0){
					char e = 0;
					printf("press enter to get a set of values\n");
					e = getchar();
					//contiguous function
					while(e == '\n'){
						Rossler(pval, dt);
						printf("%.6lf\n%.6lf\n%.6lf\n", 100*val.x, 100*val.y, 100*val.z );

						e = 0;
						printf("press enter to get the next set of values or q to quit\n");
						e = getchar();
					}
				} else {
					//in bees : dynamic input from an op.
					int r = 0;
					printf("choose an index number\n");
					scanf("%d", &r);

					while(r != 0){
						for(int i = 0; i < r; i++){
							Rossler(pval, dt);
						}

						printf("%.6lf\n%.6lf\n%.6lf\n\n",100*val.x,100*val.y,100*val.z );
						val.x = 0.1;
						val.y = 0;
						val.z = 0;

						printf("index number ? (or 0 to quit)\n");
						scanf("%d", &r);
					}
				}
	}
	return 0;
}
