class Solution {
public:
    int reverse(int x) {
        int copy = x;
        long long int rev=0;
        
        while(copy != 0)
        {
            int temp = copy%10;
            rev=rev*10+temp;
            copy=copy/10;
        }
    
        if(rev > INT_MAX || rev < INT_MIN)
            return 0;
       
        return rev;
    }
};