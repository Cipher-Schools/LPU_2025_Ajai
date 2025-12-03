class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<char>x;
        for(auto y:s){
            x.push(y);
        }
        vector<char>z;
        while(!x.empty()){
            z.push_back(x.top());
            x.pop();
        }
        s = z;
    }
};

//method 2--
class Solution {
public:
    void reverseString(vector<char>& s) {
        reverse(s.begin(),s.end());
    }
};