class Solution {
public:
    string removeKdigits(string num, int k) {

        if (num.length() == k) return "0";

    string ans;
    vector<char> stack;

    for (int i = 0; i < num.length(); ++i) {
      while (k > 0 && !stack.empty() && stack.back() > num[i]) {
        stack.pop_back();
        --k;
      }
      stack.push_back(num[i]);
    }

    while (k-- > 0)
      stack.pop_back();

    for (const char c : stack) {
      if (c == '0' && ans.empty()) continue;
      ans += c;
    }

    return ans.empty() ? "0" : ans;
        // stack<char>st;
        // if(num.length()<=k){
        //     return "0";
        // }
        // if(k==0){
        //     return num;
        // }
        // st.push(num[0]);
        // for(int i=1;i<num.length();i++){
        //     while(k>0 && !st.empty() && st.top()>num[i]){
        //         st.pop();
        //         k--;
        //     }
        //     st.push(num[i]);
        //     if(st.size()==1 && num[i]=='0'){
        //         st.pop();
        //     }
        // }
        // while(k && !st.empty()){
        //     st.pop();
        //     k--;
        // }
        // string ans="";
        // while(!st.empty()){
        //     ans=st.top()+ans;
        //     st.pop();
        // }
        // if(ans.length()==0){
        //     return "0";
        // }
        // return ans;
    }
};