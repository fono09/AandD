#!/usr/bin/perl

use strict;
use warnings;
use Data::Dumper;

my $i = 100;
#100個数字が降ってきます

my @a = ();
#空の配列を用意します

while($i != 0){
	my $insert_num = int(rand(100));

	my $first = 0;
	my $end = @a;
	
	print "\$first = $first \$end = $end\n";
	print "\@a = ";
	print Dumper @a;
	print "\nStart Insert!!\n";

	if(&insert(\@a,$insert_num,$first,$end) == -1){
		last;
	}
	

	print "End Insert!!\n";

	$i--;
}

foreach my $out_ (@a) {

	print "$out_ | ";

}
exit;

sub insert {

	my ($array_ref, $insert_num, $first, $end) = @_;

	my $center = int(($first+$end)/2);

	print "\$insert_num = $insert_num \$frist = $first \$end = $end \$center = $center\n";
	print "\@a = ";
	print Dumper @a;
	print "\n";
	if($first > $end ){ print "Error!"; return -1; }


	if(!defined($$array_ref[$center])){
		
		push(@$array_ref,$insert_num);
		return 0;

	
	}elsif($first==$end-1 || $first==$end){

		if($$array_ref[$center] < $insert_num){

			splice(@$array_ref,$center+1,0,$insert_num);
			return $center+1;

		}else{

			splice(@$array_ref,$center,0,$insert_num);
			return $center;
		}

	}elsif($$array_ref[$center]==$insert_num){

		splice(@$array_ref,$center,0,$insert_num);
		return $center;

	}elsif($$array_ref[$center] < $insert_num){

		return insert($array_ref,$insert_num,$center+1,$end);

	}elsif($$array_ref[$center] > $insert_num){
		
		return insert($array_ref,$insert_num,$first,$center-1);

	}
}
