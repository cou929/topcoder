#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

class BestView {
   public:

   int numberOfBuildings(vector <int> heights)
  {
    int i, j ,k;
    int max = 0;

    for (i=0; i<heights.size(); i++)
      {
	int count = 0;

	for (j=0; j<heights.size(); j++)
	  if (i != j)
	    {
	      int l, r;
	      if (i < j)
		{
		  l = i; r = j;
		}
	      else
		{
		  l = j; r = i;
		}

	      if ((r - l) == 1)
		{
		  count++;
		  continue;
		}

	      int flg = 0;
	      for (k=l+1; k<r; k++)
		{
		  if (heights[k] >= ((double)heights[l] + (((double)heights[r] - (double)heights[l]) / (r-l)) * (k-l)) )
		    {
		      flg = 1;
		      break;
		    }
		}

	      if (flg == 0)
		{
		  count++;
		  break;
		}
	    }

	if (max < count)
	  max = count;
      }

    return max;
   }
   

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
