# include <stdio.h>

//声明变量（不会创建内存空间） 
 extern  int a,b;
 extern float c;

int main() {
	//定义变量（会创建实际的内存空间） 
	int a,b;
	float c;
	
	//初始化变量
	a = 10;
 	b = 20;
 	c = a + b;
	
	return 0;
}