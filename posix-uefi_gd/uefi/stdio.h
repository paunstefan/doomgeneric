#ifndef STDIO_H
#define STDIO_H

#include "uefi.h"

#ifndef BUFSIZ
#define BUFSIZ 8192
#endif
#define SEEK_SET	0	/* Seek from beginning of file.  */
#define SEEK_CUR	1	/* Seek from current position.  */
#define SEEK_END	2	/* Seek from end of file.  */
#define stdin (FILE*)ST->ConsoleInHandle
#define stdout (FILE*)ST->ConsoleOutHandle
#define stderr (FILE*)ST->ConsoleErrorHandle
typedef struct efi_file_handle_s FILE;
extern int fclose (FILE *__stream);
extern int fflush (FILE *__stream);
extern int remove (const char_t *__filename);
extern FILE *fopen (const char_t *__filename, const char_t *__modes);
extern size_t fread (void *__ptr, size_t __size, size_t __n, FILE *__stream);
extern size_t fwrite (const void *__ptr, size_t __size, size_t __n, FILE *__s);
extern int fseek (FILE *__stream, long int __off, int __whence);
extern long int ftell (FILE *__stream);
extern int feof (FILE *__stream);
extern int fprintf (FILE *__stream, const char_t *__format, ...);
extern int printf (const char_t *__format, ...);
extern int sprintf (char_t *__s, const char_t *__format, ...);
extern int vfprintf (FILE *__s, const char_t *__format, __builtin_va_list __arg);
extern int vprintf (const char_t *__format, __builtin_va_list __arg);
extern int vsprintf (char_t *__s, const char_t *__format, __builtin_va_list __arg);
extern int snprintf (char_t *__s, size_t __maxlen, const char_t *__format, ...);
extern int vsnprintf (char_t *__s, size_t __maxlen, const char_t *__format, __builtin_va_list __arg);
extern int getchar (void);
/* non-blocking, only returns UNICODE if there's any key pressed, 0 otherwise */
extern int getchar_ifany (void);
extern int putchar (int __c);
extern int puts(const char *s);

#endif