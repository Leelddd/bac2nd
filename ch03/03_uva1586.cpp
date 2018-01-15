#include<cstdio>
#include<cstring>
#include<cctype>
#include<cstdlib>

char *chem = "CHON";
float chemWeight[4] = { 12.01, 1.008, 16.00,14.01 };

int buf[4] = { 0,0,0,0 };

void setBuf(char c, int count) {
	switch (c)
	{
	case 'C':
		buf[0] += count;
		break;
	case 'H':
		buf[1] += count;
		break;
	case 'O':
		buf[2] += count;
		break;
	case 'N':
		buf[3] += count;
		break;
	default:
		break;
	}
}

int main() {
	int total = 0;
	scanf("%d", &total);
	for (size_t i = 0; i < total; i++)
	{
		char element[100];
		scanf("%s", &element);
		int length = strlen(element);
		char last = ' ';
		int numBuf = 0;
		bool num = false;
		for (size_t i = 0; i < length; i++)
		{
			char c = element[i];
			if (isdigit(c)) {
				num = true;
				numBuf = numBuf * 10 + atoi(&c);
				continue;
			}
			if (num) {
				setBuf(last, numBuf - 1);
				numBuf = 0;
			}
			setBuf(c, 1);
			last = c;
			num = false;
		}
		if (num) {
			setBuf(last, numBuf - 1);
			numBuf = 0;
		}
		float out = 0.0;
		for (int i = 0; i < 4; i++) out += chemWeight[i] * buf[i];
		printf("%.3f\n", out);
		for (int i = 0; i < 4; i++)	buf[i] = 0;
	}
}