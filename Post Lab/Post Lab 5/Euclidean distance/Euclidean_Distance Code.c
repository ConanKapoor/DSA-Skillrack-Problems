#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct point
{
    int x;																												//Form a structure with x and y as int.
    int y;
}point;

main()
{
    int i,ratio;                      //Initialize variables.
    point point1,point2,middle;
    point1.x=0;
    point1.y=0;
    scanf("%d",&point2.x);
    middle.x=(point2.x)/2;
    scanf("%d",&point2.y);
    middle.y=(point2.y)/2;
    if (point2.y<point2.x)
    {
        ratio=point2.x/point2.y;
        printf("%d\n",ratio);
        for(i=0;i<middle.y;i++)
        {
            point1.x=point1.x+ratio;
            point1.y=point1.y+1;
            printf("%d\n%d\n",point1.x,point1.y);
        }
    }
    else
    {
        ratio=point2.y/point2.x;
        printf("%d\n",ratio);
        for(i=0;i<middle.x;i++)
        {
            point1.x=point1.x+1;
            point1.y=point1.y+ratio;
            printf("%d\n%d\n",point1.x,point1.y);
        }
    }
}
