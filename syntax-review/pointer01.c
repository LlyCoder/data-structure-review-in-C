# include <stdio.h> 

int main() {
	//使用 & 取得变量所在的内存地址
	int var;
	int test_arr[12]; //未初始化的数组必须指出数组长度
	printf("var变量地址%p  test_arr的首地址是%p\n", &var, test_arr);// 数组名就是数组首地址，可以不用加& 
	
	
	//初始化指针并访问指针所指向变量的值 
	float pi = 3.14;
	float *pointer = &pi; //相当于 float *pointer; pointer = $pi; 
	printf("变量的地址是 %p  指针的值是 %p  指针指向的变量值为 %f\n", &pi, pointer, *pointer); 
	
	
	// 空指针： 当指针没有确切的值可以赋于， 应当为指针变量赋值NULL，NULL 指针是一个定义在标准库中的值为零的常量
	int *demo = NULL;
	printf("被赋值NULL的指针的值是：%p\n", demo); //被赋值NULL的指针的值是：00000000
	
		
	return 0;
} 
/*
var变量地址0060FF2C  test_arr的首地址是0060FEF0
变量的地址是 0060FEEC  指针的值是 0060FEEC  指针指向的变量值为 3.140000
被赋值NULL的指针的值是：00000000
*/