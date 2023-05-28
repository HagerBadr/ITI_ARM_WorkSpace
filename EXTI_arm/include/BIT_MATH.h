/*
 * BIT_MATH.h
 *
 *  Created on: Mar 25, 2023
 *      Author: Hager Badr
 */

#ifndef LIB_BIT_MATH_H_
#define LIB_BIT_MATH_H_

#define SET_BIT(reg, bit)  (reg |= 1 << (bit))// reg = reg | (1<< bit)
#define CLR_BIT(reg, bit)  (reg &= ~(1<< bit))
#define TOG_BIT(reg,bit)   (reg ^= 1 << (bit))
#define GET_BIT(reg,bit)    ((reg>>(bit))& 1)

#define SET_REG(reg,value)	(reg=value)
#endif /* LIB_BIT_MATH_H_ */
