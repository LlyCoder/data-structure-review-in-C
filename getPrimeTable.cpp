/*���������⣬ǰ�����Ϊ����

��1��n��n������Χ��һ��Բ��������������2�����ڵ�������ӣ������Ϊ��������ô������ͳ�Ϊ��������

��������1-6����ɵ�һ�����������������ʾ��`[1, 4, 3, 2, 5, 6]`����һλ�̶�Ϊ1��

*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 100;

bool isPrimeNum[MAXN];
vector<int> ans;
bool isUsed[MAXN];
int N;

void getPrimeTable() {	//ɸѡ��������
	fill(isPrimeNum, isPrimeNum + MAXN, true);	//�ȼ��趼������
	isPrimeNum[0] = isPrimeNum[1] = false;
	for (int i = 2; i < MAXN; i++) {	//��2��ʼ����Ϊ2����С������
		if (isPrimeNum[i]) {
			//��i�ı���ȫ�����óɷ�����
			//����i=2�����4��6��9...���óɷ�����
			//��i=3�����6��9��12��15...���óɷ�����
			for (int j = 2 * i; j < MAXN; j += i) {	//ע���forѭ����д�������׳���
				isPrimeNum[j] = false;
			}
		}
	}
}

void DFS(int index) {
	if (index >= N) {
		int temp = ans[0] + ans[index - 1];	//�жϵ�һ���������һ������Ӻ��Ƿ�������
		if (isPrimeNum[temp] == false) return;
		//cpp 11 range-based for 
		for (int x : ans) {
			printf("%d ", x);
		}
		printf("\n");
		return;
	}
	//1�̶� 2��ʼ 
	for (int i = 2; i <= N; i++) {
		if (isUsed[i]) continue;
		int temp = ans[index - 1] + i;
		if (isPrimeNum[temp] == false) {
			continue;	//��֦
		}
		ans.push_back(i);
		isUsed[i] = true;
		DFS(index + 1);
		ans.pop_back();
		isUsed[i] = false;
	}
}

int main() {
	getPrimeTable();

	N = 4;
	ans.push_back(1);	//��������һ�����̶���1
	DFS(1);	//�ӵڶ�������ʼ����

	return 0;
}
