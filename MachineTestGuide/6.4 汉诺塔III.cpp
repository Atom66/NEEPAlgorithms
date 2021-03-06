#include <stdio.h>
#include <string.h>

//递归函数，返回值较大使用long long类型
long long F(int num) {
    if (num == 1)
        return 2; //当参数为1时直接返回2
    else
        return 3 * F(num - 1) + 2; //否则递归调用F(num-1)
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        printf("%lld\n", F(n));
    }
    return 0;
}
