#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
#include <bits/stdc++.h>
#include "userdefined.h"

void drawBoxes() {
	// For z0
	double x1, y_1,x2,y2;
	for(x1=-210,y_1=50,x2=-210,y2=49;x1>=-310,y2<=150;x1--,y2++) {
		glBegin(GL_POINTS);
		midpointAlgo(x1,y_1,x2,y2);
		glEnd();
    	glFlush();
	}
	for(x1=-310,y_1=50,x2=-209,y2=150;x2>=-310,y_1<=150;x2--,y_1++) {
		glBegin(GL_POINTS);
		midpointAlgo(x1,y_1,x2,y2);
		glEnd();
    	glFlush();
	}
	// For z1
	for(x1=-10,y_1=50,x2=-10,y2=51;x1>=-110,y2<=150;x1--,y2++) {
		glBegin(GL_POINTS);
		midpointAlgo(x1,y_1,x2,y2);
		glEnd();
    	glFlush();
	}
	for(x1=-110,y_1=50,x2=-11,y2=150;x2>=-110,y_1<=150;x2--,y_1++) {
		glBegin(GL_POINTS);
		midpointAlgo(x1,y_1,x2,y2);
		glEnd();
    	glFlush();
	}
	// For z2
	for(x1=-210,y_1=-50,x2=-210,y2=-49;x1<=-110,y2<=50;x1++,y2++) {
		glBegin(GL_POINTS);
		midpointAlgo(x1,y_1,x2,y2);
		glEnd();
    	glFlush();
	}
	for(x1=-110,y_1=-50,x2=-209,y2=50;x2<=-110,y_1<=50;x2++,y_1++) {
		glBegin(GL_POINTS);
		midpointAlgo(x1,y_1,x2,y2);
		glEnd();
    	glFlush();
	}
	// For z3
	for(x1=-210,y_1=-150,x2=-310,y2=-51;x1>=-310,y2>=-150;x1--,y2--) {
		glBegin(GL_POINTS);
		midpointAlgo(x1,y_1,x2,y2);
		glEnd();
    	glFlush();
	}
	for(x1=-210,y_1=-150,x2=-310,y2=-51;x2<=-210,y_1<=-50;x2++,y_1++) {
		glBegin(GL_POINTS);
		midpointAlgo(x1,y_1,x2,y2);
		glEnd();
    	glFlush();
	}
	// For z4
	for(x1=-10,y_1=-150,x2=-11,y2=-150;x2>=-110,y_1<=-50;x2--,y_1++) {
		glBegin(GL_POINTS);
		midpointAlgo(x1,y_1,x2,y2);
		glEnd();
    	glFlush();
	}
	for(x1=-109,y_1=-50,x2=-110,y2=-50;x1<=-10,y2>=-150;x1++,y2--) {
		glBegin(GL_POINTS);
		midpointAlgo(x1,y_1,x2,y2);
		glEnd();
    	glFlush();
	}
	// For z5
	for(x1=210,y_1=51,x2=210,y2=50;x2>=110,y_1<=150;x2--,y_1++) {
		glBegin(GL_POINTS);
		midpointAlgo(x1,y_1,x2,y2);
		glEnd();
    	glFlush();
	}
	for(x1=110,y_1=150,x2=110,y2=149;x1<=210,y2>=50;x1++,y2--) {
		glBegin(GL_POINTS);
		midpointAlgo(x1,y_1,x2,y2);
		glEnd();
    	glFlush();
	}
	// For z6
	for(x1=10,y_1=-49,x2=10,y2=-50;x2<=110,y_1<=50;x2++,y_1++) {
		glBegin(GL_POINTS);
		midpointAlgo(x1,y_1,x2,y2);
		glEnd();
    	glFlush();
	}
	for(x1=110,y_1=50,x2=110,y2=49;x1>=10,y2>=-50;x1--,y2--) {
		glBegin(GL_POINTS);
		midpointAlgo(x1,y_1,x2,y2);
		glEnd();
    	glFlush();
	}
	// For z7
	for(x1=210,y_1=-50,x2=211,y2=-50;x2<=310,y_1<=50;x2++,y_1++) {
		glBegin(GL_POINTS);
		midpointAlgo(x1,y_1,x2,y2);
		glEnd();
    	glFlush();
	}
	for(x1=309,y_1=50,x2=310,y2=50;x1>=210,y2>=-50;x1--,y2--) {
		glBegin(GL_POINTS);
		midpointAlgo(x1,y_1,x2,y2);
		glEnd();
    	glFlush();
	}
	while(true) {
		printf("Enter the zone number: ");
		int z;
		scanf("%d", &z);
		drawSymBox(z);	
	}
	
	glutMainLoop();
}

