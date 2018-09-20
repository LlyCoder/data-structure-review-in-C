# include <stdio.h>

int max(int a, int b);

int main() {
	int a, b,c, maxnum;
	//函数指针，此处的&可省略 
	int (*p)(int,int) = &max; 
	printf("请输入三个整数，算出最大：\n");
	scanf("%d %d %d", &a, &b, &c);
	maxnum = p(p(a,b), c);
	printf("最大数是： %d\n", maxnum);
	
	return 0;
}

int max(int a, int b){
	return a>b ? a:b;
}