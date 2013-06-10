/*
 * =====================================================================================
 *
 *       Filename:  quick.cc
 *
 *    Description:  quick sort
 *
 *        Version:  1.0
 *        Created:  2013/6/10 21:40:36
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  zhangdw 
 *        Company:  
 *
 * =====================================================================================
 */
#include <stdio.h>

void quickSort(int a[], int left, int right)
{
  if(left >= right)
  {
    return;
  }

  int i = left; //left begin
  int j = right;  //right begin

  int key = a[i + 1]; //key value,left < key, right > key
  int temp;

  while(1)
  {
    //find the first left value should be changed to right
    while(a[i] < key)
    {
      i++;
    }

    //find the first right value should be changed to left
    while(a[j] > key)
    {
      j--;
    }

    //sort finished
    if(i >= j)
    {
      break;
    }

    //else change the value of left and right
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;

    if(a[i] == key)
    {
      j--;
    }
    else
    {
      i++;
    }
  }

  if(left < i - 1)
  {
    quickSort(a, left, i - 1);
  }

  if(right > j + 1)
  {
    quickSort(a, j + 1, right);
  }
}

int main()
{
  int a[] = {5,9,6,4,2,3,8,1,0,7};
  int length = sizeof(a) / sizeof(*a);

  quickSort(a, 0, length - 1);

  for(int i = 0; i < length; i++)
  {
    printf("%d ",a[i]);
  }
  printf("\n");

  return 0;
}

