// BEGIN CUT HERE
// END CUT HERE
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
using namespace std;
class PizzaDelivery {
public:
  vector <string> terrain;
  int startx, starty;

  vector <int> make_node(int cost, int x, int y) {
    vector <int> node(3, 0);
    node[0] = cost, node[1] = x, node[2] = y;
    return node;
  }

  bool canMove(int fromx, int fromy, int tox, int toy) {
    if (0 <= fromx && fromx < terrain.size() && 0 <= fromy && fromy < terrain[0].size() &&
        0 <= tox && tox < terrain.size() && 0 <= toy && toy < terrain[0].size())
      if ((terrain[fromx][fromy] == 'X' || terrain[fromx][fromy] == '$' || terrain[tox][toy] == 'X' || terrain[tox][toy] == '$') ||
          (abs(terrain[fromx][fromy] - terrain[tox][toy]) < 2))
        return true;
    return false;
  }

  int findRoute(int x, int y) {
    int ret = -1;
    priority_queue <vector <int>, vector <vector <int> >, greater <vector <int> > > q;
    int visited[terrain.size()][terrain[0].size()];
    int dirx[4] = {0, 1, 0, -1};
    int diry[4] = {1, 0, -1, 0};

    for (int i=0; i<terrain.size(); i++)
      for (int j=0; j<terrain[0].size(); j++)
        visited[i][j] = INT_MAX;
    visited[startx][starty] = 0;
    q.push(make_node(0, startx, starty));

    while (!q.empty()) {
      vector <int> cur = q.top();
      q.pop();

      //      cout << cur[0] << " " << cur[1] << " " << cur[2] << endl;

      if (cur[1] == x && cur[2] == y) {
        ret = cur[0];
        break;
      }

      for (int i=0; i<4; i++) {
        int nextx = cur[1] + dirx[i];
        int nexty = cur[2] + diry[i];
        int next_cost = 0;

        if (canMove(cur[1], cur[2], nextx, nexty)) {
          //          cout << nextx << " " << nexty << endl;
          if (terrain[cur[1]][cur[2]] == 'X' || terrain[cur[1]][cur[2]] == '$' || terrain[nextx][nexty] == 'X' || terrain[nextx][nexty] == '$')
            next_cost = cur[0] + 2;
          else if (abs(terrain[cur[1]][cur[2]] - terrain[nextx][nexty]) == 0)
            next_cost = cur[0] + 1;
          else if (abs(terrain[cur[1]][cur[2]] - terrain[nextx][nexty]) == 1)
            next_cost = cur[0] + 3;
          else
            continue;

          if (visited[nextx][nexty] == INT_MAX) {
            q.push(make_node(next_cost, nextx, nexty));
            //            cout << next_cost << ", " << nextx << ", " << nexty << endl;
          }
        
          visited[nextx][nexty] = min(visited[nextx][nexty], next_cost);
        }
      }
    }

    return ret;
  }

  int deliverAll(vector <string> _terrain) {
    terrain = _terrain;
    vector <vector <int> > buildings;
    vector <int> costs;
    int ret = INT_MAX;

    for (int i=0; i<terrain.size(); i++)
      for (int j=0; j<terrain[0].size(); j++)
        if (terrain[i][j] == 'X') {
          startx = i, starty = j;
        } else if (terrain[i][j] == '$') {
          vector <int> tmp(2, 0);
          tmp[0] = i, tmp[1] = j;
          buildings.push_back(tmp);
        }

    for (int i=0; i<buildings.size(); i++) {
      int res = findRoute(buildings[i][0], buildings[i][1]);
      if (res == -1) return -1;
      costs.push_back(res);
    }

    //    for (int i=0; i<costs.size(); i++)
    //      cout << costs[i] << endl;
    //    cout << costs.size() << endl;

    for (int i=0; i<(1 << buildings.size()); i++) {
      int cost_1 = 0, cost_2 = 0;
      int max_1 = 0, max_2 = 0;
      for (int j=0; j<buildings.size(); j++)
        if (i & (1 << j)) {
          cost_1 += costs[j] * 2;
          max_1 = max(max_1, costs[j]);
        } else {
          cost_2 += costs[j] * 2;
          max_2 = max(max_2, costs[j]);
        }

      cost_1 -= max_1, cost_2 -= max_2;

      ret = min(ret, max(cost_1, cost_2));
    }

    return ret;
  }
   
  // BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"$$4$211123$47$3",
                                        "$4$221X$27$$$$$",
                                        "$44221111$$$$$$"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(0, Arg1, deliverAll(Arg0)); }
	void test_case_1() { string Arr0[] = {"001000$",
                                        "$010X0$",
                                        "0010000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; verify_case(1, Arg1, deliverAll(Arg0)); }
	void test_case_2() { string Arr0[] = {"001000$",
                                        "$010X0$",
                                        "0010000",
                                        "2232222",
                                        "2222222",
                                        "111$111"}
    ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(2, Arg1, deliverAll(Arg0)); }
	void test_case_3() { string Arr0[] = {"001000$",
                                        "$010X0$",
                                        "0010000",
                                        "1232222",
                                        "2222222",
                                        "111$111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 28; verify_case(3, Arg1, deliverAll(Arg0)); }
	void test_case_4() { string Arr0[] = {"5433321123442201000000001100223222221134433323554", "0013333323555677788877755446766766554555455533334", "1123335545445676667788787766678999987665566666766", "9999977767766777777555556655555554565444534444555", "8665678786543312221233333100000012211223322333200", "33210000000000$0010122221233332332122000000000000", "311112231112111113345445779988X886887777788898999", "3232201100234344443444423355788999888766666667889", "3343322234565544335766765444445554667999998787777", "4555542000012333455445554468999978888877899988887", "5544445555566776666678777777877555566533353344444", "3333333334544333444311012344467765655444443222333", "3333334566578766788664455332232222243322223322344", "0111110000112233355554557777677888877654310120133", "120000102212$565554433333222222222433333444554321", "5455555553335566545553323222233233433333322222011", "4433343344322222000011112222344532223333555556666", "4566764444423320010000110112333433346799999898986", "666022222223442244434544555444665556776666433$466", "8998766667777767777766665566665466642356668776668", "776766779889999$98899999889988$887899999977777654", "6665543445665334555666666667544434444545311112$44", "6664678889999999$$8978777998877888899986665566787", "7678998899988878998999788999899999998879998888777", "6666667789999999999998755555554455444545555432334", "3201133334446665676666677756667766664454332223344", "3333344453311334433344667777653334454566899777778", "6777789886667877755444444444442132344566788878988"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1202; verify_case(4, Arg1, deliverAll(Arg0)); }

  //{{}}


  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
PizzaDelivery ___test;
___test.run_test(-1);
}
// END CUT HERE 
