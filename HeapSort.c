#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int heap_size;
int num;

void swap(int *a,int *b){

	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	return;
}
int left(int i) {

	return 2*i+1;

}

int right(int i) {

	return 2*(i+1);
}

int max_heapify(int* p,int i) {

	int l = left(i);
	int r = right(i);
	int largest = i;

	if(l < heap_size && *(p+l) > *(p+i)){
		
		largest = l;

	}

	if(r < heap_size && *(p+r) > *(p+l)){

		largest = r;

	}

	if(largest != i){
		swap(p+largest,p+i);
		max_heapify(p,largest);
	}

	return 0;

}

int build_max_heap(int* p) {

	int i;
	for(i = heap_size/2; i > -1; i--){

		max_heapify(p,i);
	
	}

	return 0;

}

int heapsort(int *p) {

	int i;
	build_max_heap(p); 

	for(i = num-1; i > -1; i--){

		swap(p,p+i);
		heap_size--;
		max_heapify(p,0);
		
	}

	return 0;

}

int main(){

	printf("Input Number of Data:");

	scanf("%d",&num);

	int* p;
	p  = malloc(sizeof(int)*num);

	srand((unsigned)time(NULL));

	int i;
	
	printf("Input_Array\n");
	for(i = 0; i < num; i++){

		*(p+i) =  rand()%num;
		printf("%d\n",*(p+i));
	
	}
	heap_size = num;

	
	heapsort(p);

	printf("Sorted_Array\n");
	for(i = 0; i < num; i++){
		
		printf("%d\n",*(p+i));
	
	}

	
	return 0;
}


