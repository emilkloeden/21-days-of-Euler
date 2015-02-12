#include <iostream> // Preprocesser declaration to enable output to stdio
using namespace std; // Without this I'd have to write //std.cout

int fib(int n);

int main()
{
    int i = 1, max = 4000000, answer = 0;
    while (fib(i) < max) 
    {
        if (fib(i) % 2 == 0) 
        {
            answer += fib(i);
        }
        i++;
    }
    cout << answer << "\n";
    return 0;
}

/* Declare a fibonacci function */
int fib(int n)
{
    int a = 0, b = 1;

    if (n <= 0) {
        return 0;
    }
    else
    {
        int j = 0;
        while (j < n)
        {
            int c;
            c = a;
            a = b;
            b = c + b;
            j++;
        }
        return a;
    }
}