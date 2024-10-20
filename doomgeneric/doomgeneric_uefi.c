#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <uefi.h>
#include "doomgeneric.h"


extern time_t __mktime_efi(efi_time_t *t);
uint64_t get_time_ms();

uint64_t ticks_init;
uint32_t *fb;
uint32_t ppl;

void DG_Init()
{
    ticks_init = get_time_ms();

    efi_status_t status;
    efi_guid_t gopGuid = EFI_GRAPHICS_OUTPUT_PROTOCOL_GUID;
    efi_gop_t *gop = NULL;
    efi_gop_mode_info_t *info = NULL;
    uintn_t isiz = sizeof(efi_gop_mode_info_t), currentMode, i;

    BS->LocateProtocol(&gopGuid, NULL, (void **)&gop);

    status = gop->SetMode(gop, 2); // 640x480
    /* changing the resolution might mess up ConOut and StdErr, better to reset them */
    ST->ConOut->Reset(ST->ConOut, 0);
    ST->StdErr->Reset(ST->StdErr, 0);
    if (EFI_ERROR(status))
    {
        fprintf(stderr, "unable to set video mode\n");
    }

    gop->QueryMode(gop, gop->Mode ? gop->Mode->Mode : 0, &isiz, &info);

    fb = (uint32_t*)gop->Mode->FrameBufferBase;
    ppl = info->PixelsPerScanLine;
}

void DG_DrawFrame()
{
    for(int i = 0; i < DOOMGENERIC_RESY * DOOMGENERIC_RESX; i++){
        *((uint32_t *)(fb + i)) = DG_ScreenBuffer[i];
    }
}

void DG_SleepMs(uint32_t ms)
{
    usleep(ms * 1000);
}

uint32_t DG_GetTicksMs()
{
    uint64_t current = get_time_ms();
    uint32_t ticks = current - ticks_init;
    return ticks;
}

int DG_GetKey(int *pressed, unsigned char *doomKey)
{
    return 0;
}

void DG_SetWindowTitle(const char *title)
{
}

uint64_t get_time_ms(){
    time_t ts;
    efi_time_t t = {0};
    ST->RuntimeServices->GetTime(&t, NULL);
    ts = __mktime_efi(&t);
    uint32_t ms = t.Nanosecond / 1000000;
    uint64_t ret = ts * 1000 + ms;
    return ret;
}


// Maybe temporary
int _fltused = 0;

int toupper(int ch){
    if(ch >= 97 && ch <= 122){
        return ch - 32;
    }
    return ch;
}

double fabs(double x)
{
    if(x < 0){
        return -x;
    }
    return x;
}

int strcasecmp(const char *s1, const char *s2)
{   
    char *normal_s1 = (char*)calloc(strlen(s1) + 1, 1);
    for(int i = 0; i < strlen(s1);i++){
        normal_s1[i] = toupper(s1[i]);
    }
    char *normal_s2 = (char*)calloc(strlen(s2) + 1, 1);
    for(int i = 0; i < strlen(s2);i++){
        normal_s2[i] = toupper(s2[i]);
    }

    return strcmp(normal_s1, normal_s2);
}
int strncasecmp(const char *s1, const char *s2, size_t n)
{   
    char *normal_s1 = (char*)calloc(strlen(s1) + 1, 1);
    for(int i = 0; i < strlen(s1);i++){
        normal_s1[i] = toupper(s1[i]);
    }

    char *normal_s2 = (char*)calloc(strlen(s2) + 1, 1);
    for(int i = 0; i < strlen(s2);i++){
        normal_s2[i] = toupper(s2[i]);
    }

    return strncmp(normal_s1, normal_s2, n);
}

#undef abs  // already defined as macro in uefi.h, but I need it as a function

int abs(int x){
    if(x < 0){
        return -x;
    }
    return x;
}

int main(int argc, char **argv)
{
    doomgeneric_Create(argc, argv);

    for (int i = 0; ; i++)
    {
        doomgeneric_Tick();
    }
    

    return 0;
}