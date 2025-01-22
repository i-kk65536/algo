#include <iostream>
#include <vector>
using namespace std;

struct Matrix
{
    int row;
    int column;

    Matrix(int row = 0, int column = 0) : row(row), column(column) {}
};

int calc_multiplication(const vector<Matrix>& mat_chain)
{
    
}

int main()
{
    int mat_num;
    cin >> mat_num;
    vector<Matrix> mat_chain(mat_num);
    for (int i = 0; i < mat_num; i++)
    {
        cin >> mat_chain[i].row >> mat_chain[i].column;
    }

    cout << calc_multiplication(mat_chain) << endl;
}