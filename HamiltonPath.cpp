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
class HamiltonPath {
public:
  vector <int> search(int x, vector <vector <int> >  & rootAndLeaf)
  {
    vector <int> ret(2, -1);

    for (int i=0; i<rootAndLeaf.size(); i++)
      for (int j=0; j<rootAndLeaf[i].size(); j++)
	if (rootAndLeaf[i][j] == x)
	  {
	    vector <int> tmp;
	    ret[0] = i;
	    ret[1] = j;
	  }

    return ret;
  }


  int countPaths(vector <string> roads)
  {
    int ret = 1;
    vector <int> intermediates;
    vector <vector <int> > rootAndLeaf;

    for (int i=0; i<roads.size(); i++)
      for (int j=i; j<roads[i].size(); j++)
	if (roads[i][j] == 'Y')
	  {
	    if (find(intermediates.begin(), intermediates.end(), i) == intermediates.end() && find(intermediates.begin(), intermediates.end(), j) == intermediates.end())
	      {
		vector <int> resi = search(i, rootAndLeaf);
		vector <int> resj = search(j, rootAndLeaf);

		if (resi[0] == -1 && resj[0] == -1)
		  {
		    vector <int> tmp;
		    tmp.push_back(i);
		    tmp.push_back(j);
		    rootAndLeaf.push_back(tmp);
		  }
		else if (resi[0] != -1 && resj[0] != -1)
		  {
		    if (resi[0] == resj[0])
		      return 0;

		    intermediates.push_back(i);
		    intermediates.push_back(j);
		    rootAndLeaf[resi[0]][resi[1]] = rootAndLeaf[resj[0]][(resj[1]+1)%2];
		    rootAndLeaf.erase(rootAndLeaf.begin() + resj[0]);
		  }
		else
		  {
		    int inter = 0;
		    int leaf = 0;
		    vector <int> pos;
		    if (resi[0] != -1)
		      {
			inter = i;
			leaf = j;
			pos = resi;
		      }
		    else
		      {
			inter = j;
			leaf = i;
			pos = resj;
		      }

		    intermediates.push_back(inter);
		    rootAndLeaf[pos[0]][pos[1]] = leaf;
		  }
	      }
	    else
	      {
		return 0;
	      }
	  }

    int notRoadNum = roads.size() - (rootAndLeaf.size() * 2 + intermediates.size());
    int noads = notRoadNum + rootAndLeaf.size();
    long long tmpret = 1;

    for (int i=noads; i>0; i--)
      tmpret = tmpret * i % 1000000007;

    for (int i=0; i<rootAndLeaf.size(); i++)
      tmpret = tmpret * 2 % 1000000007;

    ret = tmpret;

    return ret;
  }
   

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
