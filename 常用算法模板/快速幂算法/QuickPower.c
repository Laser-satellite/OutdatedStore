#include<stdio.h>

/**
 * LaTeX: rs = (a^n)%p;
 * ��ʽ��(a*b)%p == ((a%p)*(b%p))%p
 * �Ƶ���
 * 
 * ����   (a*b)%p == ((a%p)*(b%p))%p, 
 * �õ�   (a*b)%p �� a%p ���������Ĺ�ϵ��
 * �ַ��� (a*b)%p �� a%p �־������Ƶ���ʽ��
 * �Ϳ��ԣ�
 *   ����ֵ�õ���ֵ��λ�ã��ٱ���ԭ�й�ϵ���䣬
 * �͵õ� (a*b*c)%p �� (a*b)%p Ҳ�������Ĺ�ϵ��
 * ������ (a*b*c*d)%p �� (a*b*c)%p Ҳ�������ϵ��
 * ����
 *   ���ǵõ��� (a*...*z)%p �� a%p �ĵݹ��ϵ���ݹ麯����������ʽ��
 * ��
 *   (a^n)%p д�� (a^0b(n))%p �պ��� (a*...*z)%p ����ʽ��
 * �������ǿ���ʹ��һ���ݹ麯���õ������
 * ��Ϊ����������һ����ʽ�����Կ��Ժ����׵ذ����ĳɵ�����
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

/* �ݹ�ĳɵ�����ĺ��� */
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