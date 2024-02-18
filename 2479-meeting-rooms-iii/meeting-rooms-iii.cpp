class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        map<int,int>booked;//to keep track of no. of meeting held in a particular room
        //sort by end time
        auto compare=[](const pair<long long,int>&a,const pair<long long,int>&b){
            if(a.first==b.first){//if end time same then sort using smallest room
                return a.second > b.second;
            }
            else{
                return a.first>b.first;
            }
        };
        //end time,room id
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,decltype(compare)>pq;//occupied rooms
        priority_queue<int,vector<int>,greater<int>> freerooms;
        sort(meetings.begin(),meetings.end());//to keep start time less meeting fwd
        for(int i=0;i<n;i++){
            freerooms.push(i);
        }
        for(auto v :meetings){
            long long start=v[0],end=v[1];
            while(!pq.empty() && pq.top().first<=start){
                freerooms.push(pq.top().second);
                pq.pop();
            }
            if(!freerooms.empty()){
                booked[freerooms.top()]++;
                pq.push({end,freerooms.top()});
                freerooms.pop();
            }
            else{
                //i.e delay is happening but later it will be booked
                booked[pq.top().second]++;
                auto p=pq.top();
                pq.pop();//as new element will be added in that place after updating
                pq.push({p.first+end-start,p.second});//like (1,5) was there at previous and now add 2,7 so 5+(7-2)=10 i.e end time of 2,7
            }
        }
        int maxrooms=0,meetingroom=-1;
        for(auto p:booked){
            if(p.second>maxrooms){
                maxrooms=p.second;
                meetingroom=p.first;
            }
        }
        return meetingroom;
    }
};