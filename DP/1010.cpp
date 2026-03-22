#include <iostream>
using namespace std;

int dp[31][31];

int main() {
    int T, N, M;
    cin >> T;

    for (int i = 0; i <= 30; i++) {
        dp[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }

    while (T--) {
        cin >> N >> M;
        cout << dp[M][N] << "\n";
    }
    return 0;
}
