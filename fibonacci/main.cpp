#include <iostream>

using namespace std;


//Recursive Approach to calculate Fibonacci series
int fibonacciRecursive(int n)
{
    if(n<=1)
        return n;
    return fibonacciRecursive(n-1)+fibonacciRecursive(n-2);;
}


//iterative approach

void fibonacciIterative(int n)
{
    int a=0,b=1,c;
    if(n>=1)
    {
        cout<<a<<" ";

    }

    if(n>=2)
    {
        cout<<b<<" ";
    }

    for(int i=3;i<=n;i++)
    {
        c=a+b;
        cout<<c<<" ";
        a=b;
        b=c;
    }

}

int main()
{
    int n;
    cout<<"Enter the number of terms for fib series: ";
    cin>>n;
    cout<<"Fibo series using iterative approach: ";
    fibonacciIterative(n);
    cout<<endl;
    cout<<"Fibo series using recursive approach: ";
    for(int i=0;i<n;i++)
    {
        cout<<fibonacciRecursive(i)<<" ";
    }
    cout<<endl;



    return 0;
}
