#include <bits/stdc++.h>
#define ll long long
#define NAME "XUNGPHONG"
using namespace std;
const int MAXN = 2e5 + 5;

struct Activity{
    int L, R;
    ll V;
    bool operator <(const Activity &other)const{
        if(R != other.R) return R < other.R;
        if(L != other.L) return L < other.L;
        return V < other.V;
    }
};

int N;
Activity a[MAXN];
ll ans = 0;
ll dp[MAXN];

void init(void){
    cin >> N;
    for(int i = 1; i <= N; ++i){
        cin >> a[i].L >> a[i].R >> a[i].V;
    }
}

void Try(int pos, ll sum, int prev){
    if(pos > N){
        ans = max(ans, sum);
        return ;
    }
    if(prev <= a[pos].L)
        Try(pos + 1, sum + a[pos].V, a[pos].R);
    Try(pos + 1, sum, prev);
}

bool checkSubtask1(void){
    return N <= 20;
}

void solveSubtask1(void){
    sort(a + 1, a + 1 + N);
    Try(0, 0, 0);
    cout << ans;
}

int bsearch(int pos){
    int l = 0, r = pos - 1;
    int res = -1;
    while(l <= r){
        int m = (l + r) / 2;
        if(a[m].R <= a[pos].L){
            res = m;
            l = m + 1;
        }
        else
            r = m - 1;
    }
    return res;
}

void solveSubtask23(void){
    sort(a + 1, a + 1 + N);
    dp[0] = 0;
    for(int i = 1; i <= N; ++i){
        dp[i] = dp[i-1];
        int j = bsearch(i);
        dp[i] = max(dp[i], dp[j] + a[i].V);
    }
    cout << dp[N];
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
    if(checkSubtask1()) return solveSubtask1(), 0;
    else return solveSubtask23(), 0;
}
