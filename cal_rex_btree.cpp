/*
求表达式树 2.png 

第一行给出节点的个数N，每个节点的编号为0 ~ N-1

接下来N行每行分别给出：

该节点的编号、该节点的操作数/操作符、该节点的左孩子编号、右孩子编号（-1表示NULL）

输出格式：

第一行输出该表达式树的中缀表达式，该用括号的地方需要用括号括起来。

第二行输出该表达式树的前缀表达式。

第二行输出该表达式树的后缀表达式。

第四行输出该表达式树的计算结果，保留两位小数。

结论： 
先序遍历 输出 前缀表达式 
后序遍历 输出 后缀表达式
中序遍历 除去根节点运算和叶子结点加括号 输出 中缀表达式 
*/



#include <iostream>
using namespace std;

typedef struct node {
	char data;          //为了简化，直接用char型存运算符和值 
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
		//叶子结点必是数，直接输出 
		printf("%c ", root->data);
	}
	else {
		//非叶子节点除去第一层运算均要加括号
		//在遍历左子树前加左括号，在遍历柚子树后加右括号 
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
//叶子结点是操作数，非叶节点是操作符 
double calRexTree(Node* root) {
	if(root == NULL) return 0;
	if (root->lchild == NULL && root->rchild == NULL) {
		return root->data - '0';   //叶子是数，char强制转double 
	}
	double l_num = calRexTree(root->lchild);
	double r_num = calRexTree(root->rchild);
	return cal(l_num, r_num, root->data);
	
}

int main() {
	
	int N;          //节点数 
	scanf("%d\n", &N);
    Node* nodes = new Node[N];
	for (int i=0; i<N; i++) {
		int index;  //节点编号 
		char data;  //节点值 
		int l_index,r_index;    //左右孩子的编号 
		scanf("%d %c %d %d", &index, &data, &l_index, &r_index);
		//构建节点 
		nodes[index].data = data;
	    nodes[index].lchild = (l_index != -1? &nodes[l_index] : NULL);
		nodes[index].rchild = (r_index != -1? &nodes[r_index] : NULL);		
	}
	Node* root = &nodes[0];   //拿到树的根节点 
	

	
	//输出前缀表达式
	preOrder(root);
	printf("\n");  
	
		
	//输出中缀表达式
	//inOrder(Node* root, int layer)  
	//layer用于表示标记当前是否为根节点所在层次运算，若是无需加括号 
	inOrder(root, 0); 
	printf("\n"); 
	
	//输出后缀表达式
	postOrder(root);
	printf("\n");  
	
	//输出表达式计算值
	double ans = calRexTree(root); 
    printf("运算结果：%.2f", ans);
	
	return 0;
}
