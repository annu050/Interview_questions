class LFUCache {
public:
    int cap,minfreq;
    unordered_map<int,pair<int,int>>keyval;
    unordered_map<int,list<int>>freq;
    unordered_map<int,list<int>::iterator>pos;

    void updatefreq(int key){
        //delete key from from current freq
        //increment freq;
        //insert key in new freq;
        //update new pos of the key;
        //check for min freq;
        int curr_freq=keyval[key].second;
        freq[curr_freq].erase(pos[key]);//address at which key is erased from freq
        keyval[key].second++;
        curr_freq=keyval[key].second;
        freq[curr_freq].push_back(key);
        pos[key]=--freq[curr_freq].end();//as 1-> 2 3 4 so wil point after 4 so to make it point at 4 we do --
        if(freq[minfreq].empty()){
            minfreq++;
        }
    }
    LFUCache(int capacity) {
        cap=capacity;
        minfreq=0;
    }
    
    int get(int key) {
        if(keyval.find(key)==keyval.end()){
            return -1;
        }
        updatefreq(key);
        return keyval[key].first;
    }
    
    void put(int key, int value) {
        if(cap==0)return;
        if(keyval.find(key)!=keyval.end()){
            keyval[key].first=value;
            updatefreq(key);
            return;
        }
        if(keyval.size()==cap){
            int delkey= freq[minfreq].front();
            keyval.erase(delkey);
            pos.erase(delkey);
            freq[minfreq].pop_front();
        }
        keyval[key]={value,1};
        freq[1].push_back(key);
        pos[key]=--freq[1].end();
        minfreq=1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */