// tester les rooms qui fuck

#include "../project/includes/function.h"


int main()
{
	t_lem lem;

	// charge la global de debugage
	set_debug();

	lem = new_lem();
	read_and_parse_data(lem);
    return (0);
}