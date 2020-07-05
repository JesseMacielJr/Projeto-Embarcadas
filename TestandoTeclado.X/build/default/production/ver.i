# 1 "ver.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:/Users/gabri/.mchp_packs/Microchip/PIC18Fxxxx_DFP/1.2.26/xc8\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "ver.c" 2
# 1 "./ver.h" 1



void ver_quantidade(double *);
# 1 "ver.c" 2

# 1 "./lcd.h" 1
# 14 "./lcd.h"
void lcd_init(void);
void lcd_cmd(unsigned char val);
void lcd_dat(unsigned char val);
void lcd_str(const char* str);
# 2 "ver.c" 2

# 1 "./pic18f4520.h" 1
# 3 "ver.c" 2

# 1 "./teclado.h" 1







    unsigned char tc_tecla(unsigned int timeout);
# 4 "ver.c" 2

# 1 "./delay.h" 1



void atraso_ms(int t);
# 5 "ver.c" 2

# 1 "D:\\Programs\\Microship\\xc8\\v2.20\\pic\\include\\c99\\stdio.h" 1 3



# 1 "D:\\Programs\\Microship\\xc8\\v2.20\\pic\\include\\c99\\musl_xc8.h" 1 3
# 4 "D:\\Programs\\Microship\\xc8\\v2.20\\pic\\include\\c99\\stdio.h" 2 3






# 1 "D:\\Programs\\Microship\\xc8\\v2.20\\pic\\include\\c99\\features.h" 1 3
# 10 "D:\\Programs\\Microship\\xc8\\v2.20\\pic\\include\\c99\\stdio.h" 2 3
# 24 "D:\\Programs\\Microship\\xc8\\v2.20\\pic\\include\\c99\\stdio.h" 3
# 1 "D:\\Programs\\Microship\\xc8\\v2.20\\pic\\include\\c99\\bits/alltypes.h" 1 3





typedef void * va_list[1];




typedef void * __isoc_va_list[1];
# 122 "D:\\Programs\\Microship\\xc8\\v2.20\\pic\\include\\c99\\bits/alltypes.h" 3
typedef unsigned size_t;
# 137 "D:\\Programs\\Microship\\xc8\\v2.20\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long ssize_t;
# 168 "D:\\Programs\\Microship\\xc8\\v2.20\\pic\\include\\c99\\bits/alltypes.h" 3
typedef __int24 int24_t;
# 204 "D:\\Programs\\Microship\\xc8\\v2.20\\pic\\include\\c99\\bits/alltypes.h" 3
typedef __uint24 uint24_t;
# 246 "D:\\Programs\\Microship\\xc8\\v2.20\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long long off_t;
# 399 "D:\\Programs\\Microship\\xc8\\v2.20\\pic\\include\\c99\\bits/alltypes.h" 3
typedef struct _IO_FILE FILE;
# 24 "D:\\Programs\\Microship\\xc8\\v2.20\\pic\\include\\c99\\stdio.h" 2 3
# 52 "D:\\Programs\\Microship\\xc8\\v2.20\\pic\\include\\c99\\stdio.h" 3
typedef union _G_fpos64_t {
 char __opaque[16];
 double __align;
} fpos_t;

extern FILE *const stdin;
extern FILE *const stdout;
extern FILE *const stderr;





FILE *fopen(const char *restrict, const char *restrict);
FILE *freopen(const char *restrict, const char *restrict, FILE *restrict);
int fclose(FILE *);

int remove(const char *);
int rename(const char *, const char *);

int feof(FILE *);
int ferror(FILE *);
int fflush(FILE *);
void clearerr(FILE *);

int fseek(FILE *, long, int);
long ftell(FILE *);
void rewind(FILE *);

int fgetpos(FILE *restrict, fpos_t *restrict);
int fsetpos(FILE *, const fpos_t *);

size_t fread(void *restrict, size_t, size_t, FILE *restrict);
size_t fwrite(const void *restrict, size_t, size_t, FILE *restrict);

int fgetc(FILE *);
int getc(FILE *);
int getchar(void);
int ungetc(int, FILE *);

int fputc(int, FILE *);
int putc(int, FILE *);
int putchar(int);

char *fgets(char *restrict, int, FILE *restrict);

char *gets(char *);


int fputs(const char *restrict, FILE *restrict);
int puts(const char *);

#pragma printf_check(printf) const
#pragma printf_check(vprintf) const
#pragma printf_check(sprintf) const
#pragma printf_check(snprintf) const
#pragma printf_check(vsprintf) const
#pragma printf_check(vsnprintf) const

int printf(const char *restrict, ...);
int fprintf(FILE *restrict, const char *restrict, ...);
int sprintf(char *restrict, const char *restrict, ...);
int snprintf(char *restrict, size_t, const char *restrict, ...);

int vprintf(const char *restrict, __isoc_va_list);
int vfprintf(FILE *restrict, const char *restrict, __isoc_va_list);
int vsprintf(char *restrict, const char *restrict, __isoc_va_list);
int vsnprintf(char *restrict, size_t, const char *restrict, __isoc_va_list);

int scanf(const char *restrict, ...);
int fscanf(FILE *restrict, const char *restrict, ...);
int sscanf(const char *restrict, const char *restrict, ...);
int vscanf(const char *restrict, __isoc_va_list);
int vfscanf(FILE *restrict, const char *restrict, __isoc_va_list);
int vsscanf(const char *restrict, const char *restrict, __isoc_va_list);

void perror(const char *);

int setvbuf(FILE *restrict, char *restrict, int, size_t);
void setbuf(FILE *restrict, char *restrict);

char *tmpnam(char *);
FILE *tmpfile(void);




FILE *fmemopen(void *restrict, size_t, const char *restrict);
FILE *open_memstream(char **, size_t *);
FILE *fdopen(int, const char *);
FILE *popen(const char *, const char *);
int pclose(FILE *);
int fileno(FILE *);
int fseeko(FILE *, off_t, int);
off_t ftello(FILE *);
int dprintf(int, const char *restrict, ...);
int vdprintf(int, const char *restrict, __isoc_va_list);
void flockfile(FILE *);
int ftrylockfile(FILE *);
void funlockfile(FILE *);
int getc_unlocked(FILE *);
int getchar_unlocked(void);
int putc_unlocked(int, FILE *);
int putchar_unlocked(int);
ssize_t getdelim(char **restrict, size_t *restrict, int, FILE *restrict);
ssize_t getline(char **restrict, size_t *restrict, FILE *restrict);
int renameat(int, const char *, int, const char *);
char *ctermid(char *);







char *tempnam(const char *, const char *);
# 6 "ver.c" 2


void ver_quantidade(double *vol) {

    int i;
    char y[8];
    sprintf(y, "%.1f", *vol);

    lcd_cmd(0x01);
    lcd_cmd(0x80);
    lcd_str("Atual: ");
    lcd_str(y);
    lcd_str(" L");
    lcd_cmd(0xC0);
    lcd_str("# - Voltar");
    lcd_cmd(0xC0);

    for (i = 0; i < 7; i++) {
        lcd_cmd(0x10);
    }






    unsigned char tmp;

    (*(volatile __near unsigned char*)0xF93) = 0xF8;

    while (1) {
        (*(volatile __near unsigned char*)0xF95) = 0x0F;
        tmp = tc_tecla(0) + 0x30;
        (*(volatile __near unsigned char*)0xF95) = 0x00;
        if (tmp >= 0x3C) {
            (((*(volatile __near unsigned char*)0xF94)) &= ~(1<<1));
            break;
        }
    }
}
