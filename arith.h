#if !defined(ARITH_H)
#define ARITH_H

/** @brief Add two 32-bit integers
 * @param a The first addend
 * @param b The second addend
 * @returns a + b
 */
int add(int a, int b);

/** @brief Performs a subtraction between two 32-bit integers
 * @param a The minuend
 * @param b The subtrahend
 * @returns a - b
 */
int sub(int a, int b);

/** @brief Multiplies two 32-bit integers
 * @param a The multiplicand
 * @param b The multiplier
 * @returns a * b
 */
int mult(int a, int b);

/** @brief Divides two 32-bit integers
 * @param a The dividend
 * @param b The divisor
 * @returns a / b
 */
int div(int a, int b);

/** @brief Computes the modulus between two 32-bit integers
 * @param a The dividend
 * @param b The divisor
 * @returns a % b
 */
int mod(int a, int b);

#endif