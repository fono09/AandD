#!/usr/bin/perl
use strict;
use warnings;
use Data::Dumper;

print "Input Number of Data:";
my $num = <STDIN>;

my @array = map { int rand $num } 0..$num;
our $heap_size = @array;

&heapsort(\@array);

exit;

sub parent {

	my ($i) = @_;
	return int(($i-1)/2);

}

sub left {

	my ($i) = @_;
	return 2*$i+1;

}

sub right {

	my ($i) = @_;
	return 2*($i+1);
}

sub max_heapify {

	my ($array_ref,$i) = @_;
	
	my $l = &left($i);
	my $r = &right($i);
	my $largest = $i;

	print "Searching $i\n";

	if($l < $heap_size && $array_ref->[$l] > $array_ref->[$i]){
		
		print "Hit L\n";
		$largest = $l;

	}

	if($r < $heap_size && $array_ref->[$r] > $array_ref->[$l]){

		print "Hit R\n";
		$largest = $r;

	}

	if($largest != $i){
		print "Swap $largest $i Value $array_ref->[$largest] $array_ref->[$i]\n";
		($array_ref->[$largest],$array_ref->[$i]) = ($array_ref->[$i],$array_ref->[$largest]);
		&max_heapify($array_ref,$largest);
	}

}

sub build_max_heap {

	my ($array_ref) = @_;

	for(my $i = int $heap_size/2; int $i > 0; $i--){

		&max_heapify($array_ref,$i-1);
	
	}

}

sub heapsort {

	my ($array_ref) = @_;

	print "Input Data\n";
	print Dumper $array_ref;

	&build_max_heap($array_ref); 

	print "Max Heapified\n";
	print Dumper $array_ref;

	for(my $i = $#$array_ref; $i > 0; $i--){

		print "Processing...\n";
		print Dumper $array_ref;
		($array_ref->[0],$array_ref->[$i]) = ($array_ref->[$i],$array_ref->[0]);
		$heap_size--;
		&max_heapify($array_ref,0);
		
	}

	print "Sorted\n";
	print Dumper $array_ref;

}
