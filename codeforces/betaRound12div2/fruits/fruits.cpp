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

int main(void) {
  int n, m;
  int tmp;
  vector <int> prices;
  map <string, int> list;
  vector <int> freq;
  int i;
  int mini = 0, maxi = 0;

  cin >> n >> m;
  
  for (i=0; i<n; i++) {
    cin >> tmp;
    prices.push_back(tmp);
  }

  for (i=0; i<m; i++) {
    string s;
    cin >> s;
    list[s]++;
  }

  for (map <string, int>::iterator i=list.begin(); i!=list.end(); i++)
    freq.push_back(i->second);

  sort(prices.begin(), prices.end());
  sort(freq.rbegin(), freq.rend());

  for (i=0; i<freq.size(); i++)
    mini += freq[i] * prices[i];

  reverse(prices.begin(), prices.end());

  for (i=0; i<freq.size(); i++)
    maxi += freq[i] * prices[i];

  cout << mini << " " << maxi << endl;

  return 0;
}
