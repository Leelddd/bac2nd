#include<cstdio>

int main() {
	int a = 0, b = 0, c = 0;
	scanf("%d%d%d", &a, &b, &c);
	for (size_t i = 1; i * 7 + c < 100; i++)
	{
		int num = i * 7 + c;
		if (num % 5 == b && num % 3 == a) {
			printf("%d\n", num);
			return 0;
		}
	}
	printf("No answer\n");
}