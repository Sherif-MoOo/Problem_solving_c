#define max(a,b) ( ( (a) > (b) ) ? (a) : (b) )
#define min(a,b) ( ( (a) < (b) ) ? (a) : (b) )

long maxSubarrayValue(int arr_count, int* arr) {
    
    long result = 0;
    
    for(int i = 1; i < arr_count ; i+=2)
    {
        arr[i] *= -1;
    }
    
    long MaxSoFar = arr[0];
    long Max = arr[0];
    long MinSoFar = arr[0];
    long Min = arr[0];
    
    for(int i = 1 ; i < arr_count ; i++)
    {
        Max      = max(arr[i] , Max + arr[i]);
        
        MaxSoFar = max(MaxSoFar , Max);
        
        if(Min >= 0)
            Min = arr[i];
            
        else
            Min += arr[i];
            
        MinSoFar = min(MinSoFar,Min);
    }
    
    MaxSoFar = (MaxSoFar >= 0) ? MaxSoFar : MaxSoFar*-1;
    MinSoFar = (MinSoFar >= 0) ? MinSoFar : MinSoFar*-1;
    
    Max    = max(MaxSoFar,MinSoFar);
    
    result = Max * Max;
    
    return result;
    
}