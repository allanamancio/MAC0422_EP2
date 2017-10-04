#include "my_time.h"

double time_current() {
	/*Return the time elapsed since its first call*/
	static struct timespec initial; // Time initial
	static int initialized = 0; // Lock to time initial
	
	// Variable
	struct timespec time;

	// Executes only once to start the clock
	if (!initialized) {
		initialized = 1;
		clock_gettime(CLOCK_MONOTONIC_RAW, &initial);
	}
	
	// Gets the time now
	clock_gettime(CLOCK_MONOTONIC_RAW, &time);
	
	return (double)(time.tv_sec - initial.tv_sec) + (double)(time.tv_nsec - initial.tv_nsec)/BILLION; // Time in seconds
}
