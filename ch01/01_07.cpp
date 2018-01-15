#include<cstdio>

int main() {
	int year = 0;
	scanf("%d", &year);
	char* isLeapYear = (year % 400 == 0) || ((year % 100 != 0) && (year % 4 == 0)) ? "yes" : "no";
	printf("%s", isLeapYear);
}