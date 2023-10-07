#include<bits/stdc++.h>
using namespace std;

int minNum(int sam_daily, int kelly_daily, int difference) {
    if (sam_daily >= kelly_daily)
        return -1;
    
    return (difference / (kelly_daily - sam_daily)) + (difference % (kelly_daily - sam_daily) > 0);
}

int main() {
    int sam_daily = 3, kelly_daily = 5, difference = 5;
    cout << minNum(sam_daily, kelly_daily, difference) << "\n";

    return 0;
}