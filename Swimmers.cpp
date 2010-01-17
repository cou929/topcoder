#include <string>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

class Swimmers {
public:
  vector <int> getSwimTimes(vector <int> distances, vector <int> speeds, int current) {
    vector <int> ret(distances.size());
    double time;
    int i;

    for(i=0; i<distances.size(); i++)
      {
	if(distances[i] == 0)
	  {
	    ret[i] = 0;
	    continue;
	  }

	if(current >= speeds[i])
	  {
	    ret[i] = -1;
	    continue;
	  }

	time = (double)distances[i] / ((double)speeds[i] + (double)current) + (double)distances[i] / ((double)speeds[i] - (double)current);
	ret[i] = (int)time;
      }

    return ret;
  }

};
