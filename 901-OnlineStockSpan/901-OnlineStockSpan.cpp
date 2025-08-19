// Last updated: 8/19/2025, 3:17:21 PM
class StockSpanner {
public:
    vector<int> arr;
    StockSpanner() {
        
    }
    
    int next(int price) {
        arr.push_back(price);
        int size = arr.size();
        if(size == 1) return 1;
        int i = size-1;
        while(i >= 0 && arr[i] <= price){
            i--;
        }
        if(i < 0) return size;
        return size-i-1;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */