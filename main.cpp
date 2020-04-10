#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n ;
    bool isPrime = true;
    if ( n < 2 )
        cout << "Invalid";
    else
        for ( int i = 2; i < n; ++i)
        {
            if ( n % i == 0)
            {
                isPrime = false;
                break;
            }
        }
    if (isPrime)
        cout << n << " is Prime";
    else
        cout << n << " is not Prime";
    return 0;
}
