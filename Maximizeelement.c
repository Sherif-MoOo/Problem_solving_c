
int maxValue(int n, int index, int maxSum){
    int k = index;
    long LengthOfRight = n - (k + 1);
    long LengthOfLeft  = k;
    
    long high = maxSum;
    long low  = 1;
    
    long res = 0;
    
    while(high >= low)
    {
        long mid = (high - low) / 2 + low;
        long sum = mid;
        long SumOfRight = 0;
        long SumOfLeft  = 0;
        
        long n = mid - 1;
        
        if(LengthOfRight <= n)
            SumOfRight = LengthOfRight * (2*n - LengthOfRight + 1) / 2;
        else
            SumOfRight = n*(n + 1) /2 + (LengthOfRight - n);
    
        if(LengthOfLeft <= n)
            SumOfLeft = LengthOfLeft * (2*n - LengthOfLeft + 1) / 2;
        else
            SumOfLeft = n*(n + 1)/2 + (LengthOfLeft - n);
        
        sum += SumOfRight + SumOfLeft;
        
        if(sum <= maxSum)
        {
            res = mid;
            low = mid + 1;
        }
        
        else
            high = mid - 1;
        
    }
    
    
     return res;   
}