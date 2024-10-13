#ifndef UNISTD_H
#define UNISTD_H
#include "uefi.h"

/* unistd.h */
extern unsigned int sleep (unsigned int __seconds);
extern int usleep (unsigned long int __useconds);
extern int unlink (const wchar_t *__filename);
extern int rmdir (const wchar_t *__filename);

#endif