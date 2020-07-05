#include "ver.h"
#include "lcd.h"
#include "pic18f4520.h"
#include "teclado.h"
#include "delay.h"
#include <stdio.h>

void ver_quantidade(double *vol) {

    int i;
    char y[8];
    sprintf(y, "%.1f", *vol);

    lcd_cmd(L_CLR);
    lcd_cmd(L_L1);
    lcd_str("Atual: ");
    lcd_str(y);
    lcd_str(" L");
    lcd_cmd(L_L2);
    lcd_str("0-Voltar");
    lcd_cmd(L_L2);

    for (i = 0; i < 7; i++) {
        lcd_cmd(0x10);
    }

    /*
     * Falta:
     * Adicionar o esquema dos Leds representarem o nível do tanque
     */

    unsigned int num;
    unsigned char tmp;

    TRISB = 0xF8;

    while (1) {
        TRISD = 0x0F;
        tmp = tc_tecla(0) + 0x30;
        TRISD = 0x00;
        num = (tmp - '0');
        if (num == 0) {
            break;
        }
    }
}
