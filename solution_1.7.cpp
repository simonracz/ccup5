#include <iostream>
#include <vector>
#include <set>

using namespace std;

void zero(vector<vector<int>>& matrix)
{
    set<int> rows;
    set<int> coloumns;

    int N = matrix.size();
    //mark
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            if (matrix[i][j] == 0) {
                rows.insert(i);
                coloumns.insert(j);
            }
        }
    }

    for (auto row : rows) {
        for (int i=0; i<N; ++i) {
            matrix[row][i] = 0;
        }
    }

    for (auto coloumn : coloumns) {
        for (int i=0; i<N; ++i) {
            matrix[i][coloumn] = 0;
        }
    }
}

int main()
{
    vector<vector<int>> matrix;
    matrix.push_back({1,0,0});
    matrix.push_back({1,0,1});
    matrix.push_back({1,1,1});

    zero(matrix);
    int N = matrix.size();
    for (int i=0; i<N ; ++i) {
        for (int j=0; j<N; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}



