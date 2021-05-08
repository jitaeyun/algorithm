class Solution {
public:
    bool palinedrome(int &s, int &e, long long num){
        if(num<s || num>e) return false;
        num*=num;
        string n=to_string(num);
        int l=n.length()-1;
        for(int i=0; i<l/2; ++i) if(n[i]!=n[l-i]) return false;
        return true;
    }
    int superpalindromesInRange(string left, string right) {
        int arr[]={0,1,10,100,1000,10000,100000};
        long long n1=stoll(left),n2=stoll(right);
        int s=sqrt(n1), e=sqrt(n2), sol=0;
        string t,r;
        for(int i=1; i<4; ++i) if(s<=i && i<=e) ++sol;
        for(int i=to_string(s).length(); i<=to_string(e).length(); ++i){
            for(int j=arr[i/2]; j<arr[i/2+1]; ++j){
                t=r=to_string(j); reverse(r.begin(),r.end());
                if(i%2){
                    for(char k='0'; k<='9'; ++k) if(palinedrome(s,e,stoll(t+k+r))) ++sol;
                }
                else {
                    if(palinedrome(s,e,stoll(t+r))) ++sol;
                }
            }
        }
        return sol;
    }
};