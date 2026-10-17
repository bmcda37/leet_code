#include <stdio.h>
#include <stdlib.h>


int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
  int *solution = malloc(2 * sizeof(int));
  if (solution == NULL)
  {
    *returnSize = 0;
    return NULL;
  }

  *returnSize = 0;

  for (int i = 0; i < numsSize; i++)
  {
    for (int j = i + 1; j < numsSize; j++)
    {
      if ( *(nums + i) + *(nums + j) == target)
      {
        solution[0] = i;
        solution[1] = j;
        *returnSize = 2;
        return solution;
      }
    }
  }
  free(solution);
  return NULL;
}


int main(void)
{
  int nums[] = {2,7,11,15};
  int numsSize = sizeof(nums) / sizeof(nums[0]);
  int target = 9;
  int returnSize = 0;

  int *solution = twoSum(nums, numsSize, target, &returnSize);

  printf("[%d,%d]\n", solution[0],solution[1]);
  free(solution);

  return 0;
}