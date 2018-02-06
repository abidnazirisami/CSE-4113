#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
#include <bits/stdc++.h>
#include "userdefined.h"

void drawPoint(int x, int y, int zone) {
	
	if(zone==1 || zone==2 || zone==5 || zone==6) {
		int tmp = x;
		x = y;
		y = tmp;
		if(zone>3 && zone<8) {
			y = (-1)*y;
		}
		if(zone>1 && zone <6) {
			x = (-1)*x;
		}
	}
	else {
		if(zone>3 && zone<8) {
			y = (-1)*y;
		}
		if(zone>1 && zone <6) {
			x = (-1)*x;
		}
	}
	glVertex2i(x,y);
	//printf("Converted back: %d %d\n", x,y);
}



void symmetricMidpoint(double x1, double y_1, double x2, double y2) {
	if(x1==x2 && y_1==y2) {
		glVertex2i(x1, y_1);
		return;
	}
	int zone = selectZone(x1,y_1,x2,y2);
	setColor(zone);
	int converted_x = (int) x1;
	int converted_y = (int) y_1;
	int converted_x2 = (int) x2;
	int converted_y2 = (int) y2;
	if(zone==1 || zone==2 || zone==5 || zone==6) {
		converted_x=(int)y_1;
		converted_y=(int)x1;
		converted_x2=(int)y2;
		converted_y2=(int)x2;
		if(zone>3 && zone<8) {
			converted_x = (-1) * converted_x;
			converted_x2 = (-1) * converted_x2;
		}
		if(zone>1 && zone<6) {
			converted_y = (-1) * converted_y;
			converted_y2 = (-1) * converted_y2;
		}
	}
	else {
		if(zone>1 && zone<6) {
			converted_x = (-1) * converted_x;
			converted_x2 = (-1) * converted_x2;
		}
		if(zone>3 && zone<8) {
			converted_y = (-1) * converted_y;
			converted_y2 = (-1) * converted_y2;
		}
	}

	

	//printf("Converted: %d %d %d %d\n", converted_x,converted_y,converted_x2,converted_y2);
	int dx = converted_x2-converted_x;
	int dy = converted_y2-converted_y;
	int dint = 2*dy-dx;
    int de = 2*dy;
    int dne = 2*dy-2*dx;
    int d = dint;
        

	do {
		drawPoint(converted_x,converted_y,zone);
		{
            if(direction(d,0)==AXIS) {
                converted_x++;
                d+=de;
            }
            else {
                converted_x++;
                converted_y++;
                d+=dne;
            }
        }
	} while(converted_x != converted_x2 && converted_y != converted_y2);
	drawPoint(converted_x2,converted_y2,zone);
}

void symMenu() {
	printf("[8-Way Symmetry] Enter the points: ");
	double x1, y_1,x2,y2;
	scanf("%lf %lf %lf %lf", &x1, &y_1, &x2, &y2);
	glBegin(GL_POINTS);
	symmetricMidpoint(x1,y_1,x2,y2);
	glEnd();
	glFlush();
	printf("[8-Way Symmetry] (back/continue/clear/exit): ");
    char prompt[10];
    scanf("%s", prompt);
    if(prompt[0]=='b') menu();
    else if(prompt[0]=='c') {
        if(prompt[1]=='l') clearWindow();
        symMenu();
    }
    else return;
}