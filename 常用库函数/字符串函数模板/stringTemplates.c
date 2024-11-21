#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include<errno.h>
#define BUF_LENGTH 64
#define MAX_COUNT 5


/* ���ƺ�ƴ���ַ��� */
void cpyAndCat() {

    const char* src = "123456789";
    char buffer[BUF_LENGTH];
    errno_t err;
    err = strcpy_s(buffer, BUF_LENGTH, src);
    err = strncpy_s(buffer, BUF_LENGTH, src, MAX_COUNT);
    err = strcat_s(buffer, BUF_LENGTH, src);
    err = strcat_s(buffer, BUF_LENGTH, src, MAX_COUNT);
    
    // ��Ҫ��Դ�ַ���; ��Ҫ�õ�������; ������������;

    // ���п�ָ���쳣��
    //      _s�������Դ���VS�Ĵ��󲶻�������û��_s�򲻻ᱨ����Ҫ����Ա���⡣
    // �����鱨���������ȡ�
    //      dubugʱ���������Ժ������С�releaseû�б�����Ҫ�鱨���������ȡ�
    // �л��������̵�Σ�ա�
    //     ���ĸ�������������'\0', ֻ�������Ҫ��ӣ���˻��������ȱ������strlen()��MAX_COUNT�Ա�strlen()��

    // ������err = 0;
}

/* �Ƚ����ַ����Ĵ�С */
void cmp() {
    const char* src1 = "1234567";
    const char* src2 = "1234568";
    int cmp_result;
    cmp_result = strcmp(src1, src2);
    cmp_result = strncmp(src1, src2, MAX_COUNT);
    // ������Դ�ַ��������intʾ��ֵ(cmpʽ��)
    // ���п�ָ���쳣��
    // result == 0 ����ȣ� > 0 ��˵��ĳλ�ַ�str1>str2��('\0'����С�ַ�)
}

/* Ѱ���ַ������ַ��� */
void findSub() {
    const char* src = "123456765";
    char* addr;
    char ch = '5'; addr = strchr(src, ch);
    char rch = '5'; addr = strrchr(src, rch);
    char* sub = "567"; addr = strstr(src, sub);
    
    // �п�ָ���쳣��Խ�����Σ�ա�
    // ����srcƫ�ƣ�����ʱ��Ҫ�жϿ�ָ���Խ��
    // һ�ֳ�������� addr = strchr(addr + 1, ch); ��ʱ���ж�Խ��

    // �����ҵ���һ���ҵ��˵�ֵ�ĵ�ַ��û�ҵ��򷵻�NULL
}

/* ���ַ����� */
void span() {
    const char* src = "45654321";
    int count;
    char group1[] = "456"; count = strspn(src, group1);
    char group2[] = "123"; count = strcspn(src, group2);

    printf("%d", count);

    // strspn �������ӿ�ͷ�𵽷��ֵ�һ��������group1���ַ����м乲�ж��ٸ�����group1���ַ���
    // strcspn�������ӿ�ͷ�𵽷��ֵ�һ������group2���ַ����м乲�ж��ٸ�������group2���ַ���
    
    // һ�ֳ����÷��ǣ�������group����ӷǷ��ַ��ж��ַ����Ƿ�Ϸ���
    // ���ֶ���Ҫƫ��src��λ�ã���ʱ���жϿ�ָ���Խ�硣
}

/* �ָ��ַ��� */
void tok_s() {
    char src[] = "139-12345678";
    char* token = NULL;
    char* context = NULL;
    char* delim = "-";

    token = strtok_s(src, delim, &context);

    char* endbind = src + strlen(src);
    token = strtok(src, "-");
    context = (token != NULL) ? token + strcspn(token, "-") : src + strlen(src);
    if (context != endbind) context += 1;

    // Դ�ַ��������ǻ�����; һ�θı�����ֵ(token, context);
    // token�����src��ͷ�����һ��������delim�����ַ����ұ��˶�û���ҵ�����delim�����ַ����򷵻�NULL��
    // context�����token֮�������һ������delim�����ַ�����һλ��ַ��
    //      tokenΪNULL������token֮��û������delim�����ַ��ˣ��򷵻�Դ�ַ���\0��ַ��

    // ����������������ָ��ַ����ġ�
    // ��������Ҫƫ��src���ã���������ʹ�ý�context�õ�srcλ���ϵ����������õؽ���ƫ�ơ�
    // �����ʹ��strtok_s()����strtok, ���Ƕ�contextλ�õ���Ҫ�����жϡ�����strtok�����\0, ������֮ǰ��ԭ����\0��
    // strtok_s() ���� strtok() ���ƺ����ԡ�(���ٱ�����_s��������...)
}

/* ��int��ֵ���ַ��� */
void sprint() {
    int a = 12;
    
    char buffer[3] = { 0 };
    int rs = sprintf_s(buffer, 3, "%d", a);
    printf("%s", buffer);
    printf("[%d]", rs);
    // ��Ҫ��������Դ�ַ����Ǹ�ʽ���ַ�����
    // ע���ָ���쳣���в�Ҫ�鱨���������ȡ���Ȼ�л��������̵ķ��ա�

    // ����ֵ��printfһ�����ǳɹ���ֵ�ַ��ĸ�����
}

/* �Ѵ��������ַ��� */
void strerr() {
    printf("[%s]", strerror(1));
    char buffer[24] = { 0 }; printf("%d", strerror_s(buffer, 24, 50));

    // strerror() ��������뷵����Ӧ��errorMsg;
    // strerror_s() ����ֵΪ0���е���puts�ķ���ֵ��
    // ��<errno.h>���в��ٺ궨�壬�� stderror() ��Ȼ�����������ơ�
}

int main() {
    strerr();
    return 0;
}

/* ����С��1:strchr(), strlen() */
void QA_1() {
    char* str = (char*)"\0999b";
    char ch = 'b';
    char* addr = strchr(str + 1, ch);
    printf("str = %p, res = %p, %d", str, addr, strlen(str));
}

/* Sub function of confirm() */
void test(char* src_e) {
    printf("\n");
    char src[64] = { 0 };
    strcpy_s(src, 64, src_e);
    printf("    src:%p [%s][%d]\n", src, src, strlen(src));

    char* token = NULL;
    char* context = NULL;
    token = strtok_s(src, "-", &context);

    printf("context:%p\n  token:%p", context, token);
    printf("\n");
}
/* To confirm the GongNeng of strtok_s() */
int confirm() {
    test("");
    test("-");
    test("---");
    test("123");
    test("-123");
    test("---123");
    test("123-");
    test("123---");
    test("12-3");
    test("12---3");
}

/* span����:���һ�����ַ���ַ����Ƿ��� !?$|:; ��Щ�ַ� */
void checkValid(char* src, int size) {
    char* invalid_chrs = "?!@#|&";
    // strcspn()�����ڼ��Ƿ��ַ�
    const char input[] = "www.baidu!?.com";
    if (strcspn(input, invalid_chrs) < strlen(input)) printf("There is invalid chars!\n");

}

/* span, tok_s����:�� \" �����ַ����� */
void check(char* src);

/* strerror����������ܶ������롣 */
void errors() {
    int a = 200;
    do {
        printf("%d:%s\n", 200 - a, strerror(200 - a));
    } while (a--);
}

