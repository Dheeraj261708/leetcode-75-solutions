class Solution {
public:
    int largestAltitude(vector<int>& gain) {
      int m=0;
      int c=0;

    for(int g:gain){
        c +=g;
        m=max(m,c);
    }
        return m;
    }
};





