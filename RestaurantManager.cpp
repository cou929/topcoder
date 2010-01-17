#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <map>

#define FREE -1

using namespace std;

class RestaurantManager {
public:
  int allocateTables(vector <int> tables, vector <int> groupSizes, vector <int> arrivals, vector <int> departures)
  {
    int i, j;
    vector <int> alloc;
    int counter = 0;

    for (i=0; i<tables.size(); i++)
      alloc.push_back(FREE);

    sort(tables.begin(), tables.end());

    for (i=0; i<groupSizes.size(); i++)
      {
	for (j=0; j<alloc.size(); j++)
	  if (alloc[j] != FREE && departures[alloc[j]] <= arrivals[i])
	    alloc[j] = FREE;

	int flg = 0;
	for (j=0; j<tables.size(); j++)
	  if (tables[j] >= groupSizes[i] && alloc[j] == FREE)
	    {
	      alloc[j] = i;
	      flg = 1;
	      break;
	    }

	if (flg == 0)
	  counter += groupSizes[i];
      }

    return counter;
  }

   

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
