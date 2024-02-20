class RecentCounter {
public:
    queue<int>q;
    RecentCounter() {
        return;
    }
    
    int ping(int t) {
        q.push(t);
        int st=t-3000;
        while(!q.empty()){
            if(q.front()<st){
            q.pop();
            }
            else{
                break;
            }
        }
    return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */