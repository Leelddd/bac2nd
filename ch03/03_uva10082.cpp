#include<cstdio>

int main() {
	char s[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
	int c = 0, i = 0;
	while ((c = getchar()) != EOF) {
		for (i = 0; s[i] && s[i] != c; i++);
		if (s[i]) putchar(s[i - 1]);
		else putchar(c);
	}
	return 0;
}