//һ��̨���ܹ���n�������һ�ο�����1����Ҳ������2�������ܹ��ж�����������
//��ɶ�̬�滮�����������ǵݹ�ר����ϰ 
#include <stdio.h>

int main() {
	
	int stairs; //n������
	printf("���������Ŀ��\n");
	scanf("%d", &stairs); 
	int output = cal_steps_methods(stairs); //������ 
	printf("��������%d\n",output);
	return 0;
}

int cal_steps_methods(int stairs) {
	if(stairs  == 1) return 1;
	if(stairs == 2)  return 2;
	//ÿһ���������ַ��� 
	return  cal_steps_methods(stairs - 1) + cal_steps_methods(stairs - 2); //������֮�� 
	
}
