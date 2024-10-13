#ifndef _SYS_STAT_H_
#define	_SYS_STAT_H_

#include "../uefi.h"
#include "../stdio.h"

/* sys/stat.h */
#define S_IREAD    0400 /* Read by owner.  */
#define S_IWRITE   0200 /* Write by owner.  */
#define S_IFMT  0170000 /* These bits determine file type.  */
#define S_IFIFO 0010000 /* FIFO.  */
#define S_IFCHR 0020000 /* Character device.  */
#define S_IFDIR 0040000 /* Directory.  */
#define S_IFBLK 0060000 /* Block device.  */
#define S_IFREG 0100000 /* Regular file.  */
#define S_ISTYPE(mode, mask)    (((mode) & S_IFMT) == (mask))
#define S_ISCHR(mode)   S_ISTYPE((mode), S_IFCHR)
#define S_ISDIR(mode)   S_ISTYPE((mode), S_IFDIR)
#define S_ISBLK(mode)   S_ISTYPE((mode), S_IFBLK)
#define S_ISREG(mode)   S_ISTYPE((mode), S_IFREG)
#define S_ISFIFO(mode)  S_ISTYPE((mode), S_IFIFO)
struct stat {
    mode_t      st_mode;
    off_t       st_size;
    blkcnt_t    st_blocks;
    time_t      st_atime;
    time_t      st_mtime;
    time_t      st_ctime;
};
extern int stat (const char_t *__file, struct stat *__buf);
extern int fstat (FILE *__f, struct stat *__buf);
extern int mkdir (const char_t *__path, mode_t __mode);

#endif