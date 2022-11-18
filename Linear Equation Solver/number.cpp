#include "number.h"
int solve_eq_number(double& x, double a, double b, double c, double d)
{
	if ((a - c) == 0)
	{
		if ((b - d) == 0)
			return -1; 	// vo so nghiem tra ve -1
		else
			return 0;  // vo nghiem tra ve 0
	}
	else
	{
		x = (d - b) / (a - c);
		if (x == -0.0)
			x = 0.0;
		return 1;       // co nghiem tra ve 1
	}
}
