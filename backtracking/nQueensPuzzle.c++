/* ************************************************************
	Title:		Class and functions to solve n Queens Puzzle
	Author:		Julian Schubel
	Contact:	schubeljulian@gmail.com

	History:
		Created: 	June 08 2022
		Completed:	June 08 2022
************************************************************* */

#include <iostream>

class nQueensPuzzle
{
	public:
		/* Constructor */
		/* Postcondition:
				noOfSolutions = 0;
				noOfQueens = queens;
				queensInRow is a pointer to the array to store the n-tuple
		 */
		nQueensPuzzle(int queens = 8);

		/* Function to determine whether a queen can be placed in row k and column i */
		/* Postcondition: 
				returns true is a queen can be placed in row k and column i otherwise false.
		*/
		bool canPlaceQueen(int k, int i);


		/* Function to determine all solutions to the n-queens puzzle using backtracking */
		/* Function is called with the value 0. */
		/* Postcondition:
				All n-tuples representing solutions of n-queens are generated and printed.
		 */
		void queensConfiguration(int k = 0);

		/* Function to ouput an n-tuple containing a solution to the n-queens puzzle. */
		void printConfiguration();

		/* Function to output the "board state" of the queens placement. */
		void printBoardState();

		/* Function to return the total number of solutions */
		/* Postcondition: 
				The value of noOfSolutions is returned.
		*/
		int solutionsCount();

	private:
		int noOfSolutions;
		int noOfQueens;
		int *queensInRow;
};

nQueensPuzzle::nQueensPuzzle(int queens)
{
	noOfQueens = queens;
	noOfSolutions = 0;
	queensInRow = new int[noOfQueens];
}

bool nQueensPuzzle::canPlaceQueen(int k, int i)
{
	/* We know no queen is in the same row as that is an illegal placement */
	for(int j = 0; j < k; j++)
	{
		/* Two queens are in sight if they are in the same column */
		/* Two queens are on a diagonal if the absolute value of the difference (distance) between their rows and columns are equal */
		/* Difference of columns: queensInRow[j]-i  */
		/* Difference of rows: j-k */
		if((queensInRow[j] == i) || abs(queensInRow[j]-i) == abs(j-k))
		{
			return false;	
		}
	}
	return true;
}

void nQueensPuzzle::queensConfiguration(int k)
{
	for(int i = 0; i < noOfQueens; i++)
	{
		if(canPlaceQueen(k, i))
		{
			queensInRow[k] = i; /* Place the kth queen in column i */
			if(k == noOfQueens - 1) /* All queens are placed */
			{
				printConfiguration(); /* Print the n-tuple */	
				printBoardState();
			}
			else
			{
				queensConfiguration(k+1); /* Determine placement for (k+1)th queen */
			}
		}
	}		
}

void nQueensPuzzle::printConfiguration()
{
	noOfSolutions++;
	std::cout << "(";
	for(int i = 0; i < noOfQueens - 1; ++i)
	{
		std::cout << queensInRow[i] << ", ";
	}	
	std::cout << queensInRow[noOfQueens-1] << ")" << std::endl;
}

void nQueensPuzzle::printBoardState()
{
	/* Output column label */
	std::cout << "  ";
	for(int i = 0; i < noOfQueens; ++i)
	{
		std::cout << " " << i << "  "; 
	}	
	std::cout << std::endl << " ";
	for(int i = 0; i < noOfQueens; ++i)
	{
		for(int j = 0; j < noOfQueens; ++j)
		{
			std::cout <<  " ---";
		}
		std::cout << std::endl << i;	
		for(int j = 0; j < noOfQueens; ++j)
		{
			std::cout <<  "| ";
			(queensInRow[i] == j) ? std::cout << "* " : std::cout << "  ";
		}
		std::cout << "|" << std::endl << " ";
	}
	for(int i = 0; i < noOfQueens; ++i)
	{
		std::cout << " ---";
	}
	std::cout << std::endl;
}

int nQueensPuzzle::solutionsCount()
{
	return noOfSolutions;
}

int main(int argc, char * argv[])
{
	nQueensPuzzle q(8);	
	q.queensConfiguration();
	return 0;
}
