#include <string>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

class CardCount {
	public:
	vector <string> dealHands(int numPlayers, string deck) {
        int i, j;
        vector<string> ret(numPlayers);

        for(i=0; i<deck.size()/numPlayers; i++)
            {
                for(j=0; j<numPlayers; j++)
                    {
                        ret[j] += deck[j + numPlayers * i];
                    }
            }
        return ret;
    }
};
