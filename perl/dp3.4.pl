#! /usr/bin/perl
use List::Util qw/sum/;
my @t = (1,5,2,10,3);
my $sum = sum @t;
my $len = @t;
my @dp;
my @p;
for(my $k = 0; $k < @t; $k++){
	for( my $l = 0; $l <$sum/2+1;$l++){
			$dp[$k][$l]=0;
			$p[$k][$l]=0;
	}
}
for(my $k = 0; $k < $sum/2+1; $k++){
	if($k>= $t[0]){
		$dp[0][$k] = $t[0];
		$p[0][$k]=1;
	}
}	
for(my $i = 1; $i < $len; $i++){
	for( my $j = $sum/2; $j>= 0;$j--){
		if($j-$t[$i] >=0){
		   if($dp[$i-1][$j-$t[$i]] + $t[$i]> $dp[$i-1][$j]){
				$dp[$i][$j] = $dp[$i-1][$j-$t[$i]]+$t[$i];
		   		$p[$i][$j] = $i+1;
		   }
		   else {
			   $dp[$i][$j] = $dp[$i-1][$j];
			   $p[$i][$j] = $p[$i-1][$j];
		   }
		}
		else {
			$dp[$i][$j] = $dp[$i-1][$j];
			$p[$i-1][$j] = $p[$i-1][$j];
		}
	}
}
#print "@dp\n";
for(my $k = 0; $k < @t; $k++){
	for( my $l = 0; $l <$sum/2 +1;$l++){
		
			print"$dp[$k][$l] ";
		
	}
	print"\n";
}
print "\n";
for(my $k = 0; $k < @t; $k++){
	for( my $l = 0; $l <$sum/2 + 1;$l++){
		
			print"$p[$k][$l] ";
		
	}
	print"\n";
}


