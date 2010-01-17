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
using namespace std;
class HillWalker {
public:
  vector <string> land;
  int th;
  typedef vector <int> node;
  map <char, int> alphabet;

  node make_node(int cost, int x, int y) {
    vector <int> tmp(3, 0);
    tmp[0] = cost, tmp[1] = x, tmp[2] = y;
    return tmp;
  }

  bool isInRange(int x, int y) {
    if (0 <= x && x < land.size() && 0 <= y && y < land[0].size())
      return true;
    return false;
  }

  long long calcTime(int startx, int starty, int goalx, int goaly) {
    if (isInRange(startx, starty) && isInRange(goalx, goaly) &&
        abs(startx - starty) + abs(goalx - goaly) == 1) {
      long long diff = alphabet[land[goalx][goaly]] - alphabet[land[startx][starty]];

      if (abs(diff) > th)
        return INT_MAX;
      if (diff < 1)
        return 1;
      else
        return diff*diff;
    }
    return INT_MAX;
  }

  int dijk(int startx, int starty, int goalx, int goaly) {
    bool visited[land.size()][land[0].size()];
    priority_queue <node> q;
    int dirx[4] = {1, 0, -1, 0};
    int diry[4] = {0, 1, 0, -1};
    long long paths[land.size()][land[0].size()];
    memset(visited, false, sizeof(visited));
    memset(paths, 1000000, sizeof(paths));

    q.push(make_node(0, startx, starty));

    while (!q.empty()) {
      int cur_cost = 0, cur_x = 0, cur_y = 0;
      node cur = q.top();
      q.pop();
      cur_cost = cur[0], cur_x = cur[1], cur_y = cur[2];
      visited[cur_x][cur_y] = true;

      if (cur_x == goalx && cur_y == goaly)
        break;

      for (int i=0; i<4; i++) {
        int next_x = cur_x + dirx[i];
        int next_y = cur_y + diry[i];
        if (isInRange(next_x, next_y) && !visited[next_x][next_y]) {
          int time = calcTime(cur_x, cur_y, next_x, next_y);
          if (time == INT_MAX) continue;
          //          cout << cur_x << ", " << cur_y << "   " << next_x << ", " << next_y << ": " << cur_cost << " " << time << " " << flg << endl;
          if (paths[next_x][next_y] > cur_cost + time) {
            paths[next_x][next_y] = cur_cost + time;
            q.push(make_node(cur_cost + time, next_x, next_y));
          }
        }
      }
    }

    return paths[goalx][goaly];
  }

  int highestPoint(vector <string> landscape, int threshold, int timeToDark) {
    int ret = 0;
    land = landscape;
    th = threshold;

    alphabet['A'] = 0, alphabet['B'] = 1, alphabet['C'] = 2, alphabet['D'] = 3, alphabet['E'] = 4, alphabet['F'] = 5, alphabet['G'] = 6, alphabet['H'] = 7, alphabet['I'] = 8, alphabet['J'] = 9, alphabet['K'] = 10, alphabet['L'] = 11, alphabet['M'] = 12, alphabet['N'] = 13, alphabet['O'] = 14, alphabet['P'] = 15, alphabet['Q'] = 16, alphabet['R'] = 17, alphabet['S'] = 18, alphabet['T'] = 19, alphabet['U'] = 20, alphabet['V'] = 21, alphabet['W'] = 22, alphabet['X'] = 23, alphabet['Y'] = 24, alphabet['Z'] = 25, alphabet['a'] = 26, alphabet['b'] = 27, alphabet['c'] = 28, alphabet['d'] = 29, alphabet['e'] = 30, alphabet['f'] = 31, alphabet['g'] = 32, alphabet['h'] = 33, alphabet['i'] = 34, alphabet['j'] = 35, alphabet['k'] = 36, alphabet['l'] = 37, alphabet['m'] = 38, alphabet['n'] = 39, alphabet['o'] = 40, alphabet['p'] = 41, alphabet['q'] = 42, alphabet['r'] = 43, alphabet['s'] = 44, alphabet['t'] = 45, alphabet['u'] = 46, alphabet['v'] = 47, alphabet['w'] = 48, alphabet['x'] = 49, alphabet['y'] = 50, alphabet['z'] = 51;

    //    dijk(0, 0, -1, -1, 0);

//     for (int i=0; i<land.size(); i++) {
//       for (int j=0; j<land[0].size(); j++)
//         cout << times[i][j][0] << " ";
//       cout << endl;
//     }

//     cout << endl;

    for (int i=0; i<land.size(); i++)
      for (int j=0; j<land[0].size(); j++) {
        int to = dijk(0, 0, i, j);
        int back = dijk(i, j, 0, 0);
        if (to + back < timeToDark)
          ret = max(ret, alphabet[land[i][j]]);
      }


//     for (int i=0; i<land.size(); i++) {
//       for (int j=0; j<land[0].size(); j++)
//         cout << times[i][j][1] << " ";
//       cout << endl;
//    }

    return ret;
  }
   
  // BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"AD"
                                        ,"JG"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 10000; int Arg3 = 9; verify_case(0, Arg3, highestPoint(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"AD"
                                        ,"JG"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 29; int Arg3 = 6; verify_case(1, Arg3, highestPoint(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"AABCDE"
                                        ,"GJIHGF"
                                        ,"MKLMNO"
                                        ,"STSRQP"
                                        ,"YUVWXY"
                                        ,"edcbaZ"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; int Arg2 = 36; int Arg3 = 30; verify_case(2, Arg3, highestPoint(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"BCDE"
                                        ,"AJKF"
                                        ,"AIHG"
                                        ,"AAAA"
                                        ,"AOMK"
                                        ,"AQSI"
                                        ,"ACEG"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 14; int Arg3 = 10; verify_case(3, Arg3, highestPoint(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"BCDE"
                                        ,"AJKF"
                                        ,"AIHG"
                                        ,"AAAA"
                                        ,"AOMK"
                                        ,"AQSI"
                                        ,"ACEG"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 57; int Arg3 = 18; verify_case(4, Arg3, highestPoint(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arr0[] = {"ABCDEFK"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 1000; int Arg3 = 5; verify_case(5, Arg3, highestPoint(Arg0, Arg1, Arg2)); }
	void test_case_6() { string Arr0[] = {"TRRVUXefk"
                                        ,"bSNMOWcff"
                                        ,"bRPNNQZip"
                                        ,"XSRUTVcfj"
                                        ,"WbZQPXZbV"
                                        ,"XdYSRWVOP"
                                        ,"feedVVcZR"
                                        ,"XhfdZZefg"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 50; int Arg3 = 28; verify_case(6, Arg3, highestPoint(Arg0, Arg1, Arg2)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
HillWalker ___test;
___test.run_test(-1);
}
// END CUT HERE 
