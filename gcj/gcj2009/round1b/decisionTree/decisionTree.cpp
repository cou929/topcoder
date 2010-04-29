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

string run(vector <string> dtree, vector <string> animals)
{
  string ret;
  vector <pair <int, string> > node;
  vector <vector <int> > tree;
  stack <int> s;
  int index = 0;

  for (int i=0; i<dtree.size(); i++)
    {
      for (int j=0; j<dtree[i].size(); j++)
	{
	  if (dtree[i][j] == '(')
	    {
	      ;
	    }
	  else if (dtree[i][j] == ')')
	    {
	      ;
	    }
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
      vector <string> dtree;
      vector <string> animals;

      getline(file, line);
      int n = toInt(line);
      for (int i=0; i<n; i++)
	{
	  getline(file, line);
	  dtree.push_back(line);
	}

      getline(file, line);
      n = toInt(line);
      for(int i=0; i<n; i++)
	{
	  getline(file, line);
	  animals.push_back(line);
	}

      result = run(dtree, animals);

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
