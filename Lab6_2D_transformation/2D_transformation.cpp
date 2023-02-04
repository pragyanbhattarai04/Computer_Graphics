// Title   : 2-D transformation
// Author  : Pragyan Bhattarai
// Roll    : THA077BEI030

#include<iostream>
#include<graphics.h>
#include<math.h>

using namespace std;

void rotate(){
    float x[4], y[4];
    float phi, a, b;
    int i;
    cout<<"Enter the diagonal coordinates (x1, y1) of a rectangle: ";
    cin>>x[0]>>y[0];
    cout<<"Enter another diagonal coordinates (x2, y2) of a rectangle: ";
    cin>>x[2]>>y[2];
    cout<<"Enter the angle of rotation: ";
    cin>>phi;
    phi = -3.14*phi/180;

    // Other diagonal co-ordinates
    x[1] = x[2];    y[1] = y[0];
    x[3] = x[0];    y[3] = y[2];

    initwindow(800,800);
    setbkcolor(WHITE);
    cleardevice();
    setcolor(BLACK);

    // Drawing the input rectangle
    for (i=0; i<4; i++){
        line(x[i], y[i], x[(i+1)%4], y[(i+1)%4]);
    }

    // Rotating each vertex co-ordinates of the rectangle
    for (i=0; i<4; i++){
        a = x[i];
        b = y[i];
        x[i] = a*cos(phi)-b*sin(phi);
        y[i] = a*sin(phi)+b*cos(phi);
    }

    // Rotated Rectangle
    for (i=0; i<4; i++){
        line(x[i], y[i], x[(i+1)%4], y[(i+1)%4]);
    }

    getch();
    closegraph();
}

void scale(){
    int x1, x2, y1, y2, nx1, ny1, nx2, ny2;
    int xk, yk;
    cout<<"Enter the diagonal coordinates (x1, y1) of a rectangle: ";
    cin>>x1>>y1;
    cout<<"Enter another diagonal coordinates (x2, y2) of a rectangle: ";
    cin>>x2>>y2;
    cout<<"Enter the scaling factor for x and y (xk and yk) : ";
    cin>>xk>>yk;

    initwindow(800,800);
    setbkcolor(WHITE);
    cleardevice();
    setcolor(BLACK);
    rectangle(x1, y1, x2, y2);

    // Scaled rectangle
    nx1 = x1*xk;
    ny1 = y1*yk;
    nx2 = x2*xk;
    ny2 = y2*yk;
    rectangle(nx1, ny1, nx2, ny2);

    getch();
    closegraph();
}

void translate(){
    int x1, x2, y1, y2, nx1, ny1, nx2, ny2;
    int xk, yk;
    cout<<"Enter the diagonal coordinates (x1, y1) of a rectangle: ";
    cin>>x1>>y1;
    cout<<"Enter another diagonal coordinates (x2, y2) of a rectangle: ";
    cin>>x2>>y2;
    cout<<"Enter the translating factor for x and y (dx and dy) : ";
    cin>>xk>>yk;

    initwindow(800,800);
    setbkcolor(WHITE);
    cleardevice();
    setcolor(BLACK);
    rectangle(x1, y1, x2, y2);

    // Translated rectangle
    nx1 = x1+xk;
    ny1 = y1+yk;
    nx2 = x2+xk;
    ny2 = y2+yk;
    rectangle(nx1, ny1, nx2, ny2);

    getch();
    closegraph();
}

int main(){
    int SN;
    cout<<"1. Translation"<<endl;
    cout<<"2. Scaling"<<endl;
    cout<<"3. Rotation"<<endl;
    cout<<"4. Exit"<<endl;

    do{
        cout<<"Enter the number: ";
        cin>>SN;

        switch (SN)
        {
        case 1:
            translate();
            break;
        case 2:
            scale();
            break;
        case 3:
            rotate();
            break;
        default:
            break;
        }
    } while(SN!=4);
}
