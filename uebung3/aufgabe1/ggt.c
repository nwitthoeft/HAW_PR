#include "ggt.h"

int euklidischer_algorithmus_iterativ(int m, int n)
{
	if (n == 0)
		return m;
	if (n > 0)
	{
		while (n != 0)
		{
			int h = m % n;
			m = n;
			n = h;
		}
		return(m);
	}
}

int euklidischer_algorithmus_rekursiv(int m, int n)
{
	if (n == 0)
		return m;
	else
		return euklidischer_algorithmus_rekursiv(n, m % n);

}

int primfaktoren(int zahl)
{
	int i;

	printf("\nPrimfaktoren von %d sind ..\n", zahl);
	for (i = 2; zahl > 1; i++)
	{
		while (zahl % i == 0)
		{
			printf("%d ", i);
			zahl = zahl / i;
		}
	}
	printf("\n");
}