#include<iostream>
#include<graphics.h>

using namespace std;

int main(){
    initwindow(800,800);
    setbkcolor(WHITE);
    cleardevice();

    int  x0, y0, x1, y1, dx, dy;
    int xinc, yinc, p, k;

    cout<<"Enter x0, y0:";
    cin>>x0>>y0;
    cout<<"Enter x1, y1:";
    cin>>x1>>y1;
    
    dx = x1 - x0;
    dy = y1 - y0;
    dx = abs(dx);
    dy = abs(dy);

    if (x1 > x0){
        xinc = 1;
    }
    else{
        xinc = -1;
    }

    if (y1 > y0){
        yinc = 1;
    }
    else{
        yinc = -1;
    }

    putpixel(x0,y0,BLACK);
    
    if(dx > dy){
        p=2*dy-dx;
        for (k=0;k<=dx;k++){
            if (p<0){
                x0 = x0 + xinc;
                y0 = y0;
                p = p + 2*dy;
            }
            else{
                x0 = x0 + xinc;
                y0 = y0 + yinc;
                p = p + 2*dy - 2*dx;
            }
            putpixel(x0, y0, BLACK);
            delay(200);
        }
    }
    else{
         p=2*dx-dy;
        for (k=0;k<=dy;k++){
            if (p<0){
                x0 = x0;
                y0 = y0 + yinc;
                p = p + 2*dx;
            }
            else{
                x0 = x0 + xinc;
                y0 = y0 + yinc;
                p = p - 2*dy + 2*dx;
            }
            putpixel(x0, y0, BLACK);
            delay(200);
        }
    }
    getch();
    closegraph();
    return 0;
}
