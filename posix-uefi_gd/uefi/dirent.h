/* dirent.h */
#ifndef DIRENT_H
#define DIRENT_H

#include "uefi.h"

#define IFTODT(mode)    (((mode) & 0170000) >> 12)
#define DTTOIF(dirtype) ((dirtype) << 12)
#define DT_DIR          4
#define DT_REG          8
struct dirent {
    unsigned short int d_reclen;
    unsigned char d_type;
    char d_name[FILENAME_MAX];
};
typedef struct efi_file_handle_s DIR;
extern DIR *opendir (const char *__name);
extern struct dirent *readdir (DIR *__dirp);
extern void rewinddir (DIR *__dirp);
extern int closedir (DIR *__dirp);

#endif