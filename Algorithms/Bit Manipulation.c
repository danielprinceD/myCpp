#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void decimal2Binnary(int n){
    int res = 1;
    while(n != 0)
    {
        res =  res * 10 + n % 2;
        n /= 2;
    }
    int reversed = 0;
    while(res > 0)
    {
        reversed = (reversed * 10 ) + res % 10;
        res /= 10;
    }
    printf("%d" , reversed/10);

}

void isSet(int num , int i)
{
    if(num & ( 1 << (i-1) ))
        printf("Set");
    else printf("Not Set");
}

void removeLastSetBit(int num )
{
    // eg : 10 -> 1010 -> 1000
    int  i = 0;
    while((num & (1 << i)) == 0)
        i++;
    num = num & (~(1 << i));
    printf("%d" , num);
}

void checkPowerof2(int num)
{
    if(num & (num-1))
        printf("No");
    else printf("Yes");
}


void swap(int a , int b)
{
    a ^= b;
    b ^= a;
    a ^= b;
    printf("%d %d" , a ,b);
}


void numberofSetBits(int num)
{
    int count = 0;
    while(num > 0)
    {
        if(num & 1)
            count++;
        num = num >> 1;
    }
    printf("%d" , count);
}

void minimumFlip(int start , int goal)
{
    int res = start ^ goal;
    numberofSetBits(res);
}

void findSingleNumber2(int arr[] , int n)
{
    int ones = 0 , twos = 0;
    for(int i=0;i<n;i++)
    {
        ones = (arr[i] ^ ones ) & (~twos);
        twos = (arr[i] ^ twos ) & (~ones);
    }
    printf("%d" , ones);
}

#define HELLO "Hello"


int main(){

    // int arr[] = { 2 , 2 ,10 ,  1 , 1 , 1 , 2 };
    // findSingleNumber2(arr , 7);

    // minimumFlip(10 , 2);

    // int a , b ; scanf("%d %d" , &a , &b);
    // int sum , carry = 1;
    // while(carry != 0)
    // {
    //     sum = a ^ b;
    //     carry = (~a & b) << 1;
    //     a = sum;
    //     b = carry;
    // }
    // printf("%d" , sum );

    // int **ptr;
    // ptr = (int **)malloc(5 * sizeof(int *));

    // for(int i=0;i<5;i++)
    //     *(ptr + i) = (int *)malloc(5 * sizeof(int));
            
    // int k = 1;
    // for(int i=0;i<5;i++)
    //     for(int j=0;j<5;j++)
    //         ptr[i][j] = k++ ;

    // for(int i=0;i<5;i++)
    //     for(int j=0;j<5;j++)
    //         printf("%d " , ptr[i][j]);



    return 0;
}