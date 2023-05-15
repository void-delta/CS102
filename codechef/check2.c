#include <stdio.h>
#include <stdlib.h>

int isPalindrome(int x);

int main()
{
    printf("Enter the number\t");
    int n;
    scanf("%d", &n);
    printf("%d ", isPalindrome(n));
    return 0;
}

int isPalindrome(int x)
{
    int sum = 0;
    int rev;
    for(int i = x, n = 1; i != 0; i/10, n*10)
    {
        int i = i%10;
        rev = rev + i*n;
    }
    if(rev == x)
        return 1;
    else
        return 0;
}