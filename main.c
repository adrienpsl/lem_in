#include <stdio.h>
#include "project/includes/function.h"

int main()
{
	void tab[10000];

	printf("%zu \n", sizeof(tab));

	lem_read_line();
	return 0;
}