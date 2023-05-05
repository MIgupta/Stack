//Recursive Sol 
// Space Compexity O(1) if(recursive space neglect)
// Time Complexity O(n)

int solve(vector<string> &nums,int &i)
{
    if(nums[i]=="+" || nums[i]=="-" || nums[i]=="*" || nums[i]=="/")
    {
        char oper=nums[i][0];
        int op1=solve(nums,--i);
        int op2=solve(nums,--i);

        if(oper=='+')return op2+op1;
        if(oper=='*')return op2*op1;
        if(oper=='/')return op2/op1;
        if(oper=='-')return op2-op1;
    }
    return stoi(nums[i]);
}
int evalRPN(vector<string>& tokens) {
        
        int n=tokens.size()-1;
        return solve(tokens,n);
}



// Iterative Simple Approach 
// Intitutive Solution
// Space Compexity O(n) 
// Time Complexity O(n)

int evalRPN(vector<string>& tokens) {
        
        stack<int> st;
        int i=0;
        int n=tokens.size();
        while(i<n)
        {
            
            if(tokens[i]!="*" && tokens[i]!="-" && tokens[i]!="+" && tokens[i]!="/")
            {
                int val=0;
                if(tokens[i][0]=='-')
                {
                    for(int j=1;j<tokens[i].size();j++)
                    {
                        int digit=tokens[i][j]-'0';
                        val=val*10+digit;
                    }
                }
                else
                {
                    for(int j=0;j<tokens[i].size();j++)
                    {
                        int digit=tokens[i][j]-'0';
                        val=val*10+digit;
                    }
                }
                if(tokens[i][0]=='-')
                st.push(-val);
                else st.push(val);
            }
            else
            {
                int v1=st.top();st.pop();
                int v2=st.top();st.pop();
                if(tokens[i]=="+")st.push(v2+v1);
                if(tokens[i]=="/")st.push(v2/v1);
                if(tokens[i]=="*")st.push(v2*v1);
                if(tokens[i]=="-")st.push(v2-v1);
            }
            i++;
        }
        return st.top();
        
    }