#include<cstdio>
#include<cstring>

const char base[]	= "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";
const char mirror[] = "A    3 HIL JM O   2TUVWXY51SE Z  8 ";

int main() {
	char s[30];
	while (scanf("%s", s) == 1) {
		bool palindrome = true, mirrored = true;
		size_t len = strlen(s);
		for (size_t i = 0, j = len - 1; i < len && i <= j; i++, j--)
		{
			if (s[i] != s[j])	palindrome = false;
			size_t index = 0;
			for (; index < strlen(base) && base[index] != s[i]; index++);
			if (mirror[index] != s[j])	mirrored = false;
			if (palindrome || mirrored)	continue;
			break;
		}
		if (palindrome && mirrored)	printf("%s -- is a mirrored palindrome.\n\n", s);
		if (palindrome && !mirrored)	printf("%s -- is a regular palindrome.\n\n", s);
		if (!palindrome && mirrored)	printf("%s -- is a mirrored string.\n\n", s);
		if(!palindrome && !mirrored)printf("%s -- is not a palindrome.\n\n", s);
	}
		return 0;
}