#include<cstdio>

int main() {
	int a = 0, b = 0, c = 0;
	scanf("%d%d%d", &a, &b, &c);
	if (b > a) {
		int d = a;
		a = b;
		b = d;
	}
	if (c > a) {
		int d = a;
		a = c;
		c = d;
	}
	if (a > b + c)
		printf("not a triangle");
	else if (a*a == b*b + c*c)
		printf("yes");
	else
		printf("no");
}