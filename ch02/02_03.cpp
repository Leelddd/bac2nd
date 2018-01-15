#include<cstdio>

int main() {
	int level = 0;
	scanf("%d", &level);
	for (size_t i = 0; i < level; i++)
	{
		for (size_t j = 0; j < i; j++)
		{
			printf(" ");
		}
		for (size_t j = 0; j < 2*(level-i)-1; j++)
		{
			printf("#");
		}
		printf("\n");
	}
}