#include <stdio.h>

int main(void)
{
	unsigned int n, i;
	double ans, buf;
	double m[2] = {1,3};
	printf("Введите n: ");
	scanf("%u", &n);
	while (n < 1) {
		printf("Oшибка ввода!\n");
		printf("Введите n: ");
		scanf("%u", &n);
	};
	if (n == 1) {
		printf("\nСумма первых %i равна 1\n", n);
		return 0;
	} else if (n == 2) {
		printf("\nСумма первых %i равна 3\n", n);
		return 0;
	}
	ans = 3;
	for (i = 3; i <= n; i++) {
		buf = i-m[0]/m[1];
		m[0] = m[1];
		m[1] = buf;
		ans += buf;
	}
	printf("\nСумма первых %i равна %f\n", n, ans);

	return 0;
}

