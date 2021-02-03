#include <vector>
#include <string>
using std::string;
using std::vector;

int minofthree(const int &x,const int &y,const int &z) {
    int tmp = x<y?x:y;
    return tmp<z?tmp:z;
}

int mindistance(string &str1,string& str2) {
    int n=str1.size(),m=str2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1));
    for(int i=0;i<n+1;++i) {
        dp[i][0] = i;
    }
    for(int j=0;j<m+1;++j) {
        dp[0][j] = j;
    }
    for(int i=1;i<n+1;++i) {
        for(int j=1;j<m+1;++j) {
            if(str1[i-1]==str2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            }
            else {
                dp[i][j] = minofthree(dp[i-1][j-1],dp[i][j-1],dp[i-1][j]) +1 ;
            }
        }
    }
    return dp[n][m];
}

int main() {

}