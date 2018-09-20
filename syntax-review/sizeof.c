# include <stdio.h>
# include <float.h>

int main() {
	//使用sizeof查看数据类型或对象所占的字节大小
	printf("float所占大小为：%lu\n", sizeof(float)); 
	printf("float最大值为：%e\n", FLT_MAX);
	printf("float最小值为：%e\n", FLT_MIN);
	printf("float精度值为： %d\n", FLT_DIG);
	
	return 0;
}

/*

float所占大小为：4
float最大值为：3.402823e+038
float最小值为：1.175494e-038
float精度值为： 6

*/