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
#include <numeric>
// BEGIN CUT HERE
#include "cout.hpp"
// END CUT HERE
using namespace std;
class LandAndSea {
  public:
  vector <vector <int> > label_map;
  vector <int> label_size;
  vector <string> large_map;
  vector <char> label_land_or_sea;
  vector <int> sea_label;
  map <char, vector <int> > dr;
  map <char, vector <int> > dc;

  void dfs(int row, int col) {
    stack <pair <int, int> > s;
    char land_or_sea = large_map[row][col];
    int color = label_size.size();
    int n = dr[land_or_sea].size();
    label_size.push_back(0);
    int i, j;
    label_land_or_sea.push_back(land_or_sea);

    s.push(make_pair(row, col));

    while (!s.empty()) {
      pair <int, int> cur = s.top();
      s.pop();

      label_map[cur.first][cur.second] = color;

      for (i=0; i<n; i++) {
        int nextr = cur.first + dr[land_or_sea][i];
        int nextc = cur.second + dc[land_or_sea][i];
        if (0 <= nextr && nextr < large_map.size() && 0 <= nextc && nextc < large_map[0].size() &&
            land_or_sea == large_map[nextr][nextc] &&
            label_map[nextr][nextc] == -1)
          s.push(make_pair(nextr, nextc));
      }
    }
  }

  void label() {
    int i, j, r, c;

    for (r=0; r<label_map.size(); r++)
      for (c=0; c<label_map[0].size(); c++)
        if (label_map[r][c] == -1)
          dfs(r, c);

    for (i=1; i<label_map.size()-1; i++)
      for (j=1; j<label_map[0].size()-1; j++)
        label_size[label_map[i][j]]++;
  }

  bool exists(vector <int> v, int n) {
    int i;
    for (i=0; i<v.size(); i++)
      if (v[i] == n)
        return true;
    return false;
  }

  bool is_outer_land(int row, int col) {
    stack <pair <int, int> > s;
    int visited[large_map.size()][large_map[0].size()];
    int i, j;
    memset(visited, 0, sizeof(visited));

    s.push(make_pair(row, col));

    while (!s.empty()) {
      pair <int, int> cur = s.top();
      s.pop();

      visited[cur.first][cur.second] = 1;
      if (exists(sea_label, label_map[cur.first][cur.second]))
        return true;

      for (i=0; i<dr['x'].size(); i++) {
        int nextr = cur.first + dr['x'][i];
        int nextc = cur.second + dc['x'][i];
        if (0 <= nextr && nextr < large_map.size() && 0 <= nextc && nextc < large_map[0].size() &&
            visited[nextr][nextc] == 0)
          s.push(make_pair(nextr, nextc));
      }
    }

    return false;
  }

  vector <int> howManyIslands(vector <string> seaMap) {
    vector <int> ret;
    int i, j, r, c;
    large_map = vector <string> (seaMap.size()+2, string (seaMap[0].size()+2, '.'));
    label_map = vector <vector <int> > (seaMap.size()+2, vector <int> (seaMap[0].size()+2, -1));
    label_size.clear();
    sea_label.clear();

    dr['.'].push_back(0); dr['.'].push_back(1); dr['.'].push_back(0); dr['.'].push_back(-1);
    dc['.'].push_back(-1); dc['.'].push_back(0); dc['.'].push_back(1); dc['.'].push_back(0);

    dr['x'].push_back(-1); dr['x'].push_back(-1); dr['x'].push_back(-1); dr['x'].push_back(0);
    dr['x'].push_back(0); dr['x'].push_back(1); dr['x'].push_back(1); dr['x'].push_back(1);
    dc['x'].push_back(-1); dc['x'].push_back(0); dc['x'].push_back(1); dc['x'].push_back(-1);
    dc['x'].push_back(1); dc['x'].push_back(-1); dc['x'].push_back(0); dc['x'].push_back(1);

    for (i=0; i<seaMap.size(); i++)
      for (j=0; j<seaMap[0].size(); j++)
        large_map[i+1][j+1] = seaMap[i][j];

    label();

    int maxi = 0;
    int max_index = 0;
    for (i=0; i<label_size.size(); i++)
      if (label_land_or_sea[i] == '.')
        if (maxi < label_size[i]) {
          maxi = label_size[i];
          max_index = i;
        }
    sea_label.push_back(max_index);

    int hidden_label = 0;
    for (i=0; i<label_size.size(); i++)
      if (label_size[i] == 0)
        hidden_label++;

    while ((sea_label.size() + hidden_label)!= label_size.size()) {
      vector <int> candidate;
      vector <int> searched;
      for (r=1; r<label_map.size()-1; r++)
        for (c=1; c<label_map[0].size()-1; c++)
          if (label_land_or_sea[label_map[r][c]] == 'x' && 
              !exists(searched, label_map[r][c])) {
            if (is_outer_land(r, c))
              candidate.push_back(label_map[r][c]);
            searched.push_back(label_map[r][c]);
          }
      sea_label.insert(sea_label.end(), candidate.begin(), candidate.end());
      ret.push_back(candidate.size());
      // cout << sea_label << endl;
      // cout << searched << endl;
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
}
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { 
	string Arr0[] = {"x"}; 
	vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	int Arr1[] = {1 }; 
	vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
	verify_case(0, Arg1, howManyIslands(Arg0)); }
	void test_case_1() { 
	string Arr0[] = {
"xxxxx",
"x...x",
"x.x.x",
"x...x",
"xxxxx"
}; 
	vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	int Arr1[] = {1, 1 }; 
	vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
	verify_case(1, Arg1, howManyIslands(Arg0)); }
	void test_case_2() { 
	string Arr0[] = {
"xxxxx",
"x...x",
"x.x.x",
"x...x",
"xxxxx",
"xxxxx",
"x...x",
"x.x.x",
"x...x",
"xxxxx"
}; 
	vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	int Arr1[] = {2, 1 }; 
	vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
	verify_case(2, Arg1, howManyIslands(Arg0)); }
	void test_case_3() { 
	string Arr0[] = {
"..",
".."
}; 
	vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	int Arr1[] = { }; 
	vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
	verify_case(3, Arg1, howManyIslands(Arg0)); }
	void test_case_4() { 
	string Arr0[] = {
"............",
".......xxxx.",
"..xxx.x...x.",
"..x..x..x.x.",
"..x.x.x...x.",
"..xx...xxx.."
}; 
	vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	int Arr1[] = {1, 1 }; 
	vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
	verify_case(4, Arg1, howManyIslands(Arg0)); }
	void test_case_5() { 
	string Arr0[] = {"x"}; 
	vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	int Arr1[] = {1 }; 
	vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
	verify_case(5, Arg1, howManyIslands(Arg0)); }
	void test_case_6() { 
	string Arr0[] = {"x"}; 
	vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	int Arr1[] = {1 }; 
	vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
	verify_case(6, Arg1, howManyIslands(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
LandAndSea ___test;
___test.run_test(-1);
}
// END CUT HERE 
