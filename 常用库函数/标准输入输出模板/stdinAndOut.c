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

    // getchar() ���Զ�ȡ�ո�ͻ��У���ȡ��һ���ַ��ͻ������(������Ϊ��char�൱��һ��int)
    //  gets_s() ���Զ��ո�ֻ�ж�ȡ�����вŻ������
    //              ע��gets_s()ʹ�ú��Ի��ȡ\n(��ȡָ�����\n�ĺ���)�����Ǹ�ֵʱ�ǲ���\n�ġ�
    // scanf_s() �ǳ��Ƚ���ȥ���ĵ���ע�⻺����δ��յ�bug��
}

void out() {
    char a = putchar('c');
    errno_t err = puts("1\n");
    int count = printf("%d", a);

    // putchar() ����Ǹ��ַ���ascii�롣
    //    puts() ��������ַ����󻹻����һ��\n������ɹ������err = 0;
    //              (����֪�����ʧ�ܻ����ʲô����̫�ټ���)
    //  printf() �����ʽ���ַ���������ɹ�������ַ�������
    //              ��stdint.h��inttypes.h���棬�в��ٸ�ʽ���ַ��ĺ궨�壬���Կ�һ����
}

void err() {
    perror("[errMsg]");
    
    printf("���ļ�����[%s]", strerror(errno));
    printf("[%d]", errno);
    printf("%d", ferror(stdin));
    // perror() �����errMsg�󣬻Ჹ��һ��{": %s\n", strerror(errno)}�����ĸ�ʽ���ַ�����
    //              ���Ҫ����һ�У�errMsgĩβ��Ҫ��\n
    // strerror() ����errno�����룬�����Ӧ�Ĵ�����Ϣ�ַ���������<string.h>���棬����������Ȼ��һ�졣
}

void main() {
    err();
}

/* ��������������İ취 */
void scanfTest() {

    // fflush(stdin) �����ںܶ໷�����Ѿ���������

    char a, b, c;
    scanf_s("%c", &a, 1); printf("%c", a); rewind(stdin);
    scanf_s("%c", &b, 1); printf("%c", b); 
    // �ǳ����ʣ����Ǳ������վ���ļ�ģ�����뻺�������Բ���������

    while ((c = getchar()) != '\n' && c != EOF); // ��������һ�����á�

    /*
ԭ�����ӣ�https://blog.csdn.net/qq_62044436/article/details/127336017
ԭ�����ӣ�https://blog.csdn.net/morn_l/article/details/134125407
    */
}



