#ifndef __testing_h__
#define __testing_h__

#include <stdio.h>

#define ANSI_GREEN "\033[0;32m"
#define ANSI_RED "\033[0;31m"
#define ANSI_RESET "\033[0m"

#define log_passed(M,...) fprintf(stderr,\
  ANSI_GREEN "[PASSED] " M ANSI_RESET, ##__VA_ARGS__)

#define log_failed(M,...) fprintf(stderr,\
  ANSI_RED "[FAILED] " M ANSI_RESET, ##__VA_ARGS__)

#define assert_that(A)\
  if(!(A)) { log_failed("%s", __func__); }\
      else { log_passed("%s", __func__); }

#define assert_int_eq(A, B)\
  if(A != B) { log_failed("%s got=%d expected=%d\n",__func__,A,B); }\
	else { log_passed("%s got=%d expected=%d\n",__func__,A,B); }  

#define assert_str_eq(A,B)\
  if(strcmp(A,B) != 0) { log_failed("%s got=%s expected=%s\n",__func__,A,B); }\
  else { log_passed("%s got=%s expected=%s\n",__func__,A,B); }

#endif
