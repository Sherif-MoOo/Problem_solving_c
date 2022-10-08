int cmp(const void* a , const void* b)
{
    return (*(int*)a - *(int*)b);
}

bool IsPower2(int x)
{
    return(!(x & (x-1)) && x);
}

long countPairs(int arr_count, int* arr) {
    
    long result = 0;
    
    qsort(arr, arr_count, sizeof(int), cmp);
    
    int max = arr[arr_count-1];
    
    int* Hash = (int*) calloc(max, sizeof(int));
    
    int size = arr_count;
    
    for(int i = 0 ; i < arr_count ; i++)
    {
        Hash[arr[i]]++;
        if(Hash[arr[i]] > 1)
            size--;        
    }
    
    if(size*2 > arr_count)
    {
        for(int i = 0 ; i < arr_count-1 ; i++)
        {
            for(int j = i+1; j < arr_count ; j++)
            {
                if(IsPower2(arr[i] & arr[j]))
                    result++;
            }
        }
        
        return result;
    }
    
    int* set = (int*) malloc(size*sizeof(int));
    
    int s = 0;
    
    for(int i = 0; i < arr_count ; i++)
    {
        if(arr[i] == arr[i+1])
            continue;
        
        set[s] = arr[i];
        s++;
    }
    
    for(int i =0 ; i < size ; i++)
    {
        if(Hash[set[i]] > 1)
        {
            if(IsPower2(set[i]))
            {
                result += ( (long)(Hash[set[i]] - 1)  * (long)(Hash[set[i]]) ) / 2;
            }
        }
        
        for(int j = i+1 ; j < size ; j++)
        {
            if(IsPower2(set[i] & set[j]))
            {
                result += (long)Hash[set[i]] * (long)Hash[set[j]];
            }
        }
    }
    
    
    
    return result;
}