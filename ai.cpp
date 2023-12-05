#include <cmath>
#include <iostream>

#define n 3
#define m 4
#define UNASSIGNED -1
using namespace std;

bool UsedInCross(int cross[n][m], int num1)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            if (cross[i][j] == num1)
                return true;
    }
    return false;
}

bool isFill(int cross[n][m], int row, int col, int num1)
{

    if (row == 0 && col == 1) {

        if (UsedInCross(cross, num1)
            || (abs(num1 - cross[row][col + 1]) <= 1)
            || (abs(num1 - cross[row + 1][col]) <= 1)
            || (abs(num1 - cross[row + 1][col - 1]) <= 1)
            || (abs(num1 - cross[row + 1][col + 1]) <= 1))
            return false;
    }
    else if (row == 0 && col == 2) {
        if (UsedInCross(cross, num1)
            || (abs(num1 - cross[row][col - 1]) <= 1)
            || (abs(num1 - cross[row + 1][col]) <= 1)
            || (abs(num1 - cross[row + 1][col + 1]) <= 1)
            || (abs(num1 - cross[row + 1][col - 1]) <= 1))
            return false;
    }
    else if (row == 1 && col == 0) {
        if (UsedInCross(cross, num1)
            || (abs(num1 - cross[row - 1][col + 1]) <= 1)
            || (abs(num1 - cross[row][col + 1]) <= 1)
            || (abs(num1 - cross[row + 1][col + 1]) <= 1))
            return false;
    }
    else if (row == 1 && col == 3) {
        if (UsedInCross(cross, num1)
            || (abs(num1 - cross[row - 1][col - 1]) <= 1)
            || (abs(num1 - cross[row][col - 1]) <= 1)
            || (abs(num1 - cross[row + 1][col - 1]) <= 1))
            return false;
    }
    else if (row == 2 && col == 1) {
        if (UsedInCross(cross, num1)
        || (abs(num1 - cross[row -  1][col - 1]) <= 1)
        || (abs(num1 - cross[row - 1][col]) <= 1)
        || (abs(num1 - cross[row - 1][col + 1]) <= 1)
        || (abs(num1 - cross[row][col + 1]) <= 1))
            return false;
    }
    else if (row == 2 && col == 2) {
        if (UsedInCross(cross, num1)
        || (abs(num1 - cross[row][col - 1]) <= 1)
        || (abs(num1 - cross[row - 1][col]) <= 1)
        || (abs(num1 - cross[row - 1][col + 1]) <= 1)
        || (abs(num1 - cross[row - 1][col - 1]) <= 1))
            return false;
    }
    else if (row == 1 && col == 1) {
        if (UsedInCross(cross, num1)
        || (abs(num1 - cross[row][col - 1]) <= 1)
        || (abs(num1 - cross[row - 1][col]) <= 1)
        || (abs(num1 - cross[row - 1][col + 1]) <= 1)
        || (abs(num1 - cross[row][col + 1]) <= 1)
        || (abs(num1 - cross[row + 1][col + 1]) <= 1)
        || (abs(num1 - cross[row + 1][col]) <= 1))
            return false;
    }
    else if (row == 1 && col == 2) {
        if (UsedInCross(cross, num1)
        || (abs(num1 - cross[row][col - 1]) <= 1)
        || (abs(num1 - cross[row - 1][col]) <= 1)
        || (abs(num1 - cross[row + 1][col - 1]) <= 1)
        || (abs(num1 - cross[row][col + 1]) <= 1)
        || (abs(num1 - cross[row - 1][col - 1]) <= 1)
        || (abs(num1 - cross[row + 1][col]) <= 1))
            return false;
    }
    return true;
}


bool Location(int cross[n][m],
                        int& row, int& col)
{
    for (row = 0; row < n; row++)
        for (col = 0; col < m; col++) {
            if (cross[row][col] == UNASSIGNED)
                return true;
        }
    return false;
}

void printCross(int cross[n][m])
{
    for (int i = 0; i < n; i++) {
        if (i == 0 || i == n - 1)
            cout << " ";
        for (int j = 0; j < m; j++) {
            if (cross[i][j] == 0)
                cout << " ";
            else
                cout << cross[i][j] << " ";
        }
        cout << endl;
    }
}


bool Sol(int cross[n][m])
{
    int row, col;


    if (!Location(cross, row, col))
        return true;


    for (int num1 = 1; num1 <= 8; num1++) {


        if (isFill(cross, row, col, num1)) {


            cross[row][col] = num1;


            if (Sol(cross))
                return true;


            cross[row][col] = UNASSIGNED;
        }
    }
    return false;
}
int main()
{
    int cross[n][m] = { { 0, -1, -1, 0 },
                    { -1, -1, -1, -1 },
                    { 0, -1, -1, 0 } };
    if (Sol(cross) == true)
        printCross(cross);
    else
        cout << "Not possible";
    return 0;
}
