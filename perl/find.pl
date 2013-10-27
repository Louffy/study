#! /usr/bin/perl
use 5.010000;
use warnings;
use strict;

my $team_number = 42;
my $filename = 'input.txt';

open (my $fh, '<', $filename) or die "cannot open '$filename' $!";

my %bugs = get_team_stats($fh, $team_number);

say "bugs created:";
while (my ($key, $value) = each %bugs) {
	print "$key => $value\n";
}
say " $_: $bugs{$_}[1]" for(
	sort({$bugs{$b}[1] <=> $bugs{$a}[1]} keys %bugs));
say "bugs fixed:";
say " $_: $bugs{$_}[0]" for(sort keys %bugs);

my @winners = get_winners(
	map({$_ => $bugs{$_}[0] - $bugs{$_}[1]} keys %bugs)
	);
say "$_ gets a USB rocket launcher!" for(@winners);
sub get_winners {
	my (%data) = @_;
    while (my ($k,$v) = each %data) {
		print "$k ---> $v \n";
	}	
	my $max = 0;
	my @win;
	for my $key (keys %data) {
		if($data{$key} > $max) {
			@win = ($key);
			$max = $data{$key};
		}
		elsif($data{$key} == $max) {
			push(@win, $key);
		}
	}
	return(@win);
}
sub get_team_stats {
	my ($fh, $number) = @_;
	my @data;
	my $found;

	while(my $line = <$fh>) {
		chomp($line);
		if($line =~ m/^Team (\d+)$/) { #only when Team number
			last if($found);
			$found = 1 if($1 == $number); # only found = 1
			next;
		}
		next unless($found);
		my ($name, @stats) = split(/[:,] +/, $line);
		die "malformed $line" unless(@stats == 2);
		push(@data, $name, \@stats);
	}
	die "nothing for team $number" unless(@data);
	return(@data);
}
