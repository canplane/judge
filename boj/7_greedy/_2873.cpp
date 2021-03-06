/* 1시간 20분 소요 : 더럽게 하지 말고 좀 더 예쁘게 짜보자. */

#include <cstdio>

int map[1001][1001];

int main() {
    int R, C;
    scanf("%d %d", &R, &C);
    for (int y = 1; y <= R; y++)
        for (int x = 1; x <= C; x++)
            scanf("%d", &map[y][x]);
    
    char c;
    if (R % 2) {
        for (int y = 1; y <= R; y++) {
            c = (y % 2) ? 'R' : 'L';
            for (int x = 1; x < C; x++)
                putchar(c);
            if (y < R)
                putchar('D');
        }
    }
    else if (C % 2) {
        for (int x = 1; x <= C; x++) {
            c = (x % 2) ? 'D' : 'U';
            for (int y = 1; y < R; y++)
                putchar(c);
            if (x < C)
                putchar('R');
        }
    }
    else {
        int min_cost_y = 1, min_cost_x = 2;
        int min_cost = map[1][2];
        for (int y = 1; y <= R; y++) {
            for (int x = y % 2 + 1; x <= C; x += 2) {
                if (map[y][x] < min_cost) {
                    min_cost_y = y, min_cost_x = x;
                    min_cost = map[y][x];
                }
            }
        }
        int py = (min_cost_y == R) ? min_cost_y - 1 : min_cost_y;
        c = 'L';
        for (int y = 1; y < py; y++) {
            c = (c == 'L') ? 'R' : 'L';
            for (int x = 1; x < C; x++)
                putchar(c);
            putchar('D');
        }
        char dy = 'U';
        if (c == 'L') {
            c = 'R';
            for (int x = 1; x <= C; x++) {
                if (min_cost_x != x) {
                    dy = (dy == 'U') ? 'D' : 'U';
                    putchar(dy);
                }
                if (x < C)
                    putchar(c);
            }
        }
        else {
            c = 'L';
            for (int x = C; x >= 1; x--) {
                if (min_cost_x != x) {
                    dy = (dy == 'U') ? 'D' : 'U';
                    putchar(dy);
                }
                if (x > 1)
                    putchar(c);
            }
        }
        if (py + 2 <= R) {
            putchar('D');
            for (int y = py + 2; y <= R; y++) {
                c = (c == 'L') ? 'R' : 'L';
                for (int x = 1; x < C; x++)
                    putchar(c);
                if (y < R)
                    putchar('D');
            }
        }
    }
}