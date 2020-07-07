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
    lcd_str("# - Voltar");
    lcd_cmd(L_L2);

    for (i = 0; i < 7; i++) {
        lcd_cmd(0x10);
    }

    TRISD = 0x00;
    if (*vol == 0) {
        PORTD = 0b00000000;
    } else if (*vol > 0 && *vol <= 10) {
        PORTD = 0b10000000;
    } else if (*vol > 10 && *vol <= 20) {
        PORTD = 0b11000000;
    } else if (*vol > 20 && *vol <= 30) {
        PORTD = 0b11100000;
    } else if (*vol > 30 && *vol <= 40) {
        PORTD = 0b11110000;
    } else if (*vol >= 40 && *vol <= 50) {
        PORTD = 0b11111100;
    } else if (*vol > 50 && *vol <= 60) {
        PORTD = 0b11111110;
    } else if (*vol > 60 && *vol <= 70) {
        PORTD = 0b11111111;
    }

    while ((BitTst(PORTB, 3))) {
    }

}
