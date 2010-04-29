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

char dirx[4] = {-1, 0, 0, 1};
char diry[4] = {0, -1, 1, 0};

vector <vector <int> > attrs;
int label[101][101];

bool inRange(int x, int y)
{
  bool ret = false;
  int row = attrs.size();
  int col = attrs[0].size();

  if (0 <= x && x < row && 0 <= y && y < col)
    ret = true;

  return ret;
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

vector <pair <int, int> > getSink(vector <vector <int> > attrs)
{
  vector <pair <int, int> > ret;

  for (int x=0; x<attrs.size(); x++)
    for (int y=0; y<attrs[x].size(); y++)
      {
	bool isSink = true;
	for (int i=0; i<4; i++)
	  if (inRange(x + dirx[i], y + diry[i]) &&
	      attrs[x][y] > attrs[x+dirx[i]][y+diry[i]])
	    {
	      isSink = false;
	      break;
	    }
	if (isSink)
	  ret.push_back(make_pair(x, y));
      }

  return ret;
}

pair <int, int> flowTo(int x, int y)
{
  pair <int, int> ret = make_pair(x, y);
  int minAttr = attrs[x][y];

  for (int i=0; i<4; i++)
    {
      int dx = x + dirx[i];
      int dy = y + diry[i];
      if (inRange(dx, dy))
	if (attrs[dx][dy] < minAttr)
	  {
	    ret = make_pair(dx, dy);
	    minAttr = attrs[dx][dy];
	  }
    }

  return ret;
}

int s(int x, int y, int labelnum)
{
  for (int i=0; i<4; i++)
    if (inRange(x + dirx[i], y + diry[i]))
      if (flowTo(x+dirx[i], y+diry[i]) == make_pair(x, y))
	{
	  if (label[x+dirx[i]], y+diry[i] != -1)
	    label[x+dirx[i]][y+diry[i]] = labelnum;
	  s(x+dirx[i], y+diry[i], labelnum);
	}

  return 0;
}

vector <string> labeling(void)
{
  vector <string> ret;
  int alpCounter = 0;
  char label2alphabet[26];
  memset(label2alphabet, -1, sizeof(label2alphabet));

  for (int x=0; x<attrs.size(); x++)
    {
      string row;
      for (int y=0; y<attrs[x].size(); y++)
	{
	  if (label2alphabet[label[x][y]] == -1)
	    label2alphabet[label[x][y]] = 'a' + alpCounter++;
	  row += label2alphabet[label[x][y]];
	  row += " ";
	}
      row.erase(row.end()-1);
      ret.push_back(row);
    }

  return ret;
}

vector <string> labelBasin(vector <string> in)
{
  attrs.clear();
  memset(label, -1, sizeof(label));
  vector <string> ret;
  vector <pair <int, int> > sinks;

  for (int i=0; i<in.size(); i++)
    {
      vector <string> tmp;
      vector <int> rows;

      tmp = split(in[i], " ");

      for (int j=0; j<tmp.size(); j++)
	rows.push_back(toInt(tmp[j]));

      attrs.push_back(rows);
    }

  sinks = getSink(attrs);

  for (int i=0; i<sinks.size(); i++)
    {
      label[sinks[i].first][sinks[i].second] = i;
      s(sinks[i].first, sinks[i].second, i);
    }

  ret = labeling();

  return ret;
}

int main(int argc, char ** argv)
{
  string line;
  ifstream file (argv[1]);
  int mapNum = 0;

  vector <string> firstLine;
  getline(file, line);
  mapNum = toInt(line);

  for (int mi=0; mi<mapNum; mi++)
    {
      vector <string> s;
      int row, column;
      vector <string> inputMap;
      vector <string> outputMap;

      getline(file, line);
      s = split(line, " ");
      row = toInt(s[0]);
      column = toInt(s[1]);

      for (int i=0; i<row; i++)
	{
	  getline(file, line);
	  inputMap.push_back(line);
	}

      outputMap = labelBasin(inputMap);

      cout << "Case #" << mi+1 << ":" << endl;
      for (int i=0; i<outputMap.size(); i++)
      	cout << outputMap[i] << endl;
    }

  return 0;
}
