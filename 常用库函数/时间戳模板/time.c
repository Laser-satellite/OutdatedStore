#define _CRT_SECURE_NO_WARNINGS 0
#include <stdio.h>
#include <time.h>

void getFromSys() {
    time_t timestamp = time(NULL); // time_t 相当于 int64
    printf("%d\n", timestamp);
    long current = clock(); printf("%ld\n", current);
    int i = 1e5; while (i--) { fopen_s(stdin, "2134we", "r"); }
    current = clock(); printf("%ld\n", current);

    // 这是从系统获取时间的方法。time(0) 返回当前时间戳，clock() 返回当前程序运行了多少毫秒。
    // 从系统获取到时间后，应该把他转化成一个名为tm的bean对象(结构体)，于是会有下面的函数。
    // 针对名为tm的bean对象给出了两个常用方法把他转化为字符串。

    // clock()可以搭配宏定义CLOCKS_PER_SEC使用，他实质是((time_t)1000)。
}

void transToTM() {
    time_t timestamp = time(NULL);
    struct tm tm_bean;
    tm_bean= *localtime(&timestamp);
    tm_bean= *gmtime(&timestamp); 
    errno_t err = localtime_s(&tm_bean, &timestamp);
    errno_t err2 = gmtime_s(&tm_bean, &timestamp);

    // localtime()和gmtime()的返回值是一块静态的空间，无论用多少次其地址都不会变。不信你输出地址
    // 但是要更新这块空间必须要调用localtime或者gmtime函数
    // gmtime()赋值的是格林尼治时间(utc time)，不是本地的东八区。

    /* 这里附上struct tm的结构：
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

    // asctime()是一种简易的时间赋值字符串的函数，更自由的字符串格式化需要用到strftime()
    // asctime()格式化相当于strftime()的"%a %b %d %H:%M:%S %Y\n"(或"%c\n")。注意有"\n"。
    // strftime() 的返回值是strlen(buffer), 不含末尾\0。注意buffer长度要考虑\0。
    // asctime()和strftime()都接受tm*地址，其实可以不用单独赋值tm_bean
    // asctime()有_s版本。

    // 简单的可以使用"%c"或者"%X %x"格式化，其他的直接查: 
    /*
    % a	区域设置的缩写星期名
    % A	区域设置的完整星期名
    % b	区域设置的缩写月份名
    % B	区域设置的完整月份名
    % c	区域设置的适当的日期和时间表示
    % d	表示为一个十进制数(01 - 31)的当月的第几天
    % H	表示为一个十进制数(00 - 23)的小时时间(24小时制)
    % I	表示为一个十进制数(01 - 12)的小时时间(12小时制)
    % j	表示为一个十进制数(001 - 366)的当年的第几天
    % m	表示为一个十进制数(01 - 12)的月份
    % M	表示为一个十进制数(00 - 59)的分钟数
    % p	区域设置的、与12小时制相关的AM / PM指示符等价的东西
    % S	表示为一个十进制数(00 - 61)的秒数
    % U	表示为一个十进制数(00 - 53)的当年的第几周(第一个星期日是第一个星期的第一天)
    % w	表示为一个十进制数(0 - 6)的星期几，星期日表示0
    % W	表示为一个十进制数(00 - 53)的当年的第几周(第一个星期一是第一个星期的第一天)
    % x	区域设置的适当的日期表示
    % X	区域设置的适当的时间表示
    % y	表示为一个十进制(00 - 99)的不带世纪的年份
    % Y	表示为一个十进制的带世纪的年份
    % Z	时区名字或者它的缩写取代，如果不能确定时区，则不能被字符
    % %表示%
    */
}

void main() {
    tmToString();
}