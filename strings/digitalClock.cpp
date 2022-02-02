#include <bits/stdc++.h>
using namespace std;

string convert_to_digital_time(int minutes)
{
    // complete this function
    string time = to_string(minutes / 60) + ":";
    time += (to_string(minutes % 60).length() == 1) ? ("0" + to_string(minutes % 60)) : (to_string(minutes % 60));
    return time;
}

int main()
{
    cout << convert_to_digital_time(1180);
}