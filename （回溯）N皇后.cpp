#include <vector>
#include <cmath>
using namespace std;

bool canPut(vector<int>& chessBoard, int row, int line) {
	for (int i = 0; i < row; ++i) {
		if (chessBoard[i] == line || abs(i - row) == abs(chessBoard[i] - line))
			return false;
	}
	return true;
}
int putChess(vector<int>& chessBoard, int row, int n) {
	if (row == n) 
		return 1;
	int result = 0;
	for (int i = 0; i < n; ++i) {
		if (canPut(chessBoard, row, i)) {
			chessBoard[row] = i;
			result += putChess(chessBoard, row + 1, n);
		}
	}
	return result;
}

int NQueen(int n) {
	vector<int> board(n);
	if (n < 1) return 0;
	return putChess(board, 0, n);
}
