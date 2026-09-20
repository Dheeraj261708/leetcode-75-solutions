/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l=0;
        int r=n;
        int f=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(guess(mid)<=0){
                f=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
          return f;
    }
};