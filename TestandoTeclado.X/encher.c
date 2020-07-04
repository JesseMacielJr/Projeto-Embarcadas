#include "encher.h"
#include "lcd.h"
#include "pic18f4520.h"
#include "delay.h"
#include "teclado.h"
#include <stdio.h>

void encher_tanque(double *vol) {

    //Mensagem inicial da função
    lcd_cmd(L_CLR);
    lcd_cmd(L_L1);
    lcd_str("Quant(L): ");
    lcd_cmd(L_L2);
    lcd_str("RB1-voltar");
    lcd_cmd(L_L1+10);
    //atraso_ms(1000);
    
    
    
    unsigned int incremento;

    unsigned int i = 0;
    unsigned int num[2];
    unsigned char tmp;
    
    TRISB = 0xF8;
    
    while (i!=2) {
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
    
    atraso_ms(500);
    lcd_cmd(L_CLR);
    
    incremento = num[0]+num[1];
    
    if (*vol + incremento > 70) {

        //Mensagem falha
        lcd_cmd(L_CLR);
        lcd_cmd(L_L1);
        lcd_str("ERRO: vol > MAX");
        lcd_cmd(L_L2);
        lcd_str("RB1-Voltar");

        //
        //Código do buzzer aqui
        //

    } else {

        *vol += incremento;
        char y[8];
        sprintf(y, "%.1f", *vol);
        lcd_str(y);
        lcd_str(" L");

        ////////////OPERAÇÃO//////////////
        int tempo = incremento / 2;
        int i;
        int numeros[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D,
            0x07, 0x7F, 0x6F};

        TRISA = 0x00; //config da porta A;
        BitSet(PORTA, 5); //liga o 1o display
        //BitSet(PORTA, 4); //liga o 2o display
        //BitSet(PORTA, 3); //liga o 3o display
        //BitSet(PORTA, 2); //liga o 4o display;

        lcd_cmd(L_CLR);
        lcd_cmd(L_L1);
        lcd_str("Enchendo...");
        lcd_cmd(L_L2);
        lcd_str("Aguarde!");

        //
        //Código do Cooler (fazer com que seja simultâneo ao Display)
        //

        //Timer para finalização        Falta alterar para tempo maior que 9 ou float
        for (i = tempo; i >= 0; i--) {
            PORTD = numeros[i];
            atraso_ms(1000);
        }
        BitClr(PORTA, 5);

        //Mensagem êxito
        lcd_cmd(L_CLR);
        lcd_cmd(L_L1);
        lcd_str("    SUCESSO!");
        lcd_cmd(L_L2);
        lcd_str("   RB1-Voltar");

        //
        //Código do buzzer aqui
        //

        ////////////OPERAÇÃO//////////////

    }

    /*
     * Falta:
     * Sistema de adicionar a quantidade de agua que se deseja adicionar
     * Calculo do tempo de enchimento
     * Printar o tempo estimado no display de 7 segmentos
     * Adicionar o esquema dos Leds representarem o nível do tanque
     */

    while((BitTst(PORTB, 1))){
    }
    
}
