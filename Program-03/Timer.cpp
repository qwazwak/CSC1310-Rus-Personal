#include "Timer.h"

using namespace std;

time_t getTime() {
	time_t returner;
	return time(&returner);
}

double totalTime(time_t start, time_t end) {
	return difftime(end, start);
}
