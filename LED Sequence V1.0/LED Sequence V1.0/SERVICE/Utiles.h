/*
 * Utiles.h
 *
 * Created: 03/04/2023 12:20:17 م
 *  Author: Genius
 */ 


#ifndef UTILES_H_
#define UTILES_H_

/*******************************macros***************************************************/

#define set_bit(reg,bit)            reg=(reg|(1<<bit))
#define clear_bit(reg,bit)           reg=(reg&(~(1<<bit)))
#define read_bit(reg,bit)              ((reg>>bit)&1)
#define toggel_bit(reg,bit)              reg=reg^(1<<bit)



#endif /* UTILES_H_ */