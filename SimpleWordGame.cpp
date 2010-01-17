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
class SimpleWordGame {
public:
  int points(vector <string> player, vector <string> dictionary)
  {
    set <string> s;
    int ret = 0;

    for (int i=0; i<player.size(); i++)
      s.insert(player[i]);

    for (set <string>::iterator i=s.begin(); i!=s.end(); i++)
      {
	if (find(dictionary.begin(), dictionary.end(), *i) != dictionary.end())
	  {
	    string t = *i;
	    ret += t.size() * t.size();
	  }
      }

    return ret;
  }
   

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
