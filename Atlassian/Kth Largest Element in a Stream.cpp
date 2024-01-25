class KthLargest {
public:
priority_queue<int> q;
int size;
    KthLargest(int k, vector<int>& nums) {
        size = k;
        for(int i : nums) add(i);
    }
    
    int add(int val) {
        if(q.size()<size) {
            q.push(-val);
        }
        else {
            if(-q.top()<val) {
                q.pop();
                q.push(-val);
            }
        }
        return -q.top();
    }
};