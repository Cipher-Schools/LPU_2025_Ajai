class RecentCounter {
public:
vector<int>arr;
    RecentCounter() {

    } 
    
    int ping(int t) {
      arr.push_back(t);
      int count =0;
      for(int x : arr)  
      if(x >= t -3000)
      count++;
      return count;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */