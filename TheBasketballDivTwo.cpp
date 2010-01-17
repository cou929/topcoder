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
#include <climits>
#include <cfloat>
using namespace std;
typedef struct data
{
  int maxWin;
  vector <int> score;
  vector <int> notPlayed;
};

data make_data(int m, vector <int> s, vector <int> n)
{
  data ret;
  ret.maxWin = m;
  ret.score = s;
  ret.notPlayed = n;

  return ret;
}

bool operator<(const data & a, const data & b)
{
  return a.maxWin > b.maxWin;
}

int maxWin(vector <int> score)
{
  int ret = 0;
  for (int i=0; i<score.size(); i++)
    ret = max(ret, score[i]);
  return ret;
}

bool isOver(vector <int> score)
{
  for (int i=0; i<score.size(); i++)
    if (score[i] == 1)
      return false;

  return true;
}

vector <string> tbl;
int ret;
int cc = 0;

int r(int x, int y)
{
  if (x == (int)tbl.size())
    {
      int win = 0;
      for (int i=0; i<tbl.size(); i++)
        {
          int sum = 0;
          for (int j=0; j<tbl.size(); j++)
            {
              if (tbl[i][j] == 'W')
                sum++;
              if (tbl[j][i] == 'L')
                sum++;
            }
          win = max(win, sum);
        }
      ret = min(ret, win);
    }
  else if (y == tbl.size())
    {
      r(x+1, 0);
    }
  else if (tbl[x][y] != '?')
    {
      r(x, y+1);
    }
  else
    {
      tbl[x][y] = 'W';
      r(x, y+1);
      tbl[x][y] = 'L';
      r(x, y+1);
      tbl[x][y] = '?';
    }
  cc++;
  return 0;
}

class TheBasketballDivTwo {
public:
  int find(vector <string> table)
  {
//     vector <int> init(table.size(), 0);
//     vector <pair <int, int> > notPlayed;

//     for (int i=0; i<table.size(); i++)
//       for (int j=0; j<table[i].size(); j++)
//         {
//           if (table[i][j] == 'W')
//             init[i]++;
//           if (table[j][i] == 'L')
//             init[i]++;
//           if (table[i][j] == '?')
//             notPlayed.push_back(make_pair(i, j));
//         }

//     vector <int> npflag(notPlayed.size(), 1);
//     priority_queue <data> q;
//     q.push(make_data(maxWin(init), init, npflag));

//     int counter = 0;
 
//     while (!q.empty())
//       {
//         cout << counter++ << endl;
//         data d = q.top();
//         q.pop();

//         if (isOver(d.notPlayed))
//           return d.maxWin;

//         for (int i=0; i<notPlayed.size(); i++)
//           {
//             if (d.notPlayed[i] == 1)
//               {
//                 vector <int> tmp = d.notPlayed;
//                 tmp[i] = 0;
//                 pair <int, int> match = notPlayed[i];
//                 vector <int> wins1 = d.score;
//                 vector <int> wins2 = d.score;
//                 wins1[match.first]++;
//                 wins2[match.second]++;
//                 q.push(make_data(maxWin(wins1), wins1, tmp));
//                 q.push(make_data(maxWin(wins2), wins2, tmp));
//               }
//           }
//       }

//     return maxWin(init);

    tbl = table;
    ret = INT_MAX;

    r(0, 0);

    cout << cc << endl;

    return ret;
  }
   

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
