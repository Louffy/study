#! /usr/bin/perl
my @array = (2,8,4,-4,5,9,11);
my $len = @array;
my @M;
my @f;
print "safasfsdf...$array[2]\n";
&LIS();
sub LIS {
	$M[0] = $array[0];
	$f[0] = 1;
	print "@array\n";
	print "$len\n";
	print "@M\n";
	for( my $i = 1; $i < $len; $i++) {
		my $n = @M;
			my $m = &bisearch(@M,$n,$array[$i]);
			print "$m\n";
			$M[$m] = $array[$i];
			$f[$i] = $m + 1;
		
		print "@M+++++\n";
		print "@f-----\n";
		print "@pre****\n";
	}
	my $n = @M;
	print "------$n\n";
	for(my $i = $len-1; $i >= 0; $i--) {
		if($n < 0){
			break;
		}
		while($f[$i] == $n && $n >= 0){
		   print" $array[$i] + ";
		   $n--;
		}	   
	}
	print "\n";
}

sub bisearch{
	my $bm = pop(@_);
	my $blen = pop(@_);
	my @barray = @_;
	my $left = 0;
	my $right = $blen - 1;
	my $mid;
	while($left <= $right) {
		$mid = int($left + ($right - $left)/2);
		if($barray[$mid] == $bm){
			return ($mid);
		}
		elsif($barray[$mid] > $bm){
			$right = $mid-1;
		}
		else {
			$left = $mid + 1;
		}
	}
	return ($left);
}
