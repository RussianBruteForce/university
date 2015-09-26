#include <stdio_ext.h>
#include <math.h>

void f_print(const int a, const int b, const int c, const int x)
{
	if (c < 0 && b != 0)
		printf("%f", a*pow(x,2) + b*pow(x,2));
	else if (c > 0 && b == 0) {
		if ((x+c) == 0)
			printf("error");
		else printf("%f", ((double)(x+a))/(double)(x+c));
	} else {
		if (c == 0)
			printf("error");
		else printf("%f", ((double)x)/c);
	}
}

int main(void)
{
	int d, i;
	int a, b, c, x1, x2;
	a = b = c = x1 = x2 = 0;
	unsigned int dx = 1;
	printf("Введите последовательно a, b, c, x1, x2, dx: ");
	d = scanf("%i%i%i%i%i%u", &a, &b, &c, &x1, &x2, &dx);
	__fpurge(stdin);
	while ( (d =! 6) || !(x2 > x1) || !(dx <= (int)fabs(((double)x2)-x1)) ) {
		printf("\nПроверьте ввод x1, x2 и dx!\nВведите последовательно a, b, c, x1, x2, dx: ");
		d = scanf("%i%i%i%i%i%u", &a, &b, &c, &x1, &x2, &dx);
		__fpurge(stdin);
	};
	for (i = x1; i <= x2; i += dx) {
		printf("\nx%i \t= ", i);
		f_print(a,b,c,i);
	}
	printf("\n");

	return 0;
}
