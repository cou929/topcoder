#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define ITEM_NUM 10000
#define RANDOM_MIN 5
#define RANDOM_MAX 50

class branchAndCut
{
private:
  vector <int> values;
  vector <int> weights;
  int limit;
  int opt;
  vector <int> optPos;
  vector <double> _linearRelaxation(vector <int> &vals, vector <int> &weis, int lim);
  int _trv(vector <int> pos);
public:
  branchAndCut(vector <int> &val, vector <int> &wei, int limit);
  vector <int> getSolition(void);
};

branchAndCut::branchAndCut(vector <int> &val, vector <int> &wei, int lim)
{
  values = val;
  weights = wei;
  limit = lim;
  opt = 0;
}

vector <int> branchAndCut::getSolition(void)
{
  vector <int> tmp;
  for (int i=0; i<values.size(); i++)
    tmp.push_back(-1);

  _trv(tmp);

  vector <int> ret;
  ret.push_back(opt);
  ret.insert(ret.begin(), optPos.begin(), optPos.end());

  return ret;
}

vector <double> branchAndCut::_linearRelaxation(vector <int> &vals, vector <int> &weis, int lim)
{
  vector <pair <double, int> > vpw;
  int totalWeight = 0, totalValue = 0;
  vector <pair <int, double> > sol;
  vector <double> ret;

  //   cout << "[items]" << endl;
  //   for (int i=0; i<vals.size(); i++)
  //     cout << vals[i] << " ";
  //   cout << endl;
  //   for (int i=0; i<weis.size(); i++)
  //     cout << weis[i] << " ";
  //   cout << "\nlimit " << lim << endl;

  for (int i=0; i<vals.size(); i++)
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
  //  cout << totalValue << endl;
  sort(sol.begin(), sol.end());

  ret.push_back(totalValue);

  for (int i=0; i<sol.size(); i++)
    ret.push_back(sol[i].second);

  return ret;
}

int branchAndCut::_trv(vector <int> pos)
{
  int totalValue = 0, totalWeight = 0;
  bool isUnknown = false;
  vector <int> subValues, subWeights;
  vector <double> res;

  //   for (int i=0; i<pos.size(); i++)
  //     cout << pos[i] << " ";
  //   cout << endl;

  for (int i=0; i<pos.size(); i++)  
    {
      if (pos[i] == -1)
	{
	  isUnknown = true;
	  subValues.push_back(values[i]);
	  subWeights.push_back(weights[i]);
	}
      else
	{
	  totalValue += values[i] * pos[i];
	  totalWeight += weights[i] * pos[i];
	}
    }
     
  int lim = limit - totalWeight; 
  if (isUnknown)
    {
      res = _linearRelaxation(subValues, subWeights, lim);
      totalValue += res[0];

      if (totalValue < opt)
	return 0;

      int index = -1;
      for (int i=1; i<res.size(); i++)
	if (res[i] != 1 && res[i] != 0)
	  index = i;

      if (index != -1)
	{
	  for (int i=0, j=0; i<pos.size(); i++)
	    {
	      if (pos[i] == -1)
		j++;

	      if (j == index)
		index = i;
	    }

	  vector <int> tmp = pos;
	  tmp[index] = 1;
	  _trv(tmp);
	  tmp[index] = 0;
	  _trv(tmp);
	}
      else
	{
	  if (totalValue > opt)
	    {
	      opt = totalValue;

	      for (int i=0, j=0; i<pos.size(); i++)
		if (pos[i] == -1)
		  pos[i] = res[1 + j++];

	      optPos = pos;
	    }

	  return 0;
	}
    }
  return 0;  
}

int getRandom(int mini, int maxi);
//vector <int> peggingTest(vector <int> &vals, vector <int> &weis, int lim);

int main(void)
{
  vector <int> values;
  vector <int> weights;
  int limit = 0;

  for (int i=0; i<ITEM_NUM; i++)
    {
      values.push_back(getRandom(RANDOM_MIN, RANDOM_MAX));
      weights.push_back(getRandom(RANDOM_MIN, RANDOM_MAX));
      limit = getRandom(RANDOM_MIN, RANDOM_MAX);
    }

  for (int i=0; i<ITEM_NUM; i++)
    printf("[item %2d] value: %2d, weight: %2d\n", i, values[i], weights[i]);
  cout << "[Weight limit] " << limit << endl;

  //  vector <int> pegged = peggingTest(values, weights, limit);

  branchAndCut *model = new branchAndCut(values, weights, limit);

  vector <int> res = model->getSolition();


  cout << "Solution: " << res[0] << endl;
  for (int i=1; i<res.size(); i++)
    cout << res[i] << " ";
  cout << endl;

  return 0;
}

int getRandom(int mini = 0, int maxi = RANDOM_MAX)
{
  return mini + (int)(rand() * (maxi - mini + 1.0) / (1.0 + RAND_MAX));
}

vector <double> linearRelaxation(vector <int> &vals, vector <int> &weis, int lim, vector <int> flgs)
{
  vector <pair <double, int> > vpw;
  int totalWeight = 0, totalValue = 0;
  vector <pair <int, double> > sol;
  vector <double> ret;

  //   cout << "[items]" << endl;
  //   for (int i=0; i<vals.size(); i++)
  //     cout << vals[i] << " ";
  //   cout << endl;
  //   for (int i=0; i<weis.size(); i++)
  //     cout << weis[i] << " ";
  //   cout << "\nlimit " << lim << endl;

  for (int i=0; i<vals.size(); i++)
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
  //  cout << totalValue << endl;
  sort(sol.begin(), sol.end());

  ret.push_back(totalValue);

  for (int i=0; i<sol.size(); i++)
    ret.push_back(sol[i].second);

  return ret;
}

// vector <int> peggingTest(vector <int> &vals, vector <int> &weis, int lim)
// {
//   vector <double> res = linearRelaxation(vals, weis, lim);
//   vector <int> ret(-1, vals.size());

//   for (int i=1; i<res.size(); i++)
//     {
      
//     }
// }
