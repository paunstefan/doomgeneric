#ifndef STRING_H
#define STRING_H
#include "uefi.h"

/* string.h */
extern void *memcpy(void *__dest, const void *__src, size_t __n);
extern void *memmove(void *__dest, const void *__src, size_t __n);
extern void *memset(void *__s, int __c, size_t __n);
extern int memcmp(const void *__s1, const void *__s2, size_t __n);
extern void *memchr(const void *__s, int __c, size_t __n);
extern void *memrchr(const void *__s, int __c, size_t __n);
void *memmem(const void *haystack, size_t hl, const void *needle, size_t nl);
void *memrmem(const void *haystack, size_t hl, const void *needle, size_t nl);
extern char_t *strcpy (char_t *__dest, const char_t *__src);
extern char_t *strncpy (char_t *__dest, const char_t *__src, size_t __n);
extern char_t *strcat (char_t *__dest, const char_t *__src);
extern char_t *strncat (char_t *__dest, const char_t *__src, size_t __n);
extern int strcmp (const char_t *__s1, const char_t *__s2);
extern int strncmp (const char_t *__s1, const char_t *__s2, size_t __n);
extern char_t *strdup (const char_t *__s);
extern char_t *strchr (const char_t *__s, int __c);
extern char_t *strrchr (const char_t *__s, int __c);
extern char_t *strstr (const char_t *__haystack, const char_t *__needle);
extern char_t *strtok (char_t *__s, const char_t *__delim);
extern char_t *strtok_r (char_t *__s, const char_t *__delim, char_t **__save_ptr);
extern size_t strlen (const char_t *__s);

#endif