#include <stdio.h>
void checkPrime(int n); //function to print all prime numbers between 1 to n using recursion
int main()
{
    int n;
    printf("Enter a positive integer: ");
    scanf("%d",&n);
    printf("\nPrime numbers up to %d: ", n);
    checkPrime(n);
    return 0;
}
void checkPrime(int n)
{
    static int i=2; //lower limit
    //the base case as the smallest prime number is 2
    if (n <= 2)
    {
        if (n==2)
            printf("2 ");
        return;
    }
    //checks for prime number
    if (i <= n)
    {
        int flag = 0;
        for (int j = 2; j <= i/2; ++j)
        {
            if (i % j == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag==0)
            printf("%d ",i);
        i++;
        checkPrime(n);
    }

}