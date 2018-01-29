#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
#include <bits/stdc++.h>
#include "userdefined.h"

void clearWindow() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    glEnd();
    glFlush();
}
void initialize(int argc, char** argv) {
    glutInit(&argc, argv);     // Initialize GLUT    
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB );
    glutInitWindowSize(2*max_point,max_point);   // Set the window's initial width & height
    glutInitWindowPosition(550, 50); // Position the window's initial top-left corner
    glutCreateWindow("Line drawing"); // Create a window with the given title
    glMatrixMode( GL_PROJECTION );
    glShadeModel(GL_FLAT);
    glLoadIdentity();
    gluOrtho2D(-1.0*max_point, 1.0*max_point, -0.5*max_point, 0.5*max_point);

}

int roundUp(double in) {
	double temp = in + 0.5;
	int out = (int) temp;
	return out;
}

int selectZone(double x1,double y_1,double x2,double y2) {
    double dx = x2-x1;
    double dy = y2-y_1;
    if(dx >= 0 && dy >= 0) {
        if(abs((int)dx)>=abs((int)dy)) return 0;
        else return 1;
    }
    else if(dx >= 0 && dy <0) {
        if(abs((int)dx)>=abs((int)dy)) return 7;
        else return 6;
    }
    else if(dx < 0 && dy >= 0) {
        if(abs((int)dx) >= abs((int)dy)) return 3;
        else return 2;
    }
    else {
        if(abs((int)dx) >= abs((int)dy)) return 4;
        else return 5;
    }
}
void setColor(int zone) {
    if(zone == 0) glColor3f(1.0f,0.0f,0.0f); //Red
    else if(zone == 1) glColor3f(0.0f,1.0f,0.0f); // Green
    else if(zone == 2) glColor3f(0.0f,0.0f,1.0f); // Blue
    else if(zone == 3) glColor3f(1.0f,1.0f,0.0f); // Yellow
    else if(zone == 4) glColor3f(1.0f,0.0f,1.0f); // Violet
    else if(zone == 5) glColor3f(0.0f,0.5f,0.5f); // Cyan
    else if(zone == 6) glColor3f(1.0f,0.5f,0.0f); // Orange
    else if(zone == 7) glColor3f(1.0f,1.0f,1.0f); // White
   
}


int direction(int d, int zone) {
    if(d < 0) return zone%2;
    else return (zone+1)%2;
}

void menu() {
    int selector;
    printf("Enter \n\t1 for dda\n\t2 for midpoint\n\t3 for random lines\n\t4 for 8-way symmetry\n\t5 to clear the window\n\t6 to use drawboxes\n\t7 to exit\n");
    scanf("%d", &selector);
    if(selector==1) {
        dda();
    }
    else if(selector==2) {
        midpoint();
    }
    else if(selector==3) {
        randomLines();
    }
    else if(selector==4) {
        symMenu();
    }
    else if(selector==5) {
        clearWindow();
        menu();
    }
    else if(selector==6) {
        drawBoxes();
    }
    else return;
    
}