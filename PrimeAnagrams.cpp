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
class PrimeAnagrams {
public:
  bool primeTable[1000000];
  int MAX;
  //  int toInt(string s) {int r = 0; istringstream ss(s); ss >> r; return r;}
  int toInt(string s)
  {
    int ret = 0; 

    for (int i=0; i<s.size(); i++)
      ret = ret*10 + (s[i] - '0');

    return ret;
  }

  //   bool isPrime(int n)
  //   {
  //     if (n < 2)
  //       return false;

  //     if (n != 2 && n % 2 == 0)
  //       return false;

  //     int s = sqrt(n);

  //     for (int i=3; i<=s; i++)
  //       if (n % i == 0)
  // 	return false;

  //     return true;
  //   }

  void gen_primes()
  {
    int i,j;
    for(i=0;i<MAX;i++) primeTable[i] = true;
    primeTable[0] = false;
    primeTable[1] = false;
    for(i=2;i<=(int)sqrt(MAX);i++)
      if (primeTable[i])
	for(j=i;j*i<MAX;j++) primeTable[i*j] = false;
  }

  vector <int> primes(string anagram)
  {
    vector <int> ret;
    vector <vector <int> > candidates;
    MAX = 1000000;
    gen_primes();
    int mini = 1000000000;

    sort(anagram.begin(), anagram.end());
    do {
      if (anagram[0] == '0')
	continue;
      for (int i=0; i<anagram.size()-2; i++)
	{
	  if (anagram[i+1] == '0')
	    continue;
	  for (int j=i+1; j<anagram.size()-1; j++)
	    {
	      if (anagram[j+1] == '0')
		continue;
	      vector <int> t;
	      t.push_back(toInt(anagram.substr(0, i-0+1)));
	      t.push_back(toInt(anagram.substr(i+1, j-i)));
	      t.push_back(toInt(anagram.substr(j+1)));

	      if (primeTable[t[0]] && primeTable[t[1]] && primeTable[t[2]])
		if (mini > t[0] * t[1] * t[2])
		  {
		    mini = t[0] * t[1] * t[2];
		    ret = t;
		  }
	    }
	}
      //       for (int i=0; i<anagram.size()-2; i++)
      // 	for (int j=i+1; j<anagram.size()-1; j++)
      // 	  {
      // 	    c++;
      // 	    vector <string> tmp;
      // 	    tmp.push_back(anagram.substr(0, i-0+1));
      // 	    tmp.push_back(anagram.substr(i+1, j-i));
      // 	    tmp.push_back(anagram.substr(j+1));

      // 	    if (check(tmp))
      // 	      {
      // 		vector <int> t;
      // 		for (int k=0; k<tmp.size(); k++)
      // 		  t.push_back(toInt(tmp[k]));

      // 		if (mini > t[0] * t[1] * t[2])
      // 		  {
      // 		    mini = t[0] * t[1] * t[2];
      // 		    sort(t.begin(), t.end());
      // 		    ret = t;
      // 		  }
      // 	      }
      // 	  }
    } while (next_permutation(anagram.begin(), anagram.end()));

    sort(ret.begin(), ret.end());
    return ret;
  }
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
  void test_case_0() { string Arg0 = "39151"; int Arr1[] = { 5,  13,  19 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, primes(Arg0)); }
  void test_case_1() { string Arg0 = "921179"; int Arr1[] = { 2,  17,  199 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, primes(Arg0)); }
  void test_case_2() { string Arg0 = "01123"; int Arr1[] = { 2,  3,  101 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, primes(Arg0)); }
  void test_case_3() { string Arg0 = "0707070"; int Arr1[] = { }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, primes(Arg0)); }
  void test_case_4() { string Arg0 = "222"; int Arr1[] = { 2,  2,  2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, primes(Arg0)); }
  void test_case_5() { string Arg0 = "123"; int Arr1[] = { }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, primes(Arg0)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
PrimeAnagrams ___test;
___test.run_test(-1);
}
// END CUT HERE 
