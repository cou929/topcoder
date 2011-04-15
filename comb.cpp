#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

// toInt()
// toStr()
// vector <int> split(const string _s, const string del = " ");
// vector <string> splits(const string _s, const string del = " ");
// string chomp(const string s)
// int gcd(int _a, int _b)
// double lcm(int _a, int _b)
// countBit()
// class combinations
// combination()
// factorial()
// isPrime()
// class allCombination
// factor()   : prime factorization by trial division method
// generatePrimes(int maxi)    : generate prime numbers smaller than maxi and return result as vector <int>. This requires isPrime(). Using Sleve of Eratosthenes.
// gen_primes()    : generate prime numbers for array

int toInt(string s) {int r = 0; istringstream ss(s); ss >> r; return r;}
string toStr(int n) {ostringstream ss; ss << n; return ss.str();}

vector <int> split(const string _s, const string del) {
  vector <int> ret;
  string s = _s;

  while (!s.empty())
    {
      size_t pos = s.find(del);
      string sub = "";
      sub = s.substr(0, pos);
      ret.push_back(toInt(sub));
      if (pos != string::npos)
        pos += del.size();
      s.erase(0, pos);
    }

  return ret;
}

vector <string> splits(const string _s, const string del) {
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

string chomp(const string s)
{
  string ret = s;
  size_t pos;

  for (int i=0; ret[i] == ' '; i++)
    pos = i;
  ret.erase(0, pos+1);

  for (int i=ret.size()-1; ret[i] == ' '; i--)
    pos = i;
  ret.erase(pos);

  return ret;
}

int gcd(const int _a, const int _b) {
  int a = max(_a, _b);
  int b = min(_a, _b);

  while (b) {
    int tmp = a % b;
    a = b;
    b = tmp;
  }

  return a;
}

double lcm(int _a, int _b)
{
  int a = max(_a, _b);
  int b = min(_a, _b);

  return (double)a / gcd(a, b) * b;
}

int countBit(int N)
{
  int n = N;
  int counter = 0;

  while (n)
    {
      if (n & 1)
	counter++;
      n = n >> 1;
    }

  return counter;
}

//////////////////////////////////////////////////////////

class combinations {
private:
  vector <vector <int> > result;
  int n;
  int m;
public:
  combinations(){};
  int calc(int _n, int _m);
  void r(int l, int r, vector <int> &v);
  int print();
  vector <vector <int> > get();
};

void combinations::r(int l, int r, vector <int> &v)
{
  for (int i=l; i<=r; i++)
    {
      v.push_back(i);

      if (r == n)
	result.push_back(v);
      else
	this->r(i+1, r+1, v);

      v.pop_back();
    }
}

int combinations::calc(int _n, int _m)
{
  n = _n;
  m = _m;
  vector <int> tmp;
  r(0, n-m+1, tmp);

  return 0;
}

int combinations::print()
{
  for (int i=0; i<result.size(); i++)
    {
      for (int j=0; j<result[i].size(); j++)
	cout << result[i][j] << " ";
      cout << endl;
    }

  return 0;
}

vector <vector <int> > combinations::get()
{
  return result;
}


//////////////////////////////////////////////////////////

long long combination(int n, int r)
{
  int i, j;
  long long result[r+1], tmp[r+1];

  for (i=0; i<=r; i++) {
    result[i] = 0;
    tmp[i] = 0;
  }

  result[0] = 1;

  for (i=1; i<=n; i++) {
    tmp[0] = 1;

    for (j=1; j<=r; j++)
      tmp[j] = result[j-1] + result[j];

    for (j=0; j<=r; j++)
      result[j] = tmp[j];
  }

  return result[r];
}

int factorial(int n)
{
  int i;
  int ret = 1;

  for (i=1; i<=n; i++)
    ret *= i;

  return ret;
}

int combination2(int n, int r) {
  return factorial(n) / factorial(n-r) / factorial(r);
}

bool isPrime(int n) {
  if (n < 2)
    return false;

  if (n != 2 && n % 2 == 0)
    return false;

  int s = (int)sqrt(n);

  for (int i=3; i<=s; i++)
    if (n % i == 0)
      return false;

  return true;
}

bool isPrime2(int x) {
  for(int i = 2; i * i <= x; i++)
    if(x % i == 0)
      return false;
  return true;
}

// returns all combinations
// Ex. generate(3, 2) returns:
// 0 1
// 0 2
// 1 2
class allCombination
{
private:
  int _m, _n;
  vector <vector <int> > ret;

  int _s(int start, vector <int> com)
  {
    if (com.size() == _m)
      {
	ret.push_back(com);
	return 0;
      }
    else
      {
	for (int i=start; i<_n; i++)
	  {
	    com.push_back(i);
	    _s(++start, com);
	    com.pop_back();
	  }
      }
  }

public:
  vector <vector <int> > generate(int n, int m)
  {
    _n = n;
    _m = m;
    vector <int> com;

    _s(0, com);

    return ret;
  }
};

vector <int> factor(const int n) {
  vector <int> ret;
  int num = n;

  for (int i=2; i*i<=n; i++) {
    while (num % i == 0) {
      ret.push_back(i);
      num /= i;
    }
  }

  if (num > 1)
    ret.push_back(num);

  return ret;
}

vector <int> generatePrimes(const int maxi)
{
  vector <int> ret;
  bool primes[maxi];
  memset(primes, true, sizeof(primes));

  for (int i=2; i*i<=maxi; i++)
    {
      if (isPrime(i))
	for (int j=2; j*i<maxi; j++)
	  primes[i*j] = false;
    }

  for (int i=2; i<maxi; i++)
    if (primes[i])
      ret.push_back(i);

  return ret;
}

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




int main(int argc, char *argv[])
{
  int i, j;
  int n = 5;

  if (argc == 2)
    n = atoi(argv[1]);


  for (i=0; i<n; i++)
    {
      for (j=0; j<n; j++)
	printf("%d ", combination(i, j));
      printf("\n");
    }

  if (isPrime(3))
    cout << "prime" << endl;

  return 0;
}

