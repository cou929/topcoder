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
    vector <int> getHappy(vector <string> grid) {
        vector <int> ret;
        int row, col, i;
        int dx[] = {-1, 0, 1, 1, 1, 0, -1, -1};
        int dy[] = {1, 1, 1, 0, -1, -1, -1, 0};
        ret.push_back(0); ret.push_back(0); ret.push_back(0);

        for (row=0; row<grid.size(); row++) {
            for (col=0; col<grid[row].size(); col++) {
                if (grid[row][col] == '.') {
                    int o = 0, d = 0;
                    for (i=0; i<8; i++) {
                        if (0 <= row + dy[i] && row + dy[i] < grid.size() &&
                            0 <= col + dx[i] && col + dx[i] < grid[0].size() &&
                            grid[row + dy[i]][col + dx[i]] == '.') {
                            if (i % 2 == 0)
                                o++;
                            else
                                d++;
                        }
                    }
                    if (o == 0 && d == 0)
                        ret[0]++;
                    else if (o == 0 && d != 0)
                        ret[2]++;
                    else if (o != 0 && d == 0)
                        ret[1]++;
                }
            }
        }

        return ret;
    }
};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
