//一个台阶总共有n级，如果一次可以跳1级，也可以跳2级。求总共有多少总跳法。
//亦可动态规划，这里这里是递归专项练习 
#include <stdio.h>

int main() {
	
	int stairs; //n级阶梯
	printf("输入阶梯数目：\n");
	scanf("%d", &stairs); 
	int output = cal_steps_methods(stairs); //方案数 
	printf("方案数：%d\n",output);
	return 0;
}

int cal_steps_methods(int stairs) {
	if(stairs  == 1) return 1;
	if(stairs == 2)  return 2;
	//每一步都有两种方案 
	return  cal_steps_methods(stairs - 1) + cal_steps_methods(stairs - 2); //两方案之和 
	
}
