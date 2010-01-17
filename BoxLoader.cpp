#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

class BoxLoader {
   public:
   int mostItems(int boxX, int boxY, int boxZ, int itemX, int itemY, int itemZ)
  {
    int i;
    int max;
    int ans[6];

    ans[0] = boxX/itemX * boxY/itemY * boxZ/itemZ;
    ans[1] = boxX/itemX * boxY/itemZ * boxZ/itemY;
    ans[2] = boxX/itemY * boxY/itemX * boxZ/itemZ;
    ans[3] = boxX/itemY * boxY/itemZ * boxZ/itemX;
    ans[4] = boxX/itemZ * boxY/itemX * boxZ/itemY;
    ans[5] = boxX/itemZ * boxY/itemY * boxZ/itemX;

    max = ans[0];
    for (i=1; i<6; i++)
      if (max < ans[i])
	max = ans[i];

    return max;
   }

   

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
