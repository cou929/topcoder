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
class SortingWithPermutation {
public:
  vector <int> getPermutation(vector <int> a) {
    vector <int> ret;
    vector <int> sorted = a;
    int n = a.size();
    vector <bool> used(n, false);
    int i, j;

    sort(sorted.begin(), sorted.end());

    for (i=0; i<n; i++)
      for (j=0; j<n; j++)
        if (a[i] == sorted[j] && !used[j]) {
          ret.push_back(j);
          used[j] = true;
          break;
        }      

    return ret;
  }
   

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
