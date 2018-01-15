#include<cstdio>
#define MAX 100001
int lib[MAX];

int pos(int num) {
	int p = 0;
	for (int i = num; i > 0; i /= 10) {
		p++;
	}
	return p;
}

int main() {
	for (int i = 1; i < MAX; i++) {
		lib[i] += i;
		for (int j = i; j > 0; j = j / 10) {
			lib[i] += j%10;
		}
	}
	int count = 0;
	scanf("%d", &count);
	for (int i = 0; i < count; i++) {
		int num = 0;
		scanf("%d", &num);
		int j = num - pos(num)*9;
		j = j > 1 ? j : 1;
		for (; j < num && lib[j] != num; j++);
		if (j < num)	printf("%d\n", j);
		else printf("%d\n", 0);
	}
}