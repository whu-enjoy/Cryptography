<pre>
这个文件夹下的代码是几个古典密码的C语言代码实现

displace.c   
    简单的置换密码,讲输入的数据逆序排列后,每隔K个数据(这里是5)一组输出
    
replace.c
    简单的单表代替密码,所有字符用字符表右边K(10)的位置的字符代替
    
caesar.c
    类似凯撒密码,通过输入的密文穷举找出所有可能明文
    
vernam.c
    Vernam密码,输入的明文与密钥进行模二运算

conbination.c
	将四个密码的代码集中到一起
	int Displace(void) 简单的置换密码
	int Replace(void)  简单的单表代替密码
	int Vernam(void)   Vernam密码
	int Caesar(void)   凯撒密码

</pre>	
