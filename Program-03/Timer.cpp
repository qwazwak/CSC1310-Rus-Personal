#include "Timer.h"

#include <ctime>
#include <cmath>
#include <cstdlib>
using namespace std;

time_t getTime() {
	time_t returner;
	return time(&returner);
}

double totalTime(time_t start, time_t end) {
	return difftime(end, start);
}

double findDelta(time_t start) {
	return difftime(getTime(), start);
}
