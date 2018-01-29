#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
#include <bits/stdc++.h>
#include "userdefined.h"


using namespace std;

int calcbits(int x, int y, int l, int r, int b, int t) {
	int bitvalue=0;
	if(x < l) bitvalue+=8;
	if(x > r) bitvalue+=4;
	if(y < b) bitvalue+=2;
	if(y > t) bitvalue+=1;
	return bitvalue;
}

void clipMenu() {
	printf("[Line clipping] Enter the points: ");
	double x1, y_1,x2,y2;
	double l,r,b,t;
	scanf("%lf %lf %lf %lf", &x1, &y_1, &x2, &y2);
	printf("[Line clipping] Enter the top-left and bottom-right points of the boundary: ");
	scanf("%lf %lf %lf %lf", &l, &t, &r, &b);
	int bit_1 = calcbits((int) x1, (int) y_1, (int) l, (int) r, (int) b, (int) t);
	int bit_2 = calcbits((int) x2, (int) y2, (int) l, (int) r, (int) b, (int) t);
	if((bit_1 & bit_2) != 0) {
		printf("[Line clipping] The line is out of the boundary\n");
	}
	else {
		char choice[10];
		printf("[Line clipping] (dda/midpoint/8-way): ");
		scanf("%s", choice);
		int bit_or = bit_1 | bit_2;
		if(bit_or != 0) {
			printf("[Line clipping] The line is being clipped\n");
			// Left intersect
			if(x1 < l && x2 > l) x1=l;
			else if(x1 > l && x2 < l) x2=l;
			// Right intersect		
			if(x1 < r && x2 > r) x2=r;
			else if(x1 > r && x2 < r) x1=r;
			// Top intersect
			if(y_1 < t && y2 > t) y2=t;
			else if(y_1 > t && y2 < t) y_1=t;
			// Bottom intersect
			if(y_1 < b && y2 > b) y_1=b;
			else if(y_1 > b && y2 < b) y2=b;
		}
		glBegin(GL_POINTS);
		if(choice[0]=='d') ddaAlgo(x1,y_1,x2,y2);
		else if(choice[0]=='m') midpointAlgo(x1,y_1,x2,y2);
		else symmetricMidpoint(x1,y_1,x2,y2);
		// Boundary drawing
		symmetricMidpoint(l,t,r,t);
		symmetricMidpoint(l,t,l,b);
		symmetricMidpoint(l,b,r,b);
		symmetricMidpoint(r,b,r,t);
		glEnd();
		glFlush();
		
	}
	printf("[Line clipping] (back/continue/clear/exit): ");
    char prompt[10];
    scanf("%s", prompt);
    if(prompt[0]=='b') menu();
    else if(prompt[0]=='c') {
        if(prompt[1]=='l') clearWindow();
        clipMenu();
    }
    else return;
}