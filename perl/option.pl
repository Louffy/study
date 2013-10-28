#!/usr/bin/perl
use Getopt::Long;
my $data = "zhangfeixue";
my $length = 24;
my $verbose=123;
GetOptions("length=i" => \$length,
		"file=s" => \$data,
		"verbose" => \$verbose)
or die("Error in command line arguments\n");
print "$verbose  $length  $data\n";
