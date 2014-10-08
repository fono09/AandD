#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int *a,int p, int q, int r){

	int n_1 = q - p;
	int n_2 = r - q;
	//探索範囲確保

	int i,j,k;
	//ループ用変数3つ宣言

	int *L,*R;
	//ポインタを宣言

	L = (int*)malloc(sizeof(int)*n_1+1);
	R = (int*)malloc(sizeof(int)*n_2+1);
	//必要分のみ確保

	for(i = 0; i < n_1; i++){
		L[i] = a[p+i];
	}
	//分割左配列生成

	for(j = 0; j < n_2; j++){
		R[j] = a[q+j];
	}
	//分割右配列生成

	i = 0;
	j = 0;
	//L,Rへのコピー済みインデックス

	for(k = p; k < r; k++){
		//ソート範囲に限り

		if(L[i] <= R[j] && i < n_1 && j < n_2){
			//インデックスがオーバーランしていなければ比較しより小さい方先にコピー
			a[k] = L[i];
			i++;

		}else if(L[i] > R[j] && i < n_1 && j < n_2){
			//同じく小さい方を先にコピー
			a[k] = R[j];
			j++;
		}else if(i < n_1){
			//インデックスがオーバランしていない残りをコピー
			a[k] = L[i];
			i++;
		}else{
			//インデックスがオーバランしていない残りをコピー
			a[k] = R[j];
			j++;
		}
	}

	free((void *)L);
	free((void *)R);
	//確保した領域解放

}

void merge_sort(int *a, int p, int r){

	if(p+1 < r){
		//ループ条件を満たす間
		int q=(p+r)/2;
		merge_sort(a,p,q);
		merge_sort(a,q,r);
		//二分探索し
		merge(a,p,q,r);
		//マージ
	}
}
int main(){

	
	int i,j;
	srand((unsigned)time(NULL));
	//乱数初期化

	printf("最低データ数を入力してください:");
	scanf("%d",&j);
	//最低データ数を入力

	int num_of_data = rand()%j + j;
	//データ数を最低10000データでランダム
	int data[num_of_data];
	//データ数分確保

	for(i = 0; i < num_of_data; i++){

		data[i] = rand()%j;
		printf(" %d |",data[i]);

	}
	printf("\n");
	//データをランダムで埋めつつ初期出力

	merge_sort(data,0,num_of_data);
	//先頭ポインタを与え、データ数を指定するのみでマージソート

	for(i = 0; i < num_of_data; i++){

		printf(" %d |",data[i]);

	}
	printf("\n");
	//ソート確認出力
	
	return 0;
}
