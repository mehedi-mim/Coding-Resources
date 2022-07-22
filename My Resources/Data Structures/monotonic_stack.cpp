#leetcode 84
#define ll long long 
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(-1);
        stack<int> stk;
        ll ans = 0;
        for(ll i = 0;i < heights.size();i++){
            if(stk.empty() || heights[stk.top()] <=  heights[i]){
                stk.push(i);
            }
            else{
                  while(stk.size() && heights[stk.top()] > heights[i]){
                      
                      ll rdx = i;
                      ll value = heights[stk.top()];
                      stk.pop();
                      ll len = 1;
                      if(stk.size()){
                         ll ldx = stk.top();
                         len = (rdx - ldx) - 1;
                      }
                      else len = rdx;
                      
                      ans = max(ans,len * value);
                  }
                stk.push(i);
            }
        }
        return ans;
    }
};
