class Solution {
public:
    int maxArea(vector<int>& height) {
        // int mw=0;
        // for(int i=0; i<height.size(); i++){
        //     for(int j=i+1; j<height.size();j++){
        //         int width= j-i;
        //         int ht=min(height[i],height[j]);
        //         int area=width*ht;
        //         mw=max(mw,area);
        //     }
        // }
        // return mw;
        int maxwater=0;
        int lp=0,rp=height.size()-1;
        int ans=0;
        while(lp<rp){
            int width=rp-lp;
            int ht=min(height[lp],height[rp]);
            int currentwater=width*ht;
            maxwater=max(maxwater,currentwater);
            if(height[lp]<height[rp]){
                lp++;
            }
            else{
                rp--;
            }
        }
        return maxwater;


        
    }
};