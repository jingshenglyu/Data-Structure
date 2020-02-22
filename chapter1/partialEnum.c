#include<stdio.h>

int MaxSubseqSum1(int List[] , int N)
{
    int ThisSum, MaxSum = 0;
    int i, j;

    for ( i = 0; i < N; i++)
    {
        ThisSum = 0; //ThisSum是从List[i]到List[j]的子列和
        for ( j = i; j < N; j++)
        {
            ThisSum += List[j];
            /*对于相同的i,不同的j，只要在j-1次循环一次基础上加一项即可*/
            if (ThisSum > MaxSum)
            {
                MaxSum = ThisSum;
            }
            
        }//j循环结束
        
    }//i循环结束
    
    return MaxSum;
}