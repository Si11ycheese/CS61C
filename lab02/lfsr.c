#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "lfsr.h"

uint16_t getBit(uint16_t reg,uint16_t n){
   reg=reg>>n;
   return (reg&1);
}
void modifyBit(uint16_t *reg,uint16_t n,uint16_t v){
    uint16_t temp=~(1<<n);
    *reg=(*reg&temp);
    *reg=(*reg)|(v<<n);
}
void lfsr_calculate(uint16_t *reg) {
    /* YOUR CODE HERE */
    uint16_t reg0= getBit(*reg,0);
    uint16_t reg2= getBit(*reg,2);
    uint16_t reg3= getBit(*reg,3);
    uint16_t reg5= getBit(*reg,5);
    uint16_t reg15=reg5^(reg3^(reg2^reg0));
    *reg= *reg>>1;
    modifyBit(reg,15,reg15);
}

