#include <cstdio>
#include <queue>

bool eratos[10001];

int itoa(int i, char a[]) {
    int len = 0;
    do
        a[len++] = i % 10;
    while (i /= 10);
    a[len] = '\0';
    return i;
}

void bfs(int A, int B) {
    std::queue<int> q;
    bool visited[10001] = {};

    int ans = 0, seg = 1;
    q.push(A);
    while (!q.empty()) {
        int X, next_seg = 0;
        while (seg--) {
            X = q.front(), q.pop();
            visited[X] = true;

            if (X == B) {
                printf("%d\n", ans);
                return;
            }

            char s[5];
            itoa(X, s);
            for (int i = 0; i < 10; i++) {
                X = s[3] * 1000 + s[2] * 100 + s[1] * 10 + i;
                if (!eratos[X] && !visited[X])
                    q.push(X), next_seg++;
            }
            for (int i = 0; i < 10; i++) {
                X = s[3] * 1000 + s[2] * 100 + i * 10 + s[0];
                if (!eratos[X] && !visited[X])
                    q.push(X), next_seg++;
            }
            for (int i = 0; i < 10; i++) {
                X = s[3] * 1000 + i * 100 + s[1] * 10 + s[0];
                if (!eratos[X] && !visited[X])
                    q.push(X), next_seg++;
            }
            for (int i = 1; i < 10; i++) {
                X = i * 1000 + s[2] * 100 + s[1] * 10 + s[0];
                if (!eratos[X] && !visited[X])
                    q.push(X), next_seg++;
            }
        }
        ans++, seg = next_seg;
    }
    printf("Impossible\n");
}

int main() {
    for (int i = 2; i < 5000; i++) {
        if (eratos[i])
            continue;
        for (int j = 2 * i; j < 10000; j += i)
            eratos[j] = true;
    }

    int T, A, B;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &A, &B);
        bfs(A, B);
    }
}