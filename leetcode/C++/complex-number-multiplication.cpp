class Solution {
public:
    int getReal(string &num){
        return stoi(num.substr(0,num.find("+")));
    }
    int getComplex(string &num){
        int idx = num.find("+");
        return stoi(num.substr(idx+1,num.length()-idx-1));
    }
    string complexNumberMultiply(string num1, string num2) {
        int num1_real=getReal(num1), num1_comp=getComplex(num1);
        int num2_real=getReal(num2), num2_comp=getComplex(num2);
        int real=num1_real*num2_real-(num1_comp*num2_comp);
        int comp=num1_real*num2_comp+num1_comp*num2_real;
        return to_string(real)+"+"+to_string(comp)+"i";
    }
};