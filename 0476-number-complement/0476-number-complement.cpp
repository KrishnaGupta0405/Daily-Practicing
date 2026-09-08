class Solution {
public:
    int findComplement(int num) {
        int mask =0, m = num;
        while(m != 0){
            mask = (mask << 1) | 1;
            m >>= 1;
        }
        num = (~num)&mask;
        return num;

    }
};