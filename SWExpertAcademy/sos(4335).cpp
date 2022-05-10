// vector 사용 시, 
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef struct box {
    int w;
    int h;
    int d;
    box(int a, int b, int c) {
        w = a;
        h = b;
        d = c;
    }
}Box;

int box_n;
int answer;

int memo[20][1 << 20][3];

int solution(vector<Box>& b, int cur, int visit, int direc, int w, int d) {
    int& height = memo[cur][visit][direc];
    if (height != -1) return height;

    int result = 0;

    for (int idx = 0; idx < box_n; idx++) {
        if ( (visit & (1 << idx)) != 0) continue;

        if ((b[idx].h <= w && b[idx].d <= d) || (b[idx].d <= w && b[idx].h <= d)) {
            result = b[idx].w + solution(b, idx, visit | (1 << idx), 1, b[idx].h, b[idx].d);
            height = max(height, result);
        }
        if ((b[idx].w <= w && b[idx].d <= d) || (b[idx].d <= w && b[idx].w <= d)) {
            result = b[idx].h + solution(b, idx, visit | (1 << idx), 2, b[idx].w, b[idx].d);
            height = max(height, result);
        }
        if ((b[idx].w <= w && b[idx].h <= d) || (b[idx].h <= w && b[idx].w <= d)) {
            result = b[idx].d + solution(b, idx, visit | (1 << idx), 0, b[idx].w, b[idx].h);
            height = max(height, result);
        }
    }
    if (result == 0) height = 0;

    return height;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("sos.txt", "r", stdin);
    int tc;
    cin >> tc;
    int w, h, d;

    cout << tc << endl;    
        for(int i=1; i<=tc; i++){
            cin >> box_n;
            vector<Box> b;
            memset(memo, -1, sizeof(memo));
            for(int j=0; j<box_n; j++){
                cin >> w >> h >> d;
                b.push_back(Box(w,h,d));
            }
            cout << "#" << i << " " << solution(b, 0, 0, 0, 10001, 10001) << endl;
        }        
    return 0;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

#include <iostream>
using namespace std;

int num_blocks;
int blocks[20][3];
int dp[20][(1 << 20) - 1][3];

int cal(int b, int use, int direc, int w, int d)
{
	int& height = dp[b][use][direc];
	
	if (height != -1) {
		return height;
	}
	int result = 0;
	for (int i = 0; i < num_blocks; i++) {
		if ((use & (1 << i)) != 0) {
			continue;
		}
		if ((w >= blocks[i][1] && d >= blocks[i][2]) || (w >= blocks[i][2] && d >= blocks[i][1])) {
			result = blocks[i][0] + cal(i, use | (1 << i), 0, blocks[i][1], blocks[i][2]);
			if (height < result) {
				height = result;
			}
		}
		if ((w >= blocks[i][0] && d >= blocks[i][2]) || (w >= blocks[i][2] && d >= blocks[i][0])) {
			result = blocks[i][1] + cal(i, use | (1 << i), 1, blocks[i][0], blocks[i][2]);
			if (height < result) {
				height = result;
			}
		}
		if ((w >= blocks[i][1] && d >= blocks[i][0]) || (w >= blocks[i][0] && d >= blocks[i][1])) {
			result = blocks[i][2] + cal(i, use | (1 << i), 2, blocks[i][1], blocks[i][0]);
			if (height < result) {
				height = result;
			}
		}
	}
    if (result  == 0) height = 0;
    return height;
}
int main() {
	int T;
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		cin >> num_blocks;
		for (int i = 0; i < num_blocks; i++) {
			for (int k = 0; k < (1 << num_blocks)-1; k++) {
				dp[i][k][0] = dp[i][k][1] = dp[i][k][2] = -1;
			}
			cin >> blocks[i][0] >> blocks[i][1] >> blocks[i][2];
		}
		cout << "#" << tc + 1 << " " << cal(0, 0, 0, 10001, 10001) << endl;
	}
}
