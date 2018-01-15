#include<cstdio>

int main() {
	const int price = 95;
	int count = 0;
	scanf("%d", &count);
	double total = price *count;
	total = total > 300 ? total*0.85 : total;
	printf("%.2f", total);
}