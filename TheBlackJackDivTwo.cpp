#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <utility>
#include <set>
#include <cctype>
#include <queue>
#include <stack>
using namespace std;
class TheBlackJackDivTwo {
   public:
   int score(vector <string> cards)
  {
    int ret = 0;

    for (int i=0; i<cards.size(); i++)
      {
	if (cards[i][0] == 'T' || cards[i][0] == 'J' || cards[i][0] == 'Q' || cards[i][0] == 'K')
	  ret += 10;
	else if (cards[i][0] == 'A')
	  ret += 11;
	else
	  ret += cards[i][0] - '0';
      }

    return ret;
  }
   

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
