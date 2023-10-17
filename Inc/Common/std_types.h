/*
 * std_types.h
 *
 *  Created on: Oct 11, 2023
 *      Author: Unlimited
 */

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

/*Section includes */

/*Section macros */

/*Section macros function  */

/*Section Data type */
typedef unsigned char 		uint8_t;
typedef signed char 		sint8_t;
typedef  unsigned short int 	uint16_t;
typedef signed short int  	sint16_t;
typedef unsigned long int  	uint32_t;
typedef signed  long int	sint32_t;
typedef float 				f32_t;
typedef double 				f64_t;


		typedef enum
		{
	FALSE,
	TRUE
		}boolean;
/*Section function declaration  */



        /*%c        Character
%d                  Signed integer
%e or %E            Scientific notation of floats
%f                  Float values
%g or %G            Similar as %e or %E
%hi                 Signed integer (short)
%hu                 Unsigned Integer (short)
%i                  Unsigned integer
%l or %ld or %li	Long
%lf                 Double
%Lf                 Long double
%lu                 Unsigned int or unsigned long
%lli or %lld        Long long
%llu                Unsigned long long
%o                  Octal representation
%p                  Pointer
%s                  String
%u                  Unsigned int
%x or %X            Hexadecimal representation
%n                  Prints nothing
%%                  Prints % character*/

#endif /* STD_TYPES_H_ */
