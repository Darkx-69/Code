#include <stdio.h>
#include <stdlib.h>
int main()
{char a[6];
    int i=0,j=0;
    for(int k=0;k<6;k++)
    {scanf(" %c",&a[k]);}
    while(i<6)
    {if(i==0)
        {if(a[i+1]=='?')
        {
         j=-((a[i+3]-'0')*(a[i+5]-'0'));
         printf("%c %d",a[i],j);
         i++;
        }}
        else if (i==2){
            if(a[i+1]=='?')
            {j=-((a[i-1]-'0')/(a[i+3]-'0'));
                printf("%c %d",a[i],j);
                i++;
        }}
        
 else {
    if(a[i+1]=='?')
    {j=-((a[i-3]-'0')/(a[i-1]-'0'));
        printf("%c %d",a[i],j);
        i++;
        }
        i++;
 }
    }
 return 0;}