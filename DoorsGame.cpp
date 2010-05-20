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
#include <numeric>
using namespace std;
class DoorsGame {
public:
  char searchColor(set <char> a, set <char> b) {
    char ret = *(a.begin());

    for (set <char>::iterator i=a.begin(); i!=a.end(); i++)
      if (find(b.begin(), b.end(), *i) == b.end()) {
        ret = *i;
        break;
      }

    return ret;
  }

  void eraseColor(set <char> &a, char color) {
    set <char>::iterator i = find(a.begin(), a.end(), color);
    if (i != a.end())
      a.erase(i);
    return;
  }

  int determineOutcome(string doors, int trophy) {
    int ret = 0;
    int n = doors.size();
    set <char> john;
    set <char> gogo;
    string path = doors;
    int i;
   
    for (i=0; i<n; i++)
      if (i < trophy)
        john.insert(doors[i]);
      else
        gogo.insert(doors[i]);

    for (i=0;; i++) {
      ret++;
      if (i%2 == 0) {
        char color = searchColor(john, gogo);
        eraseColor(john, color);
        eraseColor(gogo, color);
      } else {
        char color = searchColor(gogo, john);
        eraseColor(john, color);
        eraseColor(gogo, color);
      }

      bool j = false, g = false;
      if (john.empty())
        j = true;
      if (gogo.empty())
        g = true;

      if (j && g) {
        ret = 0;
        break;
      }
      if (j && !g)
        break;
      if (!j && g) {
        ret *= -1;
        break;
      }
    }

    return ret;
  }
   

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
