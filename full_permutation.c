#include <stdio.h>
#define MAXSIZE 52074
/*
ȫ�������⣺
˼·������DFS������ȫ�ֱ�������ǵ�ǰ�ڵ��Ƿ񱻷��ʹ�
δ���ʹ�push�����������б���ѷ��ʣ� 
 
*/

typedef  struct stack {
	int data[MAXSIZE];
	int top;
	
}Stack; 


int pushStack(Stack* S, int elem) {
	if(S->top == MAXSIZE-1) return 0;    //�ռ䲻�� 
	S->top++;
    S->data[S->top] = elem;
	return 1;   //suc
}
//���� pop(sqStack &s, &x)  x���ڷ���ɾ���Ľڵ� 
int popStack(Stack* S) {
	if(S->top == -1) return 0;   // ��ջ����ջ 
	S->top--;
	return 1;
}

//ȫ����
const int N = 3;
int visited[MAXSIZE];  //��¼ʹ�ù��Ľڵ� 



void init() {
	int i;
	for(i=0; i<N; i++) {
		 visited[i] = 0;
	}
}
//��Ϲдȫ�ֱ������������� 
void DFS(int layer, Stack *S) {
	//����������һ���ٰѱ���������� 
 	if (layer == N) {
 		int i;
 		for (i=0; i<N; i++) {
 			printf("%d ", S->data[i]);
		 }
		printf("\n");
		return;
	 }
   //û����ײ㣬�ͷ�����δʹ�õ����ּ����������ջ�����׺�һ���˻��ù�������
   //��ջ�ͱ����ʹ�ã���ջ���δʹ�� 
   	int i;
 	for(i=0; i<N; i++) { 
 		if(visited[i] == 0) { 
 			pushStack(S, i+1);  //N=3 �� 123������012 
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
    DFS(0, &S);  // �����ο�ʼ���� 

	
	return 0;
}
