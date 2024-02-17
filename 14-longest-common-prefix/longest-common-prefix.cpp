// in trie check for child count should be 1 
class trienode{
    public:
    char data;
    trienode* children[26];
    int childcount;
    bool isterminal;

    trienode(char ch){
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        childcount=0;
        isterminal=false;
    }
};
class trie{
    public:
        trienode* root;
        trie(char ch){
            root=new trienode(ch);
        }

        void insertutil(trienode* root,string word){
            if(word.length()==0){
                root->isterminal=true;
                return;
            }
            int index=word[0]-'a';
            trienode* child;
            if(root->children[index]!=NULL){
                child=root->children[index];
            }
            else{
                child=new trienode(word[0]);
                root->children[index]=child;
                root->childcount++;
            }
            insertutil(child,word.substr(1));
        }
        void insertword(string word){
            insertutil(root,word);
        }
        void lcp(string s,string &ans){
            for(int i=0;i<s.length();i++){
                char ch=s[i];
                if(root->childcount==1){
                    ans+=ch;
                    //now go forward
                    int index=ch-'a';
                    root=root->children[index];
                }
                else{
                    break;
                }
                if(root->isterminal){
                    break;
                }
            }
        }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        trie* t=new trie('\0');
        //insert all the strings
        for(int i=0;i<strs.size();i++){
            if(strs[i]==""){
                return "";
            }
            else{
                t->insertword(strs[i]);
            }
            
        }
        string first=strs[0];
        string ans="";
        t->lcp(first,ans);
        return ans;

        // string ans="";
        // for(int i=0;i<strs[0].length();i++){
        //     char ch=strs[0][i];
        //     bool match =true;
        //     for(int j=1;j<strs.size();j++){
        //         if(strs[j].size()<i || ch!=strs[j][i]){
        //             match=false;
        //             break;
        //         }
        //     }
        //     if(match==false){
        //         break;
        //     }
        //     else{
        //         ans+=ch;
        //     }
        // }
        // return ans;
    }
};



