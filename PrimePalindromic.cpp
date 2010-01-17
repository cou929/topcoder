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
class PrimePalindromic {
public:
  string toStr(int n) {ostringstream ss; ss << n; return ss.str();}

  vector <int> factor(const int n)
  {
    vector <int> ret;
    int num = n;

    for (int i=2; i*i<=n; i++)
      {
	while (num % i == 0)
	  {
	    ret.push_back(i);
	    num /= i;
	  }
      }

    if (num > 1)
      ret.push_back(num);

    return ret;
  }

  bool isPalindromic(string s)
  {
    bool ret = true;
    for (int i=0; i<s.size()/2; i++)
      if (s[i] != s[s.size()-1-i])
	{
	  ret = false;
	  return ret;
	}

    return ret;
  }

  int primeTable[5000];
  int MAX;

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

  int count(int A, int B)
  {
    int ret = 0;
    //     map <int, int> m;
    //     char check[10001];
    //     memset(check, -1, sizeof(check));
    //     MAX = 5000;
    //     gen_primes();

    for (int i=A; i<=B; i++)
      {
	// 	if (check[i] != -1)
	// 	  continue;

	// 	check[i] = 0;

	vector <int> primes = factor(i);
	do {
	  string str;
	  for (int j=0; j<primes.size(); j++)
	    str += toStr(primes[j]);
	  if (isPalindromic(str))
	    {
	      ret++;
	      break;
	    }
	} while (next_permutation(primes.begin(), primes.end()));

	// 	if (primes.size() > 1)
	// 	  for (vector <int>::iterator j=primes.begin(); j<primes.end()-1; j++)
	// 	    if (*j < 10 && *j == *(j+1))
	// 	      {
	// 		j = primes.erase(j);
	// 		j = primes.erase(j);
	// 		j--;
	// 	      }
	// 	map <int, int> m;
	// 	map <int, int>::iterator mi;
	// 	string str;
	// 	int odd = 0;
	// 	for (int j=0; j<primes.size(); j++)
	// 	  str+=toStr(primes[j]);
	// 	for (int j=0; j<str.size(); j++)
	// 	  m[str[j]-'0']++;
	// 	for (mi=m.begin(); mi!=m.end(); mi++)
	// 	  if (mi->second % 2 == 1)
	// 	    odd++;
	// 	if (odd > 1)
	// 	  continue;

	// 	for (int j=0; !primes.empty() && j<primes.size()-1; j++)
	// 	  if (primes[j] == primes[j+1])
	// 	    {
	// 	      primes.erase(primes.begin());
	// 	      primes.erase(primes.begin());
	// 	    }
	//	m[primes.size()]++;
	// 	if (primes.empty())
	// 	  {
	// 	    ret++;
	// 	    continue;
	// 	  }

	// 	stack <vector <int> > s;
	// 	for (int j=0; j<primes.size(); j++)
	// 	  {
	// 	    vector <int> a;
	// 	    a.push_back(j);
	// 	    s.push(a);
	// 	  }

	// 	while (!s.empty())
	// 	  {
	// 	    vector <int> t = s.top();
	// 	    s.pop();

	// 	    if (t.size() == primes.size())
	// 	      {
	// 		string pal;
	// 		for (int j=0; j<t.size(); j++)
	// 		    pal += toStr(primes[t[j]]);
	
	// 		if (isPalindromic(pal))
	// 		  {
	// 		    for (int j=0; j<MAX; j++)
	// 		      if (primeTable[j])
	// 			{
	// 			  for (int k=1; i*(int)pow((double)j, k) <= B; k++)
	// 			    {
	// 			      int p = i*(int)pow((double)j, k);
	// 			      if (check[p] == -1)
	// 				check[p] = (k % 2 == 0) ? 0 : 1;
	// 			    }
	// 			}

	// 		    break;
	// 		  }
	// 	      }

	// 	    for (int j=0; j<primes.size(); j++)
	// 	      {
	// 		if (find(t.begin(), t.end(), j) == t.end())
	// 		  {
	// 		    vector <int> tmp = t;
	// 		    tmp.push_back(j);
	// 		    s.push(tmp);
	// 		  }
	// 	      }
	// 	  }
      }

    return ret;
  }
   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { int Arg0 = 2260; int Arg1 = 2262; int Arg2 = 1; verify_case(0, Arg2, count(Arg0, Arg1)); }
  void test_case_1() { int Arg0 = 4001; int Arg1 = 5000; int Arg2 = 64; verify_case(1, Arg2, count(Arg0, Arg1)); }
  void test_case_2() { int Arg0 = 2; int Arg1 = 1000; int Arg2 = 175; verify_case(2, Arg2, count(Arg0, Arg1)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
PrimePalindromic ___test;
___test.run_test(-1);
}
// END CUT HERE 
