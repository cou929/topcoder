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
class WordPattern {
   public:
   long long countWords(string word)
  {
    if (word.size() == 1)
      return 1;
    else if (word.size() == 2)
      return 4;

    long long ret[word.size()+1];

    ret[1] = 1;
    ret[2] = 4;

    for (int i=3; i<=word.size(); i++)
      ret[i] = 4*3 + (ret[i-1] - 4)*2;

    return ret[word.size()];
  }
   

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
