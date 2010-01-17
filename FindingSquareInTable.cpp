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
class FindingSquareInTable {
public:
  string toStr(int n) {ostringstream ss; ss << n; return ss.str();}
  int toInt(string s) {int r = 0; istringstream ss(s); ss >> r; return r;}
  vector <string> table;

  bool inRange(int x, int y)
  {
    bool ret = false;
    if (0 <= x && x < table.size() && 0 <= y && y < table[0].size())
      ret = true;

    return ret;
  }

  int findMaximalSquare(vector <string> _table)
  {
    table = _table;
    int ret = -1;
    vector <int> squares;
    set <int> seqs;
    vector <int> rets;
    int sup = max(table.size(), table[0].size());

    squares.push_back(0);

    for (int i=1; i<31623; i++)
      {
	int n = i*i;;
	int c = 0;

	while (n > 0)
	  {
	    n /= 10;
	    c++;
	  }

	if (c > sup)
	  break;

	squares.push_back(i*i);
      }

    for (int i=0; i<table.size(); i++)
      for (int j=0; j<table[0].size(); j++)
	{
	  for (int difx=(table.size()-1)*(-1); difx<(int)table.size(); difx++)
	    for (int dify=(table[0].size()-1)*(-1); dify<(int)table[0].size(); dify++)
	      {
		string t = "";
		int curx = i;
		int cury = j;

		if (difx == 0 && dify == 0)
		  {
		    t = table[curx][cury];
		  }
		else
		  {
		    while (inRange(curx, cury))
		      {
			t += table[curx][cury];
			seqs.insert(toInt(t));
			curx += difx;
			cury += dify;
		      }
		  }
	      }
	}


    set <int>::reverse_iterator it;
    for (it=seqs.rbegin(); it!=seqs.rend(); it++)
      {

	if (find(squares.begin(), squares.end(), *it) != squares.end())
	  {
	    ret = *it;
	    break;
	  }
      }

    return ret;
  }
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { string Arr0[] = {"123",
					"456"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 64; verify_case(0, Arg1, findMaximalSquare(Arg0)); }
  void test_case_1() { string Arr0[] = {"00000",
					"00000",
					"00200",
					"00000",
					"00000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, findMaximalSquare(Arg0)); }
  void test_case_2() { string Arr0[] = {"3791178",
					"1283252",
					"4103617",
					"8233494",
					"8725572",
					"2937261"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 320356; verify_case(2, Arg1, findMaximalSquare(Arg0)); }
  void test_case_3() { string Arr0[] = {"135791357",
					"357913579",
					"579135791",
					"791357913",
					"913579135"}
    ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(3, Arg1, findMaximalSquare(Arg0)); }
  void test_case_4() { string Arr0[] = {"553333733",
					"775337775",
					"777537775",
					"777357333",
					"755553557",
					"355533335",
					"373773573",
					"337373777",
					"775557777"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(4, Arg1, findMaximalSquare(Arg0)); }
  void test_case_5() { string Arr0[] = {"257240281",
					"197510846",
					"014345401",
					"035562575",
					"974935632",
					"865865933",
					"684684987",
					"768934659",
					"287493867"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 95481; verify_case(5, Arg1, findMaximalSquare(Arg0)); }
  void test_case_6() { string Arr0[] = {"4000000009"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 900000000; verify_case(1, Arg1, findMaximalSquare(Arg0)); }

  // END CUT HERE

};
  // BEGIN CUT HERE
int main() {
  FindingSquareInTable ___test;
  ___test.run_test(-1);
}
  // END CUT HERE 

