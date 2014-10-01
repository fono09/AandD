#!/usr/bin/perl

use strict;
use warnings;

my @a = ();

our $k = 0;
for(; $k < 5; $k++){

	push(@a,$k^$k+2*$k+1);

}
#配列生成

our $j = $k;

for(;$k < 25; $k++){

	push(@a,int(rand(25)));

}

print "配列生成完了\n";
&out_vars(@a);

our $n = @a;

for(; $j < $n; $j++){

	print("Sorting....\n");

	&out_vars(@a);
	
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

		print "$_ | "
		
	}

	print "\n";

}
