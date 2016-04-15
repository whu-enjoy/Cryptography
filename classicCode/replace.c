/*******************************************************************************
  程序员        : enjoy
  最后修改时间  : 2016年4月15日 16:07:45
  代码功能      : 简单的单表代替密码,所有字符用字符表右边K(10)的位置的字符代替
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 40
#define K 10

int main(void)
{
    char input[SIZE] = {0};
	char output[SIZE] = {0};
	
	int i = 0;
	int strLen = 0;
	
	printf("please input a string:");
	scanf("%s",input);
	strLen = strlen(input);
	
	for (i = 0; i < strLen; i++)
	{
		output[i] = (input[i] - 'a' + K) % 26  + 'a'; //用右边K个偏移的字符代替
	}

	printf("you input string is         : %s\n",input);
	printf("after encrypt the string is : %s\n",output);

	system("pause");
	return 0;
}