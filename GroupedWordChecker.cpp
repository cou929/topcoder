#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

class GroupedWordChecker {
public:
  int howMany(vector <string> words)
  {
    int i, j, k;
    int count = 0;
    int flg = 0;

    for (i=0; i<words.size(); i++)
      {
	flg = 0;
	for (j=0; j<words[i].size()-1; j++)
	  {
	    if (words[i][j] == words[i][j+1])
	      continue;

	    for (k=j+2; k<words[i].size(); k++)
	      if (words[i][j] == words[i][k])
		{
		  flg = 1;
		  count++;
		  break;
		}
	    if (flg == 1)
	      break;
	  }
      }


    return (words.size() - count);
  }



   

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
