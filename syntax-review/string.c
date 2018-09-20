# include <stdio.h>
# include <string.h>


int main() {
	//C语言中没有字符串类型，C语言用以'\0'为终止元素的一维字符数组来表示字符串;
	//下面的语句的本质是 char str1[20] = {'a', 'b', 'c', '\0'}; 
	char str1[20] = "abc";  //不用加 '/0' ，编译器会自动在数组末尾追加 '\0' 
	//利用一维字符数组定义字符串 
	char str2[20] = {'l', 'y', '\0'};
	
	char str3[20];
	
	
	printf("%s\n", str1); // abc
	printf("%s\n", str2); // ly
	
	//一些字符串操作方法
	//strcpy(a, b); 把b的内容复制给a 
	strcpy(str3, str1);
	//strcat(a, b);  把b的内容连接到a上
	strcat(str1, str2); 
	
 	printf("strcpy( str3, str1) :  %s\n", str3 ); //strcpy( str3, str1) :  abc
 	printf("strcat( str1, str2):   %s\n", str1 ); // strcat( str1, str2):   abcly
 	
 	//strlen(str) 返回字符串长度 （元素个数，不包含'\0'） 
	 
	return 0; 
}