/*
 * Bit_Math.h
 *
 *  Created on: Oct 12, 2023
 *      Author: Unlimited
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(Register,Bit_no) 		(Register|=(1<<Bit_no))

#define CLEAR_BIT(Register,Bit_no) 		(Register&=~(1<<Bit_no))

#define TOGGLE_BIT(Register,Bit_no) 	(Register^=(1<<Bit_no))

#define READ_BIT(Register,Bit_no)  	((Register>>Bit_no)&0x01)

#define READ_REG(x)		((x))
#define WRITE_REG(x,VALUE)		((x)=(VALUE))
#define	MIDIFY_REG(x,CLEARMASK,SETMASK)		WRITE_REG((x),(((READ_REG(x))&(~(CLEARMASK)))|(SETMASK)))

#endif /* BIT_MATH_H_ */
