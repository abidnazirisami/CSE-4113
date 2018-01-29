#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
#include <bits/stdc++.h>
#include "userdefined.h"

void randomDisplay() {
    printf("[Random] (dda/midpoint/8-way): ");
    char prompt[10];
    scanf("%s", prompt);
    double x1, x2, y_1, y2;
    glBegin(GL_POINTS);
    for(int i=0; i<1000;i++) {
            x1 = 0.0;
            y_1 = 0.0;
            double mul1, mul2;
            if(i%4==0) {
                mul1 = 1.0;
                mul2 = 1.0;
            }
            else if(i%4==1) {
                mul1 = -1.0;
                mul2 = 1.0;
            }
            else if(i%4==2) {
                mul1 = 1.0;
                mul2 = -1.0;
            }
            else if(i%4==3) {
                mul1 = -1.0;
                mul2 = -1.0;
            }
            x2 = mul1*(rand()%max_point);
            y2 = mul2*(rand()%max_point);
            if(prompt[0]=='d') ddaAlgo(x1, y_1, x2, y2);
            else if(prompt[0]=='8') symmetricMidpoint(x1,y_1,x2,y2);
            else midpointAlgo(x1,y_1,x2,y2);
    }
    glEnd();
    glFlush();
    menu();
}

void randomDisplay2() {
    printf("[Random] (dda/midpoint/8-way): ");
    char prompt[10];
    scanf("%s", prompt);
    double x1, x2, y_1, y2;
    glBegin(GL_POINTS);
    for(int i=0; i<1000;i++) {
        double mul1, mul2;
            
	    x1 = ((int)rand())%(max_point*2)-max_point;
        y_1 = ((int)rand())%(max_point*2)-max_point;
        	
        x2 = ((int)rand())%(max_point*2)-max_point;
        y2 = ((int)rand())%(max_point*2)-max_point;
        if(prompt[0]=='d') ddaAlgo(x1, y_1, x2, y2);
        else if(prompt[0]=='8') symmetricMidpoint(x1,y_1,x2,y2);
        else midpointAlgo(x1,y_1,x2,y2);
    }
    glEnd();
    glFlush();
    menu();
}


void randomLines() {
    printf("[Random] \n\t1 for origin centric\n\t2 for totally random points\n\t3 to go back\n");
    int m;
    scanf("%d", &m);
    if(m==1) {
        srand(time(NULL));
        randomDisplay();
    }
    else if(m==2){
        srand(time(NULL));
        randomDisplay2();
    }
    else menu();
}
