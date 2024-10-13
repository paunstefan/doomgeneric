/* get these from the compiler or the efi headers, only define if we have neither */
#if !defined(_STDINT_H) && !defined(_GCC_STDINT_H) && !defined(_EFI_INCLUDE_)
#define _STDINT_H
typedef char                int8_t;
typedef unsigned char       uint8_t;
typedef short               int16_t;
typedef unsigned short      uint16_t;
typedef int                 int32_t;
typedef unsigned int        uint32_t;
#ifndef __clang__
typedef long int            int64_t;
typedef unsigned long int   uint64_t;
typedef unsigned long int   uintptr_t;
#else
typedef long long           int64_t;
typedef unsigned long long  uint64_t;
typedef unsigned long long  uintptr_t;
#endif
#endif