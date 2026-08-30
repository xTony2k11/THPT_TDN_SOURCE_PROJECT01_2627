#include <bits/stdc++.h>
#define ll long long
#define NAME "VIETNAMOI"
using namespace std;
const int MAX = 505;

int N, M, Q;
ll A[MAX][MAX];
ll pf[MAX][MAX];

void init(void){
    cin >> N >> M >> Q;
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= M; ++j){
            cin >> A[i][j];
        }
    }
}

void prepared(void){
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= M; ++j){
            pf[i][j] = pf[i-1][j] + pf[i][j-1] - pf[i-1][j-1] + A[i][j];
        }
    }
}

ll calculate(int x1, int y1, int x2, int y2){
    return pf[x2][y2] - pf[x1-1][y2] - pf[x2][y1-1] + pf[x1-1][y1-1];
}

void solve(ll K){
    int ans = INT_MAX;
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= M; ++j){
            for(int k = 0; i + k <= N && j + k <= M; ++k){
                ll sum = calculate(i, j, i + k, j + k);
                if(sum >= K){
                    ans = min(ans, k + 1);
                    break;
                }
            }
        }
    }
    if(ans == INT_MAX) cout << -1 << "\n";
    else cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    FILE *in = fopen(NAME".INP", "r");
    if(in != NULL){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
        fclose(in);
    }
    init();
    prepared();
    while(Q--){
        ll K;
        cin >> K;
        solve(K);
    }
    return 0;
}
