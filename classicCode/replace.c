/*******************************************************************************
  ����Ա        : enjoy
  ����޸�ʱ��  : 2016��4��15�� 16:07:45
  ���빦��      : �򵥵ĵ����������,�����ַ����ַ����ұ�K(10)��λ�õ��ַ�����
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
		output[i] = (input[i] - 'a' + K) % 26  + 'a'; //���ұ�K��ƫ�Ƶ��ַ�����
	}

	printf("you input string is         : %s\n",input);
	printf("after encrypt the string is : %s\n",output);

	system("pause");
	return 0;
}