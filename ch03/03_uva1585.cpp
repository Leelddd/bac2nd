#include<cstdio>
#include<cstring>
#define max 80

int main() {
	int total = 0;
	scanf("%d", &total);
	for (size_t i = 0; i < total; i++)
	{
		char s[80];
		scanf("%s", &s);
		int len = strlen(s);
		int buf = 0;
		int buf_count = 1;
		int score = 0;
		for (size_t i = 0; i < len; i++)
		{
			if (s[i] == 'X')	buf_count = 1;
			else score += buf_count++;
		}
		printf("%d\n", score);
	}
}