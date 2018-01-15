#include<stdio.h>

int bitAnd(int x, int y){
    return x & y;
}

int getByte(int x, int n) {
  int mask = 0xFF;
  int byte = ((mask << (n*8)) & x) >> (n*8);
  return byte;

}

int ilog2(int x) {
  // the find the leftmost1
  int result = 0;
  // a is either all 1 or all zero
  int a = (!!(x>>16)) << 31 >> 31;
  result = result + a & 16;
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

int main(void){
    int op1 = 6; //1100
    int op2 = 5; //1001
    int opres = bitAnd(op1, op2);
    printf("The result of tested bit and should be %d\n", opres);
    int byte = 0x12345678;
    printf("The result should be %x\t%x\t%x\t%x\n", getByte(byte, 3), getByte(byte, 2), getByte(byte, 1), getByte(byte, 0));
    int digit = 0x1;
    int size = sizeof(int) * 8 ;
    printf("The result should be %x\n%x\n%x\n", ~((digit << size) >> 0), digit << (size + 10), (0xffff << 4));
    int mask1 = 0x11 | (0x11 << 8);
    int mask2 = mask1 | (mask1 << 16);
    printf("Mask1:%x\tMask2:%x\n", mask1, mask2);
    printf("Result:%x\n", ~0 + 0x1234);
    printf("Result:%d\n", sizeof(int) - 1);
    printf("Result:%x\n", (-1 >> 3));
    printf("Result:%x\n", 0xffff0000 << 25);
    printf("Testfunc:%d%d%d\n", ilog2(5), ilog2(7), ilog2(8));
    int uf = 0x7fc00000;
    int pattern = uf & 0x7f800000;
    printf("Test:%x\n", pattern >> 20);
    printf("%x\t\n", 158);
    return 0;
}