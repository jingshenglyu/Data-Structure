#include<stdio.h>

int Max3(int A, int B, int C)
{
    return A > B ? A > C ? A : C : B > C ? B : C;
}

int DivideAndConquer(int List[], int left, int right)
{
    int MaxLeftSum, MaxRightSum; //存放与左右子问题的解
    int MaxLeftBorderSum, MaxRightBorderSum; //存方跨分界线的结果
    int LeftBorderSum, RightBorderSum;
    int center, i;

    if(left == right)//递归终止条件，子列只有一个数字
    {
        if(List[left] > 0)
        {
            return List[left];
        }
        else
        {
            return 0;
        }
        
    }

    //分的过程
    center = (left + right) / 2; //找到中分点
    //递归秋得两边子列的最大和
    MaxLeftSum = DivideAndConquer(List, left, center);
    MaxRightSum = DivideAndConquer(List, center + 1, center);
    
    //求跨分界线的最大子列和
    MaxLeftBorderSum = 0;LeftBorderSum = 0;
    for ( i = center; i >= left; i--)
    {
        LeftBorderSum += List[i];
        if(LeftBorderSum > MaxLeftBorderSum)
        {
            MaxLeftBorderSum = LeftBorderSum;
        }
    }// 左边扫描结束
    
    MaxRightBorderSum = 0;
    RightBorderSum = 0;
    for ( i = center + 1; i <= right; i++) //从中线向右扫描
    {
        RightBorderSum += List[i];
        if (RightBorderSum > MaxRightBorderSum)
        {
            MaxRightBorderSum = RightBorderSum;
        }
        
    }//右边扫描结束
    
    //返回递归（治）的结果
    return Max3(MaxLeftSum, MaxRightSum, 
                MaxLeftBorderSum + MaxRightBorderSum);
}

int MaxSubseqSum3(int List[], int N)
{
    //保持与前两种算法相同的函数接口
    return DivideAndConquer(List, 0, N-1);
}