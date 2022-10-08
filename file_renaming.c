#define m 1000000007

void init(long* arr , long size, int val)
{
    for(int i = 0 ; i < size ; i++)
        arr[i] = val;

}
   
int renameFile(char* newName,char* oldName)
{
    long LengthOfNew = strlen(newName);
    
    long LengthOfOld = strlen(oldName);
    
    //long* accumulator = (long*) calloc(LengthOfOld + 1, sizeof(long))
    
    long* result = (long*)malloc( (LengthOfOld + 1) * sizeof(long));
    
    init(result, LengthOfOld + 1 , 1);
    
    long* accumulator = NULL;
    
    for(int i = 1 ; i < LengthOfNew + 1; i++)
    {
        free(accumulator);
        accumulator = (long*) calloc(LengthOfOld + 1, sizeof(long));
        
        for(int j = i ; j < LengthOfOld + 1; j++)
        {
            accumulator[j] = accumulator[j-1];
            
            if(newName[i-1] == oldName[j-1])
                accumulator[j] += result[j-1];
        }
        
        memcpy(result,accumulator , (LengthOfOld + 1)*sizeof(long));
    }
    
    return accumulator[LengthOfOld] %   m ;
}