/*******************************************************************************
  ����Ա        : enjoy
  ����޸�ʱ��  : 2016��4��15�� 16:07:45
  ���빦��      : �򵥵��û�����,������������������к�,
                  ÿ��K������(������5)һ�����
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 40        //�����ַ�����С
#define GROUPLEN 5     //�����С

int main(void)
{
    char input[SIZE] = {0};
	char output[SIZE] = {0};
    
	int incount = 0;
	int outcount = 0;
	int strLen = 0;
	int count = 0;
	
	printf("please input a string:");
	scanf("%[^\n]",input);
	strLen = strlen(input);        //��ȡ�������鳤��
	
	for (incount = strLen-1,outcount = 0; incount >= 0; incount--)
	{
		if (32 != input[incount])          //�������Ĳ��ǿո����Ƹ�����ַ���
		{
			output[outcount] = input[incount];
			outcount++;
			count++;
		}
		if (GROUPLEN == count)             //ÿ������������һ���ո�
		{
			output[outcount] = 32;
			outcount++;
			count = 0;
		}
	}

	printf("you input string is         : %s\n",input);
	printf("after encrypt the string is : %s\n",output);

	system("pause");
	return 0;
}