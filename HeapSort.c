#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEFT(i) (2*(i)+1)
#define RIGHT(i) (2*((i)+1))
//子のインデックスに関する計算をインライン展開

int heap_size;
//ヒープサイズ(後から葉を切り詰める)

int num;
//入力配列長(データ数)

void swap(int *a,int *b){
	//値交換

	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	return;
}

int max_heapify(int* p,int i) {
	//maxヒープ化

	int l = LEFT(i);
	int r = RIGHT(i);
	int largest = i;
	//左右の子と最大値を持つ子のインデックス(以下:例のインデックス)

	if(l < heap_size && *(p+l) > *(p+i)){
		//左の子が存在し、値がインデックスiより大きければ
		
		largest = l;
		//例のインデックスはl


	}

	if(r < heap_size && *(p+r) > *(p+l)){
		//さらに右の子が存在し、より右の子のほうが大きければ

		largest = r;
		//例のインデックスはr

	}

	if(largest != i){
		//子のほうが大きければ

		swap(p+largest,p+i);
		//当該のインデックスと入れ替える

		max_heapify(p,largest);
		//入れ替えた子についてmaxヒープを保つ
	}

	return 0;

}

int build_max_heap(int* p) {
	//最大ヒープ初期化

	int i;
	for(i = (max-1)/2; i > -1; i--){
		//子がいる前提のため末端1段上からソート

		max_heapify(p,i);
	
	}

	return 0;

}

int heapsort(int *p) {
	//int配列をヒープソートできます

	int i;
	build_max_heap(p);
	//maxヒープを作る

	for(i = num-1; i > -1; i--){
		//末端から切り離していく

		swap(p,p+i);
		//根を末端と入れ替えると

		heap_size--;
		//ヒープサイズ右端から小さくなる

		max_heapify(p,0);
		//もう一度根から最大ヒープに
		
	}

	return 0;

}

int main(){

	printf("Input Number of Data:");

	scanf("%d",&num);
	//データ数のみ入力可

	int* p;
	p  = malloc(sizeof(int)*num);
	//配列確保

	srand((unsigned)time(NULL));
	//乱数初期化

	int i;
	
	printf("Input_Array\n");
	for(i = 0; i < num; i++){
		//入力データ作成ループ

		*(p+i) =  rand()%num;
		printf("%d\n",*(p+i));
	
	}
	heap_size = num;
	//ヒープサイズとして保管(numは不変にする)

	
	heapsort(p);
	//ヒープソートの実行

	printf("Sorted_Array\n");
	for(i = 0; i < num; i++){
		//ソート済み配列出力ループ
		
		printf("%d\n",*(p+i));
	
	}

	
	return 0;
}


