void sort_by_area(triangle* tr, int n)
{
    float s[1000];
    for (int i=0 ; i<n; i++) 
    {
        
        float p;
        p=(tr[i].a+tr[i].b+tr[i].c)/2.0;
        
        s[i]=(p*(p-tr[i].a)*(p-tr[i].b)*(p-tr[i].c));
    }
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n-i-1; j++) 
        {
            if (s[j]>s[j+1]) 
            {
                int temp;
                temp = s[j];
                s[j]=s[j+1];
                temp=s[j+1];
            
            
                temp = tr[j].a;
                tr[j].a=tr[j+1].a;
                tr[j+1].a=temp;
            
                
                temp = tr[j].b;
                tr[j].b=tr[j+1].b;
                tr[j+1].b=temp;
            
                
                temp = tr[j].c;
                tr[j].c=tr[j+1].c;
                tr[j+1].c=temp;
            }
            
        }
    
    }
    
}