class Solution {
public:
    int furthestBuilding(vector<int>& h, int b, int l) 
    {
        priority_queue<int,vector<int>, greater<int> > q;
        int req = 0, max_ans = 0;
        
        for(int i = 1; i < h.size(); ++i)
        {
            if(h[i] <= h[i-1])
            {
                max_ans = i;
                continue;
            }
            
            int cur = h[i] - h[i-1];
            
            q.push(cur);
            
            if(q.size() > l)
            {
                req += q.top();
                q.pop();
            }
            
            if(req <= b)
                max_ans = i;
            
            else
                break;
        }
        
        return max_ans;
    }
};
