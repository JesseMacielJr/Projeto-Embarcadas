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
    atraso_ms(1000);
    lcd_cmd(L_CLR);

    //Especificações
    lcd_cmd(L_L1);
    lcd_str("Vol max = 70L");
    lcd_cmd(L_L2);
    lcd_str("Vazao: 1.5 L/s");
    atraso_ms(2000);
    lcd_cmd(L_CLR);

    int flag = 0;

    while (1) {
        //Menu de opções
        flag = 0;
        lcd_cmd(L_CLR);
        lcd_cmd(L_L1);
        lcd_str("RB3-Ver RB4-Encher");
        lcd_cmd(L_L2);
        lcd_str("RB5-Retirar");
        for (i = 0; i < 2; i++) {
            atraso_ms(350);
            lcd_cmd(0x18);
        }
        for (i = 0; i < 2; i++) {
            atraso_ms(350);
            lcd_cmd(0x1C);
        }

        //Teclado numérico
        TRISB = 0xF8;
        TRISA = 0x20;
        TRISB = 0x3F;
        TRISA = 0x20;
        TRISB = 0x3F;
        TRISE = 0x00;

        /*
         Falta:
         * Procurar algum código fonte de calculadora para poder realizar as operações básicas (somar e subtrair os valores obtidos no teclado).
         * Declarar uma variável global que será a quantidade de água no tanque.
         * Passar essa variável como parâmetro para todas as funções acessarem e modificarem (passar a referência &)    void encher(int), etc....
         * Implementar o Buzzer
         * Implementar o Cooler
         * Implementar as mensagens de erro/sucesso das operações
         */
        while (1) {
            if (!(BitTst(PORTB, 1))) {
                break;
            }
            else if (!(BitTst(PORTB, 3))) {
                ver_quantidade(&volume);
            }
            else if (!(BitTst(PORTB, 4))) {
                encher_tanque(&volume);
            }
            else if (!(BitTst(PORTB, 5))) {
                esvaziar_tanque(&volume);
            }
        }
    }
}
