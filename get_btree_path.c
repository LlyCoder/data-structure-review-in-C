#include <stdio.h>
#include <stdlib.h> 
#define MAXSIZE 52074

/*
求待查节点之间的路径 图3.png 
方案1： 利用全局数组（栈）,在遍历进入前当前节点入栈，左右孩子均访问完后（未找到）出栈（路径回退） 
  类似于求所在节点的层数的全局变量法 
方案2： 使用参数传递(值传递) 

*/
typedef  struct stack {
	int data[MAXSIZE];
	int top;
	
}Stack; 


typedef struct node {
	int data;
	struct node* left_child;
	struct node* right_chlid;
}Node;


Node* create_node(int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->left_child = node->right_chlid = NULL;
	return node;
}

void  set_node_pos(Node* root, Node* lchild, Node* rchild) {
	root->left_child  = lchild;
	root->right_chlid = rchild;
}

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

//基于先序遍历 
//避免找到节点后继续递归 
int flag = 0; 
int i;
void getBtreePath(Node* root, int elem, Stack* S) {
	if(root == NULL) return;
	if(flag == 1) return;
	pushStack(S, root->data);
	if(root->data == elem) {
		flag = 1;
		for(i=0; i<=S->top; i++) {
			printf("%d ", S->data[i]);
		}
	} else {
		getBtreePath(root->left_child, elem, S);
		getBtreePath(root->right_chlid, elem, S);
		popStack(S);
	}	
}


int main() {
	//生成节点 
	Node* root = create_node(1);
	Node* node2 = create_node(2);
	Node* node3 = create_node(3);
	Node* node4 = create_node(4);
	Node* node5 = create_node(5);
	Node* node6 = create_node(6);
	Node* node7 = create_node(7);
	Node* node8 = create_node(8); 
	//构建树 
	set_node_pos(root, node2, node3);
	set_node_pos(node2, node4, node5);
	set_node_pos(node3, NULL, node6);
	set_node_pos(node4, NULL, NULL); 
	set_node_pos(node5, node7, NULL);
	set_node_pos(node6, NULL, NULL);
	set_node_pos(node7, NULL, node8);
	set_node_pos(node8, NULL, NULL);
	
	Stack S;
	S.top = -1;
	//求根节点到节点7的路径 
	getBtreePath(root, 7, &S);

	
	return 0;
}
