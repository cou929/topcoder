#!/usr/bin/perl

use strict;
use warnings;

use LWP::UserAgent;
use utf8;

# ===============
# parse arguments
# ===============

my $matchNo = shift;
my $div = shift;
my $proxy = shift or die("Useage: blog.pl <match No> <div No (1 or 2)> <use proxy (1 or else)>\n");

# =======================
# fetch contents from web
# =======================

my $urlStat = "http://www.topcoder.com/tc?module=MatchList&sc=&sd=&nr=200&sr=";
my $topCoderHost = "http://www.topcoder.com";
my $overviewUrl;

for (my $i = 1; $i < 500; $i+=200) {
    my $url = $urlStat . $i;

    my $ua = LWP::UserAgent->new;
    $ua->proxy('http', 'http://proxy.cc.chuo-u.ac.jp:8080/') if ($proxy == 1);
    my $res = $ua->get($url);
    my $content = $res->content;

# <td nowrap="nowrap" class="value"><a href="/stat?c=round_overview&amp;er=5&amp;rd=13513">SRM 422</a></td>
    if ($content =~ m#<a href="(.*?)">SRM $matchNo</a></td>#) {
	$overviewUrl = $1;
	last;
    }
}

# ==============
# parse contents
# ==============

#<td valign="middle" nowrap="0" height="16" class="statText">&#160;Level One</td>
#<td valign="middle" nowrap="0" height="16" class="statText">&#160;&#160;<A HREF="/stat?c=problem_statement&pm=6677&rd=9998" class="statText">BiggestRectangleEasy</A></td>

my $url = $topCoderHost . $overviewUrl;
my $ua = LWP::UserAgent->new;
$ua->proxy('http', 'http://proxy.cc.chuo-u.ac.jp:8080/') if ($proxy == 1);
my $res = $ua->get($url);
my $content = $res->content;

my @results;

push(@results, $content =~ m#Level (?:One|Two|Three)</td>\n.*?<a href="(.*?)" class="statText">(.*?)</a></td>#gi);

# =============
# print results
# =============

my $code;
my $start = 0;
if ($div == 2) {
    $start = 6;
}

# entry title
print "*SRM", $matchNo, " div", $div, "\n";

print "[http://www.topcoder.com/tc?module=Static&d1=tutorials&d2=primeNumbers:title=Prime Numbers, Factorization and Euler Function]\n素数のチュートリアルからの練習問題。\n\n";

# easy
print "**Easy - [", $topCoderHost, $results[$start + 0], ":title=", $results[$start + 1], "]\n\n";
$code = getCode($results[$start + 1] . ".cpp");
print ">|cpp|\n";
print $code;
print "||<\n\n";

# medium
print "**Medium - [", $topCoderHost, $results[$start + 2], ":title=", $results[$start + 3], "]\n\n";
$code = getCode($results[$start + 3] . ".cpp");
print ">|cpp|\n";
print $code;
print "||<\n\n";

# hard
print "**Hard - [", $topCoderHost, $results[$start + 4], ":title=", $results[$start + 5], "]\n\n";
$code = getCode($results[$start + 5] . ".cpp");
print ">|cpp|\n";
print $code;
print "||<\n\n";


sub getCode {
# cut code region from cpp file if it exists
    my $filename = shift;
    my $fh;
    open($fh, $filename) or return "file not found\n";

    my $code;
    my $cut = 0;

    while (<$fh>) {
	my $line = $_;
	if ($line =~ m{// BEGIN CUT HERE}) {
	    $cut = 1;
	    next;
	}
	if ($line =~ m{// END CUT HERE}) {
	    $cut = 0;
	    next;
	}
	if ($cut == 1 || $line =~ m{(// Powered|#include|using namespace)}) {
	    next;
	}
	$code = $code . $line;
    }

    close($fh);
    return $code;
}
