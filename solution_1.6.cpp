#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> rotate_90(const vector<vector<int>>& matrix)
{
    vector<vector<int>> ret;
    int N = matrix.size();
    //initialize the return matrix
    ret.resize(N);
    for (int i=0; i<N; ++i) {
        ret[i].resize(N);
    }

    //rows
    for (int i=0; i<N; ++i) {
        //coloumns
        for (int j=0; j<N; ++j) {
            ret[j][N-i-1] = matrix[i][j];
        }
    }

    return ret;
}

void rotate_90_in_place(vector<vector<int>>& matrix)
{
    int N = matrix.size();
    if (N<=1) return;

    // 3 swaps
    for (int i=0; i<N/2; ++i) {
        for (int j=0; j<(N+1)/2; ++j) {
            swap(matrix[i][j], matrix[j][N-1-i]);
            swap(matrix[i][j], matrix[N-1-j][i]);
            swap(matrix[N-1-j][i], matrix[N-1-i][N-1-j]);
        }
    }   
}

void print_matrix(const vector<vector<int>>& matrix)
{
    int N = matrix.size();
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> test_matrix;
    test_matrix.resize(3);
    test_matrix[0].resize(3);
    test_matrix[1].resize(3);
    test_matrix[2].resize(3);
    test_matrix[0][0] = 1;
    test_matrix[0][1] = 2;
    test_matrix[0][2] = 3;
    test_matrix[1][0] = 4;
    test_matrix[1][1] = 5;
    test_matrix[1][2] = 6;
    test_matrix[2][0] = 7;
    test_matrix[2][1] = 8;
    test_matrix[2][2] = 9;

    print_matrix(test_matrix);
    auto ret = rotate_90(test_matrix);
    print_matrix(ret);
    rotate_90_in_place(test_matrix);
    print_matrix(test_matrix);
}
            
