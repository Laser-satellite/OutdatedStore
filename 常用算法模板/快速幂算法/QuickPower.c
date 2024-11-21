#include<stdio.h>

/**
 * LaTeX: rs = (a^n)%p;
 * 公式：(a*b)%p == ((a%p)*(b%p))%p
 * 推导：
 * 
 * 由于   (a*b)%p == ((a%p)*(b%p))%p, 
 * 得到   (a*b)%p 与 a%p 具有这样的关系，
 * 又发现 (a*b)%p 与 a%p 又具有相似的形式，
 * 就可以：
 *   把左值拿到右值的位置，再保持原有关系不变，
 * 就得到 (a*b*c)%p 与 (a*b)%p 也是这样的关系，
 * 继续得 (a*b*c*d)%p 与 (a*b*c)%p 也是这个关系，
 * 于是
 *   我们得到了 (a*...*z)%p 与 a%p 的递归关系，递归函数是上述公式。
 * 而
 *   (a^n)%p 写成 (a^0b(n))%p 刚好是 (a*...*z)%p 的形式。
 * 所以我们可以使用一个递归函数得到结果。
 * 因为函数不过是一个公式，所以可以很容易地把他改成迭代。
 */

int QuickPowerRs(int a, int n, int p) {
    if (n == 0) {
        return 1;
    }
    if (n & 1)
        return QuickPowerRs((a * a % p), n >> 1, p) * a % p;
    else
        return QuickPowerRs((a * a % p), n >> 1, p);
}

/* 递归改成迭代后的函数 */
int QuickPower(int a, int n, int p) {
	int rs = 1;
	while (n) {
		if (n & 1) {
			rs = rs * a % p;
		}
		a = a * a % p;
		n >>= 1;
	}
	return rs;
}

#define s 34,210050,37
int main() {
	printf("DATA:{%d %d %d}\n", s);
	printf("%d\n", QuickPower(s));
    printf("%d", QuickPowerRs(s));
}