 class Solution {
public:
     set<pair<int,int>> s;
    int r , c; 
    Solution(int m, int n) {
        r=m;
        c=n;
    }
    
    vector<int> flip() {
        //randomnly generates x and y coordinates
        int x = rand()%r; 
        int y = rand()%c; 
        //check if x,y is present in set if not then insert it and return coordinates
        if(s.find({x,y})==s.end())
        {    s.insert({x,y});
            return {x,y};
        }
        //else return flip
        else return flip();
    }
    
    void reset() {
        //clear is used because it removes all elements from the set.
        s.clear(); 
    }
};