#include <iostream>

using namespace std;

#define ROWS    15
#define COLS    15

// let's put the triangle into a 2d array
int triangle[ROWS][COLS] = {    { 75 },
                                { 95, 64 },
                                { 17, 47, 82 },
                                { 18, 35, 87, 10 },
                                { 20, 04, 82, 47, 65, },
                                { 19, 01, 23, 75, 03, 34 },
                                { 88, 02, 77, 73, 07, 63, 67 },
                                { 99, 65, 04, 28, 06, 16, 70, 92 },
                                { 41, 41, 26, 56, 83, 40, 80, 70, 33 },
                                { 41, 48, 72, 33, 47, 32, 37, 16, 94, 29 },
                                { 53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14 },
                                { 70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57 },
                                { 91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48 },
                                { 63, 66, 04, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31 },
                                { 04, 62, 98, 27, 23,  9, 70, 98, 73, 93, 38, 53, 60, 04, 23 } };


/*
test data
#define ROWS    4
#define COLS    4

// let's put the triangle into a 2d array
int triangle[ROWS][COLS] = {    { 3 },
                                { 7, 4 },
                                { 2, 4, 6 },
                                { 8, 5, 9, 3 } };
*/

int main()
{
    int rowmax;
    
    for (int row=1;row<ROWS;row++)
    {
        rowmax=0;
        
        // just check the numbers above each cell, sum the max with current one and write it in the cell
        for (int col=0;col<row+1;col++)
        {
            int max=0;
            
            if (col>=1)    
            {
                max=triangle[row-1][col-1];
            }
            
            if (col<=row)
            {
                if (max<triangle[row-1][col])
                    max=triangle[row-1][col];
            }
            
            cout << triangle[row][col] << "-";
            
            triangle[row][col]+=max;
            
            cout << triangle[row][col] << " ";
            
            if (triangle[row][col]>rowmax)
                rowmax=triangle[row][col];
        }
        
        cout << "\r\n";
    }
    
    cout << rowmax << "\r\n";
    return 0;
}

