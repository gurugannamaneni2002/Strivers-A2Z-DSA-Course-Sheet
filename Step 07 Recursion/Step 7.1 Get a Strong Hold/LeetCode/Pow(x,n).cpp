class Solution {
public:
    double pow(double x, long long n){
        if(n==0){
            return 1;
        }
        if(n==1){
            return x;
        }
        double ans;
        ans = pow(x,n/2);
        if(n%2==0){
            ans = ans*ans;
        }
        else{
            ans = ans*ans*x;
        }
        return ans;
    }
    double myPow(double x, int n) {
        long long N = n;
        if (n<0){
            return 1/pow(x,-N);
        }
        return pow(x,n);
    }
};
