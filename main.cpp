#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int row, column;
    cout << "EQN v. 1.2.0" << endl << "Size of matrix" << endl << "Rows: ";
    cin >> row;
    cout << "Columns: ";
    cin >> column;
    // First, put all the values in the variable "matrix"
    double matrix[row][column];
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            cout << "x" << i+1 << "-" << j+1 << " ";
            cin >> matrix[i][j];
        }
    }
    // Start calculating
    for (int i = 0; i < row; i++)
    {
        double use = matrix[i][i]; // Get the position of the matrix at the same number of row and column, ex: x1-1, x2-2, x3-3, etc
        if (use == 0) // If use is equal to 0, try to exchange rows
        {
            int j;
            for (j = i+1; j < row; j++) // Start at the next row trying to exchange rows. It will perform some operations later, so it will check only next rows and not previous rows
            {
                if (matrix[j][i] != 0) // If true, then it is possible to exchange rows
                {
                    double oldmatrix[column], newmatrix[column];
                    for (int k = 0; k < column; k++) oldmatrix[k] = matrix[i][k];
                    for (int k = 0; k < column; k++)
                    {
                        matrix[i][k] = matrix[j][k];
                        matrix[j][k] = oldmatrix[k];
                    }
                    use = matrix[i][i];
                    cout << endl << "Exchanging rows..." << endl << endl;
                    for (int k = 0; k < column; k++) cout << "x" << i+1 << "-" << k+1 << " = " << matrix[i][k] << endl;
                    for (int k = 0; k < column; k++) cout << "x" << j+1 << "-" << k+1 << " = " << matrix[j][k] << endl;
                    break;
                }
            }
            if (j == row) // If true, then it is not possible to exchange rows
            {
                cout << endl << "Zeros, half of the Gauss-Jordan" << endl;
                break; // And stop calculating, because it could alter the answer
            }
        }
        if (use != 1) // If true, divide all the row by use, so use will be 1 too
        {
            cout << endl << "x" << i+1 << "-" << i+1 << " is not 1, divide it by " << use << ". Result:" << endl;
            for (int j = 0; j < column; j++)
            {
                matrix[i][j] /= use;
                if (matrix[i][j] == -0) matrix[i][j] = 0;
                cout << "x" << i+1 << "-" << j+1 << " / " << use << " = " << matrix[i][j] << endl;
            }
        }
        for (int j = i+1; j < row; j++) // Check the values in the same column, but in the next rows. We need them to be 0
        {
            double cons = matrix[j][i];
            if (cons != 0) // If true, perform operations to be 0
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
    // We have finished the first half, we need some values in the second half to be 0
    for (int i = row-1; i >= 0; i--)
    {
        if (matrix[i][i] == 0) break; // Because it could alter the answer
        for (int j = i-1; j >= 0; j--)
        {
            double cons = matrix[j][i];
            if (cons != 0) // Perform operations to be 0
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
    // Done, now print the answer on the screen
    cout << endl << "Answer:" << endl;
    for (int i = 0; i < row; i++) for (int j = 0; j < column; j++) cout << "x" << i+1 << "-" << j+1 << " = " << matrix[i][j] << endl;
    cout << "Press ENTER key to exit." << endl;
    cin.ignore();
    cin.get();
    return 0;
}
