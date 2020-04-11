#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn = 50010;
const long double PI = acos(-1.0);

struct Complex {
    long double x, y;
    Complex(long double a = 0, long double b = 0):x(a), y(b){}
};
//手写复数运算
Complex operator + (Complex A, Complex B) { return Complex(A.x + B.x, A.y + B.y); }
Complex operator - (Complex A, Complex B) { return Complex(A.x - B.x, A.y - B.y); }
Complex operator * (Complex A, Complex B) { return Complex(A.x * B.x - A.y * B.y, A.x * B.y + A.y * B.x); }

Complex n[maxn * 4], m[maxn * 4];//像线段树一样要开4倍
int r[maxn * 4], l, limit, nl;
/*---以上为FFT所需部分---*/

int a, b, c;//abc含义见题面
bool composite[maxn];//合数记录
bool lost[4][maxn];//卡牌丢失记录

void init(int n) {//求50000以内的合数
    int m = int(sqrt(n) + 0.5);
    for (int i = 2; i <= m; i++)
        if (!composite[i])
            for (int j = i * i; j <= n; j += i)
                composite[j] = 1;
}

const char *ss = "SHCD";
int idx(char c) {//巧得丢失字符位置
    return strchr(ss, c) - ss;
}

/*--以下为一个普通的FFT板子--*/
void fft_init() {
    limit = 1, l = 0;
    while (limit < 2*(b + 1)) {
        limit <<= 1;
        l++;
    }

    for (int i = 0; i < limit; i++)
        r[i] = (r[i>>1] >> 1) | ((i&1) << (l-1));
}

void fft(Complex *A, int type) {
    for (int i = 0; i < limit; i++)
        if (i < r[i])
            swap(A[i], A[r[i]]);

    for (int mid = 1; mid < limit; mid <<= 1) {
        Complex Wn(cos(PI / mid), type * sin(PI / mid));
        for (int R = mid << 1, j = 0; j < limit; j += R) {
            Complex w(1, 0);
            for (int k = 0; k < mid; k++, w = w * Wn) {
                Complex x = A[j+k], y = w * A[j+k+mid];
                A[j+k] = x + y;
                A[j+k+mid] = x - y;
            }
        }
    }
}

void Fourier(Complex *A, Complex *B) {
    fft(A, 1);
    fft(B, 1);
    for (int i = 0; i < limit; i++)
        A[i] = A[i] * B[i];
    fft(A, -1);
    for (int i = 0; i < nl + b + 1; i++)
        A[i].x /= limit, A[i].y = 0.0;
}
/*---FFT结束---*/

int main() {
    init(50000);//求5万以内合数
    while (~scanf("%d%d%d", &a, &b, &c) && a) {
        memset(lost, false, sizeof(lost));//丢牌数组
        for (int i = 0; i < c; i++) {
            int temp; char ch;
            scanf("%d%c", &temp, &ch);
            lost[idx(ch)][temp] = 1;//这张牌丢了
        }

        n[0].x = 1.0, n[0].y = 0.0;//同下方m数组注释
        nl = 1;//常数项
        fft_init();//这个东西反复调用没意义就先拿出来了
        for (int i = 0; i < 4; i++) {
            //n是上一轮结束时的多项式结果，nl是多项式n的长度
            //答案只要求a到b的多项式系数，所以次幂为b以上可以置零
            for (int j = nl; j <= limit; j++)
                n[j].x = n[j].y = 0.0;
            //m数组用来表示当前花色的多项式，所以先全置零
            for (int j = 0; j <= limit; j++)
                m[j].x = m[j].y = 0.0;

            for (int j = 4; j <= b; j++) {
                if (composite[j] && !lost[i][j])
                    m[j].x = 1.0, m[j].y = 0.0;
                    //将这个合数的多项式系数设为复数（1 + 0*i），即实数的1
            }
            Fourier(n, m);//n和m这两个多项式相乘
            nl = b + 1;//b+1的原因是常数项也是一项
        }

        for (int i = a; i <= b; i++)//x为实数项，即系数
            printf("%lld\n", (long long)(n[i].x + 0.5));
        puts("");
    }
    return 0;
}