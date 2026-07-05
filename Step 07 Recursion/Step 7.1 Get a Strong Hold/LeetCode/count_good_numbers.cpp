class Solution {
public:
    long long pow(long long x,long long n){
        long long ans = 1;
        while(n>0){
            if(n%2==1){
                ans = (ans*x)%1000000007;
            }
            x = (x*x)%1000000007;
            n = n/2;             
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        int ans = 1;
        if(n%2==1){
            ans = 5;
            n = n-1;
        }
        return (ans*pow(20,n/2))%1000000007;
    }
};
