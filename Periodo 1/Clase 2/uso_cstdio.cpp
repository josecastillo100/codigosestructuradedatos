#include <cstdio>
//C++ printf ejemplo

int main()
{
	char ch = 'A';
	float a = 8.0, b = 3.0;
	double d = 3.142;
	int x = 20;
	printf("Division flotante : %.3f / %.3f = %.3f \n", a,b,a/b);
	printf("Doble valor : %.4f \n", d);
	printf("Ancho de ajuste %*c \n",4, ch);
	printf("Equivalente octal de %d es %o \n", x, x);
	printf("Equivalente hexadecimal %d is %x \n", x, x);
	
	return 0;
	
}
