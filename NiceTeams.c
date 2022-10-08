int cmp(const void * a , const void * b)
{
    return (*(int*) a - *(int*) b);
}


int maxPairs(int skillLevel_count, int* skillLevel, int minDiff) {

    qsort(skillLevel,skillLevel_count, sizeof(int), cmp);
    
    int mid = skillLevel_count / 2;
    
    int left = mid - 1;
    
    int res = 0;
    
    for(int i = skillLevel_count - 1 ;  i >= mid ; i--)
    {
        while(left >= 0)
        {
            if( abs(skillLevel[left] - skillLevel[i]) >= minDiff )
            
            {
                res++;
                left--;
                break;
            }
            left--;
        }
    }
   return res; 
}       