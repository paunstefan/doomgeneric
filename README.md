# UEFI Doom

## Setting up the environment

UEFI Doom uses [POSIX-UEFI](https://gitlab.com/bztsrc/posix-uefi) as a development environment
to create the UEFI application, this is the easiest way, as it already implements most of
the LibC functions used by Doom.

The Makefile will do the rest of the work.

To simplify the running of the program with QEMU, [uefi-run](https://github.com/Richard-W/uefi-run)
can be used.

```bash
uefi-run -b ../OVMF.fd -q /usr/bin/qemu-system-x86_64 -f ../DOOM1.WAD  doom.efi
```

The OVMF file and the DOOM.WAD are not included in the repo, but they are freely available on the 
internet.
