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

vector <int> split(const string _s, const string del = " ");
vector <string> splits(const string _s, const string del = " ");
int toInt(string s) {int r = 0; istringstream ss(s); ss >> r; return r;}
string toStr(int n) {ostringstream ss; ss << n; return ss.str();}

int req[10];

bool check(int _n)
{
  bool ret = true;
  int n = _n;
  int test[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  while (n >= 1)
    {
      test[n%10]++;
      n /= 10;
    }

  for (int i=1; i<10; i++)
    if (test[i] != req[i])
      {
	ret = false;
	break;
      }

  return ret;
}

string run(string input)
{
  string ret;

  for (int i=0; i<10; i++)
    req[i] = 0;

  int in = toInt(input);

  for (unsigned int i=0; i<input.size(); i++)
    req[input[i]-'0']++;

  for (int i=in+1; i<100000000; i++)
    {
      if (check(i))
	{
	  ret = toStr(i);
	  break;
	}
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
  vector <int> args;

  getline(file, line);
  args = split(line);

  for (int lineNum = 0; lineNum<args[0]; lineNum++)
    {
      string result;

      getline(file, line);

      result = run(line);

      cout << "Case #" << lineNum+1 << ": " << result << endl;
    }

  return 0;
}

vector <int> split(const string _s, const string del)
{
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

vector <string> splits(const string _s, const string del)
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
