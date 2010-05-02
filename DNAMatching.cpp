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
class DNAMatching {
public:
  string rev(string s) {
    string ret = s;
    int i, n = ret.size();

    reverse(ret.begin(), ret.end());

    for (i=0; i<n; i++) {
      if (ret[i] == 'A')
        ret[i] = 'T';
      else if (ret[i] == 'T')
        ret[i] = 'A';
      else if (ret[i] == 'C')
        ret[i] = 'G';
      else if (ret[i] == 'G')
        ret[i] = 'C';
    }

    return ret;
  }

  int getMaxSize(vector <string> dna) {
    int i, j;

    for (i=0; i<dna.size(); i++) {
      string tmp = rev(dna[i]);
      for (j=0; j<dna.size(); j++)
        if (i != j)
          if (tmp == dna[j])
            dna.erase(dna.begin() + j);
    }

    return dna.size();
  }
   

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
