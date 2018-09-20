# include <stdio.h>

int g;

int main() {
	//全局变量在函数内依然可见 
	g = 20;
	printf("g：%d", g); // 20
	//局部变量可以与全局同名，只在函数内有效 
	int g = 30;
	printf("g：%d", g);  // 30
	
	return 0;
}

