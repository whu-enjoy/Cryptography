/*******************************************************************************
  程序员        : enjoy
  最后修改时间  : 2016年4月15日 16:07:45
  代码功能      : 类似凯撒密码,通过输入的密文穷举找出所有可能明文
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 40

int main(void)
{
    char input[SIZE] = {0};
	char output[SIZE] = {0};
    
	int i = 0;
	int j = 0;
	int keyt = 0;
	int strLen = 0;

	printf("please input a ciphertext string:");
	scanf("%[^\n]",input);       //读取除了\n以外所有字符
	strLen = strlen(input);

	printf("your input ciphertext is : %s\n",input);
	printf("\n密钥\t明文\n");
	for (i = 1; i < 27; i++)    //1-26穷举一次
	{
		for (j = 0; j < strLen; j++)
		{
			if (32 == input[j]) //如果是空格不处理
			{
				output[j] = input[j];
			}
			else               //减去密钥
			{
				output[j] = (input[j] - 'a' - i + 26) % 26  + 'a';
			}
		}
		printf("%d \t: %s\n",i,output);
	}

	system("pause");
	return 0;
}
