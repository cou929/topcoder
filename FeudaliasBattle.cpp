#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

class FeudaliasBattle {
public:
  double getd(int x1, int y1, int x2, int y2)
  {
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
  }

  double getMinimumTime(vector <int> baseX, vector <int> baseY, vector <int> siloX, vector <int> siloY, int takeOffTime, int rechargeTime, int missileSpeed)
  {
    vector <double> ret;
    double tmp = 0;

    tmp = max((double)takeOffTime/60.0 + (getd(baseX[0], baseY[0], siloX[0], siloY[0]) / missileSpeed), 2*(double)takeOffTime/60.0 + (double)rechargeTime + (getd(baseX[1], baseY[1], siloX[0], siloY[0]) / missileSpeed));
    ret.push_back(tmp);

    tmp = max((double)takeOffTime/60.0 + (getd(baseX[1], baseY[1], siloX[0], siloY[0]) / missileSpeed), 2*(double)takeOffTime/60.0 + (double)rechargeTime + (getd(baseX[0], baseY[0], siloX[0], siloY[0]) / missileSpeed));
    ret.push_back(tmp);

    tmp = max((double)takeOffTime/60.0 + (getd(baseX[0], baseY[0], siloX[1], siloY[1]) / missileSpeed), 2*(double)takeOffTime/60.0 + (double)rechargeTime + (getd(baseX[1], baseY[1], siloX[1], siloY[1]) / missileSpeed));
    ret.push_back(tmp);

    tmp = max((double)takeOffTime/60.0 + (getd(baseX[1], baseY[1], siloX[1], siloY[1]) / missileSpeed), 2*(double)takeOffTime/60.0 + (double)rechargeTime + (getd(baseX[0], baseY[0], siloX[1], siloY[1]) / missileSpeed));
    ret.push_back(tmp);

    tmp = max((getd(baseX[0], baseY[0], siloX[0], siloY[0]) / missileSpeed), (getd(baseX[1], baseY[1], siloX[1], siloY[1]) / missileSpeed)) + (double)takeOffTime/60.0;
    ret.push_back(tmp);

    tmp = max((getd(baseX[0], baseY[0], siloX[1], siloY[1]) / missileSpeed), (getd(baseX[1], baseY[1], siloX[0], siloY[0]) / missileSpeed)) + (double)takeOffTime/60.0;
    ret.push_back(tmp);

    sort(ret.begin(), ret.end());

    return ret[0];
  }

   

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
