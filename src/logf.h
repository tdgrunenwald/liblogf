/*
 * TODO: License header
 */

#ifndef LOGF_MAX_LOG_LENGTH
	#define LOGF_MAX_LOG_LENGTH 256
#endif

#ifndef LOGF_DEBUG_PREFIX
	#define LOGF_DEBUG_PREFIX "[DEBUG]\t"
#endif

#define LOGF_DEBUG(log_handle, ...) \
	(log_handle)->log_writer((log_handle), LOGF_DEBUG_PREFIX, __VA_ARGS__)

struct logf_t {
	void (*log_sink)(char * const);
	void (*log_writer)(struct logf_t *, const char * const, const char * const, ...);
};

void logf_init(struct logf_t *log_handle, void (*log_sink)(char * const));

