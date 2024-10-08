/*
 * BIT_MATH.h
 *
 * Created: 7/12/2024 9:08:26 PM
 *  Author: Carnival Stores
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(REG,BIT) REG|= (1<<BIT)

#define CLR_BIT(REG,BIT) REG&=~(1<<BIT)

#define TGL_BIT(REG,BIT) REG^= (1<<BIT)

#define GET_BIT(REG,BIT) ((REG>>BIT)&1)




#endif /* BIT_MATH_H_ */