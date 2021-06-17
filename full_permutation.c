#include <stdio.h>
#define MAXSIZE 52074
/*
全排列问题：
思路：基于DFS，设置全局标记数组标记当前节点是否被访问过
未访问过push，并在数组中标记已访问， 
 
*/

typedef  struct stack {
	int data[MAXSIZE];
	int top;
	
}Stack; 


int pushStack(Stack* S, int elem) {
	if(S->top == MAXSIZE-1) return 0;    //空间不够 
	S->top++;
    S->data[S->top] = elem;
	return 1;   //suc
}
//王道 pop(sqStack &s, &x)  x用于返回删除的节点 
int popStack(Stack* S) {
	if(S->top == -1) return 0;   // 空栈不出栈 
	S->top--;
	return 1;
}

//全排列
const int N = 3;
int visited[MAXSIZE];  //记录使用过的节点 



void init() {
	int i;
	for(i=0; i<N; i++) {
		 visited[i] = 0;
	}
}
//别瞎写全局变量啊，呜呜呜 
void DFS(int layer, Stack *S) {
	//遍历到最下一层再把本次序列输出 
 	if (layer == N) {
 		int i;
 		for (i=0; i<N; i++) {
 			printf("%d ", S->data[i]);
		 }
		printf("\n");
		return;
	 }
   //没到达底层，就反复将未使用的数字加入输出序列栈，到底后一次退回用过的数字
   //入栈就标记已使用，出栈标记未使用 
   	int i;
 	for(i=0; i<N; i++) { 
 		if(visited[i] == 0) { 
 			pushStack(S, i+1);  //N=3 出 123而不是012 
 			visited[i] = 1;
 			DFS(layer+1, S);
 			popStack(S);
 			visited[i] = 0;
		 }
		 
	 }
 	
 }

int main() {

	Stack S;
	S.top = -1;
	init();
    DFS(0, &S);  // 从零层次开始搜索 

	
	return 0;
}
