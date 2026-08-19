// grader.cpp - đặt cùng thư mục với cave.cpp của mày
#include "cave.h"
#include <cstdio>
#include <cstdlib>
#include <cassert>

static int N;
static int door[5000], switch_[5000];
static int opened[5000];
static int tried = 0;

int tryCombination(int S[]) {
    tried++;
    if (tried > 70000) {
        printf("Exceeded 70000 calls\n");
        exit(0);
    }
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == switch_[i]) cnt++;
        else opened[i] = 1;
    }
    for (int i = 0; i < N; i++) {
        if (opened[i]) {
            opened[i] = 0;
            return i; // trả về cửa mở đầu tiên
        }
    }
    return -1; // tất cả đúng
}

void answer(int S[], int D[]) {
    for (int i = 0; i < N; i++) {
        if (S[i]!= switch_[i] || D[i]!= door[i]) {
            printf("Wrong Answer\n");
            exit(0);
        }
    }
    printf("Accepted\n");
    exit(0);
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &door[i]);
    for (int i = 0; i < N; i++) scanf("%d", &switch_[i]);
    exploreCave(N); // hàm của mày
    printf("Did not call answer()\n");
    return 0;
}