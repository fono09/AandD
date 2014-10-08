#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int *a,int p, int q, int r){

	int n_1 = q - p;
	int n_2 = r - q;

	int *L,*R;

	L = (int*)malloc(sizeof(int)*n_1+1);
	R = (int*)malloc(sizeof(int)*n_2+1);

	int i,j,k;
	printf("make L[%d] array.....\n",n_1);
	for(i = 0; i < n_1; i++){
		printf(" %d |",a[p+i]);
		L[i] = a[p+i];
	}
	printf("\n");

	printf("make R[%d] array.....\n",n_2);
	for(j = 0; j < n_2; j++){
		printf(" %d |",a[q+j]);
		R[j] = a[q+j];
	}
	printf("\n");

	i = 0;
	j = 0;

	for(k = p; k < r; k++){
		if(L[i] <= R[j] && i < n_1 && j < n_2){
			a[k] = L[i];
			i++;
		}else if(L[i] > R[j] && i < n_1 && j < n_2){
			a[k] = R[j];
			j++;
		}else if(i < n_1){
			a[k] = L[i];
			i++;
		}else{
			a[k] = R[j];
			j++;
		}
	}

	printf("Sorted a[%d] to a[%d].....\n",p,r-1);
	for(k = p; k < r; k++){
		printf(" %d |",a[k]);
	}
	printf("\n");

	free((void *)L);
	free((void *)R);

}

void merge_sort(int *a, int p, int r){

	printf("Called merge_sort(*a,%d,%d)\n",p,r);
	if(p+1 < r){
		int q=(p+r)/2;
		merge_sort(a,p,q);
		merge_sort(a,q,r);
		merge(a,p,q,r);
	}
}
int main(){

	
	int i;
	srand((unsigned)time(NULL));

	int num_of_data = rand()%50 + 50;
	int data[num_of_data];

	for(i = 0; i < num_of_data; i++){

		data[i] = rand()%100;
		printf(" %d |",data[i]);

	}
	printf("\n");
	printf("Complete Initialize.....\n");

	merge_sort(data,0,num_of_data);

	printf("Complete Sort.....\n");
	for(i = 0; i < num_of_data; i++){

		printf(" %d |",data[i]);

	}
	printf("\n");
	
	return 0;
}
