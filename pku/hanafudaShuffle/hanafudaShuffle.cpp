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

using namespace std;

int run(vector <vector <int> > shuffles, int n) {
  int i, j;
  int shuffles_length = shuffles.size();
  vector <int> deck(n, 0);

  for (i=0; i<n; i++)
    deck[i] = i+1;

  for (i=0; i<shuffles_length; i++) {
    int p = shuffles[i][0], c = shuffles[i][1];
    int top = n - p;
    int bottom = top - c + 1;
    vector <int> new_deck;

    for (j=0; j<n; j++)
      if (j < bottom || top < j)
        new_deck.push_back(deck[j]);
    
    for (j=bottom; j<=top; j++)
      new_deck.push_back(deck[j]);

    deck = new_deck;
  }

  return deck[n-1];
}

int main(int argc, char ** argv) {
  int i, n, r, p, c;

  while (1) {
    cin >> n >> r;
    cin.ignore();

    if (n == 0 && r == 0) break;

    vector <vector <int> > arg;

    for (i=0; i<r; i++) {
      cin >> p >> c;
      cin.ignore();
      vector <int> tmp;
      tmp.push_back(p);
      tmp.push_back(c);
      arg.push_back(tmp);
    }

    int result = run(arg, n);

    cout << result << endl;
  }

  return 0;
}
