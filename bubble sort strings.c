#include<stdio.h>
#include<string.h>
main()
{
    char str[100][100],temp[100];
    printf("Enter no of strings");
    int n;
    scanf("%d",&n);
    int i,j;
    for(i=0;i<n;i++)
        scanf("%s",str[i]);
    for(i=0;i<n;i++)
        for(j=0;j<n-i-1;j++)
    {
        int z=strcmp(str[j],str[j+1]);
        if(z>0)
        {
            strcpy(temp,str[j]);
            strcpy(str[j],str[j+1]);
            strcpy(str[j+1],temp);
        }
    }
    for(i=0;i<n;i++)
        printf("%s\t",str[i]);
}
