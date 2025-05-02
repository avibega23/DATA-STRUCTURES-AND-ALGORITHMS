#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int maxi = INT_MAX;
    long long sum = 0;

    for(int i = n - 1; i >= 0; i--) {
        if(maxi == 0) break;

        int take = min(nums[i], maxi - 1);
        take = max(take, 0); // make sure take is non-negative

        sum += take;
        maxi = take;
    }

    cout << sum << "\n";
    return 0;
}
