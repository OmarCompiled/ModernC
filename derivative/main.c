#include <stdio.h>
#include <math.h>

double
derivative(double (* F)(double), double x)
{
	const double delta = 1.0e-6;
	double x1 = x - delta;
	double x2 = x + delta;
	double y1 = F(x1);
	double y2 = F(x2);

	/* basically taking the slope of the tangent at a very close point */
	return (y2 - y1) / (x2 - x1);
}

double
F(double x)
{
	return x*x*x;
}

int
main()
{
	double y = derivative(F, 2);

	printf("%f\n", y);
}
