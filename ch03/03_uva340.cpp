#include<cstdio>
#define MAX 1000

int main() {
	int len = 0, game = 1;
	int answer[1000], guess[1000];
	while (scanf("%d", &len) == 1 && len) {
		printf("Game %d:\n", game++);
		for (size_t i = 0; i < len; i++)	scanf("%d", &answer[i]);
		int answer_count[10];
		for (int i = 0; i < 10; i++)answer_count[i] = 0;
		for (int i = 0; i < len; i++)answer_count[answer[i]]++;
		for (;;) {
			for (size_t i = 0; i < len; i++)	scanf("%d", &guess[i]);
			if (!guess[0])	break;
			int pos = 0, val = 0;
			int count[10];
			for (int i = 0; i < 10; i++)count[i] = 0;
			for (size_t i = 0; i < len; i++)
			{
				if (answer[i] == guess[i])	pos++;
				count[guess[i]]++;
			}
			for (int i = 0; i < 10; i++)val += answer_count[i] > count[i] ? count[i] : answer_count[i];
			val -= pos;
			printf("    (%d,%d)\n", pos, val);
		}
	}
}