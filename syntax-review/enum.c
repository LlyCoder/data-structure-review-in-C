# include <stdio.h>

int main () {
	//定义枚举类型 
	//第一个枚举成员默认值为0，后面的成员都在前一个成员的基础上加 1 ，这里我们限定第一个成员为 1 
	enum DAY {
		MON = 1, TUE, WED, THU, FFI, SAT, SUN
	};
	
	enum season = {spring, summer=3, autumn, winter}; // 0 3 4 5
	
	
	
	//定义枚举变量
	//1. 先创建枚举类型再定义变量 
	enum DAY = {
		mon = 1, tue, wed, thu. fri ,sat, sun 
	};
	enum DAY day;
	
	//2. 创建枚举类型的同时创建枚举变量 
	enum DAY = {
		mon = 1, tue, wed, thu, fri, sta, sun
	} day;
	
	//3. 省略枚举类型直接创建枚举变量
	enum {
		mon = 1, tue, wed, thu, fri, sta, sun
	} day;
	
	return 0;
}