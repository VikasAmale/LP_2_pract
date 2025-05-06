#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isSafe(const vector<int> &board, int row, int col)
{
	for (int i = 0; i < row; ++i)
	{
		if (board[i] == col || abs(board[i] - col) == row - i)
			return false;
	}

	return true;
}

void display(const vector<int> &board, int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << (board[i] == j ? "0 " : ". ");
		}

		cout << endl;
	}
}

bool N_queen(vector<int> &board, int row, int n)
{
	if (row == n)
	{
		display(board, n);
		return true;
	}

	for (int k = 0; k < n; ++k)
	{
		if (isSafe(board, row, k))
		{
			board[row] = k;
			if (N_queen(board, row + 1, n))
			{
				return true;
			}
		board[row] = -1;
		}
	}

	return false;
}

int main()
{
	int n;
	cout << "Enter n: ";

	cin >> n;
	vector<int> board(n, -1);
	if (!N_queen(board, 0, n))
		cout << "No solution\n";
	return 0;
}