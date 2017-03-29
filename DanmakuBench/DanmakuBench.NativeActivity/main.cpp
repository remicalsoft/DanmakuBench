#include <DxLib.h>
#include "SystemMain.h"

int android_main(void)
{
	SystemMain* system = new SystemMain();
	system->main();
	delete system;

	return 0;
}
