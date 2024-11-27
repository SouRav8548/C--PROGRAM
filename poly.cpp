#include <stdio.h>
int main()
{
	char m;
	int x, pow[10], cof[10], p;
	scanf("%d", &x);
	scanf("%d", &p);
	scanf("%d", &m);
	pow[0] = p;
	cof[0] = x;
	while (1)
	{

		scanf("%d", &m);
		switch (m)
		{
		case '+':
			scanf("%d", &x);
			cof[0] = x;
			break;
		case '^':
			scanf("%d", &p);
			pow[0] = p;
			break;
		default:
			break;
		}
	}
}
