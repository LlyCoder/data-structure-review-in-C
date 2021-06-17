#include <stdio.h>
#include <stdlib.h> 

/*
求所在节点所在层数 图3.png 
方案1： 设置全局变量layer当进入递归时layer+1，当左右子树都遍历完仍未找到则需要回退到上一层，layer-1
设置flag可以在找到节点后退出遍历，节约开校

方案2： 使用参数传递(值传递) 

*/

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


int layer = 0;
int flag = 0; 

int getNodeLayer1(Node* root, int elem) {
	if(root == NULL) return;
	layer++; 
	if(flag == 1) return;
	if(root->data == elem) {
		printf("所在层数：%d\n", layer);
		flag = 1;
		return;
	}
	getNodeLayer1(root->left_child, elem);
    getNodeLayer1(root->right_chlid, elem);
	layer--;	 
}

int isFinded = 0;

int getNodeLayer2(Node* root, int elem, int layer) {
	if(root == NULL) return;
	if(isFinded == 1) return;
	if(root->data == elem) {
		printf("所在层数：%d\n", layer);
		isFinded = 1;
		return;
	}
	getNodeLayer2(root->left_child, elem, layer+1);
	getNodeLayer2(root->right_chlid, elem, layer+1);
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
	
	getNodeLayer1(root, 7); 
	
	getNodeLayer2(root, 7, 1);
	
	return 0;
}
