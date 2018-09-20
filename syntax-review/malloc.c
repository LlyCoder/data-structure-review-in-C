#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	//一般的我们一直内存大小，直接声明获取
	char name[100];
	strcpy(name, "lly");
	printf("name: %s\n", name);
	
	//未知大小需要动态内存分配
	char *p;
	//char *表示将申请下来的空间以char的类型存储（即1个字节当做一个字符） 
	//malloc() 只接受一个参数就是申请多少 字节 空间 
	p = (char *)malloc(30 * sizeof(char));
	if(p == NULL) {
		printf("申请内存空间失败！\n");
	} else {
		strcpy(p, "这里的空间是动态分配来的");
		printf("%s\n", p);
	}
	//动态申请的空间要手动释放掉，避免内存泄漏
	free(p); 
	
	return 0; 
}