// BEGIN CUT HERE
// END CUT HERE
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
// BEGIN CUT HERE
#include "cout.hpp"
// END CUT HERE 
using namespace std;
class Gifts {
public:
  vector <pair <int, int> > setPositions(vector <string> &city) {
    vector <pair<int, int> > positions(2);
    int i, j;
    int n = city.size(), m = city[0].size();

    for (i=0; i<n; i++)
      for (j=0; j<m; j++)
        if (city[i][j] == 'K')
          positions[0] = make_pair(i, j);
        else if (city[i][j] == 'Q')
          positions[1] = make_pair(i, j);
        else if (city[i][j] == 'G')
          positions.push_back(make_pair(i, j));
    
    return positions;
  }

  vector <vector <int> > constructGraph(vector <string> &city, vector <pair <int, int> > &positions) {
    int i, j;
    int n = city.size(), m = city[0].size();
    int dists[n][m];
    vector <vector <int> > graph(positions.size(), vector <int> (positions.size(), 0));
    queue <int> q;
    int dirx[4] = {0, 1, 0, -1};
    int diry[4] = {1, 0, -1, 0};

    for (i=0; i<positions.size(); i++) {
      memset(dists, -1, sizeof(dists));
      q.push(positions[i].first);
      q.push(positions[i].second);
      q.push(0);

      while (!q.empty()) {
        int curx = q.front(); q.pop();
        int cury = q.front(); q.pop();
        int curdist = q.front(); q.pop();

        dists[curx][cury] = curdist;

        for (j=0; j<4; j++)
          if (0 <= curx + dirx[j] && curx + dirx[j] < n && 0 <= cury + diry[j] && cury + diry[j] < m)
            if (city[curx + dirx[j]][cury + diry[j]] != '#' && dists[curx + dirx[j]][cury + diry[j]] == -1)
              q.push(curx + dirx[j]), q.push(cury + diry[j]), q.push(curdist + 1);
      }

      for (j=0; j<positions.size(); j++)
        graph[i][j] = dists[positions[j].first][positions[j].second];
    }

    return graph;
  }

  int maxGifts(vector <string> city, int T) {
    int ret = 0;
    int i, j, k;;

    vector <pair <int, int> > positions = setPositions(city);
    vector <vector <int> > graph = constructGraph(city, positions);

    int gifts = graph.size() - 2;
    int dp[1 << gifts][gifts];
    memset(dp, INT_MAX, sizeof(dp));

    for (i=0; i<gifts; i++)
      dp[1 << i][i] = graph[0][i+2];

    for (i=0; i<1 << gifts; i++) {
      int g = __builtin_popcount(i);
      if (dp[i][j] < INT_MAX)
        for (j=0; j<gifts; j++)
          if (dp[j][k] < INT_MAX)
            if (!(i & (1 << j)))
              for (k=0; k<gifts; k++)
                dp[i][j] = min(dp[i][j], dp[i][j] + graph[j+2][k+2] * (g + 1));
    }

    for (i=0; i<1 << gifts; i++) {
      int g = __builtin_popcount(i);
      for (j=0; j<gifts; j++)
        if (dp[i][j] < INT_MAX && graph[1][j+2] < INT_MAX && dp[i][j] + graph[1][j+2] * (g + 1) <= T) {
          ret = max(ret, g);
        }
    }

    return ret;
  }
   
  // BEGIN CUT HERE
public:
	void run_test(int Case) { 
    if ((Case == -1) || (Case == 0)) test_case_0();
    if ((Case == -1) || (Case == 1)) test_case_1();
    if ((Case == -1) || (Case == 2)) test_case_2();
    if ((Case == -1) || (Case == 3)) test_case_3();
    if ((Case == -1) || (Case == 4)) test_case_4();
    if ((Case == -1) || (Case == 5)) test_case_5();
    if ((Case == -1) || (Case == 6)) test_case_6();
    if ((Case == -1) || (Case == 7)) test_case_7();
  }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { 
    string Arr0[] = {"#######",
                     "#K.G.Q#",
                     "#######"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 6; 
    int Arg2 = 1; 
    verify_case(0, Arg2, maxGifts(Arg0, Arg1)); }
	void test_case_1() { 
    string Arr0[] = {"#######",
                     "#K.G.Q#",
                     "#######"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 4; 
    int Arg2 = 0; 
    verify_case(1, Arg2, maxGifts(Arg0, Arg1)); }
	void test_case_2() { 
    string Arr0[] = {"#######",
                     "#K.Q.G#",
                     "#######"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 6; 
    int Arg2 = 0; 
    verify_case(2, Arg2, maxGifts(Arg0, Arg1)); }
	void test_case_3() { 
    string Arr0[] = {"#######",
                     "#K.Q.G#",
                     "#######"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 8; 
    int Arg2 = 1; 
    verify_case(3, Arg2, maxGifts(Arg0, Arg1)); }
	void test_case_4() { 
    string Arr0[] = {"#######",
                     "#K.QGG#",
                     "#######"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 9; 
    int Arg2 = 2; 
    verify_case(4, Arg2, maxGifts(Arg0, Arg1)); }
	void test_case_5() { 
    string Arr0[] = {"#....G#", 
                     "###G###", 
                     "#K...Q#", 
                     "###.###", 
                     "#G..GG#"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 50; 
    int Arg2 = 4; 
    verify_case(5, Arg2, maxGifts(Arg0, Arg1)); }
	void test_case_6() { 
    string Arr0[] = {"#######",
                     "#K.G.Q#",
                     "#######"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 6; 
    int Arg2 = 1; 
    verify_case(6, Arg2, maxGifts(Arg0, Arg1)); }
	void test_case_7() { 
    string Arr0[] = {"#######",
                     "#K.G.Q#",
                     "#######"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 6; 
    int Arg2 = 1; 
    verify_case(7, Arg2, maxGifts(Arg0, Arg1)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
  Gifts ___test;
  ___test.run_test(-1);
}
// END CUT HERE 
