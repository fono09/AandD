#!/usr/bin/perl


use strict;
use warnings;
use Data::Dumper;

my $i = <STDIN>;
chomp $i;
$i--;

my @array = map {int rand 100} (0..$i);

print Dumper @array;

&quicksort(\@array,0,$#array);

my $before;

print Dumper @array;

sub quicksort {

	my ($array_ref,$p,$r) = @_;

	if($p < $r){
		my $q = &partition($array_ref,$p,$r);
		&quicksort($array_ref,$p,$q-1);
		&quicksort($array_ref,$q+1,$r);
	}else{
		print "0 0 partition detected! \n";
	}

}

sub partition {
	
	my ($array_ref,$p,$r) = @_;
	
	my $x = $array_ref->[$r];

	my $i = $p - 1;
	
	my $j;
	for($j=$p; $j < $r; $j++){
		if($array_ref->[$j] <= $x){
			$i++;
			($array_ref->[$i],$array_ref->[$j]) = ($array_ref->[$j],$array_ref->[$i]);
		}
	}
	($array_ref->[$i+1],$array_ref->[$r]) = ($array_ref->[$r],$array_ref->[$i+1]);
	return $i+1;
}
