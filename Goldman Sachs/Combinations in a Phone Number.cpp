class Solution {
public:
    void solve(int index,string output,vector<string>& ans,string mapping[],string digits){
    if(index>=digits.length()){
        ans.push_back(output);
        return;
    }
    int number=digits[index]-'0';//char m aega to pehle convert krlo
    string val=mapping[number];
    for(int i=0;i<val.length();i++){
        output.push_back(val[i]);
        solve(index+1,output,ans,mapping,digits);
        output.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
        int index=0;
        vector<string> ans;
        if(digits.length()==0){
            return ans;
        }
        string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string output="";
       
        solve(index,output,ans,mapping,digits);
        return ans;

    }
};