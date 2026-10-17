#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int compare( const void *a, const void *b)
{
  char x = *(const char *) a;
  char y = *(const char *) b;
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


bool isAnagram(char *s, char *t)
{
  size_t sSize = strlen(s);
  size_t tSize = strlen(t);
  qsort(s, sSize,sizeof(s[0]), compare);
  qsort(t, tSize,sizeof(t[0]), compare);
  if (tSize != sSize)
  {
    return false;
  }
  for (int i = 0; i < tSize; i++)
  {
    if ( *(s + i) != *(t + i))
    {
      return false;
    }

  }
  return true;
}

int main(void)
{
  char s[] = "rat";
  char t[] = "tar";
  //isAnagram(s,t);
  if (isAnagram(s,t))
  {
    puts("ANAGRAM");
  }
  else
  {
    puts("NOT ANAGRAM");
  }
  return 0;
}