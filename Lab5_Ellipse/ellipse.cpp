// Title   : Implementation of Mid-point ellipse drawing algorithm
// Author  : Pragyan Bhattarai
// Roll    : THA077BEI030

#include<iostream>
#include<graphics.h>
#include<math.h>

using namespace std;

int main(){
    initwindow(800, 800);
    setbkcolor(WHITE);
    cleardevice();

    int Rx, Ry, xc, yc, x, y, p, q;
    cout<<"Enter x-radius of ellipse Rx: ";
    cin>>Rx;
    cout<<"Enter y-radius of ellipse Ry: ";
    cin>>Ry;
    cout<<"Enter center xc, yc: ";
    cin>>xc>>yc;

    // For Region 1
    x = 0;
    y = Ry;

    // Initial decision parameter for Region 1
    p = Ry*Ry - Rx*Rx*Ry + (Rx*Rx)/4;
    do
    {
        putpixel(xc + x, yc + y, 1);
        putpixel(xc + x, yc - y, 2);
        putpixel(xc - x, yc - y, 3);
        putpixel(xc - x, yc + y, 4);
        if (p<0){
            x = x + 1;
            p = p + 2*Ry*Ry*x + Ry*Ry;
        }
        else{
            x = x + 1;
            y = y - 1;
            p = p + 2*Ry*Ry*x - 2*Rx*Rx*y + Ry*Ry;
        }
    } while ((2*Ry*Ry*x)<=(2*Rx*Rx*y));

    // For Region 2
    // Initial decision parameter for Region 2
    q = Ry*Ry*pow((x+1/2),2) + Rx*Rx*pow((y-1),2) - pow((Rx*Ry),2);
    do
    {
        putpixel(xc + x, yc + y, 1);
        putpixel(xc + x, yc - y, 2);
        putpixel(xc - x, yc - y, 3);
        putpixel(xc - x, yc + y, 4);
        if (q>=0){
            y = y - 1;
            q = q + (3-2*y)*Rx*Rx;
        }
        else{
            x = x + 1;
            y = y - 1;
            q = q + 2*Ry*Ry*(x + 1) + Rx*Rx*(3 - 2*y);
        }
    } while (y!=0);
    getch();
    closegraph();
}
