# include <stdio.h>
# include <stdlib.h>
# include <time.h>

int * get_random() {
	//C语言不支持返回局部变量的地址，除非变量被设置为static静态变量
	int static r[10];
	int i;
	 for (i=0; i<10; i++) {
 		r[i] = rand();
 		printf("r[%d] = %d\n", i, r[i]);
 	}
 	//返回的其实是数组首地址（指针） 
 	return r;
} 

int main() {
	int *p = &get_random();
	int i;
	for ()
	
	return 0;
}