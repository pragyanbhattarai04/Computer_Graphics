#include<iostream>
#include<graphics.h>

using namespace std;

int main(){
    initwindow(800,800);
    //setting the background color as white
    setbkcolor(WHITE);
    cleardevice();
    //setting the color as black
    setcolor(BLACK);
    putpixel(100,100,BLACK);
    //to create a rectangle
    rectangle(200,200,400,400);
    //drawing diagonal lines
    line(200,400,400,200);
    line(200,200,400,400);
    //drawing an ellipse
    ellipse(300,300,0,360,200,120);
    //drawing a circle
    circle(300,300,100);
    closegraph(getch());
}
