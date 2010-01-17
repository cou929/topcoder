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
class IsomorphicWords {
public:
  int countPairs(vector <string> words)
  {
    int ret = 0;
    vector <vector <int> > labeled;

    for (int i=0; i<words.size(); i++)
      {
	vector <int> v(words[i].size(), -1);
	int counter = 0;
	for (int j=0; j<words[i].size(); j++)
	  {
	    if (v[j] == -1)
	      {
		v[j] = counter;
		for (int k=j+1; k<words[i].size(); k++)
		  if (v[k] == -1 && words[i][k] == words[i][j])
		    v[k] = counter;
		counter++;
	      }
	  }
	labeled.push_back(v);
      }

    int flg[words.size()];
    vector <int> sames;
    memset(flg, 0, sizeof(flg));

    for (int i=0; i<labeled.size(); i++)
      {
	if (flg[i] == 0)
	  {
	    int counter = 0;
	    flg[i] = 1;
	    for (int j=i+1; j<labeled.size(); j++)
	      if (flg[j] == 0 && labeled[i] == labeled[j])
		{
		  flg[j] = 1;
		  counter++;
		}
	    if (counter > 0)
	      sames.push_back(++counter);
	  }
      }

    for (int i=0; i<sames.size(); i++)
      ret += (sames[i] * (sames[i] - 1)) / 2;

    return ret;
  }
   

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
