#include<iostream>
#include<graphics.h>

using namespace std;
int main(){
    initwindow(800,800);
    setbkcolor(WHITE);
    cleardevice();
    float x, y, i, steps, x1, x2, y1, y2, dx, dy;

    //read the values
    cout<<"Enter the values for x1, y1:";
    cin>>x1>>y1;
    cout<<"Enter the values for x2, y2:";
    cin>>x2>>y2;

    //calculations
    dx = x2 - x1;
    dy = y2 - y1;
    if (abs(dx)>=abs(dy)) steps = abs(dx);
    else steps = abs(dy);
    dx = dx/(float)steps;
    dy = dy/(float)steps;
    x = x1;
    y = y1;
    i = 1;

    //drawing the line
    while (i<=steps){
        putpixel(x, y, BLACK);
        x = x + dx;
        y = y + dy;
        i++;
        delay(200);
    }
    getch();
    closegraph();
}
