#include<stdio.h>

int MaxSubseqSum1(int List[] , int N)
{
    int ThisSum, MaxSum = 0;
    int i, j, k;

    for ( i = 0; i < N; i++)
    {
        for ( j = i; j < N; j++)
        {
            ThisSum = 0; //ThisSum是从List[i]到List[j]的子列和
            for ( k = 0; k <= j; k++)
            {
                ThisSum += List[k];
                if (ThisSum > MaxSum)  //如果这个子列和更大
                {
                    MaxSum = ThisSum; //更新这个结果
                }
                
            }
            
        } // j循环结束
        
    } // i循环结束
    
    return MaxSum;
}