#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main()
{
    int length1,length2,i,j,c=0;
    char String[50],Pattern[40];
    scanf("%s",String);
    scanf("%s",Pattern);
    length1=strlen(Pattern);
    length2=strlen(String);
    if(length1>length2||length2<0||length1<0)
    {
        printf("Invalid input");
        exit(0);
    }
    else
    {
        for(i=0;i<length2;i++)
        {
            for(j=0;j<length1;j++)
            {
                if (String[i+j]==Pattern[j])
                {
                    c++;
                }
                else
                {
                    c=0;
                    break;
                }
            }
            if(c==length1)
            {
                printf("%d",i);
                exit(0);
            }
        }
        printf("-1");
    }
}

