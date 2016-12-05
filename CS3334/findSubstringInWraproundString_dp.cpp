//DP
//LeetCode
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;


int findSubstringInWraproundString(char* p) {
    int dp[26], i;
    memset(dp, 0, sizeof(dp));
    int len = strlen(p);
    for (i = 0; i < len; i++) {
        int cnt = 1, temp = i;
        while (i + 1 < len && (p[i + 1] == p[i] + 1 || (p[i] == 'z' && p[i + 1] == 'a'))) {
            cnt++;
            i++;
        }
        if (cnt > dp[p[temp] - 'a'])
            dp[p[temp] - 'a'] = cnt;
    }
    for (i = 0; i < 26; i++) {
        int j, k;
        for (k = 1, j = (i == 25 ? 0 : i + 1); k <= dp[i]; k++, j == 25 ? j = 0 : j++)
            if (dp[i] - k > dp[j])
                dp[j] = dp[i] - k;
    }
    int res = 0;
    for (i = 0; i < 26; i++)
        res += dp[i];
    return res;
}
int main() {
    char arr[10001];
    cin >> arr;
    cout << findSubstringInWraproundString(arr) << endl;
    return 0;
}
