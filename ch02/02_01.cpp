#include<cstdio>

int main() 
{
	for (size_t i = 1; i < 10; i++)
	{
		for (size_t j = 0; j < 10;j ++)
		{
			for (size_t k = 0; k < 10; k++)
			{
				int num = i * 100 + j * 10 + k;
				if (num == i * i * i + j * j * j + k * k * k)
					printf("%d\n", num);
			}
		}
	}
}