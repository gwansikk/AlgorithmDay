// 시간복잡도: n^2, 공간복잡도: 1

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    vector<int> dp(k + 1);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    dp[0] = 1;
    for (int i = 0; i < v.size(); i++) {
        for (int j = v[i]; j <= k; j++) {
            dp[j] += dp[j - v[i]];
        }
    }

    cout << dp[k] << "\n";

    return 0;
}