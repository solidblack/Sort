/*
 * =====================================================================================
 *
 *       Filename:  merge.cc
 *
 *    Description:  merge sort
 *
 *        Version:  1.0
 *        Created:  2013/6/9 21:36:01
 *       Revision:  1.0
 *       Compiler:  gcc
 *
 *         Author:  Zhangdw 
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>

void merge(int *a, int *b, int low, int mid, int high)
{
  int k = low;
  int begin1 = low;
  int end1 = mid;
  int begin2 = mid + 1;
  int end2 = high;

  while(k <= high)
  {
    if(begin1 > end1)
    {
      b[k++] = a[begin2++];
    }
    else if(begin2 > end2)
    {
      b[k++] = a[begin1++];
    }
    else
    {
      if(a[begin1] <= a[begin2])
      {
        b[k++] = a[begin1++];
      }
      else
      {
        b[k++] = a[begin2++];
      }
    }
  }
}

void mergePass(int *a, int *b, int seg, int length)
{
  int seg_start_index = 0;

  while(seg_start_index <= (length - 2 * seg)) //we merge 2 * seg numbers at one time
  {
    merge(a, b, seg_start_index, seg_start_index + seg - 1, seg_start_index + 2 * seg -1);
    seg_start_index += 2 * seg;
  }

  //pare merge end
  if(seg_start_index + seg < length)
  {
    //the number of left is bigger than seg and smaller than 2 * seg
    merge(a, b, seg_start_index, seg_start_index + seg - 1, length - 1);
  }
  else
  {
    //the number of left is smaller than seg
    //just copy the left
    for(int i = seg_start_index; i < length; i++)
    {
      b[i] = a[i];
    }
  }
}

void mergeSort(int *a, int length)
{
  int *temp = new int[length];
  int seg = 1; // merge step distance

  while(seg < length)
  {
    mergePass(a, temp, seg, length);
    seg += seg;

    //merge based the merged one, must do so
    mergePass(temp, a, seg, length);
    seg += seg;
  }

  delete [] temp;
}

int main()
{
  int a[] = {3,5,6,1,8,2,9,4,0};
  int length = sizeof(a) / sizeof(*a);

  mergeSort(a, length);
  
  printf("After sort:\n");
  for(int i = 0; i < length; i++)
  {
    printf("%d ",a[i]);
  }

  return 0;
}


