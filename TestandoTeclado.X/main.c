#include "config.h"
#include "pic18f4520.h"
#include "delay.h"
#include "lcd.h"
#include "teclado.h"
#include "ver.h"
#include "encher.h"
#include "esvaziar.h"

unsigned int atrasoMin = 20;
unsigned int atrasoMed = 500;
unsigned int atrasoMax = 1000;
double volume = 0;
int i;

void main() {

    ADCON1 = 0x06;
    TRISB = 0x01;
    TRISD = 0x00;
    TRISE = 0x00;
    lcd_init();

    //Apresentação
    lcd_cmd(L_CLR);
    lcd_cmd(L_L1);
    lcd_str("Abastecimento de");
    lcd_cmd(L_L2);
    lcd_str("      agua");
    atraso_ms(atrasoMin);
    lcd_cmd(L_CLR);

    //Especificações
    lcd_cmd(L_L1);
    lcd_str("Vol max = 70L");
    lcd_cmd(L_L2);
    lcd_str("Vazao: 0.5 L/s");
    atraso_ms(atrasoMin);
    lcd_cmd(L_CLR);

    while (1) {
        //Menu de opções
        lcd_cmd(L_CLR);
        lcd_cmd(L_L1);
        lcd_str("1-Ver 2-Encher");
        lcd_cmd(L_L2);
        lcd_str("3-Retirar");

        unsigned int opt;
        unsigned char tmp;

        TRISB = 0xF8;

        while (1) {
            TRISD = 0x0F;
            tmp = tc_tecla(0) + 0x30;
            TRISD = 0x00;
            opt = (tmp - '0');
            if (opt == 1) {
                ver_quantidade(&volume);
                break;
            } else if (opt == 2) {
                encher_tanque(&volume);
                break;
            } else if (opt == 3) {
                esvaziar_tanque(&volume);
                break;
            } else {
                lcd_cmd(L_CLR);
                lcd_str("    INVALIDO!");
                atraso_ms(200);
                break;
            }
        }
    }
}
