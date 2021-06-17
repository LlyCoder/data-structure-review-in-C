/*
八皇后问题是一个以国际象棋为背景的问题：如何能够在8×8的国际象棋棋盘上放置八个皇后，使得任何一个皇后都无法直接吃掉其他的皇后？
为了达到此目的，任两个皇后都不能处于同一条横行、纵行或斜线上。
八皇后问题可以推广为更一般的n皇后摆放问题：这时棋盘的大小变为n×n，而皇后个数也变成n。当且仅当n = 1或n ≥ 4时问题有解。

*/

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100;
int solution[MAXN];	//solution[i]=j 表示棋盘的第i行第j列放有皇后
int cnt;  //方案数
int N;

char chessboard[MAXN][MAXN];
void printSolution() {
	fill(chessboard[0], chessboard[0] + MAXN * MAXN, '*');
	for (int i = 0; i < N; i++) {
		int j = solution[i];
		chessboard[i][j] = '#';
		chessboard[i][N] = '\0';
	}
	printf("solution #%d\n", cnt);
	for (int i = 0; i < N; i++) {
		printf("%s\n", chessboard[i]);
	}
	printf("\n");
}

bool judge(int row, int col) {
	for (int i = 0; i < row; i++) {
		int j = solution[i];  //皇后坐在列
		//冲突判断：因为按行摆放，行上不会冲突，无需判断 
		//1.两则列坐标相等（在同一列） 2.不主对角线（斜率-1，两者行列和相等）  3.在副对角线（斜率+1，两者行列只差相等） 
		if (j == col || row + col == i + j || row - col == i - j)
			return false;
	}
	return true;
}

void DFS(int row) {
	if (row >= N) {
		cnt++;
		printSolution();
		return;
	}
	for (int col = 0; col < N; col++) {
		if (judge(row, col) == false) continue;
		solution[row] = col;  //记录该行所在的列坐标
		DFS(row + 1);
	}
}

int main() {
	N = 8;
	DFS(0);  //从0行开始摆放
	printf("N = %d, total solutions: %d\n", N, cnt);
	return 0;
}
