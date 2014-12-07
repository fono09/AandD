#include<stdio.h>
#include<time.h>

#define LENGTH 3

int ref(int (*q)[LENGTH][LENGTH]){

	int i,j,k;
	int (*r)[LENGTH];
	int *s;
	int t;
	for(i = 0; i < LENGTH; i++){

		r = q[i];
		printf("int (*r)[%d] = q[%d] = %p\n",LENGTH,i,q);

		for(j = 0; j < LENGTH; j++){

			s = r[j];
			printf("int (*s) = r[%d] = %p\n",j,s);

			printf("int t = s[0..%d] =(",LENGTH-1);
			for(k = 0; k < LENGTH; k++){

				t = s[k];
				printf("%d ",t);

			}
			printf(")\n");

		}

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


				p[i][j][k] = rand()%(LENGTH*LENGTH*LENGTH);

			}

		}

	}
	
	printf("Start ref(p)\n");
	ref(p);
	printf("End ref(p)\n");


	return 0;

}
