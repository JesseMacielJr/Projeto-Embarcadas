#include "encher.h"
#include "lcd.h"
#include "pic18f4520.h"
#include "delay.h"
#include "teclado.h"
#include "pwm.h"
#include <stdio.h>

void encher_tanque(double *vol) {

    //Mensagem inicial da fun��o
    lcd_cmd(L_CLR);
    lcd_cmd(L_L1);
    lcd_str("Quant(L): ");
    lcd_cmd(L_L2);
    lcd_str("RB1-voltar");
    lcd_cmd(L_L1 + 10);
    //atraso_ms(1000);



    unsigned int incremento;

    unsigned int i = 0;
    unsigned int num[2];
    unsigned char tmp;

    TRISB = 0xF8;

    while (i != 2) {
        TRISD = 0x0F;
        tmp = tc_tecla(0) + 0x30;
        TRISD = 0x00;
        lcd_dat(tmp);
        if (i == 0) {
            num[i] = (tmp - '0')*10;
        } else {
            num[i] = (tmp - '0');
        }
        i++;
    }

    TRISA = 0x20;
    TRISB = 0x3F;

    atraso_ms(500);
    lcd_cmd(L_CLR);

    incremento = num[0] + num[1];

    if (*vol + incremento > 70) {

        //Mensagem falha
        lcd_cmd(L_CLR);
        lcd_cmd(L_L1);
        lcd_str("ERRO: vol > MAX");
        lcd_cmd(L_L2);
        lcd_str("RB1-Voltar");

        BitClr(PORTC, 1);

        /* BUZZER */
        BitSet(TRISC, 1);
        /* FIM BUZZER */

    } else {

        *vol += incremento;
        char y[8];
        sprintf(y, "%.1f", *vol);
        lcd_str(y);
        lcd_str(" L");
        atraso_ms(500);

        ////////////OPERA��O//////////////
        int tempo = incremento / 2;
        int t1, t2;
        float porcento;
        int i = 0, potencia = 100;
        int numeros[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D,
            0x07, 0x7F, 0x6F};

        TRISA = 0x00; //config da porta A;

        lcd_cmd(L_CLR);
        lcd_cmd(L_L1);
        lcd_str("Enchendo...");
        lcd_cmd(L_L2);
        lcd_str("Aguarde!");

        pwmInit();

        //Timer para finaliza��o
        t1 = tempo / 10;
        t2 = tempo % 10;
        while ((t1 != 0) || (t2 != 0)) {
            /* funcao para a potencia do
             * cooler ser linear de acordo
             * com o restante de tempo 
             */
            porcento = ((((float) t1 * 10.0) + (float) t2) / (float) tempo);
            potencia = 100 * porcento;
            if (potencia == 100) {
                potencia = 99;
            }
            pwmSet1(potencia);

            //print nos displays
            BitClr(PORTA, 5);
            BitSet(PORTA, 4);
            PORTD = numeros[t1];
            atraso_ms(5);
            BitSet(PORTA, 5);
            BitClr(PORTA, 4);
            PORTD = numeros[t2];
            atraso_ms(5);

            if (i == 40) {
                i = 0;
                if (t2 == 0) {
                    t1--;
                    t2 = 9;
                } else {
                    t2--;
                }
            } else {
                i++;
            }
        }
        pwmSet1(0);
        
        /* BUZZER */
        BitSet(TRISC, 1);
        /* FIM BUZZER */
        
        BitClr(PORTA, 5);
        BitClr(PORTA, 4);

        //Mensagem �xito
        lcd_cmd(L_CLR);
        lcd_cmd(L_L1);
        lcd_str("    SUCESSO!");
        lcd_cmd(L_L2);
        lcd_str("    0-Voltar");
    }

    /*
     * Falta:
     * Adicionar o esquema dos Leds representarem o n�vel do tanque
     */

    unsigned int opt;

    TRISB = 0xF8;

    while (1) {
        TRISD = 0x0F;
        tmp = tc_tecla(0) + 0x30;
        TRISD = 0x00;
        opt = (tmp - '0');
        if (opt == 0) {
            BitClr(TRISC, 1);
            break;
        }
    }

}
