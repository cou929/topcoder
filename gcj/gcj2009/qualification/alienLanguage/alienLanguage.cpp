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

vector <string> getWords(string s)
{
  vector <string> ret;
  bool inParen = false;
  string tmp;

  for (int i=0; i<s.size(); i++)
    {
      if (inParen)
	{
	  if (s[i] == '(')
	    {
	      cout << "Unexpected characotr" << endl;
	      exit(-1);
	    }
	  else if (s[i] == ')')
	    {
	      ret.push_back(tmp);
	      inParen = false;
	      tmp.clear();
	    }
	  else
	    {
	      tmp += s[i];
	    }
	}
      else
	{
	  if (s[i] == '(')
	    {
	      inParen = true;
	      tmp.clear();
	    }
	  else if (s[i] == ')')
	    {
	      cout << "Unexpected characotr" << endl;
	      exit(-1);
	    }
	  else
	    {
	      tmp = s[i];
	      ret.push_back(tmp);
	      tmp.clear();
	    }
	}
    }

  return ret;
}

int match(vector <string> & words, vector <string> & dictionary)
{
  int ret = 0;

  for (int i=0; i<dictionary.size(); i++)
    {
      bool ok = true;

      for (int j=0; j<dictionary[i].size(); j++)
	if (words[j].find(dictionary[i][j]) == string::npos)
	  {
	    ok = false;
	    break;
	  }

      if (ok)
	ret++;
    }

  return ret;
}

int main(int argc, char ** argv)
{
  string line;
  ifstream file (argv[1]);
  int wordNum = 0;
  int dicNum = 0;
  int testNum = 0;
  vector <string> dictionary;

  vector <string> firstLine;
  getline(file, line);
  firstLine = split(line, " ");
  wordNum = toInt(firstLine[0]);
  dicNum = toInt(firstLine[1]);
  testNum = toInt(firstLine[2]);

  for (int i=0; i<dicNum; i++)
    {
      getline(file, line);
      dictionary.push_back(line);
    }

  for (int i=0; i<testNum; i++)
    {
      int matches = 0;
      vector <string> words;
      getline(file, line);

      words = getWords(line);

      if (words.size() != wordNum)
	{
	  cout << "Word number is wrong" << endl;
	  return -1;
	}

      matches = match(words, dictionary);
      
      cout << "Case #" << i+1 << ": " << matches << endl;
    }

  return 0;
}
