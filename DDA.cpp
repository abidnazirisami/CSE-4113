#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
#include <bits/stdc++.h>
#include "userdefined.h"

void ddaAlgo(double x1, double y_1, double x2, double y2) {
    int zone = selectZone(x1, y_1,x2,y2);
    //setColor(zone); 
    if(zone == 0 || zone == 3 || zone == 4 || zone == 7) {
        double y= y_1;
        for(double x = x1; ; ) {
            glVertex2i(roundUp(x), roundUp(y));
            //printf("%lf, %lf, %d\n", x, y, zone);
            double m = (y2-y_1)/((x2-x1)*1.0);
            //printf("%lf\n",m);

            if(zone == 3 || zone == 4) {
                y -=  m;
                x--;
                if( x<=  x2) break;
            }
            else {
                x++;
                y +=  m;
                if( x>=  x2) break;
            }
        }

    }
    else {
        double x =x1;
        for(double y=(int)y_1;;) {
            glVertex2i(roundUp(x), roundUp(y));
            //printf("%lf, %lf\n", x, y);
            double m = (x2-x1)/((y2-y_1)*1.0);

            if(zone == 5 || zone == 6) {
                y--;
                x -=  m;
                if(y<=y2) break;
            }
            else {
                y++;
                x +=  m;
                if(y>=y2) break;
            }
        }
    }
      
}

void dda() {
    double x1, x2, y_1, y2;
    int zone;  
	glBegin(GL_POINTS);
	printf("[DDA] Enter the points: ");
	scanf("%lf %lf %lf %lf",&x1, &y_1, &x2, &y2);
	ddaAlgo(x1, y_1, x2, y2);
	glEnd();
    glFlush();
    printf("[DDA] (back/continue/clear/exit): ");
    char prompt[10];
    scanf("%s", prompt);
    if(prompt[0]=='b') menu();
    else if(prompt[0]=='c') {
        if(prompt[1]=='l') clearWindow();
        dda();
    }
    else return;
}
