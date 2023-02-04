// Author   : Pragyan Bhattarai
// Roll     : THA077BEI030
// TITLE    : Implementation of mid-point circle drawing algorithm


#include<iostream>
#include<graphics.h>

using namespace std;

int main(){
    initwindow(800,800);
    setbkcolor(WHITE);
    cleardevice();

    int radius, x0, y0, xc, yc, p;
    cout<<"Enter radius of circle r:";
    cin>>radius;
    cout<<"Enter center xc, yc:";
    cin>>xc>>yc;

    x0 = 0;
    y0 = radius;
    p = 1 - radius;

    do{
        if (p<0){

            x0 = x0 + 1;
            y0 = y0;
            p = p +2 *x0 +3;

        }
        else{

            x0 = x0 + 1;
            y0 = y0 - 1;
            p = p + 2*x0 - 2*y0 + 5;

        }

        putpixel(x0 + xc, y0 + yc, 1);
        putpixel(y0 + yc, x0 + xc, 2);
        
        putpixel(-y0 + yc, x0 + xc, 4);
        putpixel(-x0 + xc, -y0 + yc, 5);
        putpixel(-y0 + yc, -x0 + xc, 6);
        putpixel(y0 + yc, -x0 + xc, 7);
        putpixel(-x0 + xc, y0 + yc, 8);

    } while(x0<=y0);
    getch();
    closegraph();

}
