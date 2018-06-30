/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#if defined(__XC)
#include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
#include <htc.h>        /* HiTech General Include File */
#endif

#include <stdint.h>         /* For uint8_t definition */
#include <stdbool.h>        /* For true/false definition */

#include "user.h"
#include "system.h"

/******************************************************************************/
/* User Functions                                                             */
/******************************************************************************/

/* <Initialize variables in user.h and insert code for user algorithms.> */

void InitApp(void) {
    /* TODO Initialize User Ports/Peripherals/Project here 
    
    кнопки
    RE5 - lock
    RE6 - unlock
    RE7 - ch2
    RE2 - F 
    Включаются еденицей на  RB7
    
     */

    TRISE |= 0xE4; //Turn RE2,RE5,RE6,RE7 as input (11100100))

    TRISB &= ~0x80; // set RB7 as output
    PORTB |= 0x80;

    TRISF &= ~0x01; //Turn RF0 as output(посдсветка))
    PORTF &= ~0x01; //Set low level on RF0 pin

    TRISD &= ~0x04; //Turn RD2 as output(вибро))
    PORTD |= 0x04; //Set high level on RD2 pin

    TRISF &= ~0x04; //Turn RF2 as output(пищалка))
    PORTF &= ~0x04; //Set high level on RD2 pin
    /* Setup analog functionality and port direction */

    /* Initialize peripherals */

    /* Enable interrupts */
}

/*Обработка дребезга*/
bool CheckButton1(void) {
    unsigned char result = 0;
    //unsigned int butcount = 0;

    if (RE5) {
        __delay_ms(20);
        if (RE5) {
            result = 1;
        }
    }

    /*while (RE5) {
        if (butcount < 1000) {
            butcount++;
        } else {
            result = 1;
            break;
        }
    }*/

    return result;
}

bool CheckButton2(void) {
    unsigned char result = 0;
    //unsigned int butcount = 0;

    if (RE6) {
        __delay_ms(20);
        if (RE6) {
            result = 1;
        }
    }

    /*while (RE6) {
        if (butcount < 1000) {
            butcount++;
        } else {
            result = 1;
            break;
        }
    }*/

    return result;
}

bool CheckButton3(void) {
    unsigned char result = 0;
    //unsigned int butcount = 0;

    if (RE7) {
        __delay_ms(20);
        if (RE7) {
            result = 1;
        }
    }

    /*while (RE7) {
        if (butcount < 1000) {
            butcount++;
        } else {
            result = 1;
            break;
        }
    }*/

    return result;
}

/*bool CheckButton4(void) {
    unsigned char result = 0;
    
    if (RE2) {
        __delay_ms(20);
        if (RE2) {
            result = 1;
        }
    }

    return result;
}*/

void LCDstart() {
    LCDEN = 1;
    SLPEN = 0;
    VLCDEN = 1;
    CS1 = 0;
    CS0 = 0;
    LMUX0 = 1;
    LMUX1 = 1;
    WFT = 1;
    BIASMD = 0;
    LP3 = 0;
    LP2 = 0;
    LP1 = 0;
    LP0 = 0;
    SE2 = 1;
    SE3 = 1;
    SE4 = 1;
    SE5 = 1;
    SE6 = 1;
    SE7 = 1;
    SE8 = 1;
    SE9 = 1;
    SE11 = 1;
    SE15 = 1;
    SE16 = 1;
    SE17 = 1;
    SE18 = 1;
    SE19 = 1;
    SE20 = 1;
    SE21 = 1;
    SE22 = 1;
    SE28 = 1;
    SE29 = 1;
    SE30 = 1;
    SE31 = 1;
    SE34 = 1;
    SE35 = 1;
    SE36 = 1;
    SE37 = 1;
}

void Light() {
    PORTF ^= 0x01;
    __delay_ms(500);
}

void Vibro() {
    PORTDbits.RD2 = 0;
    __delay_ms(500);
    PORTDbits.RD2 = 1;
}

void Beeper() {
    PORTFbits.RF2 = 0;
    __delay_ms(500);
    PORTFbits.RF2 = 1;
}