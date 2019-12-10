#ifndef calc_gen_h
#define calc_gen_h

	/*! @file calc_gen.h
 *  This header supplies the interface of calc_gen module,
 *  which is used to generate the calculation questions.
 */

/*! @brief This function starts the random number generator used
 * to sort the math operation.
 *
 * @note This function must be executed once before execute #calc_gen
         to sort the operations
 */
void calc_gen_start();

/*! @brief This function generates a math. calculation question. 
 * 
 *  @return This function returns the sorted calculation.
 *  
 *  @note The function #calc_gen_start must have been previously executed to 
 *  start the random number generator used to sort the math operation.
 */
unsigned calc_gen();

#endif 
