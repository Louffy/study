#! /usr/bin/perl
use v5.10.0;
use warnings;
use strict;
use Digest::MD5 'md5_hex';

open (my $fh, '<', 'pwd') or die "cannot open pwd file $!";
my %passwords = map({chomp; split(/:/, $_,2)} <$fh>);
my $user;
while (1) {
	print "Username: ";
	chomp($user = <>);
	print "Password: ";
	chomp(my $pass = <>);
	last if($passwords{$user} and md5_hex($pass) eq $passwords{$user});
	say "Sorry!";
}
say "congratulations $user!";
