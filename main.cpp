#include <vector>
#include <iostream>

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define pb push_back
#define sz(i) (int)(i.size())
#define F first
#define S second
#define P pair<int, int>

using namespace std;

template<class T>
void smin(T &a, T val) { if (a > val) a = val; }

template<class T>
void smax(T &a, T val) { if (a < val) a = val; }

const int N = (int) 1e5 + 10;

int n, a[N + 10];
vector<int> v[N + 10];

int check(int x) {
    if (sz(v[x]) == 1) {
        return 0;
    }
    int diff = v[x][1] - v[x][0];
    for (int i = 0; i + 1 < sz(v[x]); ++i) {
        if (v[x][i + 1] - v[x][i] != diff)
            return -1;
    }
    return diff;
}

using namespace std;

int32_t main() {
    _

    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        v[a[i]].pb(i);
    }

    vector<P > vec;
    for (int i = 1; i <= N; ++i) {
        if (v[i].empty())continue;
        int get = check(i);
        if (get == -1)continue;
        else {
            vec.pb({i, get});
        }
    }

    cout << sz(vec) << endl;
    for (auto it: vec)
        cout << it.F << ' ' << it.S << endl;

    return 0;
}
