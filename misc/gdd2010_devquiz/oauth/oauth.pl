#!/usr/bin/perl 

use 5.0.8;
use strict;
use warnings;

use Data::Dumper;
use OAuth::Lite;
use OAuth::Lite::Consumer;

my $consumer = OAuth::Lite::Consumer->new(
  consumer_key		=> 'f769083a642cab4135939e68',
  consumer_secret	=> 'd61c900a32fc9dbc283aead5',
  realm			=> 'devquiz',
);

my $response = $consumer->request(
    method  => 'POST',
    url     => 'http://gdd-2010-quiz-japan.appspot.com/oauth/f769083a642cab4135939e68',
    params  => {
        hello => 'world'
    });

if ($response->is_success) {
    print Dumper($response->decoded_content);
} else {
    warn $response->status_line;
}
