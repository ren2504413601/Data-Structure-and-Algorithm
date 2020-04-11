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
//��д��������
Complex operator + (Complex A, Complex B) { return Complex(A.x + B.x, A.y + B.y); }
Complex operator - (Complex A, Complex B) { return Complex(A.x - B.x, A.y - B.y); }
Complex operator * (Complex A, Complex B) { return Complex(A.x * B.x - A.y * B.y, A.x * B.y + A.y * B.x); }

Complex n[maxn * 4], m[maxn * 4];//���߶���һ��Ҫ��4��
int r[maxn * 4], l, limit, nl;
/*---����ΪFFT���貿��---*/

int a, b, c;//abc���������
bool composite[maxn];//������¼
bool lost[4][maxn];//���ƶ�ʧ��¼

void init(int n) {//��50000���ڵĺ���
    int m = int(sqrt(n) + 0.5);
    for (int i = 2; i <= m; i++)
        if (!composite[i])
            for (int j = i * i; j <= n; j += i)
                composite[j] = 1;
}

const char *ss = "SHCD";
int idx(char c) {//�ɵö�ʧ�ַ�λ��
    return strchr(ss, c) - ss;
}

/*--����Ϊһ����ͨ��FFT����--*/
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
/*---FFT����---*/

int main() {
    init(50000);//��5�����ں���
    while (~scanf("%d%d%d", &a, &b, &c) && a) {
        memset(lost, false, sizeof(lost));//��������
        for (int i = 0; i < c; i++) {
            int temp; char ch;
            scanf("%d%c", &temp, &ch);
            lost[idx(ch)][temp] = 1;//�����ƶ���
        }

        n[0].x = 1.0, n[0].y = 0.0;//ͬ�·�m����ע��
        nl = 1;//������
        fft_init();//���������������û��������ó�����
        for (int i = 0; i < 4; i++) {
            //n����һ�ֽ���ʱ�Ķ���ʽ�����nl�Ƕ���ʽn�ĳ���
            //��ֻҪ��a��b�Ķ���ʽϵ�������Դ���Ϊb���Ͽ�������
            for (int j = nl; j <= limit; j++)
                n[j].x = n[j].y = 0.0;
            //m����������ʾ��ǰ��ɫ�Ķ���ʽ��������ȫ����
            for (int j = 0; j <= limit; j++)
                m[j].x = m[j].y = 0.0;

            for (int j = 4; j <= b; j++) {
                if (composite[j] && !lost[i][j])
                    m[j].x = 1.0, m[j].y = 0.0;
                    //����������Ķ���ʽϵ����Ϊ������1 + 0*i������ʵ����1
            }
            Fourier(n, m);//n��m����������ʽ���
            nl = b + 1;//b+1��ԭ���ǳ�����Ҳ��һ��
        }

        for (int i = a; i <= b; i++)//xΪʵ�����ϵ��
            printf("%lld\n", (long long)(n[i].x + 0.5));
        puts("");
    }
    return 0;
}