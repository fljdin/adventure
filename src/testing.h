#ifndef __testing_h__
#define __testing_h__

#include <stdio.h>

#define log_passed(M, ...) fprintf(stderr, "\033[0;32m[PASSED] " M "\n\033[0m", ##__VA_ARGS__)
#define log_failed(M, ...) fprintf(stderr, "\033[0;31m[FAILED] " M "\n\033[0m", ##__VA_ARGS__)

#define assert_that(A, M, ...) if(!(A)) { log_failed(M, ##__VA_ARGS__); }\
	                       else { log_passed(M, ##__VA_ARGS__); }

#endif
