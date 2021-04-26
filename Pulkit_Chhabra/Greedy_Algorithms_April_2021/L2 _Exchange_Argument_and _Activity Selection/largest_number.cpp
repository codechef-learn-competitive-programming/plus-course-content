 bool cmp(int a,int b)
{
    return to_string(a) + to_string(b) > to_string(b) + to_string(a);
}


class Solution {
    
    public:
    string largestNumber(vector<int>& nums) {
        
        if(*max_element(nums.begin(),nums.end())==0)
            return "0";
        
        sort(nums.begin(), nums.end(), cmp);
        string ans;
        
        for(int i : nums)
            ans += to_string(i);
        
        return ans;
            
    }
};
