/*
����ʽ�� 2.png 

��һ�и����ڵ�ĸ���N��ÿ���ڵ�ı��Ϊ0 ~ N-1

������N��ÿ�зֱ������

�ýڵ�ı�š��ýڵ�Ĳ�����/���������ýڵ�����ӱ�š��Һ��ӱ�ţ�-1��ʾNULL��

�����ʽ��

��һ������ñ��ʽ������׺���ʽ���������ŵĵط���Ҫ��������������

�ڶ�������ñ��ʽ����ǰ׺���ʽ��

�ڶ�������ñ��ʽ���ĺ�׺���ʽ��

����������ñ��ʽ���ļ�������������λС����

���ۣ� 
������� ��� ǰ׺���ʽ 
������� ��� ��׺���ʽ
������� ��ȥ���ڵ������Ҷ�ӽ������� ��� ��׺���ʽ 
*/



#include <iostream>
using namespace std;

typedef struct node {
	char data;          //Ϊ�˼򻯣�ֱ����char�ʹ��������ֵ 
	struct node* lchild;
	struct node* rchild;
}Node;

void preOrder(Node* root) {
	if(root == NULL) return;
	printf("%c ", root->data);
	preOrder(root->lchild);
	preOrder(root->rchild);
}


void inOrder(Node* root, int layer) {
	if(root == NULL) return;
	if(root->lchild == NULL && root->rchild == NULL) {
		//Ҷ�ӽ���������ֱ����� 
		printf("%c ", root->data);
	}
	else {
		//��Ҷ�ӽڵ��ȥ��һ�������Ҫ������
		//�ڱ���������ǰ�������ţ��ڱ������������������ 
		if(layer > 0) printf("( ");
		inOrder(root->lchild, layer+1);	
		printf("%c ", root->data);
		inOrder(root->rchild, layer+1);
		if(layer > 0) printf(") ");				
	}
	
}

void postOrder(Node* root) {
	if(root == NULL)  return;
	postOrder(root->lchild);
	postOrder(root->rchild);
	printf("%c ", root->data);
	
}


double cal(double a, double b, char op) {
	switch (op) {
		case '+': return a + b;
	  	case '-': return a - b;
		case '*': return a * b;
		case '/': return a / b;
	}
	
}
//Ҷ�ӽ���ǲ���������Ҷ�ڵ��ǲ����� 
double calRexTree(Node* root) {
	if(root == NULL) return 0;
	if (root->lchild == NULL && root->rchild == NULL) {
		return root->data - '0';   //Ҷ��������charǿ��תdouble 
	}
	double l_num = calRexTree(root->lchild);
	double r_num = calRexTree(root->rchild);
	return cal(l_num, r_num, root->data);
	
}

int main() {
	
	int N;          //�ڵ��� 
	scanf("%d\n", &N);
    Node* nodes = new Node[N];
	for (int i=0; i<N; i++) {
		int index;  //�ڵ��� 
		char data;  //�ڵ�ֵ 
		int l_index,r_index;    //���Һ��ӵı�� 
		scanf("%d %c %d %d", &index, &data, &l_index, &r_index);
		//�����ڵ� 
		nodes[index].data = data;
	    nodes[index].lchild = (l_index != -1? &nodes[l_index] : NULL);
		nodes[index].rchild = (r_index != -1? &nodes[r_index] : NULL);		
	}
	Node* root = &nodes[0];   //�õ����ĸ��ڵ� 
	

	
	//���ǰ׺���ʽ
	preOrder(root);
	printf("\n");  
	
		
	//�����׺���ʽ
	//inOrder(Node* root, int layer)  
	//layer���ڱ�ʾ��ǵ�ǰ�Ƿ�Ϊ���ڵ����ڲ�����㣬������������� 
	inOrder(root, 0); 
	printf("\n"); 
	
	//�����׺���ʽ
	postOrder(root);
	printf("\n");  
	
	//������ʽ����ֵ
	double ans = calRexTree(root); 
    printf("��������%.2f", ans);
	
	return 0;
}
