#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
#include <bits/stdc++.h>
#include "userdefined.h"


void midpointAlgo(double x1, double y_1, double x2, double y2) {
    int zone = selectZone(x1, y_1,x2,y2);
    setColor(zone);
    // Midpoint code here
    int x = (int) x1;
    int y = (int) y_1;
    int dx = (int) (x2-x1);
    int dy = (int) (y2 - y_1);
    glVertex2i(x,y);

    if(zone == 0) {
        int dint = 2*dy-dx;
        int de = 2*dy;
        int dne = 2*dy-2*dx;
        int d = dint;
        while(x != x2 && y != y2) {
            if(direction(d,zone)==AXIS) {
                x++;
                d+=de;
            }
            else {
                x++;
                y++;
                d+=dne;
            }
            glVertex2i(x,y);
        }
    }
    else if(zone == 1) {
        int dint = dy-2*dx;
        int dn = -2*dx;
        int dne = 2*dy-2*dx;
        int d = dint;
        while(x != x2 && y != y2) {
            if(direction(d,zone)==AXIS) {
                y++;
                d+=dn;
            }
            else {
                x++;
                y++;
                d+=dne;
            }
            glVertex2i(x,y);
        }
    }
    else if(zone == 2) {
        int dint = -1*dy-2*dx;
        int dn = -2*dx;
        int dnw = -2*dy-2*dx;
        int d = dint;
        while(x != x2 && y != y2) {
            if(direction(d,zone)==AXIS) {
                y++;
                d+=dn;
            }
            else {
                x--;
                y++;
                d+=dnw;
            }
            glVertex2i(x,y);
        }
    }
    else if(zone == 3) {
        int dint = -2*dy-dx;
        int dw = -2*dy;
        int dnw = -2*dy-2*dx;
        int d = dint;
        while(x != x2 && y != y2) {
            if(direction(d,zone)==AXIS) {
                x--;
                d+=dw;
            }
            else {
                x--;
                y++;
                d+=dnw;
            }
            glVertex2i(x,y);
        }
    }
    else if(zone == 4) {
        int dint = -2*dy+dx;
        int dw = -2*dy;
        int dsw = -2*dy+2*dx;
        int d = dint;
        while(x != x2 && y != y2) {
            if(direction(d,zone)==AXIS) {
                x--;
                d+=dw;
            }
            else {
                x--;
                y--;
                d+=dsw;
            }
            glVertex2i(x,y);
        }
    }
    else if(zone == 5) {
        int dint = -1*dy+2*dx;
        int ds = 2*dx;
        int dsw = -2*dy+2*dx;
        int d = dint;
        while(x != x2 && y != y2) {
            if(direction(d,zone)==AXIS) {
                y--;
                d+=ds;
            }
            else {
                x--;
                y--;
                d+=dsw;
            }
            glVertex2i(x,y);
        }
    }
    else if(zone == 6) {
        int dint = dy+2*dx;
        int ds = 2*dx;
        int dse = 2*dy+2*dx;
        int d = dint;
        while(x != x2 && y != y2) {
            if(direction(d,zone)==AXIS) {
                y--;
                d+=ds;
            }
            else {
                x++;
                y--;
                d+=dse;
            }
            glVertex2i(x,y);
        }
    }
    else if(zone == 7) {
        int dint = 2*dy+dx;
        int de = 2*dy;
        int dse = 2*dy+2*dx;
        int d = dint;
        while(x != x2 || y != y2) {
            if(direction(d,zone)==AXIS) {
                x++;
                d+=de;
            }
            else {
                x++;
                y--;
                d+=dse;
            }
            glVertex2i(x,y);
        }
    }
}

void midpoint() {
    double x1, x2, y_1, y2;
    glBegin(GL_POINTS);              
    printf("[Midpoint] Enter the points: ");
    scanf("%lf %lf %lf %lf",&x1, &y_1, &x2, &y2);
    midpointAlgo(x1, y_1, x2, y2);
    glEnd();
    glFlush();
    printf("[Midpoint] (back/continue/clear/exit): ");
    char prompt[10];
    scanf("%s", prompt);
    if(prompt[0]=='b') menu();
    else if(prompt[0]=='c') {
        if(prompt[1]=='l') clearWindow();
        midpoint();
    }
    else return;
}







