#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
#include <bits/stdc++.h>
#include "userdefined.h"

double dot_prod(double A[2], double B[2]) {
	return A[0]*B[0] + A[1]*B[1];
}

double max(double a, double b) {
	if(a>b) return a;
	return b;
}

double min(double a, double b) {
	if(a<b) return a;
	return b;
}

void drawborders(double xmin, double ymin, double xmax, double ymax) {
	ddaAlgo(xmin,ymin, xmax,ymin);
	ddaAlgo(xmin,ymin, xmin,ymax);
	ddaAlgo(xmax,ymax, xmax,ymin);
	ddaAlgo(xmax,ymax, xmin,ymax);
}

void cyrus_beck(double x1, double y_1, double x2, double y2, double xmin, double xmax, double ymin, double ymax) {
	glBegin(GL_POINTS);
	drawborders(xmin,ymin,xmax,ymax);
	double t[4];
	t[0] = -1.0*(y_1-ymax)/(y2-y_1);
	t[1] = -1.0*(y_1-ymin)/(y2-y_1);
	t[2] = -1.0*(x1-xmax)/(x2-x1);
	t[3] = -1.0*(x1-xmin)/(x2-x1);

	double N[4][2] = {{0.0,1.0},{0.0,-1.0},{1.0,0.0},{-1.0,0.0}};
	double d[2];
	d[0] = x2-x1;
	d[1] = y2-y_1;
	double te=0, tl=1;
	for(int i=0;i<4;i++) {
		if(dot_prod(d, N[i]) < 0) {
			te = max(te, t[i]);
		}
		else {
			tl = min(tl, t[i]);
		}
	}
	if(te>tl) {
		printf("Got rejected :(\n");
	}
	else {
		double newx0 = x1+(x2-x1)*te;
		double newx1 = x1+(x2-x1)*tl;
		double newy0 = y_1+(y2-y_1)*te; 
		double newy1 = y_1+(y2-y_1)*tl;
		printf("%lf %lf %lf %lf\n", newx0,newy0,newx1,newy1);	
		ddaAlgo(newx0,newy0,newx1,newy1);
	}

	glEnd();
	glFlush();
}


void cymenu() {
	printf("[Cyrus-Beck] Enter the points: ");
	double x0,y0,x1,y_1;
	scanf("%lf %lf %lf %lf", &x0, &y0, &x1, &y_1);
	cyrus_beck(x0,y0,x1,y_1,-320,-220,-80,80);
	cyrus_beck(x0,y0,x1,y_1,220,320,-80,80);
	printf("[Cyrus-Beck] (back/continue/clear/exit): ");
    char prompt[10];
    scanf("%s", prompt);
    if(prompt[0]=='b') menu();
    else if(prompt[0]=='c') {
        if(prompt[1]=='l') clearWindow();
        cymenu();
    }
    else return;
}