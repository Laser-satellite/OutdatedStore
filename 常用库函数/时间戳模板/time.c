#define _CRT_SECURE_NO_WARNINGS 0
#include <stdio.h>
#include <time.h>

void getFromSys() {
    time_t timestamp = time(NULL); // time_t �൱�� int64
    printf("%d\n", timestamp);
    long current = clock(); printf("%ld\n", current);
    int i = 1e5; while (i--) { fopen_s(stdin, "2134we", "r"); }
    current = clock(); printf("%ld\n", current);

    // ���Ǵ�ϵͳ��ȡʱ��ķ�����time(0) ���ص�ǰʱ�����clock() ���ص�ǰ���������˶��ٺ��롣
    // ��ϵͳ��ȡ��ʱ���Ӧ�ð���ת����һ����Ϊtm��bean����(�ṹ��)�����ǻ�������ĺ�����
    // �����Ϊtm��bean����������������÷�������ת��Ϊ�ַ�����

    // clock()���Դ���궨��CLOCKS_PER_SECʹ�ã���ʵ����((time_t)1000)��
}

void transToTM() {
    time_t timestamp = time(NULL);
    struct tm tm_bean;
    tm_bean= *localtime(&timestamp);
    tm_bean= *gmtime(&timestamp); 
    errno_t err = localtime_s(&tm_bean, &timestamp);
    errno_t err2 = gmtime_s(&tm_bean, &timestamp);

    // localtime()��gmtime()�ķ���ֵ��һ�龲̬�Ŀռ䣬�����ö��ٴ����ַ������䡣�����������ַ
    // ����Ҫ�������ռ����Ҫ����localtime����gmtime����
    // gmtime()��ֵ���Ǹ�������ʱ��(utc time)�����Ǳ��صĶ�������

    /* ���︽��struct tm�Ľṹ��
    int tm_sec;   // seconds after the minute - [0, 60] including leap second
    int tm_min;   // minutes after the hour - [0, 59]
    int tm_hour;  // hours since midnight - [0, 23]
    int tm_mday;  // day of the month - [1, 31]
    int tm_mon;   // months since January - [0, 11]
    int tm_year;  // years since 1900
    int tm_wday;  // days since Sunday - [0, 6]
    int tm_yday;  // days since January 1 - [0, 365]
    int tm_isdst; // daylight savings time flag
    */
}

void tmToString() {
    time_t timestamp = time(NULL);
    struct tm tm_bean = *localtime(&timestamp);

    printf(asctime(localtime(&timestamp)));
    char buffer[50] = { 0 };
    size_t str_size = strftime(buffer, 50, "%c", &tm_bean);
    printf("%s", buffer);

    // asctime()��һ�ּ��׵�ʱ�丳ֵ�ַ����ĺ����������ɵ��ַ�����ʽ����Ҫ�õ�strftime()
    // asctime()��ʽ���൱��strftime()��"%a %b %d %H:%M:%S %Y\n"(��"%c\n")��ע����"\n"��
    // strftime() �ķ���ֵ��strlen(buffer), ����ĩβ\0��ע��buffer����Ҫ����\0��
    // asctime()��strftime()������tm*��ַ����ʵ���Բ��õ�����ֵtm_bean
    // asctime()��_s�汾��

    // �򵥵Ŀ���ʹ��"%c"����"%X %x"��ʽ����������ֱ�Ӳ�: 
    /*
    % a	�������õ���д������
    % A	�������õ�����������
    % b	�������õ���д�·���
    % B	�������õ������·���
    % c	�������õ��ʵ������ں�ʱ���ʾ
    % d	��ʾΪһ��ʮ������(01 - 31)�ĵ��µĵڼ���
    % H	��ʾΪһ��ʮ������(00 - 23)��Сʱʱ��(24Сʱ��)
    % I	��ʾΪһ��ʮ������(01 - 12)��Сʱʱ��(12Сʱ��)
    % j	��ʾΪһ��ʮ������(001 - 366)�ĵ���ĵڼ���
    % m	��ʾΪһ��ʮ������(01 - 12)���·�
    % M	��ʾΪһ��ʮ������(00 - 59)�ķ�����
    % p	�������õġ���12Сʱ����ص�AM / PMָʾ���ȼ۵Ķ���
    % S	��ʾΪһ��ʮ������(00 - 61)������
    % U	��ʾΪһ��ʮ������(00 - 53)�ĵ���ĵڼ���(��һ���������ǵ�һ�����ڵĵ�һ��)
    % w	��ʾΪһ��ʮ������(0 - 6)�����ڼ��������ձ�ʾ0
    % W	��ʾΪһ��ʮ������(00 - 53)�ĵ���ĵڼ���(��һ������һ�ǵ�һ�����ڵĵ�һ��)
    % x	�������õ��ʵ������ڱ�ʾ
    % X	�������õ��ʵ���ʱ���ʾ
    % y	��ʾΪһ��ʮ����(00 - 99)�Ĳ������͵����
    % Y	��ʾΪһ��ʮ���ƵĴ����͵����
    % Z	ʱ�����ֻ���������дȡ�����������ȷ��ʱ�������ܱ��ַ�
    % %��ʾ%
    */
}

void main() {
    tmToString();
}