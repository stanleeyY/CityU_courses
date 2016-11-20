//Nim Game
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int arr[10000];
int N;
bool finished() {
    for (int i = 0; i < N; i++)
        if (arr[i])
            return false;
    return true;
}
inline int getxor() {
    int xo = arr[0];
    for (int i = 1; i < N; i++)
        xo ^= arr[i];
    return xo;
}
void report() {
    printf("The current situation is: \n");
    for (int i = 0; i < N; i++)
        printf("[%d]\t", arr[i]);
    printf("\n");
    for (int i = 1; i <= N; i++)
        printf(" %d \t", i);
    printf("\n");
}
void bot() {
    for (int i = 0; i < N; i++) {
        int temp = arr[i];
        for (arr[i]--; arr[i] >= 0; arr[i]--)
            if (getxor() == 0) {
                printf("Now the robot take %d stones from the pile %d\n", temp - arr[i], i + 1);
                if (finished())
                    printf("You lost (v_v)\n");
                else
                    report();
                return;
            }
        arr[i] = temp;
    }
    for (int i = 0; i < N; i++)
        if (arr[i]) {
            arr[i]--;
            printf("Now the robot take %d stones from the pile %d\n", 1, i + 1);
            if (finished())
                printf("You lost (v_v)\n");
            else
                report();
            return;
        }
}
void human() {
    printf("Please input the pile you want to choose from:\n");
    int pile;
    scanf("%d", &pile);
    printf("Please input the number of stones you want to choose:\n");
    int stone;
    scanf("%d", &stone);
    if (arr[pile - 1] < stone || pile > N || pile < 1) {
        printf("Invalid request\n");
        human();
    } else {
        arr[pile - 1] -= stone;
        report();
    }
}

int main() {
    memset(arr, 0, sizeof(arr));
    printf("Please input the total number of piles (1-10000):\n");
    cin >> N;
    if (N) {
        while (finished()) {
            printf("Please input the number of stones in each pile:\n");
            for (int i = 0; i < N; i++)
                scanf("%d", &arr[i]);
        }
    }
    report();
    while (!finished()) {
        human();
        if (finished())
            printf("You win! (^_^)\n");
        else
            bot();
    }
    return 0;
}