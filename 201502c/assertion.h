#ifndef ASSERTION_H_INCLUDED
#define ASSERTION_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sig_handler(int signo)
{
    if (signo == SIGSEGV) {
        printf("Memory management error - TEST FAILED\n");
        exit(1);
    }

};

#define dump(...) printf(__VA_ARGS__)

#define dumpAssert(value, expected)                                 \
    dump("(%s == %s) - FAILD! - %s:%d\n",                           \
        #value, #expected, __FILE__, __LINE__);                     \

#define dumpDeny(value, expected)                                   \
    dump("(%s != %s) - FAILD! - %s:%d\n",                           \
        #value, #expected, __FILE__, __LINE__);                     \

#define assert( value, expected )                                   \
    if ( (value) != (expected) ) {                                  \
        dumpAssert(value, expected);                                \
    }                                                               \

#define deny( value, expected )                                     \
    if ( (value) == (expected) ) {                                  \
        dumpDeny(value, expected);                                  \
    }                                                               \

#define assertStr( value, expected )                                \
    if (strcmp( (value), (expected) ) != 0 ) {                      \
        dumpAssert(#value, #expected);                              \
    }                                                               \

#define denyStr( value, expected )                                  \
    if (strcmp( (value), (expected) ) == 0 ) {                      \
        dumpDeny(#value, #expected);                                \
    }                                                               \

#define setupTestEnv()                                              \
    signal(SIGSEGV, sig_handler);                                   \


#endif // ASSERTION_H_INCLUDED
