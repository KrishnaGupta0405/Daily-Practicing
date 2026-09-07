class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum = 0, mul = 1;
        while ( n > 0 ){
            int ld = n%10;
            sum +=ld;
            mul*=ld;
            n=n/10;
        }
        return (mul-sum);
        
    }
};