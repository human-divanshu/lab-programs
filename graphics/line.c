#include <stdio.h>
#include <graphics.h>

int main(void)
{
    float x1, y1, x2, y2;
    float m, c;
    float x, y;
    float ctr;
    int gd = DETECT, gm;
    
    printf("Enter the starting point in format (x,y) :");
    scanf("%f %f", &x1, &y1);

    printf("Enter the end point in format (x,y) :");
    scanf("%f %f", &x2, &y2);
    
    m = (y2 - y1) / (x2 - x1);
    c = y1 - m * x1;
    
    
    initgraph(&gd, &gm, NULL);

    if(x1 < x2) {
          for(ctr = x1; ctr <= x2; ctr++) {
                  x = ctr;
                  y = m * x + c;
                  putpixel((int)x, (int)y, 10);      
          }
    } else {
          for(ctr = x2; ctr <= x1; ctr++) {
                  x = ctr;
                  y = m * x + c;
                  putpixel((int)x, (int)y, 10);      
          }    
    }
    delay(10000);
    closegraph();
    return 0;
}
