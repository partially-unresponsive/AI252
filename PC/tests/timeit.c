#include "timeit.h"

void get_desc_time(uint64_t ns, char *buf, int len)
{
	uint64_t nano_per_sec = 1000000000;
	uint64_t nano_per_milli = 1000000;
	uint64_t nano_per_micro = 1000;
	uint64_t unit = 1000;

	uint64_t nanos = ns % unit;
	uint64_t micros = ns / nano_per_micro % unit;
	uint64_t millis = ns / nano_per_milli % unit;
	uint64_t seconds = ns / nano_per_sec;

	memset(buf, '\0', len);
	if (seconds > 0) {
		snprintf(buf+strlen(buf), len-strlen(buf), "%lus", seconds);
	}

	if (millis > 0) {
		snprintf(buf+strlen(buf), len-strlen(buf), "%lums", millis);
	}

	if (micros > 0) {
		snprintf(buf+strlen(buf), len-strlen(buf), "%luus", micros);
	}

	if (nanos > 0) {
		snprintf(buf+strlen(buf), len-strlen(buf), "%luns", nanos);
	}
}