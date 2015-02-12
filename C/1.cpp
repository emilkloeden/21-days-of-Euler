#include <iostream>
using namespace std;

int main()
{
    int i = 1, max = 1000, answer = 0;
    while (i < max) 
    {
        if (i % 3 == 0 || i % 5 == 0) 
        {
            answer += i;
        }
        i++;
    }
    cout << answer;
    return 0;
}