void drawSymBox(int zone) {
	int dlx, dly, drx, dry, ulx, uly,urx, ury;
	dlx = 110;
	dly = -150;
	ulx = 110;
	uly = -50;
	drx = 210;
	dry = -150;
	urx = 210;
	ury = -50;
	double x1,y_1,x2,y2;

	if(zone==0) {
		for(x1=dlx,y_1=dly,x2=urx,y2=ury-1;x1<=drx,y2>=dry;x1++,y2--) {
			glBegin(GL_POINTS);
			symmetricMidpoint(x1,y_1,x2,y2);
			glEnd();
    		glFlush();		
		}
		for(x1=dlx,y_1=dly+1,x2=urx,y2=ury;y_1<=uly,x2>=ulx;y_1++,x2--) {
			glBegin(GL_POINTS);
			symmetricMidpoint(x1,y_1,x2,y2);
			glEnd();
    		glFlush();	
		}
	}
	else if(zone==1) {
		for(x1=dlx,y_1=dly,x2=urx,y2=ury+1;x1<=drx,y2>=dry;x1++,y2--) {
			glBegin(GL_POINTS);
			symmetricMidpoint(x1,y_1,x2,y2);
			glEnd();
    		glFlush();		
		}
		for(x1=dlx,y_1=dly-1,x2=urx,y2=ury;y_1<=uly,x2>=ulx;y_1++,x2--) {
			glBegin(GL_POINTS);
			symmetricMidpoint(x1,y_1,x2,y2);
			glEnd();
    		glFlush();	
		}
	}
	else if(zone==2) {
		for(x1=drx-1,y_1=dry,x2=ulx,y2=uly;x1>=dlx,y2>=dly;x1--,y2--) {
			glBegin(GL_POINTS);
			symmetricMidpoint(x1,y_1,x2,y2);
			glEnd();
    		glFlush();		
		}
		for(x1=drx,y_1=dry,x2=ulx+1,y2=uly;y_1<=ury,x2<=urx;y_1++,x2++) {
			glBegin(GL_POINTS);
			symmetricMidpoint(x1,y_1,x2,y2);
			glEnd();
    		glFlush();	
		}
	}
	else if(zone==3) {
		for(x1=drx+1,y_1=dry,x2=ulx,y2=uly;x1>=dlx,y2>=dly;x1--,y2--) {
			glBegin(GL_POINTS);
			symmetricMidpoint(x1,y_1,x2,y2);
			glEnd();
    		glFlush();		
		}
		for(x1=drx+1,y_1=dry,x2=ulx+1,y2=uly;y_1<=ury,x2<=urx;y_1++,x2++) {
			glBegin(GL_POINTS);
			symmetricMidpoint(x1,y_1,x2,y2);
			glEnd();
    		glFlush();	
		}
	}
	else if(zone==4) {
		for(x1=urx,y_1=ury,x2=dlx,y2=dly+1;x1>=ulx,y2<=uly;x1--,y2++) {
			glBegin(GL_POINTS);
			symmetricMidpoint(x1,y_1,x2,y2);
			glEnd();
    		glFlush();		
		}
		for(x1=drx,y_1=dry,x2=drx-1,y2=dry;y_1<=ury,x2>=dlx;y_1++,x2--) {
			glBegin(GL_POINTS);
			symmetricMidpoint(x1,y_1,x2,y2);
			glEnd();
    		glFlush();	
		}
	}
	else if(zone==5) {
		for(x1=urx,y_1=ury,x2=dlx+1,y2=dly;x1>=ulx,y2<=uly;x1--,y2++) {
			glBegin(GL_POINTS);
			symmetricMidpoint(x1,y_1,x2,y2);
			glEnd();
    		glFlush();		
		}
		for(x1=drx,y_1=dry,x2=drx,y2=dry-1;y_1<=ury,x2>=dlx;y_1++,x2--) {
			glBegin(GL_POINTS);
			symmetricMidpoint(x1,y_1,x2,y2);
			glEnd();
    		glFlush();	
		}
	}
	else if(zone==6) {
		for(x1=ulx,y_1=uly,x2=drx-1,y2=dry;x2>=dlx,y_1>=dly;x2--,y_1--) {
			glBegin(GL_POINTS);
			symmetricMidpoint(x1,y_1,x2,y2);
			glEnd();
    		glFlush();		
		}
		for(x1=ulx,y_1=uly,x2=drx-1,y2=dry;y2<=ury,x1<=urx;y2++,x1++) {
			glBegin(GL_POINTS);
			symmetricMidpoint(x1,y_1,x2,y2);
			glEnd();
    		glFlush();	
		}
	}
	else if(zone==7) {
		for(x1=ulx,y_1=uly,x2=drx,y2=dry+1;x2>=dlx,y_1>=dly;x2--,y_1--) {
			glBegin(GL_POINTS);
			symmetricMidpoint(x1,y_1,x2,y2);
			glEnd();
    		glFlush();		
		}
		for(x1=ulx,y_1=uly,x2=drx,y2=dry+1;y2<=ury,x1<=urx;y2++,x1++) {
			glBegin(GL_POINTS);
			symmetricMidpoint(x1,y_1,x2,y2);
			glEnd();
    		glFlush();	
		}
	}
}