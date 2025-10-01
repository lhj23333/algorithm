#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int n;
    cin >> n;
    vector<pair<ll, ll>> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }
    vector<vector<pair<ll, ll>>> quads(4);
    for (auto& p : points) {
        int idx = 0;
        if (p.first < 0) idx += 2;
        if (p.second < 0) idx += 1;
        quads[idx].push_back(p);
    }
    // quads[0]: A ++, [1]: B +-, [2]: C -+, [3]: D --
    ll weight = 0;
    vector<int> rem(4, 0);
    for (int q = 0; q < 4; q++) {
        auto& vec = quads[q];
        map<pair<ll, ll>, vector<pair<ll, ll>>> groups;
        for (auto& p : vec) {
            ll x = p.first, y = p.second;
            ll g = gcd(abs(x), abs(y));
            pair<ll, ll> key = {x / g, y / g};
            groups[key].push_back(p);
        }
        for (auto& grp : groups) {
            int s = grp.second.size();
            weight += (s / 2) * 2;
            rem[q] += s % 2;
        }
    }
    // Now, opposite pairs
    int min_ad = min(rem[0], rem[3]);
    weight += min_ad * 2;
    rem[0] -= min_ad;
    rem[3] -= min_ad;
    int min_bc = min(rem[1], rem[2]);
    weight += min_bc * 2;
    rem[1] -= min_bc;
    rem[2] -= min_bc;
    // Now, adjacent
    // A-B
    int min_ab = min(rem[0], rem[1]);
    weight += min_ab;
    rem[0] -= min_ab;
    rem[1] -= min_ab;
    // A-C
    int min_ac = min(rem[0], rem[2]);
    weight += min_ac;
    rem[0] -= min_ac;
    rem[2] -= min_ac;
    // B-D
    int min_bd = min(rem[1], rem[3]);
    weight += min_bd;
    rem[1] -= min_bd;
    rem[3] -= min_bd;
    // C-D
    int min_cd = min(rem[2], rem[3]);
    weight += min_cd;
    rem[2] -= min_cd;
    rem[3] -= min_cd;
    cout << weight << endl;
    return 0;
}