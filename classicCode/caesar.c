/*******************************************************************************
  ����Ա        : enjoy
  ����޸�ʱ��  : 2016��4��15�� 16:07:45
  ���빦��      : ���ƿ�������,ͨ���������������ҳ����п�������
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
	scanf("%[^\n]",input);       //��ȡ����\n���������ַ�
	strLen = strlen(input);

	printf("your input ciphertext is : %s\n",input);
	printf("\n��Կ\t����\n");
	for (i = 1; i < 27; i++)    //1-26���һ��
	{
		for (j = 0; j < strLen; j++)
		{
			if (32 == input[j]) //����ǿո񲻴���
			{
				output[j] = input[j];
			}
			else               //��ȥ��Կ
			{
				output[j] = (input[j] - 'a' - i + 26) % 26  + 'a';
			}
		}
		printf("%d \t: %s\n",i,output);
	}

	system("pause");
	return 0;
}
