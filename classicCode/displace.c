/*******************************************************************************
  程序员        : enjoy
  最后修改时间  : 2016年4月15日 16:07:45
  代码功能      : 简单的置换密码,讲输入的数据逆序排列后,
                  每隔K个数据(这里是5)一组输出
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 40        //输入字符串大小
#define GROUPLEN 5     //分组大小

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
	strLen = strlen(input);        //获取输入数组长度
	
	for (incount = strLen-1,outcount = 0; incount >= 0; incount--)
	{
		if (32 != input[incount])          //如果输入的不是空格则复制给输出字符串
		{
			output[outcount] = input[incount];
			outcount++;
			count++;
		}
		if (GROUPLEN == count)             //每隔五个数据输出一个空格
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