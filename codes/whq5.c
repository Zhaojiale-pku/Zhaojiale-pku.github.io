#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>
bool is_prime(int num) {
	if (num <= 1)return false;
	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0)return false;
	}
	return true;
}
bool is_palindrome(int num) {
	char str[11];
	sprintf(str, "%d", num);
	int len = strlen(str);
	for (int i = 0; i < len / 2; i++) {
		if (str[i] != str[len - 1 - i]) {
			return false;
		}
	}
	return true;
}
int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	for (int i = 0; i <= b - a; i++) {
		if (is_prime(a + i) && is_palindrome(a + i)) {
			printf("%d\n", a + i);
		}
	}
	return 0;
}