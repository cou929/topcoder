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
class ErdosNumber {
public:
  vector <string> split(const string _s, const string del) {
    vector <string> ret;
    string s = _s;

    while (!s.empty())
      {
        size_t pos = s.find(del);
        string sub = "";
        sub = s.substr(0, pos);
        ret.push_back(sub);
        if (pos != string::npos)
          pos += del.size();
        s.erase(0, pos);
      }

    return ret;
  }

  string toStr(int n) {ostringstream ss; ss << n; return ss.str();}

  vector <string> calculateNumbers(vector <string> publications) {
    vector <string> ret;
    map <string, int> numbers;
    map <string, int> index;
    typedef map <string, int>::iterator it;
    queue <pair <int, int> > q;

    for (int i=0; i<publications.size(); i++) {
      vector <string> tmp = split(publications[i], " ");
      for (int j=0; j<tmp.size(); j++) numbers[tmp[j]] = (tmp[j] == "ERDOS") ? 0 : INT_MAX;
    }

    int ind=0;
    for (it i=numbers.begin(); i!=numbers.end(); i++, ind++)
      index[i->first] = ind, ret.push_back(i->first);

    int graph[numbers.size()][numbers.size()];
    memset(graph, 0, sizeof(graph));

    for (int i=0; i<publications.size(); i++) {
      vector <string> tmp = split(publications[i], " ");
      for (int j=0; j<tmp.size(); j++)
        for (int k=0; k<tmp.size(); k++)
          if (j != k)
            graph[index[tmp[j]]][index[tmp[k]]] = 1;
    }

    q.push(make_pair(index["ERDOS"], 0));
    while (!q.empty()) {
      pair <int, int> cur = q.front();
      q.pop();
      int cur_pos = cur.first, cur_num = cur.second;

      for (int i=0; i<numbers.size(); i++) {
        if (graph[cur_pos][i] == 1 && numbers[ret[i]] == INT_MAX) {
          numbers[ret[i]] = cur_num + 1;
          q.push(make_pair(i, cur_num + 1));
        }
      }
    }

    ret.clear();
    for (it i=numbers.begin(); i!=numbers.end(); i++, ind++) {
      string tmp = i->first;
      if (i->second != INT_MAX) tmp += " " + toStr(i->second);
      ret.push_back(tmp);
    }

    return ret;
  }
   
  // BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 4)) test_case_5(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"ERDOS"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"ERDOS 0" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, calculateNumbers(Arg0)); }
	void test_case_1() { string Arr0[] = {"KLEITMAN LANDER", 
                                        "ERDOS KLEITMAN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"ERDOS 0", "KLEITMAN 1", "LANDER 2" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, calculateNumbers(Arg0)); }
	void test_case_2() { string Arr0[] = {"ERDOS A", "A B", "B AA C"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"A 1", "AA 3", "B 2", "C 3", "ERDOS 0" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, calculateNumbers(Arg0)); }
	void test_case_3() { string Arr0[] = {"ERDOS B", "A B C", "B A E", "D F"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"A 2", "B 1", "C 2", "D", "E 2", "ERDOS 0", "F" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, calculateNumbers(Arg0)); }
	void test_case_4() { string Arr0[] = {"ERDOS KLEITMAN", "CHUNG GODDARD KLEITMAN WAYNE", "WAYNE GODDARD KLEITMAN", 
                                        "ALON KLEITMAN", "DEAN GODDARD WAYNE KLEITMAN STURTEVANT"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"ALON 2", "CHUNG 2", "DEAN 2", "ERDOS 0", "GODDARD 2", "KLEITMAN 1", "STURTEVANT 2", "WAYNE 2" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, calculateNumbers(Arg0)); }
	void test_case_5() { string Arr0[] = {"ERDOS", "KOSEI"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"ERDOS 0", "KOSEI" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, calculateNumbers(Arg0)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
ErdosNumber ___test;
___test.run_test(-1);
}
// END CUT HERE 
