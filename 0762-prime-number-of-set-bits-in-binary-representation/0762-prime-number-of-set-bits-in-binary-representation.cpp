class Solution {
public:
  bool isprime(int num)
{
    if(num<=1)
        return false;
    for(int i=2; i<num; i++)
    {
        if(num%i == 0)
            return false;
    }
      return true;
}
    
    int countPrimeSetBits(int left, int right) {
        int count = 0;
        for(int i=left; i<=right; i++)
        {
            int no = __builtin_popcount(i);
            if(isprime(no))
                count++;
        }
        return count;
    }
};