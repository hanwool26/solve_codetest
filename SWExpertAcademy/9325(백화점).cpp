#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
ll answer;
ll N, P, D;
#define MAX_N (unsigned int)(2*1e6+2)

ll product[MAX_N];
ll pre_sum[MAX_N];
ll coupon[MAX_N];
ll c_tree[4*MAX_N];

ll get_discount(ll  s, ll e) {
    ll discount = 0;
    if ((e - s) >= D) {
        for (int i = s + D - 1; i <= e; i++) {
            discount = max(discount, coupon[i]);
        }
    }
    return discount;
}

ll make_node(ll n, ll s, ll e) {
    if (s == e) {
        return c_tree[n] = coupon[s];
    }
    else {
        return c_tree[n] = max(make_node(n * 2, s, (s + e)/ 2), make_node((n * 2)+1, ((s + e) / 2) + 1, e));
    }
}

ll get_discount_node(ll n, ll l, ll r, ll s, ll e) { // ( 1, 1, N, s+D, e)
    //cout << n << endl;
    if (r < s || l > e) return 0;
    if (l>=s && r<=e) {
        return c_tree[n];
    }
    else {
        return max(get_discount_node(n * 2, l, (l+r)/2 , s, e), get_discount_node((n * 2) + 1, (l+r)/2+1, r, s, e));
    }
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
    make_node(1, 1, N);

    // two pointer 활용 
    ll s = 0, e = D;
    ll value, discount=0;
    while (e <= N) {
        value = pre_sum[e] - pre_sum[s];
        discount = get_discount_node(1, 1, N, s, e);
        value -= discount;

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
