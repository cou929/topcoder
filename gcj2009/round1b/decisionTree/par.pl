#!/usr/bin/perl

use strict;
use warnings;
use Data::Dumper;

open my $fh, '<', $ARGV[0];

my $T = readline $fh;

for (my $i=0; $i<$T; $i++) {
    print "Case #", $i, ":\n";
    my $dtree = "";
    my $animals = ();
    my $treeNum = readline $fh;
    for (my $j=0; $j<int($treeNum); $j++) {
	$dtree .= readline $fh;
    }
    my $root = parse_i($dtree);

    my $animalNum = scalar readline $fh;
    for (my $j=0; $j<int($animalNum); $j++) {
	my $an = split(/ /, scalar readline $fh);
	my $p = r($root, $an, 1);
	print $p, "\n";
    }
}

sub r {
    my $dtree = shift;
    my $animal = shift;
    my $p = shift;

    print Dumper $animal;

    if (ref @$dtree ne 'ARRAY') {
	return $p * @$dtree[0];
    }

    my $have = 0;

    for my $f ($animal) {
	if ($f eq @$dtree[0]->[1]) {
	    $have = 1;
	}
    }

    if ($have) {
	return r(@$dtree[0]->[2], $animal, $p * @$dtree[0]->[0]);
    } else {
	return r(@$dtree[0]->[3], $animal, $p * @$dtree[0]->[0]);
    }
}


sub parse_i {
    my $str = shift;
    my $tree = [];
    while (
        $str =~ s{\A             # start of the string
                    \s*          # spaces
                    (  [\(]      # open paren
                     | [^\s\(]+  # or atom
                    )
                   }{}x
      )
    {
        my $token;
        if ( $1 eq '(' ) {
            my $nest = 1;
            my $pos;
            for ( $pos = 0 ; $pos < length($str) ; $pos++ ) {
                my $c = substr( $str, $pos, 1 );
                $nest +=
                    $c eq '(' ? 1
                  : $c eq ')' ? -1
                  :             0;
                last unless $nest;
            }
            my $paren = substr( $str, 0, $pos + 1, '' );
            substr( $paren, -1, 1, '' );
            $token = parse_i($paren);

        }
        else {
            $token = $1;
        }
        push @$tree, $token;
    }
    return $tree;
}
