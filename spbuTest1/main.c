#include <stdio.h>
#include <stdbool.h>

long long int FibonacciNumber(long long int theFirstNumber, long long int theSecondNumber, long long int sum)
{
    long long int nextNumber = theFirstNumber + theSecondNumber;
    while (nextNumber <= 1000000)
    {
        if (nextNumber % 2 == 0)
        {
            sum += nextNumber;
        }

        theFirstNumber = theSecondNumber;
        theSecondNumber = nextNumber;
        nextNumber = theFirstNumber + theSecondNumber;
    }

    return sum;
}

long long int test()
{
    long long int rightAnswer = 1089154;
    return rightAnswer;
}

int main()
{
    long long int theFirstNumber = 1;
    long long int theSecondNumber = 1;
    long long int sum = 0;
    long long int answer = FibonacciNumber(theFirstNumber, theSecondNumber, sum);

    if (test() == answer)
    {
        printf("The sum of even Fibonacci numbers is %lld", answer);
        return 0;
    }
    else
    {
        printf("The programm failed :c");
        return -1;

    }
    

}