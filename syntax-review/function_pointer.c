# include <stdio.h>

int max(int a, int b);

int main() {
	int a, b,c, maxnum;
	//����ָ�룬�˴���&��ʡ�� 
	int (*p)(int,int) = &max; 
	printf("����������������������\n");
	scanf("%d %d %d", &a, &b, &c);
	maxnum = p(p(a,b), c);
	printf("������ǣ� %d\n", maxnum);
	
	return 0;
}

int max(int a, int b){
	return a>b ? a:b;
}