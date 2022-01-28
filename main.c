/*Include Application header file*/
#include "APP/TrafficLightApp.h"


int main(void)
{
	/*App initialization*/
	App_init();
	while(1)
	{
		/*Call App program*/
		App_program();
	}
	return 0;
}

