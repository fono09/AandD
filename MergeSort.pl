#!/usr/bin/perl

use strict;
use warnings;


sub merge {

	my ($array_ref,$p,$q,$r) = @_;

	my $n_1 = $q - $p;

	my $n_2 = $r - $q;

	my (@L,@R);

	for(my $i = 0; $i < $n_1; $i++){

		$L[$i] = $A[$p + $i];

	}
	
	for(my $j = 0; $j < $n_2; $j++){

		$R[$j] = $A[$q + $j];

	}

	$L[$n_1] = inf;
	$R[$n_2] = inf;

	my $i = 1;
	my $j = 1;
	
	for(my $k = $p; $k < $r; $k++){

		if( $L[$i] <= $R[$j] ){

			$A[$k] = $L[$i];
			
			$i++;

		}else{

			$A[$k] = $R[$j]

			$j++;

		}
	}
}
