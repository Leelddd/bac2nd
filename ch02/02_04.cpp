#include<cstdio>

int main() {
	int c = 1;
	while (true) {
		float n = 0, m = 0;
		scanf("%f%f", &n, &m);
		if (n == 0 && m == 0)break;
		float total = 0;
		for (size_t i = n; i < m + 1; i++)
		{
			total += 1.0 / (i*i);
		}
		printf("Case %d: %.5f", c, total);
		c++;
	}
}