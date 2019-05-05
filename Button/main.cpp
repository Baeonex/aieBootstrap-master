#include "ButtonApp.h"
#include <random>
#include <time.h>
int main() {
	srand(time(NULL));
	// allocation
	auto app = new ButtonApp();

	// initialise and loop
	app->run("AIE", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}