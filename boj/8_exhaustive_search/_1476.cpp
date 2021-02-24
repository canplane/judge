/* 나머지 연산, 배열 인덱스의 기준이 0이냐 1이냐 중심을 잘 잡아야 할 것 같다.
 * 나머지 연산에서는 0을 기준으로 하는 게 편함.
 * 그러니 인덱스 접근할 때 -1 더해서 접근하고, 얻은 값에는 1 더하는 식으로 가는 게 좋을 듯.
 */

#include <cstdio>

int year[15][28][19];

int main() {
    for (int i = 0; i < 15 * 28 * 19; i++)
        year[i % 15][i % 28][i % 19] = i;
    
    int E, S, M;
    scanf("%d %d %d", &E, &S, &M);
    printf("%d", year[E - 1][S - 1][M - 1] + 1);
}