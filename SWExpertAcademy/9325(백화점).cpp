#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
ll answer;
int N, P, D;
#define MAX_N (unsigned int)(2*1e6+1)

ll product[MAX_N];
ll pre_sum[MAX_N];
ll coupon[MAX_N];

int get_discount(ll  s, ll e) {
    ll discount = 0;
    if ((e - s) >= D) {
        for (int i = s + D - 1; i <= e; i++) {
            discount = max(discount, coupon[i]);
        }
    }
    return discount;
}

void solution() {
    // presum 
    pre_sum[0] = product[0];
    for (int i = 1; i <= N; i++) {
        pre_sum[i] = product[i] + pre_sum[i - 1];
    }

    for (int i = 1; i <= N; i++) {
        if (i >= D)  coupon[i] = product[i] + coupon[i - 1] - product[i - D];
        else coupon[i] = product[i] + coupon[i - 1];
    }

    // two pointer 활용 
    ll s = 0, e = D;
    ll value;
    while (e <= N) {
        value = pre_sum[e] - pre_sum[s];
        value = value - get_discount(s, e);

        if (value <= P) {
            answer = max(answer, (e - s) );
            e++;
        }
        else {
            s++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("9325.txt", "r", stdin);
    int T; cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        cin >> N >> P >> D;
        answer = 0;
        for (int i = 1; i <= N; i++) {
            cin >> product[i];
        }
        solution();

        cout << "#" << tc << " " << answer << endl;
    }
}
