/*******************************************************************************
  程序员        : enjoy
  最后修改时间  : 2016年4月15日 16:07:45
  代码功能      : 四个密码代码的组合利用
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 40
#define GROUPLEN 5
#define K 10

int Displace(void); //简单置换密码
int Replace(void);  //简单的单表代替密码
int Vernam(void);   //Vernam密码,模二运算
int Caesar(void);   //凯撒密码

int main(void)
{
	int flag  = 0;

	for (;;) //循环接收子函数选择
	{
		system("cls");
		printf("1. Displace()\n");
		printf("2. Replace()\n");
		printf("3. Vernam()\n");
		printf("4. Caesar()\n");
		printf("0. Exit\n");
		printf("please input a num to choose a func :");
		scanf("%d",&flag);
		fflush(stdin);
		
		if (0 == flag)
		{
			break;
		}
		else if (1 == flag)
		{
			Displace();
		}
		else if (2 == flag)
		{
			Replace();
		}
		else if (3 == flag)
		{
			Vernam();
		}
		else if (4 == flag)
		{
			Caesar();
		}
		else
		{
			continue;
		}
	}

	system("pause");
	return 0;
}

/*****************************
    函数说明 :
        简单的置换密码,讲输入的数据逆序排列后,每隔K个数据(这里是5)一组输出
    输入参数 : 
        无
    输出参数 :
        0
*****************************/
int Displace(void)
{
    char input[SIZE] = {0};
	char output[SIZE] = {0};
	
	int incount = 0;
	int outcount = 0;
	int strLen = 0;
	int count = 0;
	
	printf("please input a string:");
	scanf("%[^\n]",input);
	strLen = strlen(input);
	
	for (incount = strLen-1,outcount = 0; incount >= 0; incount--)
	{
		if (32 != input[incount])
		{
			output[outcount] = input[incount];
			outcount++;
			count++;
		}
		if (GROUPLEN == count)
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

/*****************************
    函数说明 :
        简单的单表代替密码,所有字符用字符表右边K(10)的位置的字符代替
    输入参数 : 
        无
    输出参数 :
        0
*****************************/
int Replace(void)
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
		output[i] = (input[i] - 'a' + K) % 26  + 'a';
	}

	printf("you input string is         : %s\n",input);
	printf("after encrypt the string is : %s\n",output);

	system("pause");
	return 0;
}

/*****************************
    函数说明 :
        ernam密码,输入的明文与密钥进行模二运算
    输入参数 : 
        无
    输出参数 :
        0
*****************************/
int Vernam(void)
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
		output[i] = keyt[i] ^ input[i];
	}

	printf("you input string is         \t: %s \t",input);
	for (i = 0; i < strLen; i++)
	{
		temp = input[i];
		for (j = 0; j < 8; j++)
		{
			printf("%d",temp/128);
			temp = 255&(temp<<1);
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

/*****************************
    函数说明 :
        类似凯撒密码,通过输入的密文穷举找出所有可能明文
    输入参数 : 
        无
    输出参数 :
        0
*****************************/
int Caesar(void)
{
    char input[SIZE] = {0};
	char output[SIZE] = {0};
	int test[6] = {1,2,3,4,5};
    
	int i = 0;
	int j = 0;
	int keyt = 0;
	int strLen = 0;

	for (i = 0; i < 6; i++)
	{
		printf(" %d",test[i]);
	}
	printf("\n");
	scanf("%d",&test[0]);
	for (i = 0; i < 6; i++)
	{
		printf(" %d",test[i]);
	}
	printf("\n");

	printf("please input a ciphertext string:");
	scanf("%[^\n]",input);
	strLen = strlen(input);

	printf("your input ciphertext is : %s\n",input);
	printf("\n密钥\t明文\n");
	for (i = 1; i < 27; i++)
	{
		for (j = 0; j < strLen; j++)
		{
			if (32 == input[j])
			{
				output[j] = input[j];
			}
			else
			{
				output[j] = (input[j] - 'a' - i + 26) % 26  + 'a';
			}
		}
		printf("%d \t: %s\n",i,output);
	}

	system("pause");
	return 0;
}
