class DataStream {
public:
int v;
int m;
queue<int> q;
unordered_map<int, int> mp;
    DataStream(int value, int k) {
        v=value;
        m=k;
    }
    bool consec(int num) {
        q.push(num);
        mp[num]++;
        bool flag=false;
        if(q.size()==m){
            if(mp.size() == 1 && mp[v] == m)
            {
                flag = true;
            }
            // pop out from queue
            int front = q.front();
            q.pop();
            // decrement the frequency of front from map
            mp[front]--;
            // if the frequency of the from in map is zero then erase the front from map
            
            if(mp[front] == 0)
            {
                mp.erase(front);
            }
        }
        return flag;
    }
};