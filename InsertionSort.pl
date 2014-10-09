#!/usr/bin/perl

use strict;
use warnings;

my @a = ();

our $k = 0;

printf("データ数を入力してください:");
$k = <STDIN>;

our $j;

for($j = 0;$j < $k; $j++){

	push(@a,int(rand($j) + $j));

}
$j = 0;

&out_vars(@a);
our $n = @a;

for(; $j < $n; $j++){

	my $key = $a[$j];

	my $i = $j-1;

	while($i > -1 && $a[$i] > $key){

		$a[$i+1] = $a[$i];

		$i = $i-1;

	}


	$a[$i+1] = $key;

}

print "挿入完了\n";

&out_vars(@a);

exit;

sub out_vars {

	my @array = @_;

	foreach (@array) {

		print " $_ \n"
		
	}

}
