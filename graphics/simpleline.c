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

    // calculate slope of line  
    m = (y2 - y1) / (x2 - x1);
    c = y1 - m * x1;
    
    // create a window
    initgraph(&gd, &gm, "Simple Line");

    if(m <= 1) {
        // when slope is less or equal to 1
        if(x1 < x2) {
            // when x1 lies to left of x2
            for(ctr = x1; ctr <= x2; ctr++) {
                x = ctr;
                y = m * x + c;
                putpixel((int)x, (int)y, 10);      
            }
        } else {
            // when x2 lies to left of x1
            for(ctr = x2; ctr <= x1; ctr++) {
                x = ctr;
                y = m * x + c;
                putpixel((int)x, (int)y, 10);
            }
        }
        // when slope is more than 1
        } else {
            if(y1 < y2) {
                // when y1 lies left of y2
                for(ctr = y1; ctr <= y2; ctr++) {
                    y = ctr;
                    x = (y - c)/m;
                    putpixel((int)x, (int)y, 10);      
                }   
            } else {
                // when y2 lies left on y1
                for(ctr = y2; ctr <= y1; ctr++) {
                    y = ctr;
                    x = (y - c)/m;
                    putpixel((int)x, (int)y, 10);      
                }   
            }
        }
    delay(10000);
    closegraph();
    return 0;
}
