/*
 *TODO: License header
 */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "logf.h"

static void
log_writer(struct logf_t *log_handle, const char * const log_prefix,
		const char * const format, ...) {
	va_list args;
	char composed_format[LOGF_MAX_LOG_LENGTH] = {0};
	char entry[LOGF_MAX_LOG_LENGTH] = {0};

	snprintf(composed_format, LOGF_MAX_LOG_LENGTH, "%s\t%s", log_prefix, format);

	va_start(args, format);
	vsnprintf(entry, LOGF_MAX_LOG_LENGTH, composed_format, args);
	va_end(args);

	log_handle->log_sink(entry);
}

void
logf_init(struct logf_t *log_handle, void (*log_sink)(char * const)) {
	log_handle->log_sink = log_sink;
	log_handle->log_writer = &log_writer;
}
