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
#include <fstream>
#include <cstring>
#include <numeric>

#include "cout.hpp"

using namespace std;

int solve(int n, vector <int> B, vector <int> I, vector <int> R) {
  int ret = 0;
  int i;
  vector <vector <int> > upper;




  return ret;
}

int main(void) {
  int n, tmp;
  vector <int> B;
  vector <int> I;
  vector <int> R;
  int i;

  cin >> n;

  for (i=0; i<n; i++) {
    cin >> tmp;
    B.push_back(tmp);
  }

  for (i=0; i<n; i++) {
    cin >> tmp;
    I.push_back(tmp);
  }

  for (i=0; i<n; i++) {
    cin >> tmp;
    R.push_back(tmp);
  }

  cout << solve(n, B, I, R) << endl;

  return 0;
}
