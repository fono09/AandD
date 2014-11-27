#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define DATA 10

int main(){

	srand((unsigned)time(NULL));
	//乱数初期化

	int array[DATA];
	//指定数配列確保

	int j;
	for(j=0; j<DATA; j++){

		array[j] = rand()%(DATA*10);

	}
	//データ準備

	printf("input : \n");
	for(j=0; j<DATA; j++){

		printf("%d \n",array[j]);

	}
	//入力配列を表示

	quicksort(array,0,DATA-1);
	//配列全体へクイックソート実行

	printf("output : \n");
	for(j=0; j<DATA; j++){

		printf("%d \n",array[j]);

	}
	//出力配列を表示

	return 0;

}
int quicksort(int* array,int p,int r){

	if(p < r){

		int q = partition(array,p,r);
		quicksort(array,p,q-1);
		quicksort(array,q+1,r);

	}
	//分割処理

	return 0;

}

int partition(int* array,int p,int r){
	
	int x = array[r];
	//ピボット

	int i = p - 1;
	//処理開始位置
	
	int tmp;
	//値交換退避領域

	int j;
	for(j=p; j < r; j++){

		if(array[j] <= x){

			i++;
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;

		}
		//ピボットと比較して入れ替え

	}
	//範囲全体に対して行う

	tmp = array[i+1];
	array[i+1] = array[r];
	array[r] = tmp;
	//ピボットを最終的に入れ替え

	return i+1;
}
