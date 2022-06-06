#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int *binary, *new_binary, bin_dig, bit, rem = 1, i = 0;
  
  printf("Enter binary size: ");
  scanf("%d", &bin_dig);
  printf("Enter the binary: \n");
  binary = malloc(sizeof(int) * bin_dig);
  for (int i = 0; i < bin_dig; i++)
  {
    printf("\tEnter bit: ");
    scanf("%d", &bit);
    binary[i] = bit;
  }
  for (; i < bin_dig; i++)
  {
    if (binary[i] == 1)
      binary[i] = 0;
    else
      binary[i] = 1;
  }
  i = bin_dig - 1;
  while(rem) 
  {
    bit = binary[i] + 1;
    if(bit != 2)
    {
      binary[i] = bit;
      rem = 0;
      continue;
    }
    bit -= 2;
    binary[i] = bit;
    rem = 1;
    i--;
  }
  printf("%d\n", rem);
  if (rem)
  {
    new_binary = malloc(sizeof(int) * (bin_dig + 1));
    new_binary[0] = 1;
    for (int i = 1; i < bin_dig + 1; i++)
      new_binary[i] = binary[i - 1];
    free(binary);
    for (int i = 0; i < bin_dig; i++)
      printf("%d", new_binary[i]);
  }
  else
    for (int i = 0; i < bin_dig; i++)
      printf("%d", binary[i]);
  
  return (0);
}