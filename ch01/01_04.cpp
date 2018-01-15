#include<cstdio>
#include<cmath>

int main() {
	const double PI = acos(-1.0);
	int n = 0;
	scanf("%d", &n);
	printf("%f", sin((180/PI)*n));
}