// tester les rooms qui fuck

#include "../project/includes/function.h"


static void test__1_() // nb fourmis negatif
{
	char *str="test 1 \n nb fourmis negatif";
	(void)str;
	
		
}

int main()
{
	t_lem lem;

	// charge la global de debugage
	set_debug();

	lem = new_lem();
	read_and_parse_data(lem);

    return (0);
}