#ifndef STDLIB_H
#define STDLIB_H
#include "uefi.h"

/* stdlib.h */
#define RAND_MAX       2147483647
typedef int (*__compar_fn_t) (const void *, const void *);
extern int atoi (const char_t *__nptr);
extern int64_t atol (const char_t *__nptr);
extern int64_t strtol (const char_t *__nptr, char_t **__endptr, int __base);
extern void *malloc (size_t __size);
extern void *calloc (size_t __nmemb, size_t __size);
extern void *realloc (void *__ptr, size_t __size);
extern void free (void *__ptr);
extern void abort (void);
extern void exit (int __status);
/* exit Boot Services function. Returns 0 on success. */
extern int exit_bs(void);
extern void *bsearch (const void *__key, const void *__base, size_t __nmemb, size_t __size, __compar_fn_t __compar);
extern void qsort (void *__base, size_t __nmemb, size_t __size, __compar_fn_t __compar);
extern int mblen (const char *__s, size_t __n);
extern int mbtowc (wchar_t * __pwc, const char * __s, size_t __n);
extern int wctomb (char *__s, wchar_t __wchar);
extern size_t mbstowcs (wchar_t *__pwcs, const char *__s, size_t __n);
extern size_t wcstombs (char *__s, const wchar_t *__pwcs, size_t __n);
extern void srand(unsigned int __seed);
extern int rand(void);
extern uint8_t *getenv(char_t *name, uintn_t *len);
extern int setenv(char_t *name, uintn_t len, uint8_t *data);

#endif