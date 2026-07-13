class Solution {
public:
long long calculateHours(vector<int>& piles,int hrs){
        long long thrs=0;
        int n=piles.size();
        for(int i=0;i<n;i++){
            thrs+= ceil((double)(piles[i])/(double)(hrs));
        }
        return thrs;
    }
        int minEatingSpeed(vector<int>& piles, int h) {
            int low=1;
            int high=*max_element(piles.begin(),piles.end());
            while(low<=high){
                int mid=(low+high)/2;
                long long totalH = calculateHours(piles,mid);
                if(totalH<=h){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }return low;
        }
};