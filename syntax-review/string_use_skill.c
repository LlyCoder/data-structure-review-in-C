# include <stdio.h>

int main() {
	
	//在C语言中，定义字符串编译器会在字符串末尾追加 '\0' 为字符串结束标志 
	char str[] = "Lly"; //数组元素为  'L' 'l'  'y' '\0'
	int i = 0;
	while (str[i] != '\0') {
		printf("%c \n", str[i]);
		i++;
	}
	
	return 0;
}
/*

L
l
y

*/