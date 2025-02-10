/* 
 * File:   constVar.h
 * Author: User
 *
 * Created on 08 February 2025, 12:46
 */

#ifndef CONSTVAR_H
#define	CONSTVAR_H

#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>

#include <xc.h>
#define _XTAL_FREQ 16000000      // Internal clock 4MHz
enum
{
    LO,
    HI
};

#define LED LATCbits.LATC7 // pin 9

/********States**********/
#define STARTIR 0
#define MID1 1
#define START1 2
#define MID0 3
#define START0 4

/******pulse_types****/
#define SP 0
#define LP 1
#define SS 2
#define LS 3
#define ERR 4
#define IR  PORTBbits.RB5

/************global variables for IR code********/
volatile bool has_run = 0;
volatile unsigned int space_width, pulse_width,temp2, temp3, countRC5 = 0;
unsigned char pulse_type = SP;
unsigned char state = MID1;
volatile unsigned int RC5_code = 0x0000;
short bits = 14;        // number of bits to be shifted left to form the RC5_code (14 bits)
volatile unsigned char magic_num = 1;

#endif	/* CONSTVAR_H */

