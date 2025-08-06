// Last updated: 8/6/2025, 12:20:05 PM
// class Solution {
// public:
    
//     void buildSegTree(vector<int> &baskets,vector<int> &seg,int left,int right,int segIndex){
//         if(left == right){
//             seg[segIndex] = baskets[low];
//         }
//         int mid = left + (right-left)/2;
//         buildSegTree(fruits,seg,left,mid,2*segIndex);
//         buildSegTree(fruits,seg,mid,right,2*segIndex+1);
//         seg[segIndex] = max(seg[2*segIndex],seg[2*segIndex+1]);
//     }
//     int solve(vector<int> &seg,fruit,int n,int segIndex,int left,int right){
//         if(left == right){
//             seg[segIndex] = -1;
            
//             return 1;
//         }
//         if(seg[segIndex] >= fruit){
//             int mid = left + (right-left)/2;
//             int ans = max(solve(seg,fruit,n,2*segIndex,left,mid),solve(seg,fruit,n,2*segIndex+1,mid,right));
//         }
//         return -1;
        
//     }
//     int canFruitsBePlaced(vector<int>& fruits,vector<int> &seg,int fruit,int n,int segIndex){

//         int left = 0,right = n-1;
//         int ans = solve(seg,fruit,n,1,left,right);
//         return ans;
//         int mid = left + (right-left)/2;
//         if(seg[segIndex] >= fruit){

//         }
//     }
//     int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
//         int n = fruits.size();
//         vector<int> seg(4*n+1);
//         int left = 0,right = n-1;
//         buildSegTree(baskets,seg,left,right,1);
//         int count = 0;
//         for(int i=0;i<n;i++){
//             if(canFruitBePlaced(fruits,seg,fruits[i],n,1) == -1) count++;
//         }

//         return count;
//     }
// };




class Solution {
    vector<int> segTree;

    void buildSegTreeRMQ(vector<int>& baskets,int low,int high,int st_idx){
        if(low==high){
            segTree[st_idx] = baskets[low];
            return;
        }

        int mid = low + (high-low)/2;
        buildSegTreeRMQ(baskets,low,mid,2*st_idx);
        buildSegTreeRMQ(baskets,mid+1,high,2*st_idx+1);
        segTree[st_idx] = max(segTree[2*st_idx],segTree[2*st_idx+1]);
    }
    int findLeftmostBasket(const int& fruit,int low,int high,int st_idx){
        if(segTree[st_idx]<fruit)
            return -1;
        if(low==high){
            segTree[st_idx] = -1;
            return 1;//1 shows the basket was found
        }
        
        int val;
        int mid = low + (high-low)/2;
        if(segTree[2*st_idx]>=fruit)    val = findLeftmostBasket(fruit,low,mid,2*st_idx);
        else                            val = findLeftmostBasket(fruit,mid+1,high,2*st_idx+1);
        segTree[st_idx] = max(segTree[2*st_idx],segTree[2*st_idx+1]);
        return val;
    }
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        segTree = vector<int>(4*n+1);

        //Step-1: Build Segment Tree RMQ
        int st_idx = 1;
        buildSegTreeRMQ(baskets,0,n-1,st_idx);

        //Step-2: Query the leftmost basket to be used
        int count = 0;
        for(int i=0;i<n;++i){
            if(findLeftmostBasket(fruits[i],0,n-1,st_idx)==-1)
                count++;
        }
        return count;
    }
};