//
// Created by olivier on 25/09/15.
//

#ifndef RTP_DEBUG_H
#define RTP_DEBUG_H


#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

#include <stdio.h>
#include <errno.h>
#include <string.h>

#ifdef DBG_VERBOSE
#define debug(M, ...) fprintf(stderr, "DEBUG %s:%d: " M "\n", __FILENAME__, __LINE__, ##__VA_ARGS__)
#else
#define debug(M, ...)
#endif

#define clean_errno() (errno == 0 ? "None" : strerror(errno))

#define log_err(M, ...) fprintf(stderr, "[ERROR] (%s:%d: errno: %s) " M "\n", __FILENAME__, __LINE__, clean_errno(), ##__VA_ARGS__)

#define log_warn(M, ...) fprintf(stderr, "[WARN] (%s:%d: errno: %s) " M "\n", __FILENAME__, __LINE__, clean_errno(), ##__VA_ARGS__)

#define log_info(M, ...) fprintf(stdout, "[INFO] (%s:%d) " M "\n", __FILENAME__, __LINE__, ##__VA_ARGS__)

#define check(A, M, ...) if(!(A)) { log_err(M, ##__VA_ARGS__); errno=0; goto error; }

#define sentinel(M, ...)  { log_err(M, ##__VA_ARGS__); errno=0; goto error; }

#define check_mem(A) check((A), "Out of memory.")

#define check_debug(A, M, ...) if(!(A)) { debug(M, ##__VA_ARGS__); errno=0; goto error; }

#ifdef DBG_EXE
#define dbg_exe(M) M
#else
#define dbg_exe(M)
#endif

#ifdef DBG_TEST_EXE
#define dbg_test_exe(M) M
#else
#define dbg_test_exe(M)
#endif

#define dbg_check(A, M, ...) dbg_exe(check(A, M, ##__VA_ARGS__))


#endif //RTP_DEBUG_H
