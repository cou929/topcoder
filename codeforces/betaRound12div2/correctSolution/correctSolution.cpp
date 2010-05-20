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

using namespace std;

string solve(string a, string b) {
  int i, j;
  string c;
  sort(a.begin(), a.end());

  for (i=0; i<a.size(); i++)
    if (a[i] != '0') {
      c = a[i];
      break;
    }

  for (j=0; j<i; j++)
    c += '0';

  for (j=i+1; j<a.size(); j++)
    c += a[j];

  if (c != b)
    return "WRONG_ANSWER";

  return "OK";
}

int main(void) {
  string a, b;

  getline(cin, a);
  getline(cin, b);

  cout << solve(a, b) << endl;

  return 0;
}
