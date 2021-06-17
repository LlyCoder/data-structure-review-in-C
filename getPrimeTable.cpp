/*素数环问题，前后相加为素数

将1到n这n个整数围成一个圆环，若其中任意2个相邻的数字相加，结果均为素数，那么这个环就成为素数环。

例如数字1-6所组成的一个素数环，用数组表示是`[1, 4, 3, 2, 5, 6]`（第一位固定为1）

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

void getPrimeTable() {	//筛选法求质数
	fill(isPrimeNum, isPrimeNum + MAXN, true);	//先假设都是素数
	isPrimeNum[0] = isPrimeNum[1] = false;
	for (int i = 2; i < MAXN; i++) {	//从2开始，因为2是最小的质素
		if (isPrimeNum[i]) {
			//把i的倍数全部设置成非质数
			//比如i=2，则把4、6、9...设置成非质数
			//若i=3，则把6、9、12、15...设置成非质数
			for (int j = 2 * i; j < MAXN; j += i) {	//注意该for循环的写法，容易出错
				isPrimeNum[j] = false;
			}
		}
	}
}

void DFS(int index) {
	if (index >= N) {
		int temp = ans[0] + ans[index - 1];	//判断第一个数和最后一个数相加后是否是质数
		if (isPrimeNum[temp] == false) return;
		//cpp 11 range-based for 
		for (int x : ans) {
			printf("%d ", x);
		}
		printf("\n");
		return;
	}
	//1固定 2开始 
	for (int i = 2; i <= N; i++) {
		if (isUsed[i]) continue;
		int temp = ans[index - 1] + i;
		if (isPrimeNum[temp] == false) {
			continue;	//剪枝
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
	ans.push_back(1);	//素数环第一个数固定是1
	DFS(1);	//从第二个数开始搜索

	return 0;
}
