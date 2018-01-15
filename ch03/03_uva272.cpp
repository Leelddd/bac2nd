#include<cstdio>

int main() 
{
	char c = ' ';
	size_t index = 1;
	while ((c = getchar()) != EOF) {
		if (c == '"')
			printf("%s", index++ % 2 == 0 ? "''" : "``");
		else printf("%c", c);
	}
	return 0;
}