/*******************************************************************************
  ����Ա        : enjoy
  ����޸�ʱ��  : 2016��4��15�� 16:07:45
  ���빦��      : Vernam����,�������������Կ����ģ������
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 40

int main(void)
{
    char input[SIZE] = {0};
	char keyt[SIZE] = {0};
	char output[SIZE] = {0};
    
	int i = 0;
	int j = 0;
	int strLen = 0;
	int temp = 0;
	
	printf("please input a string:");
	scanf("%s",input);
	printf("please input the keyt:");
	scanf("%s",keyt);
	strLen = strlen(input);
	
	for (i = 0; i < strLen; i++)
	{
		output[i] = keyt[i] ^ input[i];  //��λ���
	}

	printf("you input string is         \t: %s \t",input);
	for (i = 0; i < strLen; i++)
	{
		temp = input[i];
		for (j = 0; j < 8; j++)         //�����Ӧ��λ������
		{
			printf("%d",temp/128);      //ÿ��ȡ��λ
			temp = 255&(temp<<1);       //Ȼ������һλ
		}
		printf(" ");
	}
	printf("\n");
	printf("you input keyt is           \t: %s \t",keyt);
	for (i = 0; i < strLen; i++)
	{
		temp = keyt[i];
		for (j = 0; j < 8; j++)
		{
			printf("%d",temp/128);
			temp = 255&(temp<<1);
		}
		printf(" ");
	}
	printf("\n");
	printf("after encrypt the string is \t: %s \t",output);
	for (i = 0; i < strLen; i++)
	{
		temp = output[i];
		for (j = 0; j < 8; j++)
		{
			printf("%d",temp/128);
			temp = 255&(temp<<1);
		}
		printf(" ");
	}
	printf("\n");

	system("pause");
	return 0;
}