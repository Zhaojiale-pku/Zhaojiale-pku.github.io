#include<stdio.h>
#include<string.h>
int charToValue(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	else {
		return c - 'A' + 10;
	}
}
char valueToChar(int v) {
	if (v < 10) {
		return v + '0';
	}
	else {
		return v - 10 + 'A';
	}
}
long long convertToDecimal(const char* a, int m) {
	long long result = 0;
	int len = strlen(a);
	for (int i = 0; i < len; i++) {
		result = result = result * m + charToValue(a[i]);
	}
	return result;
}
void convertFromDecimal(long long decimal, int n, char* result) {
	int i = 0;
	if (decimal == 0) {
		result[i++] = '0';
	}
	else {
		while (decimal > 0) {
			result[i++] = valueToChar(decimal % n);
			decimal /= n;
		}
	}
	result[i] = '\0';
	int len = i;
	for (int j = 0; j < len / 2; j++) {
		char temp = result[j];
		result[j] = result[len - j - 1];
		result[len - j - 1] = temp;
	}
}
int main() {
	int k;
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		int m, n;
		char a[1001];
		scanf("%d", &m);
		scanf("%s", a);
		scanf("%d", &n);
		long long decimal = convertToDecimal(a, m);
		char result[1001];
		convertFromDecimal(decimal, n, result);
		printf("%s\n", result);
	}
	return 0;
}