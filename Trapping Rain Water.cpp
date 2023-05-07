// First Intitive Aprroch
// Global Max

class Solution {
public:
    int trap(vector<int>& nums) {
        int n=nums.size();
        stack<int> st;
        vector<int> left(n,-1),right(n,-1);
        left[n-1]=-1;
        st.push(nums[n-1]);
        int mx=nums[n-1];
        right[0]=-1;
        for(int i=n-2;i>=0;i--)
        {
            mx=max(mx,nums[i]);
            while(st.size() && st.top()<=nums[i])
            {
                st.pop();
            }
            if(st.size()==0)left[i]=-1;
            else left[i]=mx;
            st.push(mx);
        }
        mx=nums[0];
        while(st.size())st.pop();
        st.push(nums[0]);
        for(int i=1;i<n;i++)
        {
            mx=max(mx,nums[i]);
            while(st.size() && st.top()<=nums[i])
            {
                st.pop();
            }
            if(st.size()==0)right[i]=-1;
            else right[i]=mx;
            st.push(mx);
        }
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            int mn=min(left[i],right[i]);
            if(mn==-1)continue;
            else ans=ans+mn-nums[i];
        }
        return ans;
    }
};


// Second Approch Max

class Solution {
public:
    int trap(vector<int>& nums) {
        
        stack<int> st;
        int ans=0;
        st.push(0);
        for(int i=1,n=nums.size();i<n;i++)
        {
            while(st.size() && nums[st.top()]<=nums[i])
            {
                int curr=st.top();
                int right=i;
                st.pop();
                if(st.size()==0)break;
                int left=st.top();
                int width=right-left-1;
                int mn=min(nums[left],nums[right]);
                ans=ans+(mn-nums[curr])*width;
            }
            if(st.size() && nums[st.top()]>nums[i])st.push(i);
            else st.push(i);
        }
        return ans;
    }
};