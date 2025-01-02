/* 简介：用于实验C预处理器相关知识
 * 来源：菜鸟教程: https://www.runoob.com/cprogramming/c-preprocessors.html
 */
#include <stdio.h>

// 预定义宏
void demo1()
{
   printf("File :%s\n", __FILE__ ); //当前日期，一个以 "MMM DD YYYY" 格式表示的字符常量。
   printf("Date :%s\n", __DATE__ ); //当前时间，一个以 "HH:MM:SS" 格式表示的字符常量。
   printf("Time :%s\n", __TIME__ ); //这会包含当前文件名，一个字符串常量。
   printf("Line :%d\n", __LINE__ ); //这会包含当前行号，一个十进制常量。
   printf("ANSI :%d\n", __STDC__ ); //当编译器以 ANSI 标准编译时，则定义为 1。
}

//字符串常量化运算符（#）,把一个宏的参数转换为字符串常量
#define AandB(A, B)  \
        printf(#A " and " #B "\n")

//标记粘贴运算符（##）,合并两个参数
#define tokenpaster(n) printf ("token" #n " = %d", token##n)


int main()
{
    demo1();

    AandB(1, 2);

    int token34 = 40;
    tokenpaster(34);
    return 0;
}