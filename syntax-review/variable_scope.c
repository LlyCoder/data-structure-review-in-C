# include <stdio.h>

int g;

int main() {
	//ȫ�ֱ����ں�������Ȼ�ɼ� 
	g = 20;
	printf("g��%d", g); // 20
	//�ֲ�����������ȫ��ͬ����ֻ�ں�������Ч 
	int g = 30;
	printf("g��%d", g);  // 30
	
	return 0;
}

