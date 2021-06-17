/*
�����������ֱ�����ʽ��������
ͼ 1.png 

*/

#include <stdio.h>
#include <stdlib.h> 
#define MAXNODESIZE 2021

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

void pre_order(Node* T) {
	if (T != NULL) {
		printf("%d ", T->data);
		pre_order(T->left_child);
		pre_order(T->right_chlid);
	}
}
void in_order(Node* T) {
	if(T != NULL) {
		in_order(T->left_child);
		printf("%d ", T->data);
		in_order(T->right_chlid);
	}
}

void post_order(Node* T) {
	if (T != NULL) {
		post_order(T->left_child);
		post_order(T->right_chlid);
		printf("%d ", T->data);
	}
}

//��α����Ƿǵݹ��㷨 
void level_order(Node* T) {
	if (T == NULL) return;
	Node* Queue[MAXNODESIZE];
	int front, rear = 0;
	Queue[rear++] = T;           //���ڵ����,���в��ղ��ϳ��� 
	while (front != rear) {
		Node* tem =  Queue[front++];
		printf("%d ", tem->data);
		if (tem->left_child != NULL)  {
			Queue[rear++] = tem->left_child;		
		}
		if(tem->right_chlid != NULL) {
			Queue[rear++] = tem->right_chlid;
		}
	}
	
	
}

//������
int max(int left_h, int right_h)  {
	if (left_h > right_h)  return left_h;
	else return right_h;	
}

int cal_tree_h(Node* T) {
  if (T == NULL)  return 0;
  int left_h = cal_tree_h(T->left_child);
  int right_h = cal_tree_h(T->right_chlid);
  return max(left_h, right_h) + 1;
  
}

int main() {
	//���ɽڵ� 
	Node* root = create_node(1);
	Node* node2 = create_node(2);
	Node* node3 = create_node(3);
	Node* node4 = create_node(4);
	Node* node5 = create_node(5);
	Node* node6 = create_node(6);
	Node* node7 = create_node(7);
	Node* node8 = create_node(8); 
	//������ 
	set_node_pos(root, node2, node3);
	set_node_pos(node2, node4, node5);
	set_node_pos(node4, NULL, node8); 
	set_node_pos(node5, NULL, node8);
	set_node_pos(node8, NULL, NULL);
	set_node_pos(node5, node6, NULL); 
	set_node_pos(node3, NULL, node7);
	set_node_pos(node7, NULL, NULL);
	
	//������� 
	pre_order(root);
	printf("\n");
	
	//�������
	in_order(root);
	printf("\n");
	
	//�������
	post_order(root);
	printf("\n");
	
	//��α��� 
	level_order(root);
	printf("\n");
	
	//������
	int tree_h = cal_tree_h(root);
	printf("����Ϊ��%d \n", tree_h);
	
	return 0;
}
