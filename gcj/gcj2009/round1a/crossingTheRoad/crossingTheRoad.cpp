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

#define MOVE_LEFT 0
#define MOVE_TOP 1

vector <int> inters[20][20];

int waitInter(pair <int, int> curPos, int minute, int dir)
{
  int ret = 0;

  int x = curPos.first / 2;
  int y = curPos.second / 2;

  int n = inters[x][y][0];
  int e = inters[x][y][1];
  int t = inters[x][y][2];

  int curTIme = abs(t - minute);
  int mod = curTIme%(n+e);

  if (dir == MOVE_LEFT)
    {
      if (mod < n)
	ret = n - mod - 1;
      else
	ret = 0;
    }
  else
    {
      if (mod < n)
	ret = 0;
      else
	ret = mod - n + 2;
    }
  return ret;
}

int moveRight(pair <int, int> curPos, int minute)
{
  int ret = 0;

  if (curPos.second % 2 == 0)
    ret = waitInter(curPos, minute, MOVE_LEFT) + 1;
  else
    ret = 2;

  return ret;
}

int moveTop(pair <int, int> curPos, int minute)
{
  int ret = 0;

  if (curPos.first % 2 == 0)
    ret = 2;
  else
    ret = waitInter(curPos, minute, MOVE_TOP) + 1;

  return ret;
}

string run(int N, int M)
{
  string ret = "0";

//   cout << N << " " << M << endl;
//   for (int i=0; i<N; i++)
//     for (int j=0; j<M; j++)
//       cout << i << ", " << j << ": " << inters[i][j][0] << " " << inters[i][j][1] << " " << inters[i][j][2] << endl;

  pair <int, int> start = make_pair(N*2-1, 0);
  pair <int, int> goal = make_pair(0, M*2-1);
  queue <pair <pair <int, int>, int> > q;
  int time[N*2][M*2];
  for (int i=0; i<N*2; i++)
    for (int j=0; j<M*2; j++)
      time[i][j] = 2000000000;

  int tt = 2000000000;

  q.push(make_pair(start, 0));

  while (!q.empty())
    {
      pair <int, int> curPos;
      int minute;
      pair <pair <int, int>, int> t;

      t = q.front();
      q.pop();

      curPos = t.first;
      minute = t.second;

//       if (time[curPos.first][curPos.second] > minute)
// 	time[curPos.first][curPos.second] = minute;
//       else
// 	continue;

      if (curPos == goal)
	tt = min(tt, minute);

      //      cout << curPos.first << ", " << curPos.second << ": " << minute << endl;

      if (curPos.second+1 < M*2)
	q.push(make_pair(make_pair(curPos.first, curPos.second+1), minute + moveRight(curPos, minute)));
      if (curPos.first-1 >= 0)
	q.push(make_pair(make_pair(curPos.first-1, curPos.second), minute + moveTop(curPos, minute)));
    }

  //  ret = toStr(time[goal.first][goal.second]);
  ret = toStr(tt);

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
      string road, inter;

      getline(file, road);
      vector <string> roadt = split(road, " ");
      int N = toInt(roadt[0]);
      int M = toInt(roadt[1]);

      for (int i=0; i<N; i++)
	{
	  getline(file, inter);
	  vector <string> intert;
	  intert = split(inter, " ");
	  for (int j=0; j<M; j++)
	    {
	      vector <int> tmp;
	      tmp.push_back(toInt(intert[j*3+0]));
	      tmp.push_back(toInt(intert[j*3+1]));
	      tmp.push_back(toInt(intert[j*3+2]));
	      inters[i][j] = tmp;
	    }
	}

      result = run(N, M);

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
