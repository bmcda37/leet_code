//
// Created by Ben McDaniel on 10/17/26.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



int compare(const void *a, const void *b)
{
  int x = *(const int *)a;
  int y = *(const int *)b;
  if (x < y)
  {
    return -1;
  }
  if (x > y)
  {
    return 1;
  }
  return 0;
}



bool containsDuplicate(int *nums, int numsSize)
{
  qsort(nums, numsSize, sizeof(nums[0]), compare);
  int i = 0;
  int j = 1;
  while (j < numsSize)
  {
    if (*(nums + i) == *(nums + j))
    {
      return true;
    }
    i++;
    j++;
  }
  return false;
}


int main(void)
{
  int nums[] = {2,14,18,22,22};
  int numsSize = sizeof(nums) / sizeof(nums[0]);
  if (containsDuplicate(nums, numsSize))
  {
    printf("TRUE: DUPLICATES FOUND");
  }
  else
  {
    printf("FALSE: DUPLICATES NOT FOUND");
  }
  return 0;
}
