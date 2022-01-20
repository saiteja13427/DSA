#include <bits/stdc++.h>
using namespace std;

struct triplet
{
    int x, y, gcd;
};

//ax+by = gcd(a,b);
//gcd(b, a%b) = bx1 + (a%b)y1
//x = y1
//y = x1 - (a/b)y1

triplet exteuclid(int a, int b)
{
    if (b == 0)
    {
        triplet ans;
        ans.x = 1;
        ans.y = 0;
        ans.gcd = a;
        return ans;
    }

    triplet smallAns = exteuclid(b, a % b);
    triplet ans;
    ans.gcd = smallAns.gcd;
    ans.x = smallAns.y;
    ans.y = smallAns.x - (a / b) * smallAns.y;
    return ans;
}

int main()
{
    int a, b;
    cin >> a >> b;
    triplet ans = exteuclid(a, b);
    cout << ans.gcd << " " << ans.x << " " << ans.y;
}