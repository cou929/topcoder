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
class ShufflingMachine {
public:
  double stackDeck(vector <int> shuffle, int maxShuffles, vector <int> cardsReceived, int K)
  {
    vector <vector <int> > v;
    vector <int> t;
    vector <pair <int, int> > freq;
    vector <int> initPos;

    for (int i=0; i<shuffle.size(); i++)
      {
	t.push_back(i);
	pair <int, int> t;
	t.first = 0;
	t.second = i;
	freq.push_back(t);
      }

    for (int i=0; i<maxShuffles; i++)
      {
	vector <int> tmp;
	for (int j=0; j<shuffle.size(); j++)
	  tmp.push_back(t[shuffle[j]]);

	v.push_back(tmp);
	t = tmp;
      }

    for (int i=0; i<cardsReceived.size(); i++)
      for (int j=0; j<v.size(); j++)
	freq[v[j][cardsReceived[i]]].first++;

    sort(freq.rbegin(), freq.rend());

    for (int i=0; i<K; i++)
      initPos.push_back(freq[i].second);

    int times = 0;

    for (int i=0; i<v.size(); i++)
      for (int j=0; j<cardsReceived.size(); j++)
	for (int k=0; k<initPos.size(); k++)
	  if (v[i][cardsReceived[j]] == initPos[k])
	    {
	      times++;
	      break;
	    }

    return (double)times / maxShuffles;
  }
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { int Arr0[] = {1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arr2[] = {0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; double Arg4 = 0.6666666666666666; verify_case(0, Arg4, stackDeck(Arg0, Arg1, Arg2, Arg3)); }
  void test_case_1() { int Arr0[] = {1,2,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arr2[] = {0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; double Arg4 = 0.8; verify_case(1, Arg4, stackDeck(Arg0, Arg1, Arg2, Arg3)); }
  void test_case_2() { int Arr0[] = {1,2,0,4,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; int Arr2[] = {0,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; double Arg4 = 1.0; verify_case(2, Arg4, stackDeck(Arg0, Arg1, Arg2, Arg3)); }
  void test_case_3() { int Arr0[] = {0,4,3,5,2,6,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 19; int Arr2[] = {1,3,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; double Arg4 = 1.0526315789473684; verify_case(3, Arg4, stackDeck(Arg0, Arg1, Arg2, Arg3)); }
  void test_case_4() { int Arr0[] = {3,4,7,2,8,5,6,1,0,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 47; int Arr2[] = {6,3,5,2,8,7,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 8; double Arg4 = 6.297872340425532; verify_case(4, Arg4, stackDeck(Arg0, Arg1, Arg2, Arg3)); }

  // END CUT HERE
};
// BEGIN CUT HERE
int main() {
ShufflingMachine ___test;
___test.run_test(-1);
}
// END CUT HERE 
