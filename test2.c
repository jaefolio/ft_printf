#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	result;
	int	result2;

	fclose(stdout);
	result = printf("hello");
	result2 = ft_printf("hello");

	freopen("/dev/tty", "w", stdout);
	printf("%d\n", result);
	printf("%d\n", result2);

	ft_printf("mine: hello %  bbum\n");
	printf("actual: hello %  bbum");

}
