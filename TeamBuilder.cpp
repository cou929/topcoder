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
class TeamBuilder {
public:
  vector <int> specialLocations(vector <string> paths)
  {
    vector <int> ret(2, 0);

    for (int i=0; i<paths.size(); i++)
      paths[i][i] = '1';

    for (int k=0; k<paths.size(); k++)
      for (int i=0; i<paths.size(); i++)
	for (int j=0; j<paths.size(); j++)
	  if (paths[i][k] == '1' && paths[k][j] == '1')
	    paths[i][j] = '1';

    for (int i=0; i<paths.size(); i++)
      {
	int row = 0, col = 0;
	for (int j=0; j<paths.size(); j++)
	  {
	    if (paths[i][j] == '1')
	      row++;
	    if (paths[j][i] == '1')
	      col++;
	  }
 
	if (row == paths.size())
	  ret[0]++;
	if (col == paths.size())
	  ret[1]++;
      }

    return ret;
  }
   

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
