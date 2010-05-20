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
#include <cstring>
#include <numeric>

using namespace std;

const double pi = 3.14159265;

bool isCross(vector <int> line, int x, int y) {
  double inc = 0, inter = 0;

  if ((line[0] - line[2]) == 0)
    inc = 0;
  else
    inc = (line[1] - line[3]) / (line[0] - line[2]);
  inter = line[1] - line[0] * inc;

  if (x * inc + inter == y)
    if (line[0] <= x && x <= line[2] && line[1] <= y && y <= line[3])
      return true;
  
  return false;
}

double getAngle(vector <int> firstLine, vector <int> secondLine, pair <int, int> endpoint) {
  double a, b, c;
  int point1x, point1y, point2x, point2y;

  b = sqrt((firstLine[0] - firstLine[2]) * (firstLine[0] - firstLine[2]) + (firstLine[1] - firstLine[3]) * (firstLine[1] - firstLine[3]));
  c = sqrt((secondLine[0] - secondLine[2]) * (secondLine[0] - secondLine[2]) + (secondLine[1] - secondLine[3]) * (secondLine[1] - secondLine[3]));

  if (firstLine[0] == endpoint.first && firstLine[1] == endpoint.second)
    point1x = firstLine[0], point1y = firstLine[1];
  else
    point1x = firstLine[2], point1y = firstLine[3];

  if (secondLine[0] == endpoint.first && secondLine[1] == endpoint.second)
    point2x = secondLine[0], point2y = secondLine[1];
  else
    point2x = secondLine[2], point2y = secondLine[3];

  a = sqrt((point1x - point2x) * (point1x - point2x) + (point1y - point2y) * (point1y - point2y));

  return acos((b*b + c*c - a*a) / 2*b*c);
}

bool ok(vector <int> line, int x, int y) {
  double a, b;
  a = (line[0] - x) * (line[0] - x) + (line[1] - y) * (line[1] - y);
  b = (line[2] - x) * (line[2] - x) + (line[3] - y) * (line[3] - y);
  if (max(a, b) / min(a, b) <= 4.0)
    return true;
  return false;
}

string solve(vector <vector <int> > lines) {
  int i, j;
  int thirdLineIndex = -1;

  for (i=0; i<3; i++) {
    int left = 0, right = 0;
    for (j=0; j<3; j++) {
      if (i != j)
        if (isCross(lines[j], lines[i][0], lines[i][1]))
          left++;
        else if (isCross(lines[j], lines[i][2], lines[i][3]))
          right++;
    }
    thirdLineIndex = i;
  }
  
  if (thirdLineIndex == -1)
    return "NO";

  vector <int> firstLine, secondLine, thirdLine;

  thirdLine = lines[thirdLineIndex];

  for (i=0; i<3; i++)
    if (i != thirdLineIndex)
      if (firstLine.empty())
        firstLine = lines[i];
      else
        secondLine = lines[i];

  pair <int, int> endpoint(make_pair(-1, -1));
  int numOfEndPOint = 0;

  for (i=0; i<2; i++)
    for (j=0; j<2; j++)
      if (firstLine[i*2] == secondLine[j*2] && firstLine[i*2+1] == secondLine[j*2 + 1]) {
        endpoint = make_pair(firstLine[i], firstLine[i+1]);
        numOfEndPOint++;
      }

  if (numOfEndPOint != 1)
    return "NO";

  if (getAngle(firstLine, secondLine, endpoint) >= pi / 2.0)
    return "NO";

  if (isCross(firstLine, thirdLine[0], thirdLine[1])) {
    if (!ok(firstLine, thirdLine[0], thirdLine[1]))
      return "NO";
  } else {
    if (!ok(firstLine, thirdLine[2], thirdLine[3]))
      return "NO";
  }

  if (isCross(secondLine, thirdLine[0], thirdLine[1])) {
    if (!ok(secondLine, thirdLine[0], thirdLine[1]))
      return "NO";
  } else {
    if (!ok(secondLine, thirdLine[2], thirdLine[3]))
      return "NO";
  }

  return "YES";
}

int main(void) {
  int probNum;
  int i, j;

  cin >> probNum;

  for (i=0; i<probNum; i++) {
    vector <vector <int> > lines;
    int a, b, c, d;
    vector <int> line;
    for (j=0; j<3; j++) {
      cin >> a >> b >> c >> d;
      line.push_back(a);
      line.push_back(b);
      line.push_back(c);
      line.push_back(d);
      lines.push_back(line);
    }
    cout << solve(lines) << endl;
  }

  return 0;
}
