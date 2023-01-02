class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> checkerG(10,0),checkerS(10,0);
        int A=0,B=0,n=guess.size();
        for(int i=0;i<n;i++){
            if(guess[i]==secret[i]){
                A++;
                continue;
            }
            checkerG[guess[i]-'0']++;
            checkerS[secret[i]-'0']++;
        }
        for(int i=0;i<10;i++)B+=min(checkerG[i],checkerS[i]);
        string ans="";
        ans+=to_string(A)+"A"+to_string(B)+"B";
        return ans;
    }
};
