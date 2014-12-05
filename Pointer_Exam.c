#include<stdio.h>
#include<time.h>

#define LENGTH 10

int ref(int *q){

	int i;
	for(i = 0; i < LENGTH; i++){

		*(q+i) = *(q+i)*2;
		printf("q = %p,i = %d,q+i = %p\n",q,i,q+i);

	}

	return 0;
}

int main(){

	int *p;
	int test[LENGTH];
	int **test_table[LENGTH][LENGTH];


	srand((unsigned int)time(NULL));

	p = test;
	int i;
	for(i = 0; i < LENGTH; i++){

		p[i] = rand()%LENGTH;
		printf("test[i] = %d,p[i] = %d,i[p] = %d,*(p+i) = %d\n",test[i],p[i],i[p],*(p+i));

	}
	printf("test = %p\np = %p\n",test,p);
	
	printf("Start ref(p)\n");
	ref(p);
	printf("End ref(p)\n");

	for(i = 0; i < LENGTH; i++){

		printf("*(p+i) = %d\n",*(p+i));

	}

	return 0;

}
