#include<stdio.h>
#include<time.h>

#define LENGTH 2

int ref(void *q){

	int i;
	for(i = 0; i < LENGTH; i++){

		printf("q = %p,i = %d,q+i = %p\n",q,i,q+i);

	}

	return 0;
}

int main(){

	int (*p)[LENGTH][LENGTH];
	int test[LENGTH][LENGTH][LENGTH];

	srand((unsigned int)time(NULL));

	p = test;
	int i,j,k;
	for(i = 0; i < LENGTH; i++){

		for(j = 0; j < LENGTH; j++){

			for(k = 0; k < LENGTH; k++){


				p[i][j][k] = rand()%LENGTH;
				printf("test[i][j][k] = %d,p[i][j][k] = %d\n",test[i][j][k],p[i][j][k]);

			}

		}

	}
	printf("test = %p\np = %p\n",test,p);
	
	printf("Start ref(p)\n");
	ref(p);
	printf("End ref(p)\n");

	for(i = 0; i < LENGTH; i++){

		for(j = 0; j < LENGTH; j++){

			for(k = 0; k < LENGTH; k++){

				printf("p[i][j][k] = %d\n",p[i][j][k]);

			}

		}

	}

	return 0;

}