class Solution {
public:
    string addStrings(string num1, string num2) {
        int m=max(num1.length(),num2.length())-1, carry=0, n, p_n1=num1.length()-1, p_n2=num2.length()-1;
        string sol(m+1,'0');
        for(; p_n1>=0&&p_n2>=0; --p_n1, --p_n2, --m){
            n=carry+num1[p_n1]-'0'+num2[p_n2]-'0';
            carry=n/10;
            sol[m]=(n%10)+'0';
        }
        for(; p_n1>=0; --p_n1, --m){
            n=carry+num1[p_n1]-'0';
            carry=n/10;
            sol[m]=(n%10)+'0'; 
        }
        for(; p_n2>=0; --p_n2, --m){
            n=carry+num2[p_n2]-'0';
            carry=n/10;
            sol[m]=(n%10)+'0'; 
        }
        if(carry) sol="1"+sol;
        return sol;
    }
};