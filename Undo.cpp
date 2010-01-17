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

using namespace std;

class Undo {
public:
  string getText(vector <string> commands, vector <int> time)
  {
    int i;
    vector <string> V(100);
    string ret = "";

    for (i=0; i<commands.size(); i++)
      {
	if (commands[i][0] == 't')
	  {
	    V[i] = ret;
	    ret += commands[i][5];
	  }
	else
	  {
	    V[i] = ret;

	    int u;
	    sscanf(commands[i].c_str(), "undo %d", &u);

	    for (int j=i-1; j>=0; j--)
	      {
		if (time[i] - time[j] <= u)
		  {
		    ret = V[j];
		  }
		else
		  break;
	      }
	  }
      }

    return ret;
  }

   

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
