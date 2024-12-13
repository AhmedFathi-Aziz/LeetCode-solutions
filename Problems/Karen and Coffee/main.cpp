#include <bits/stdc++.h>
using namespace std;

void doWork() {
    int n, k, q;
    cin >> n >> k >> q;

    int prefix[200009];
    memset(prefix, 0, sizeof(prefix));
    while (n--) {
        int u, v;
        cin >> u >> v;
        prefix[u]++;
        prefix[v + 1]--;
    }
    for (int i = 1; i <= 200000; i++)
        prefix[i] += prefix[i - 1];
    for (int i = 1; i <= 200000; i++) {
        if (prefix[i] >= k)
            prefix[i] = 1;
        else
            prefix[i] = 0;
    }
    for (int i = 1; i <= 200000; i++)
        prefix[i] += prefix[i - 1];
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << prefix[v] - prefix[u - 1] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef ONLINE_JUDGE
#endif

    int cases = 1;
    // cin >> cases;
    while (cases--)
        doWork();
    return 0;
}
