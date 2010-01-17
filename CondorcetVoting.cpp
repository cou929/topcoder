#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

class CondorcetVoting {
   public:
   int winner(vector <string> votes)
  {
    int i, j;
    int ret = -1;
    int mini = 10000000;
    vector <int> v;

    for (i=0; i<votes[0].size(); i++)
      v.push_back(0);

    for (i=0; i<votes.size(); i++)
      {
	for (j=0; j<votes[i].size(); j++)
	  {
	    v[j] += votes[i][j] - 'a';
	  }
      }

    for (i=0; i<v.size(); i++)
      {
	if (mini > v[i])
	  {
	    mini = v[i];
	    ret = i;
	  }
      }
      
      cout << ret << endl;

    sort(v.begin(), v.end());
    if (v[0] == v[1])
      return -1;

    return ret;
   }

   

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
