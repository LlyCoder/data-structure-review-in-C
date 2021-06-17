/*
�˻ʺ�������һ���Թ�������Ϊ���������⣺����ܹ���8��8�Ĺ������������Ϸ��ð˸��ʺ�ʹ���κ�һ���ʺ��޷�ֱ�ӳԵ������Ļʺ�
Ϊ�˴ﵽ��Ŀ�ģ��������ʺ󶼲��ܴ���ͬһ�����С����л�б���ϡ�
�˻ʺ���������ƹ�Ϊ��һ���n�ʺ�ڷ����⣺��ʱ���̵Ĵ�С��Ϊn��n�����ʺ����Ҳ���n�����ҽ���n = 1��n �� 4ʱ�����н⡣

*/

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100;
int solution[MAXN];	//solution[i]=j ��ʾ���̵ĵ�i�е�j�з��лʺ�
int cnt;  //������
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
		int j = solution[i];  //�ʺ�������
		//��ͻ�жϣ���Ϊ���аڷţ����ϲ����ͻ�������ж� 
		//1.������������ȣ���ͬһ�У� 2.�����Խ��ߣ�б��-1���������к���ȣ�  3.�ڸ��Խ��ߣ�б��+1����������ֻ����ȣ� 
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
		solution[row] = col;  //��¼�������ڵ�������
		DFS(row + 1);
	}
}

int main() {
	N = 8;
	DFS(0);  //��0�п�ʼ�ڷ�
	printf("N = %d, total solutions: %d\n", N, cnt);
	return 0;
}
