# include <stdio.h> 

//û���ڵ���֮ǰ����ĺ��������ڵ���ǰ���� 
void sayHello(int day);

int main(){
	int day = 9;

	sayHello(day);
	
	return 0;
}

void sayHello( int day) {
	printf("����żٵ�%d��\n", day);
}

