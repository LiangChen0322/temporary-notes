#include <stdio.h>

void parameter(int a, int b, int c, int d)
{
	printf("- %d, %d, %d, %d\n", a, b, c, d);
}

int main(void)
{
	int i = 0;

	printf("%d, %d, %d, %d\n", i, i++, ++i, ++i);

	i = 0;
	parameter(i, i++, ++i, ++i);
}
