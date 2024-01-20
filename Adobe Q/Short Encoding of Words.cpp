class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        for(auto &i:words){
            reverse(i.begin(),i.end());
        }
        sort(words.begin(),words.end());

        int n=words.size();
        string str=words[0];
        int ans=0,strsize;
        for(int i=1;i<n;i++){
            strsize=str.size();
            if(words[i].compare(0,strsize,str)){
                ans+=1+strsize;
            }
            str=words[i];
        }
        ans+=1+str.size();
        return ans;
    }
};