#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define ITEM_NUM 6

vector <double> linearRelaxation(vector <int> &vals, vector <int> &weis, int lim);

int main(void)
{
  int v[ITEM_NUM] = {5, 26, 7, 47, 29, 36};
  int w[ITEM_NUM] = {11, 29, 36, 22, 35, 32};
  vector <int> values(v, v+ITEM_NUM);
  vector <int> weights(w, w+ITEM_NUM);
  int limit = 37;

  vector <double> res = linearRelaxation(values, weights, limit);

  for (int i=0; i<res.size(); i++)
    cout << res[i] << " ";
  cout << endl;

  return 0;
}


vector <double> linearRelaxation(vector <int> &vals, vector <int> &weis, int lim)
{
  vector <pair <double, int> > vpw;
  int totalWeight = 0, totalValue = 0;
  vector <pair <int, double> > sol;
  vector <double> ret;

  cout << "[items]" << endl;
  for (int i=0; i<vals.size(); i++)
    cout << vals[i] << " ";
  cout << endl;
  for (int i=0; i<weis.size(); i++)
    cout << weis[i] << " ";
  cout << endl;

  for (int i=0; i<ITEM_NUM; i++)
    {
      pair <double, int> p ((double)vals[i] / weis[i], i);
      vpw.push_back(p);
    }

  sort(vpw.rbegin(), vpw.rend());

  for (int i=0; i<vpw.size(); i++)
    {
      if (totalWeight < lim)
	{
	  if ((lim - totalWeight) >= weis[vpw[i].second])
	    {
	      totalWeight += weis[vpw[i].second];
	      totalValue += vals[vpw[i].second];
	      pair <int, double> p (vpw[i].second, 1);
	      sol.push_back(p);
	    }
	  else
	    {
	      double realTerm = (double)(lim - totalWeight) / weis[vpw[i].second];
	      totalWeight = lim;
	      totalValue += vals[vpw[i].second] * realTerm;
	      pair <int, double> p (vpw[i].second, realTerm);
	      sol.push_back(p);
	    }
	}
      else
	{
	  pair <int, double> p (vpw[i].second, 0);
	  sol.push_back(p);
	}
    }
  cout << totalValue << endl;
  sort(sol.begin(), sol.end());

  ret.push_back(totalValue);

  for (int i=0; i<sol.size(); i++)
    ret.push_back(sol[i].second);

  return ret;
}
