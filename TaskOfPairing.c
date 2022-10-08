long taskOfPairing(int freq_count, long* freq) {
    
    long res  = 0;
    
    bool test = false;
    
    for(int i = 0 ; i < freq_count ; i++)
    {
        if(freq[i] != 0)
        {   
            res += freq[i]/2;
            
            if(freq[i]%2 != 0 && test)
            {
                test = false;
                
                res++;
            }
            
            else if(freq[i]%2 != 0)
                test = true;
        }
        
        else
            test = false;
    }
    
    return res;
}