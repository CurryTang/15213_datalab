/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
  return x & y;
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
  int mask = 0xFF;
  int byte = (((mask << (n*8)) & x) >> (n*8)) & mask;
  return byte;

}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
  int size = sizeof(int) * 8;
  // We construct a mask to eliminate the 1s at the hed of the logical shift result
  int mask = ((1 << (size - 1)) >> n) << 1; // for the 0 case, you can't use n - 1, you must first move 1 more and then turn back
  int result = (x >> n) & ~mask;
  return result;
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
  // For detailed explanation, you can refer to 
  // http://www.chenzhikai.com/2018/01/11/%E5%A6%82%E4%BD%95%E4%B8%8D%E7%94%A8%E5%BE%AA%E7%8E%AF%E4%B8%8E%E4%BB%BB%E4%BD%95%E6%8E%A7%E5%88%B6%E8%AF%AD%E5%8F%A5%E5%BE%97%E5%88%B0%E4%B8%80%E4%B8%AA%E4%BA%8C%E8%BF%9B%E5%88%B6%E6%95%B0%E4%B8%AD1%E7%9A%84%E4%B8%AA%E6%95%B0/
  x = x - ((x >> 1) & 0x5555555555555555);
  x = (x & 0x3333333333333333) + ((x >> 2) & 0x3333333333333333);
  return (((x + (x >> 4)) & 0x0F0F0F0F0F0F0F0F) * 0x0101010101010101) >> 56;
}
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
  int minusX = ~x + 1;
  int bits = (minusX | x) >> (sizeof(int) * 8 - 1);
  return bits + 1;
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  return (1 << (sizeof(int) * 8 - 1));
}
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
  int m = n - 1;
  int sign = (x >> (sizeof(int) * 8 - 1)) & 0x1;
  int mask = ~(sign - 1);
  x ^= mask;
  x >>= m;
  return !x;
}
/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zer
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
    // form a bit pattern 000..01111 where 1 starts from the pos of n - 1
    int mask = (1 << n) - 1;
    // if positive, then mask unchanged, otherwise 0
    int equal = (x >> 31) & mask;
    // if positive then 0
    // if negative then 2^n - 1
    return (x + equal) >> n;
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ~x + 1;
}
/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x) {
  int size = sizeof(int) * 8;
  int sign = (x >> (size - 1));
  // only consider two cases: negative and zero
  return !((sign & 0x1) | !x);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  int size = sizeof(int) * 8 - 1;
  int sign1 = (x >> size);
  int sign2 = y >> size;
  int mask = (1 << size) - 1;
  int pos_part_1 = x & mask;
  int pos_part_2 = y & mask;
  int sub = pos_part_1 - pos_part_2;
  int sub_sign = !(((sub >> size) & 0x1) | !sub);
  int pos_x_neg_y = (!sign1) & sign2;
  return ((sign1 & (!sign2)) | (!sub_sign && !pos_x_neg_y) );
  // The one below seems a better solution than mine (doesn't use minus)
  /*
  int sign, isLess, dif, equal, isLessorEqual;

  sign = x ^ y;
  isLess = ~sign;
  dif = y + (~x + 1);

  equal = !dif;

  sign = sign & x;
  
  dif = ~dif;
  
  isLess = isLess & dif;
  isLess = isLess | sign;
  isLess = isLess & (1 << 31);

  isLessorEqual = (!!isLess) | (equal);

  return isLessorEqual;  
  */

}
/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int ilog2(int x) {
  // find the leftmost1
  int result = 0;
  // a is either all 1 or all zero
  int a = (!!(x>>16)) << 31 >> 31;
  result = result + (a & 16);
  x >>= (a & 16);

  a = (!!(x >> 8)) << 31 >> 31;
  result += a & 8;
  x >>= (a & 8);

  a = (!!(x >> 4)) << 31 >> 31;
  result += a & 4;
  x >>= (a & 4);

  a = (!!(x >> 2)) << 31 >> 31;
  result += a & 2;
  x >>= (a & 2);

  a = (!!(x >> 1)) << 31 >> 31;
  result += a & 1;
  x >>= (a & 1);

  return result;
}
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
 int pattern = uf & 0x7f800000;
 if ((pattern >> 20) == 0x7f8){
    if (!!(uf & 0x007fffff)){
      return uf;
    }
   
 } 
 return uf ^ 0x80000000;

}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
  // i found an easier to understand version on https://github.com/DreamAndDead/CSAPP-3e-Solutions/blob/master/chapter2/code/floats/float-i2f.c
  unsigned s = 0, exp = 31, frac = 0, add = 0;
  if (x == 0) return x;
  else if(!!(x & 0x80000000)){
    s = 0x80000000u;
    x = -1 * x;
  }
  while(1){
    if (x & 0x80000000u) break;
    exp -= 1;
    x <<= 1;
  }
  if ((x & 0x000001ff) == 0x180) add = 1;
  else if ((x & 0xff) > 0x80) add = 1;
  frac = ((x & 0x7fffffff) >> 8) + add;
  return s + ((exp + 127) << 23) + frac;
}
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
  // this is the solution of @mofaph on github,
  // i found it correct and easy to understand 
  unsigned sign = uf >> 31;
  unsigned exp = (uf >> 23) & 0xFF;
  unsigned frac = uf & 0x7FFFFF;

  /* NaN, +oo, -oo */
  if (exp == 0xFF)
    return uf;

  if (exp == 0xFE) {
    exp = 0xFF;
    frac = 0;
  } else if (exp > 0) {
    exp++;
  } else /* exp == 0 */ {
    // the special case that a denormalized number
    // becomes a normalized one
    if ((frac & 0x400000) == 0x400000) {
        exp = 1;
        frac = (frac << 1) & 0x7FFFFF;
    } else {
        frac <<= 1;
    }
  }

  return (sign << 31) | (exp << 23) | frac;
}
