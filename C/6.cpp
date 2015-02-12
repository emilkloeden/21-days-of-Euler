#include <iostream> // Preprocesser declaration to enable output to stdio
using namespace std; // Without this I'd have to write //std.cout

int go(int max);
int square (int n);

int main()
{
    cout << go (100) << "\n";
}

/* Declare a function for no apparent reason */
int go(int max) 
{
    int i = 1, sum = 0, sum_squares = 0;

    while (i <= max)
    {
        sum += i;
        sum_squares += square(i);
        i++;
    }
    
    return square(sum) - sum_squares;
}

int square(int n)
{
    return n * n;
}