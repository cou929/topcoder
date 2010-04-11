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

int toInt(string s) {int r = 0; istringstream ss(s); ss >> r; return r;}
string toStr(int n) {ostringstream ss; ss << n; return ss.str();}

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

string welcome = "welcome to code jam";
string paragpeph;
int memo[501][20];

int r(int iParagraph, int iWelcome)
{
  int ret = 0.0;

  if (memo[iParagraph][iWelcome] != -1.0)
    return memo[iParagraph][iWelcome];

  for (int i=iParagraph; i<paragpeph.size(); i++)
    if (paragpeph[i] == welcome[iWelcome])
      if (iWelcome == welcome.size()-1)
	ret+=1.0;
      else
	ret += r(i+1, iWelcome+1);

  ret = ret % 10000;

  memo[iParagraph][iWelcome] = ret;
    
  return ret;
}

string getCount(string s)
{
  string ret;
  int count;
  char c[10];
  paragpeph = s;
  for (int i=0; i<501; i++)
    for (int j=0; j<20; j++)
      memo[i][j] = -1;

  count = r(0, 0);

  sprintf(c, "%04d", count);
  ret = c;

  return ret;
}

int main(int argc, char ** argv)
{
  string line;
  ifstream file (argv[1]);
  int problemNum = 0;

  vector <string> firstLine;
  getline(file, line);
  problemNum = toInt(line);

  for (int pi=0; pi<problemNum; pi++)
    {
      string ret;

      getline(file, line);

      ret = getCount(line);

      cout << "Case #" << pi+1 << ": " << ret << endl;
    }

  return 0;
}
