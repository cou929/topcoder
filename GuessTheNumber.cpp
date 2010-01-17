#include <string>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

class GuessTheNumber {
	public:
	int noGuesses(int upper, int answer) {
		int count = 1;
        int left = 1;
        int right = upper;
        int guess = 0;

        while(1)
            {
                guess = (right + left)/2;
                if(guess < answer)
                    left = guess + 1;
                else if(guess > answer)
                    right = guess - 1;
                else
                    break;
                count++;
            }

        return count;
	}
};
