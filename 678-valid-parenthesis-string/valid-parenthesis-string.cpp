class Solution {
public:
    bool checkValidString(string s) {
        stack<int>star,op;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                op.push(i);
            }
            if(s[i]=='*'){
                star.push(i);
            }
            if(s[i]==')'){
                if(!op.empty()){
                    op.pop();
                }
                else if(!star.empty()){
                    star.pop();
                }
                else{
                    return false;
                }
            }
        }
        while(!op.empty() && !star.empty()){
            if(op.top()>star.top())return false;
            op.pop();
            star.pop();
        }

        return op.empty();
    }
};