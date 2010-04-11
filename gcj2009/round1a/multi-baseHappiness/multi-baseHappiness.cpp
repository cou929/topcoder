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
#include <fstream>

using namespace std;

vector <string> split(const string _s, const string del);
int toInt(string s) {int r = 0; istringstream ss(s); ss >> r; return r;}
string toStr(int n) {ostringstream ss; ss << n; return ss.str();}

map <pair <int, int>, bool> memo;

vector <int> cnv(const int n, const int base)
{
  vector <int> ret;
  int num = n;

  while (num >= base)
    {
      ret.push_back(num%base);
      num /= base;
    }

  ret.push_back(num);

  return ret;
}

bool happy(const int n, const int base)
{
  bool ret = false;
  int num = n;
  set <int> past;

  while (1)
    {
      //      cout << num << endl;;
      past.insert(num);
      vector <int> elems = cnv(num, base);
      int sum = 0;
      for (unsigned int i=0; i<elems.size(); i++)
	sum += elems[i]*elems[i];
      //      cout << "sum: " << sum << endl;

      if (sum == 1 || (memo.find(make_pair(sum, base)) != memo.end() && memo[make_pair(sum, base)]))
	{
	  ret = true;
	  past.insert(sum);
	  
	  for (set <int>::iterator it=past.begin(); it!=past.end(); it++)
	    memo[make_pair(*it, base)] = true;

	  break;
	}
      else if ((memo.find(make_pair(sum, base)) != memo.end() && !memo[make_pair(sum, base)]) ||
	       past.find(sum) != past.end())
	{
	  past.insert(sum);
	  for (set <int>::iterator it=past.begin(); it!=past.end(); it++)
	    memo[make_pair(*it, base)] = false;

	  break;
	}

      num = sum;
    }

  return ret;
}

string run(string inputs)
{
  string ret;
  vector <string> st;
  vector <int> bases;

  st = split(inputs, " ");
  for (unsigned int i=0; i<st.size(); i++)
    bases.push_back(toInt(st[i]));

  int i = 2;

  while (1)
    {
      bool isHappy = true;
      for (unsigned int j=0; j<bases.size(); j++)
	{
	  if ((memo.find(make_pair(i, bases[j])) != memo.end() && !memo[make_pair(i, bases[j])]) ||
	      !happy(i, bases[j]))
	    {
	      isHappy = false;
	      break;
	    }
	}

      if (isHappy)
	{
	  ret = toStr(i);
	  break;
	}

      i++;
    }

  return ret;
}

int main(int argc, char ** argv)
{
  if (argc != 2)
  {
    cout << "Usage " << argv[0] << " <input file name>\n";
    return 0;
  }

  ifstream file (argv[1]);
  string line;
  vector <string> tmp;
  vector <int> args;

  getline(file, line);
  tmp = split(line, " ");
  for (unsigned int i=0; i<tmp.size(); i++) args.push_back(toInt(tmp[i]));

  for (int lineNum = 0; lineNum<args[0]; lineNum++)
    {
      string result;

      getline(file, line);

      result = run(line);

      cout << "Case #" << lineNum+1 << ": " << result << endl;
    }

  return 0;
}

vector <string> split(const string _s, const string del)
{
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
