#include<stdio.h>
struct coord {
int x;
int y;
};
int main()
{
coord rect1[4] ;
coord rect2[4];
rect1[0].x = 1;
rect1[0].y = 2;
rect1[1].x = 5;
rect1[1].y = 2;
rect1[2].x = 1;
rect1[2].y = 0;
rect1[3].x = 5;
rect1[3].y = 0;

rect2[0].x = 1;
rect2[0].y = 2;
rect2[1].x = 5;
rect2[1].y = 2;
rect2[2].x = 1;
rect2[2].y = 0;
rect2[3].x = 5;
rect2[3].y = 0;

int xcoorDiff;
int ycoorDIff;
/*
left above, left below, right above , right below;
fullX, fullY;
fullX, fullY;
*/
for(int i = 0; i<4;i++)
{
    areaRect1 = (rect1[0].x - rect1[1].x) * (rect1[0].y - rect1[1].y);
     
    areaRect2 = (rect2[0].x - rect2[1].x) * (rect2[0].y - rect2[1].y);
   
    if(rect1[0].x)

}


}
