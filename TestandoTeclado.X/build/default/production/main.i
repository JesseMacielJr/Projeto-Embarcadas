# 1 "main.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:/Users/gabri/.mchp_packs/Microchip/PIC18Fxxxx_DFP/1.2.26/xc8\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "main.c" 2
# 1 "./config.h" 1
# 38 "./config.h"
#pragma config OSC=HS
#pragma config WDT=OFF
#pragma config LVP=OFF
#pragma config DEBUG = OFF
#pragma config WDTPS = 1
# 1 "main.c" 2

# 1 "./pic18f4520.h" 1
# 2 "main.c" 2

# 1 "./delay.h" 1



void atraso_ms(int t);
# 3 "main.c" 2

# 1 "./lcd.h" 1
# 14 "./lcd.h"
void lcd_init(void);
void lcd_cmd(unsigned char val);
void lcd_dat(unsigned char val);
void lcd_str(const char* str);
# 4 "main.c" 2

# 1 "./teclado.h" 1







    unsigned char tc_tecla(unsigned int timeout);
# 5 "main.c" 2

# 1 "./ver.h" 1



void ver_quantidade(double *);
# 6 "main.c" 2

# 1 "./encher.h" 1



void encher_tanque(double *);
# 7 "main.c" 2

# 1 "./esvaziar.h" 1



void esvaziar_tanque(double *);
# 8 "main.c" 2


unsigned int atrasoMin = 20;
unsigned int atrasoMed = 500;
unsigned int atrasoMax = 1000;
double volume = 0;
int i;

void main() {

    (*(volatile __near unsigned char*)0xFC1) = 0x06;
    (*(volatile __near unsigned char*)0xF93) = 0x01;
    (*(volatile __near unsigned char*)0xF95) = 0x00;
    (*(volatile __near unsigned char*)0xF95) = 0x00;
    (*(volatile __near unsigned char*)0xF96) = 0x00;

    lcd_init();


    lcd_cmd(0x01);
    lcd_cmd(0x80);
    lcd_str("Abastecimento de");
    lcd_cmd(0xC0);
    lcd_str("      agua");
    atraso_ms(atrasoMin);
    lcd_cmd(0x01);


    lcd_cmd(0x80);
    lcd_str("Vol max = 70L");
    lcd_cmd(0xC0);
    lcd_str("Vazao: 0.5 L/s");
    atraso_ms(atrasoMin);
    lcd_cmd(0x01);

    int flag = 0;

    while (1) {

        flag = 0;
        lcd_cmd(0x01);
        lcd_cmd(0x80);
        lcd_str("1-Ver 2-Encher");
        lcd_cmd(0xC0);
        lcd_str("3-Retirar");


        (*(volatile __near unsigned char*)0xF93) = 0xF8;
        (*(volatile __near unsigned char*)0xF92) = 0x20;
        (*(volatile __near unsigned char*)0xF93) = 0x3F;
        (*(volatile __near unsigned char*)0xF92) = 0x20;
        (*(volatile __near unsigned char*)0xF93) = 0x3F;
        (*(volatile __near unsigned char*)0xF96) = 0x00;
# 72 "main.c"
        unsigned int opt;
        unsigned char tmp;

        (*(volatile __near unsigned char*)0xF93) = 0xF8;

        while (1) {
            (*(volatile __near unsigned char*)0xF95) = 0x0F;
            tmp = tc_tecla(0) + 0x30;
            (*(volatile __near unsigned char*)0xF95) = 0x00;
            opt = (tmp - '0');
        if (opt == 0) {
            break;
        } else if (opt == 1) {
            ver_quantidade(&volume);
        } else if (opt == 2) {
            encher_tanque(&volume);
        } else if (opt == 3) {
            esvaziar_tanque(&volume);
        } else {
            lcd_cmd(0x01);
            lcd_str("    INVALIDO!");
            break;
        }
    }
}
}
