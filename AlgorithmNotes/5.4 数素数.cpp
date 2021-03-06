#include <cstdio>
const int maxn = 1000001;

int prime[maxn], num = 0;
bool p[maxn] = { 0 };

void Find_Prime(int n) {
    for (int i = 2; i < maxn; i++) {
        if (p[i] == false) {
            prime[num++] = i;
            if (num >= n)
                break; //只需要n个素数，因此超过时即可结束
            for (int j = i + i; j < maxn; j += i)
                p[j] = true;
        }
    }
}

int main() {
    int m, n, count = 0;
    scanf("%d%d", &m, &n);
    Find_Prime(n);
    //输出第m个至第n个素数
    for (int i = m; i <= n; i++) {
        printf("%d", prime[i - 1]); //下标从0开始
        count++;
        if (count % 10 != 0 && i < n)
            printf(" ");
        else
            printf("\n");
    }
    return 0;
}
