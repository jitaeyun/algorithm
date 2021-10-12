/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long r=n, l=1, m=0, t=0;
        while(l<=r){
            m=(l+r)/2;
            if((t=guess(m))<0) r=m-1;
            else if(t>0) l=m+1;
            else break;
        }
        return m;
    }
};