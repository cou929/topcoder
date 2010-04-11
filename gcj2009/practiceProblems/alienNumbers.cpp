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

int toDigit(string pat, string n)
{
  int ret = 0;
  int place = 0;
  int scale = pat.size();
  
  for (int i=n.size()-1; i>=0; i--)
    {
      int j;
      for (j=0; j<pat.size(); j++)
	if (pat[j] == n[i])
	  break;

      ret += j * (int)pow((double)scale, (double)place);

      place++;
    }

  return ret;
}

string fromDigit(string pat, int n)
{
  string ret;
  int scale = pat.size();
  vector <int> indices;

  while (n >= scale)
    {
      indices.push_back(n % scale);
      n /= scale;
    }

  indices.push_back(n);

  for (int i=indices.size()-1; i>=0; i--)
    ret += pat[indices[i]];

  return ret;
}

int main(int argc, char ** argv)
{
  string line;
  ifstream file (argv[1]);
  int lineNumber = 1;

  while (!file.eof())
    {
      vector <string> inputs;
      getline(file, line);

      inputs = split(line, " ");

      if (inputs.size() == 3)
	cout << "Case #" << lineNumber++ << ": " << fromDigit(inputs[2], toDigit(inputs[1], inputs[0])) << endl;
    }

  return 0;
}
