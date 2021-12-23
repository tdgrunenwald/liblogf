#include <stdio.h>

#include "logf.h"

void stdout_sink(char * const log) {
	fprintf(stdout, log);
}

void main(int argc, char **argv) {
	struct logf_t log;

	logf_init(&log, &stdout_sink);

	LOGF_DEBUG(&log, "HELLO, WORLD!");
}
