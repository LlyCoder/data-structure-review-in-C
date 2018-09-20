# include <stdio.h> 

//没有在调用之前定义的函数必须在调用前声明 
void sayHello(int day);

int main(){
	int day = 9;

	sayHello(day);
	
	return 0;
}

void sayHello( int day) {
	printf("今天放假第%d天\n", day);
}

