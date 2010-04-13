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

using namespace std;

const int N = 13;
vector <int> pais;
vector <vector <int> > results;

bool filled(vector <int> &label) {
  int i, n = label.size();
  for (i=0; i<n; i++)
    if (label[i] == 0)
      return false;
  return true;
}

int r(vector <int> label, bool hasJangToh, int color) {
  int head = 0;
  bool hasMachi = false;
  int i;

  if (filled(label)) {
    results.push_back(label);
    return 0;
  }

  for (i=N-1; i>=0; i--)
    if (label[i] == 0)
      head = i;
    else if (label[i] == 5)
      hasMachi = true;

  int samePos1 = -1, samePos2 = -1, nextPos1 = -1, nextPos2 = -1;
  for (i=head + 1; i<N; i++)
    if (label[i] == 0) {
      if (pais[i] == pais[head])
        if (samePos1 == -1)
          samePos1 = i;
        else
          samePos2 = i;
      else if (pais[i] == pais[head] + 1)
        nextPos1 = i;
      else if (pais[i] == pais[head] + 2)
        nextPos2 = i;
    }

  // 刻子
  if (samePos1 != -1 && samePos2 != -1) {
    label[head] = label[samePos1] = label[samePos2] = color + 1;
    r(label, hasJangToh, color + 1);
    label[head] = label[samePos1] = label[samePos2] = 0;
  }

  // 順子
  if (nextPos1 != -1 && nextPos2 != -1) {
    label[head] = label[nextPos1] = label[nextPos2] = color + 1;
    r(label, hasJangToh, color + 1);
    label[head] = label[nextPos1] = label[nextPos2] = 0;
  }

  // 雀頭
  if (samePos1 != -1)
    if (hasJangToh && !hasMachi) {
      // 待ち扱い(双碰待ち)
      label[head] = label[samePos1] = 5;
      r(label, hasJangToh, color);
      label[head] = label[samePos1] = 0;
    } else if (!hasJangToh && hasMachi) {
      // 雀頭扱い
      label[head] = label[samePos1] = color + 1;
      r(label, true, color + 1);
      label[head] = label[samePos1] = 0;
    } else if (!hasJangToh && !hasMachi) {
      // 雀頭扱い
      label[head] = label[samePos1] = color + 1;
      r(label, true, color + 1);
      label[head] = label[samePos1] = 0;
      // 待ち扱い(双碰待ち)
      label[head] = label[samePos1] = 5;
      r(label, hasJangToh, color);
      label[head] = label[samePos1] = 0;
    }

  // 待ち
  if (!hasMachi) {
    // 単騎
    label[head] = 5;
    r(label, hasJangToh, color);
    label[head] = 0;

    // 両面 or 辺張
    if (nextPos1) {
      label[head] = label[nextPos1] = 5;
      r(label, hasJangToh, color);
      label[head] = label[nextPos1] = 0;
    }

    // 嵌張
    if (nextPos2) {
      label[head] = label[nextPos2] = 5;
      r(label, hasJangToh, color);
      label[head] = label[nextPos2] = 0;
    }
  }

  return 0;
}

set <string> run(void) {
  set <string> ret;
  vector <int> label(N, 0);
  int i, j;
  results.clear();

  r(label, false, 0);

  for (i=0; i<results.size(); i++) {
    vector <string> sortedPais(5, "");
    string tmp;
    for (j=0; j<N; j++)
      sortedPais[results[i][j] - 1] += pais[j] + '0';
    sort(sortedPais.begin(), sortedPais.end()-1);
    for (j=0; j<4; j++)
      tmp += "(" + sortedPais[j] + ")";
    tmp += "[" + sortedPais[4] + "]";
    ret.insert(tmp);
  }

  return ret;
}

int main(void) {
  string line;
  int i;

  while (getline(cin, line)) {
    pais.clear();
    for (i=0; i<N; i++)
      pais.push_back(line[i] - '0');
    set <string> res = run();
    for (set <string>::iterator i=res.begin(); i!=res.end(); i++)
      cout << *i << ", ";
    cout << endl;
  }

  return 0;
}
