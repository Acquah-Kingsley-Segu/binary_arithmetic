#include <stdio.h>
#include <stdlib.h>

int _pow(int, int);
int main(void)
{
    int sig_num, temp, bin_num, dec_num = 0;
    int *binary;

    printf("Enter the most significant bit: ");
    scanf("%d", &sig_num);
    binary = malloc(sizeof(int) * sig_num + 1);
    for (int i = 0; i <= sig_num; i++)
    {
      printf("Enter the bit: ");
      scanf("%d", &bin_num);
      binary[i] = bin_num;
    }
    temp = sig_num;
    for (int i = 0; sig_num >= 0; i++)
    {
      dec_num += (_pow(2, sig_num) * binary[i]);
      sig_num--;
    }
    printf("The decimal equivalence of ");
    for (int i = 0; i < temp + 1; i++)
      printf("%d", binary[i]);
    printf(" is %d\n", dec_num);
    free(binary);
    return 0;
}

int _pow(int base, int expo)
{
  int i, result = 1;

  if (expo == 0)
    return 1;
  for (i = 0; i < expo; i++)
    result *= base;
  return result;
}