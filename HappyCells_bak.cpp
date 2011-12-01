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

class HappyCells {
public:
    vector <string> _grid;

    bool check(int i, int j)
    {
        if (i >= 0 && j >= 0 && i < _grid.size() && j < _grid[0].size() && _grid[i][j] == '.')
            return true;
        return false;
    }

    vector <int> getHappy(vector <string> grid)
    {
        _grid = grid;
        int i, j;
        vector <int> ret;
        ret.push_back(0); ret.push_back(0); ret.push_back(0);

        for (i=0; i<grid.size(); i++)
            for (j=0; j<grid[i].size(); j++)
                {
                    if (grid[i][j] == '.')
                        {
                            int orth = 0;
                            int diag = 0;

                            if (check(i-1, j) || check(i+1, j) || check(i, j-1) || check(i, j+1))
                                orth = 1;
                            if (check(i-1, j-1) || check(i+1, j-1) || check(i-1, j+1) || check(i+1, j+1))
                                diag = 1;

                            if (orth == 0 && diag == 0)
                                ret[0]++;
                            if (orth == 0 && diag == 1)
                                ret[1]++;
                            if (orth == 1 && diag == 0)
                                ret[2]++;
                        }
                }

        return ret;
    }
};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
