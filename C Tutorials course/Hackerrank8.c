#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;
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
        for (int j=i+1; j<n; j++) 
        {
            if (s[i]>=s[j]) 
            {
                int temp;
                temp = s[i];
                s[i]=s[j];
                temp=s[j];
            
            
                temp = tr[i].a;
                tr[i].a=tr[j].a;
                tr[j].a=temp;
            
                
                temp = tr[i].b;
                tr[i].b=tr[j].b;
                tr[j].b=temp;
            
                
                temp = tr[i].c;
                tr[j].c=tr[j].c;
                tr[j].c=temp;
            }
            
        }
    
    }
    
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
    printf("\n");
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}


