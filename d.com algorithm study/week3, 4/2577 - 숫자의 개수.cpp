#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

int A, B, C, mul;
string str_mul;
int number[10];

int main() {

    scanf("%d", &A);
    scanf("%d", &B);
    scanf("%d", &C);
    mul = A * B * C;
    str_mul = to_string(mul);

    int length = str_mul.size();

    for (int i = 0; i < length; i++) number[str_mul[i] - '0']++;
    for (int i = 0; i < 10; i++) printf("%d\n", number[i]);

    return 0;
}