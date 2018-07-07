#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int row, column;
    cout << "EQN v. 1.1.0" << endl << "Size of matrix" << endl << "Rows: ";
    cin >> row;
    cout << "Columns: ";
    cin >> column;
    double matrix[row][column];
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            cout << "x" << i+1 << "-" << j+1 << " ";
            cin >> matrix[i][j];
        }
    }
    for (int i = 0; i < row; i++)
    {
        double use = matrix[i][i];
        if (use == 0)
        {
            int j;
            for (j = i+1; j < row; j++)
            {
                if (matrix[j][i] != 0)
                {
                    double oldmatrix[column], newmatrix[column];
                    for (int k = 0; k < column; k++)
                    {
                        oldmatrix[k] = matrix[i][k];
                        newmatrix[k] = matrix[j][k];
                    }
                    for (int k = 0; k < column; k++)
                    {
                        matrix[i][k] = newmatrix[k];
                        matrix[j][k] = oldmatrix[k];
                    }
                    cout << endl << "Exchanging rows..." << endl << endl;
                    for (int k = 0; k < column; k++)
                    {
                        cout << "x" << i+1 << "-" << k+1 << " = " << matrix[i][k] << endl;
                    }
                    for (int k = 0; k < column; k++)
                    {
                        cout << "x" << j+1 << "-" << k+1 << " = " << matrix[j][k] << endl;
                    }
                    break;
                }
            }
            if (j == row)
            {
                cout << endl << "0's, half of the Gauss-Jordan" << endl;
                break;
            }
        }
        use = matrix[i][i];
        if (use != 1)
        {
            cout << endl << "x" << i+1 << "-" << i+1 << " is not 1, divide it by " << use << ". Result:" << endl;
            for (int j = 0; j < column; j++)
            {
                matrix[i][j] /= use;
                if (matrix[i][j] == -0) matrix[i][j] = 0;
                cout << "x" << i+1 << "-" << j+1 << " / " << use << " = " << matrix[i][j] << endl;
            }
        }
        for (int j = i+1; j < row; j++)
        {
            double cons = matrix[j][i];
            if (cons != 0)
            {
                cout << endl << "x" << j+1 << "-" << i+1 << " is not 0, do x" << j+1 << "-k = -x" << j+1 << "-" << i+1 << "*x" << i+1 << "-k+x" << j+1 << "-k, where k is every column of x" << j+1 << ". Result:" << endl;
                for (int k = i; k < column; k++)
                {
                    matrix[j][k] = -cons*matrix[i][k]+matrix[j][k];
                    cout << "x" << j+1 << "-" << k+1 << " = " << matrix[j][k] << endl;
                }
            }
        }
    }
    for (int i = row-1; i >= 0; i--)
    {
        if (matrix[i][i] == 0)
        {
            break;
        }
        for (int j = i-1; j >= 0; j--)
        {
            double cons = matrix[j][i];
            if (cons != 0)
            {
                cout << endl << "x" << j+1 << "-" << i+1 << " is not 0, do x" << j+1 << "-k = -x" << j+1 << "-" << i+1 << "*x" << i+1 << "-k+x" << j+1 << "-k, where k is every column of x" << j+1 << ". Result:" << endl;
                for (int k = i; k < column; k++)
                {
                    matrix[j][k] = -cons*matrix[i][k]+matrix[j][k];
                    cout << "x" << j+1 << "-" << k+1 << " = " << matrix[j][k] << endl;
                }
            }
        }
    }
    cout << endl << "Answer:" << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cout << "x" << i+1 << "-" << j+1 << " = " << matrix[i][j] << endl;
        }
    }
    cout << "Press ENTER key to exit." << endl;
    cin.ignore();
    cin.get();
    return 0;
}
