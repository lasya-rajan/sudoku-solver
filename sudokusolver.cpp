/* 
This is a C++ program to solve a 9X9 Sudoku puzzle utilizing a backtracking algorithm.
I will start without user input and construct solving algorithms, and go back and add UI.
This second version attempts to use iteration instead of recursion. 

USER INSTRUCTION: Fill the grid in main with any solvable sudoku puzzle, and the algorithm will solve it. 

*/ 


#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

// constants 

	const int N = 9;
	const int EMPTY = 0;

// functions 

	bool numberChecksOut(int grid[N][N], int row, int col, int num);


int main()
{

		int grid[N][N] = {{ 0, 0, 3,  5, 7, 8,  0, 9, 0 },
	                   {0, 0, 0,  0, 1, 0,  0, 4, 8 },
	                    {1, 0, 0,  0, 0, 0,  7, 3, 0 },

	                    {0, 0, 2,  7, 8, 3,  0, 0, 6 },
	                    {3, 0, 0,  4, 0, 6,  0, 0, 2 }, 
	                    {7, 0, 0,  1, 9, 2,  5, 0, 0 }, 

	                    {0, 9, 7,  0, 0, 0,  0, 0, 4 }, 
	                    {8, 3, 0,  0, 6, 0,  0, 0, 0 },
	                    {0, 6, 0,  8, 4, 7,  3, 0, 0 },};


	    //iterate through the grid, if a blank is found solve it 

	 int num = 0;
	 int row = 0;
	 int col = 0; 


	for(row = 0; row < N; row++)
		for (col = 0; col < N; col++ )
			if(grid[col][row] == EMPTY)
			{
				cout << "Found empty box at row: " << row << " and column: " << col << endl; 
				for (num = 1; num <= 9; num++)
					if(numberChecksOut(grid, row, col, num) == true)
					{
						grid[row][col] = num; 
						cout << "Solved one number!" << endl; 

					}
			}	

	cout << "Here is the solved grid:" << endl;
	cout << endl;

	for (row = 0; row < N; row++)
	{
	        for (col = 0; col < N; col++)
	        {
	            cout<<grid[row][col]<<"  ";
	        }

	        cout<<endl;


	}

	cout << endl;
	cout << endl; 
	cout << endl; 



} // end of int main  



bool numberChecksOut(int grid[N][N], int row, int col, int num)
{
	bool numUsedInRow = true;
	bool numUsedInBox = true;
	bool numUsedinCol = true; 

	for (row = 0; row < N; row++)
	{
		if(grid[row][col] == num)
			numUsedInRow = true; 
	}

	for (col = 0; col < N; col++)
	{
		if(grid[row][col] == num)
			numUsedinCol = true;
	}

	for(row = 0; row < N; row++)
	{
		for (col = 0; col < N; col++)
		{
			int rowWhereBoxStarts = row - row % 3;
			int colWhereBoxStarts = col - col % 3; 

			if (grid[row + rowWhereBoxStarts][col + colWhereBoxStarts] == num)
				numUsedInBox = true; 
		}
	}


	if ( (!numUsedInRow) && (!numUsedInBox) && (!numUsedinCol) )
	{
		return true;
	}
	else
		return false; 


} // end function numberChecksOut 

	



