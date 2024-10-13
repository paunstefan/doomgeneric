#ifndef TIME_H
#define TIME_H
#include "uefi.h"

/* time.h */
struct tm {
  int tm_sec;   /* Seconds. [0-60] (1 leap second) */
  int tm_min;   /* Minutes. [0-59] */
  int tm_hour;  /* Hours.   [0-23] */
  int tm_mday;  /* Day.	    [1-31] */
  int tm_mon;   /* Month.   [0-11] */
  int tm_year;  /* Year     - 1900.  */
  int tm_wday;  /* Day of week. [0-6] (not set) */
  int tm_yday;  /* Days in year.[0-365] (not set) */
  int tm_isdst; /* DST.     [-1/0/1]*/
};
extern struct tm *localtime (const time_t *__timer);
extern time_t mktime(const struct tm *__tm);
extern time_t time(time_t *__timer);

#endif