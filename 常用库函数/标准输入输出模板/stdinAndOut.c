#define _CRT_SECURE_NO_WARNINGS 0
#include<stdio.h>
#include<string.h>

void in() {
    char ch = getchar();
    char buffer[24] = { 0 }; gets_s(buffer, 24); 
    int a; scanf_s("%d", &a);

    printf("[%c]", ch);
    printf("[%s]", buffer);
    printf("[%d]", a);

    // getchar() 可以读取空格和换行，读取了一个字符就会继续。(暂且认为，char相当于一个int)
    //  gets_s() 可以读空格，只有读取到换行才会继续。
    //              注意gets_s()使用后仍会读取\n(读取指针会在\n的后面)，但是赋值时是不带\n的。
    // scanf_s() 非常先进，去看文档，注意缓冲区未清空的bug。
}

void out() {
    char a = putchar('c');
    errno_t err = puts("1\n");
    int count = printf("%d", a);

    // putchar() 输出那个字符的ascii码。
    //    puts() 在输出了字符串后还会输出一个\n。输出成功则输出err = 0;
    //              (并不知道输出失败会输出什么，这太少见了)
    //  printf() 输入格式化字符串，输出成功输出的字符个数。
    //              在stdint.h和inttypes.h里面，有不少格式化字符的宏定义，可以看一看。
}

void err() {
    perror("[errMsg]");
    
    printf("打开文件出错[%s]", strerror(errno));
    printf("[%d]", errno);
    printf("%d", ferror(stdin));
    // perror() 在输出errMsg后，会补上一个{": %s\n", strerror(errno)}这样的格式化字符串。
    //              如果要保持一行，errMsg末尾不要加\n
    // strerror() 输入errno错误码，输出对应的错误信息字符串。他在<string.h>里面，但在这里仍然提一嘴。
}

void main() {
    err();
}

/* 各种清除缓冲区的办法 */
void scanfTest() {

    // fflush(stdin) 当今在很多环境下已经不能用了

    char a, b, c;
    scanf_s("%c", &a, 1); printf("%c", a); rewind(stdin);
    scanf_s("%c", &b, 1); printf("%c", b); 
    // 非常合适，但是编程题网站用文件模拟输入缓冲区所以不能用这种

    while ((c = getchar()) != '\n' && c != EOF); // 笨方法，一定能用。

    /*
原文链接：https://blog.csdn.net/qq_62044436/article/details/127336017
原文链接：https://blog.csdn.net/morn_l/article/details/134125407
    */
}



