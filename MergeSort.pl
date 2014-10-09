#!/usr/bin/perl

use strict;
use warnings;


sub merge {
	
	my ($array_ref,$p,$q,$r) = @_;

	my $n_1 = $q - $p;
	my $n_2 = $r - $q;
	#探索範囲確保

	my ($i,$j,$k);
	#ループ用変数3つ宣言

	my (@L,@R);
	#配列を宣言

	for($i = 0; $i < $n_1; $i++){
		push(@L,$array_ref->[$p+$i]);
	}
	#分割左配列生成

	for($j = 0; $j < $n_2; $j++){
		push(@R,$array_ref->[$q+$j]);
	}
	#分割右配列生成

	$i = 0;
	$j = 0;
	#L,Rへのコピー済みインデックス

	for($k = $p; $k < $r; $k++){
		#ソート範囲に限り

		
		if(defined($L[$i]) && defined($R[$j])){
			if($L[$i] <= $R[$j]){
				#インデックスがオーバーランしていなければ比較しより小さい方先にコピー
				$array_ref->[$k] = $L[$i];
				$i++;

			}elsif($L[$i] > $R[$j]){
				#同じく小さい方を先にコピー
				$array_ref->[$k] = $R[$j];
				$j++;
			}
		}elsif($i < $n_1){
			#インデックスがオーバランしていない残りをコピー
			$array_ref->[$k] = $L[$i];
			$i++;
		}else{
			#インデックスがオーバランしていない残りをコピー
			$array_ref->[$k] = $R[$j];
			$j++;
		}
	}

}

sub merge_sort {
	my ($array_ref, $p, $r) = @_;

	if($p+1<$r){
		#ループ条件を満たす間
		my $q=int(($p+$r)/2);
		&merge_sort($array_ref,$p,$q);
		&merge_sort($array_ref,$q,$r);
		#二分探索し
		&merge($array_ref,$p,$q,$r);
		#マージ
	}
}



my ($i,$j);

printf("最低データ数を入力してください:");
$j = <STDIN>;
#最低データ数を入力

my $num_of_data = int(rand($j) + $j);
#データ数を最低$jデータでランダム
my @data;
#データ数分確保

for($i = 0; $i < $num_of_data; $i++){

	push(@data,int(rand($j)));
	printf(" %d \n",$data[$i]);

}
#データをランダムで埋めつつ初期出力

&merge_sort(\@data,0,$num_of_data);
#アレイレファレンスを与え、データ数を指定するのみでマージソート

for($i = 0; $i < $num_of_data; $i++){

	printf(" %d \n",$data[$i]);

}
#ソート確認出力

exit;
