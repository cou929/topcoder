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
class TheCitiesAndRoadsDivTwo {
public:
  // graphをmap にしてもできるか
  // ワーしゃるフロイドの順番
  // ケーリーの計算
  // brute-froce
  vector <int> subgraph;
  int visited[10];

//   bool visitedAllCity() {
//     for (int i=0; i<subgraph.size(); i++)
//       if (visited[i] == 0)
//         return false;
//     return true;
//   }

  int dfs(int cur) {
    int ret = 0;
    visited[cur] = 1;
    
    for (int i=0; i<subgraph.size(); i++) if (visited[i] == 0) {
        int tmp = 0;
        for (int j=i; j<subgraph.size(); j++)
          for (int k=0; k<i-j; k++)
            if (visited[k] == 0)
              visited[k] = 1, 
            //          ret += subgraph[cur] * dfs(i);
    }
    
    visited[cur] = 0;

    if (ret == 0) ret = subgraph[cur];

    return ret;
  }

  int find(vector <string> map) {
    int ret = 0;
    subgraph.clear();
    stack <pair <int, int> > s;
    vector <int> visited(map.size(), 0);
    int label = 1;

    for (int start=0; start<map.size(); start ++) if (visited[start] == 0) {
        s.push(make_pair(start, -1));
        while (!s.empty()) {
          int cur = s.top().first;
          int pre = s.top().second;
          s.pop();

          visited[cur] = label;

          for (int i=0; i<map.size(); i++)
            if (i != cur && i != pre && map[cur][i] == 'Y')
              if (visited[i] == 0)
                s.push(make_pair(i, cur));
              else if (visited[i] == label) // if there is already a loop
                return 0;
        }
        label++;
      }
    for (int i=1; i<label; i++)
      subgraph.push_back(count(visited.begin(), visited.end(), i));

    if (subgraph.size() == 1) 
      return 1;

    cout << subgraph << endl;

    for (int i=0; i<subgraph.size(); i++) {
      int tmp = dfs(i);
      cout << tmp <<endl;
      ret += tmp;
    }

    ret /= subgraph.size() - 1;

    return ret;
  }


//   int find(vector <string> map) {
//     int ret = 0;
//     int n = map.size();
//     int i, j, k;
//     vector <bool> used(n, false);
//     vector <vector <int> > graph(map.size(), vector <int> (map.size(), 0));
//     vector <int> subgraphs;

//     for (i=0; i<n; i++)
//       for (j=0; j<n; j++)
//         if (map[i][j] == 'Y')
//           graph[i][j] = 1;

//     for (i=0; i<n; i++)
//       graph[i][i] = 1;

//     for (k=0; k<n; k++)
//       for (i=0; i<n; i++)
//         for (j=0; j<n; j++)
//           if (graph[i][k]  && graph[k][j])
//             graph[i][j] = 1;

//     for (i=0; i<n; i++) 
//       if (!used[i]) {
//         int counter = 0;
//         for (j=0; j<n; j++)
//           if (graph[i][j])
//             counter++, used[j] = true;
//         subgraphs.push_back(counter);
//       }

//     cout << subgraphs << endl;

//     ret = 1;
//     if (subgraphs.size() >= 2) {
//       ret *= pow((double)n, subgraphs.size()-2.0); // Cayley's formula
//       for (i=0; i<subgraphs.size(); i++)
//         ret *= subgraphs[i];
//     }

//     return ret;
//   }
   
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
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { 
    string Arr0[] = {"NN",
                     "NN"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 1; 
    verify_case(0, Arg1, find(Arg0)); }
	void test_case_1() { 
    string Arr0[] = {"NY",
                     "YN"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 1; 
    verify_case(1, Arg1, find(Arg0)); }
	void test_case_2() { 
    string Arr0[] = {"NNY",
                     "NNN",
                     "YNN"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 2; 
    verify_case(2, Arg1, find(Arg0)); }
	void test_case_3() { 
    string Arr0[] = {"NYNN",
                     "YNNN",
                     "NNNY",
                     "NNYN"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 4; 
    verify_case(3, Arg1, find(Arg0)); }
	void test_case_4() { 
    string Arr0[] = {"NNNN",
                     "NNNN",
                     "NNNN",
                     "NNNN"
    }; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 16; 
    verify_case(4, Arg1, find(Arg0)); }
	void test_case_5() { 
    string Arr0[] = {
      "NNYNNNYN", 
      "NNNNNYNN", 
      "YNNNNNNN", 
      "NNNNNNNN",  // 1
      "NNNNNNNN",  // 1
      "NYNNNNYN", 
      "YNNNNYNN", 
      "NNNNNNNN"   // 1
    }; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 320; 
    verify_case(5, Arg1, find(Arg0)); }
	void test_case_6() { 
    string Arr0[] = {"NNNNN",
                     "NNNNN",
                     "NNNNN",
                     "NNNNN",
                     "NNNNN"
    }; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 125; 
    verify_case(5, Arg1, find(Arg0)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
TheCitiesAndRoadsDivTwo ___test;
 ___test.run_test(4);
}
// END CUT HERE 
