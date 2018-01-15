#include<cstdio>
#include<cstring>
#define max 100

bool less(int now, int min, char* s) {
	int len = strlen(s);
	for (int i = 0; i < len; i++) {
		char r = s[(now + i) % len];
		char l = s[(min + i) % len];
		if (r < l)	return true;
		else if (r > l)	return false;
	}
	return false;
}

int main() {
	int total = 0;
	scanf("%d", &total);
	for (size_t i = 0; i < total; i++)
	{
		char s[max];
		scanf("%s", &s);
		int len = strlen(s);
		int min = 0;
		for (int j = 1; j < len; j++) {
			if (less(j, min, s)) {
				min = j;
			}
		}
		for (size_t i = 0; i < len; i++) { printf("%c", s[(min+i)%len]); }
		printf("\n");
	}
}