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

string run(string inputs)
{
  string ret;



  return ret;
}

int main(int argc, char ** argv)
{
  if (argc != 1 && argc != 3)
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
  for (int i=0; i<tmp.size(); i++) args.push_back(toInt(tmp[i]));

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
