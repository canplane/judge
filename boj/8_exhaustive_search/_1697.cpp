#include <cstdio>
#include <algorithm>

int N, K;

int f(int k) {
    if (k <= N)
        return N - k;
    
    int ret;
    if (k % 2 && k > 1)
        ret = 1 + std::min(f(k - 1), f(k + 1));
    else
        ret = 1 + f(k / 2);
    ret = std::min(ret, k - N);
    
    return ret;
}

int main() {
    scanf("%d %d", &N, &K);
    printf("%d", f(K));
}