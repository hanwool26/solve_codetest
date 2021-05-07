#include <iostream>

using namespace std;

int box[20][3];
int dp[20][1 << 20 - 1][3];
int answer;
int N, w, l, h;

int DFS(int w, int d, int idx, int side, int visit){

    int sum = 0;

    int& height = dp[idx][visit][side];
    
    if (height != -1) {
        return height;
    }    

    for (int i = 0; i < N; i++) {
        if ((visit & (1 << i))!=0) continue;        

        if ((w >= box[i][1] && d >= box[i][2]) || (w >= box[i][2] && d >= box[i][1])) {
            sum = box[i][0] + DFS(box[i][1], box[i][2], i, 0, visit | (1<<i));
            if (height < sum) {
                height = sum;
            }
        }
        if ((w >= box[i][0] && d >= box[i][2]) || (w >= box[i][2] && d >= box[i][0])) {
            sum = box[i][1] + DFS(box[i][0], box[i][2], i, 1, visit | (1<<i));
            if (height < sum) {
                height = sum;
            }
        }
        if ((w >= box[i][0] && d >= box[i][1]) || (w >= box[i][1] && d >= box[i][0])) {
            sum = box[i][2] + DFS(box[i][0], box[i][1], i, 2, visit | (1<<i));
            if (height < sum) {
                height = sum;
            }
        }
    }
    if (sum == 0) {
        height = sum; 
    }
    return height; 
}

int main()
{
    int T;
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("sos_input.txt", "r", stdin);

    cin >> T;

    for (int tc = 0; tc < T; tc++) {        
        cin >> N;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < (1 << N)-1; j++) {
                dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = -1;
            }
            cin >> w >> l >> h;
            box[i][0] = w;
            box[i][1] = l;
            box[i][2] = h;
        }
        cout << "#" << tc+1 << " " << DFS(10001,10001,0,0,0) << endl;
    }
    return 0;
}
