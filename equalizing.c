int cmp(const void* a , const void* b)
{
    return ( *(int*) a - *(int*)b );
}

int minOperations(int arr_count, int* arr, int threshold, int d) {
    
    qsort(arr, arr_count, sizeof(int), cmp);
    
    int result = pow(2,31) - 1 ;
    
    int (*Hash)[2];
    
    Hash = calloc(arr[arr_count-1] + 1, sizeof(int));
    Hash = calloc(1, sizeof(int[arr[arr_count-1] + 1][2]));
    
    
    for(int i = 0 ; i < arr_count ; i++)
    {
        int op = 0;
        
        for(;;)
        {
            Hash[arr[i]][0]++;
            
            Hash[arr[i]][1] += op;
            
            if(Hash[arr[i]][0] == threshold)
                result = (result <= Hash[arr[i]][1]) ? result : Hash[arr[i]][1];
                
            if(arr[i] == 0)
                break;
                
            arr[i] /= d;
            
            op++;
        }
    }
    
    return result;
}