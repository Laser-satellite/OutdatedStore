#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include<errno.h>
#define BUF_LENGTH 64
#define MAX_COUNT 5


/* 复制和拼接字符串 */
void cpyAndCat() {

    const char* src = "123456789";
    char buffer[BUF_LENGTH];
    errno_t err;
    err = strcpy_s(buffer, BUF_LENGTH, src);
    err = strncpy_s(buffer, BUF_LENGTH, src, MAX_COUNT);
    err = strcat_s(buffer, BUF_LENGTH, src);
    err = strcat_s(buffer, BUF_LENGTH, src, MAX_COUNT);
    
    // 都要有源字符串; 都要用到缓冲区; 都输出错误代码;

    // 都有空指针异常。
    //      _s函数可以搭配VS的错误捕获函数，但没有_s则不会报错。需要程序员避免。
    // 可能虚报缓冲区长度。
    //      dubug时报错，但忽略后还在运行。release没有报错。不要虚报缓冲区长度。
    // 有缓冲区过短的危险。
    //     这四个函数都不操作'\0', 只是最后需要添加，因此缓冲区长度必须大于strlen()。MAX_COUNT对标strlen()。

    // 正常则err = 0;
}

/* 比较两字符串的大小 */
void cmp() {
    const char* src1 = "1234567";
    const char* src2 = "1234568";
    int cmp_result;
    cmp_result = strcmp(src1, src2);
    cmp_result = strncmp(src1, src2, MAX_COUNT);
    // 有两个源字符串。输出int示性值(cmp式的)
    // 都有空指针异常。
    // result == 0 则相等， > 0 则说明某位字符str1>str2。('\0'是最小字符)
}

/* 寻找字符和子字符串 */
void findSub() {
    const char* src = "123456765";
    char* addr;
    char ch = '5'; addr = strchr(src, ch);
    char rch = '5'; addr = strrchr(src, rch);
    char* sub = "567"; addr = strstr(src, sub);
    
    // 有空指针异常和越界访问危险。
    // 允许src偏移，但此时需要判断空指针和越界
    // 一种常见情况是 addr = strchr(addr + 1, ch); 此时请判断越界

    // 返回找到第一个找到了的值的地址，没找到则返回NULL
}

/* 数字符个数 */
void span() {
    const char* src = "45654321";
    int count;
    char group1[] = "456"; count = strspn(src, group1);
    char group2[] = "123"; count = strcspn(src, group2);

    printf("%d", count);

    // strspn 用于数从开头起到发现第一个不属于group1的字符，中间共有多少个属于group1的字符。
    // strcspn用于数从开头起到发现第一个属于group2的字符，中间共有多少个不属于group2的字符。
    
    // 一种常见用法是：还有向group中添加非法字符判断字符串是否合法。
    // 这种都需要偏移src的位置，此时请判断空指针和越界。
}

/* 分割字符串 */
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

    // 源字符串本身是缓冲区; 一次改变两个值(token, context);
    // token代表从src开头找起第一个不属于delim集的字符。找遍了都没有找到属于delim集的字符，则返回NULL。
    // context代表从token之后找起第一个属于delim集的字符的下一位地址，
    //      token为NULL，或者token之后没有属于delim集的字符了，则返回源字符串\0地址。

    // 这个函数就是用来分割字符串的。
    // 他经常需要偏移src调用，不过我们使用将context拿到src位置上的做法来更好地进行偏移。
    // 如果不使用strtok_s()而是strtok, 我们对context位置的需要如上判断。由于strtok添加了\0, 必须在之前存原来的\0。
    // strtok_s() 比起 strtok() 优势很明显。(至少比其他_s函数明显...)
}

/* 把int赋值给字符串 */
void sprint() {
    int a = 12;
    
    char buffer[3] = { 0 };
    int rs = sprintf_s(buffer, 3, "%d", a);
    printf("%s", buffer);
    printf("[%d]", rs);
    // 需要缓冲区。源字符串是格式化字符串。
    // 注意空指针异常还有不要虚报缓冲区长度。仍然有缓冲区过短的风险。

    // 返回值与printf一样，是成功赋值字符的个数。
}

/* 把错误码变成字符串 */
void strerr() {
    printf("[%s]", strerror(1));
    char buffer[24] = { 0 }; printf("%d", strerror_s(buffer, 24, 50));

    // strerror() 输入错误码返回相应的errorMsg;
    // strerror_s() 返回值为0。有点像puts的返回值。
    // 在<errno.h>里有不少宏定义，但 stderror() 显然比他更有优势。
}

int main() {
    strerr();
    return 0;
}

/* 辨析小题1:strchr(), strlen() */
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

/* span案例:检查一代表地址的字符串是否含有 !?$|:; 这些字符 */
void checkValid(char* src, int size) {
    char* invalid_chrs = "?!@#|&";
    // strcspn()可用于检查非法字符
    const char input[] = "www.baidu!?.com";
    if (strcspn(input, invalid_chrs) < strlen(input)) printf("There is invalid chars!\n");

}

/* span, tok_s案例:按 \" 划分字符串。 */
void check(char* src);

/* strerror案例：输出很多错误代码。 */
void errors() {
    int a = 200;
    do {
        printf("%d:%s\n", 200 - a, strerror(200 - a));
    } while (a--);
}

