#include "taskMenu.h"
#include "taskCalc.h"

int main(void)
{
	// SETUP
	taskMenu_init();
	taskCalc_init();

	// LOOP
	for(;;)
	{
		taskMenu_run();
		taskCalc_run();
	}
	return 0;
}
