#include <bits/stdc++.h>
using namespace std;

struct triplet
{
    int b, y, gcd;
};

//Modular Inverse of a and m is b
//a and m are co primes
//(a*b)%m= 1;
//mm = multiple of m
//a*b - mm = 1
// a*b + m(y) = 1
//This is like extended euclid where
// a = a, x = b, b=m

//gcd(b, a%b) = bx1 + (a%b)y1
//x = y1
//y = x1 - (a/b)y1

triplet exteuclid(int a, int m)
{
    if (m == 0)
    {
        triplet ans;
        ans.b = 1;
        ans.y = 0;
        ans.gcd = a;
        return ans;
    }

    triplet smallAns = exteuclid(m, a % m);
    triplet ans;
    ans.gcd = smallAns.gcd;
    ans.b = smallAns.y;
    ans.y = smallAns.b - (a / m) * smallAns.y;
    return ans;
}

int moduloInverse(int a, int m)
{
    triplet ans = exteuclid(a, m);
    if (ans.b < 0)
        return (ans.b + m) % m;
    return ans.b;
}

int main()
{
    int a, m;
    cin >> a >> m;
    cout << moduloInverse(a, m) << endl;
}