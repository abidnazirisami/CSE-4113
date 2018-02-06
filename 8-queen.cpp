#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
#include <bits/stdc++.h>
#include "userdefined.h"
//#define deb printf("Here %d\n", it++);
#define deb printf("Here %d %d, Queen %d\n", newqueen[i][0], newqueen[i][1], i);
#define bias 40.0
using namespace std;
int it=0;
struct moves {
	int queenNo;
	int oldposx;
	int oldposy;
	int newposx;
	int newposy;
	moves(){}
	moves(int _qN, int _opx,  int _opy, int _npx, int _npy) {
		queenNo=_qN;
		oldposx=_opx;
		oldposy=_opy;
		newposx=_npx;
		newposy=_npy;
	}
	
};


struct queens {
	queue <moves> st;
	int qarray[8][2];
	int sum;
	queens(){}
	queens(int _q[8][2], int _s, queue <moves> _sta) {
		sum=_s;
		for(int i=0;i<8;i++) {
			qarray[i][0]=_q[i][0];
			qarray[i][1]=_q[i][1];
		}
		st = _sta;
	}

	bool operator <(const queens &a)const {
		return sum < a.sum;
	}
 	bool operator >(const queens &a)const {
		return sum > a.sum;
	}
};

priority_queue<queens, vector<queens>, greater<queens> > pq;

vector <int> v;

bool safe(int queen[8][2], int qx, int qy) {
	for(int i=0;i<8;i++) {
		if(queen[i][0]==qx && queen[i][1]== qy) return false;
	}
	return true;
}

int genMask(int queen[8][2]) {
	int gene = 0;
	for(int i=0;i<8;i++) {
		gene += pow(queen[i][0], i);
		gene += pow(queen[i][1], i);
	}
	return gene;
}

bool repCheck(int g) {
	for(int i=0;i<v.size();i++) {
		if(g==v[i]) return false;
	}
	return true;
}

void printpath(queens qu) {
	while(!qu.st.empty()) {
		moves m = qu.st.front();
		printf("Queen %d moves from %d %d to %d %d\n", m.queenNo, m.oldposx,m.oldposy,m.newposx,m.newposy);
		qu.st.pop();
		glBegin(GL_POINTS);
	
		setColor(m.queenNo);
		ddaAlgo(m.oldposx*bias, m.oldposy*bias,m.newposx*bias, m.newposy*bias);
		for(double dk=bias/10.0;dk>=0.0;dk--) {
			
			double minx=m.newposx*bias-dk;
			double miny=m.newposy*bias-dk;
			double maxx=m.newposx*bias+dk;
			double maxy=m.newposy*bias+dk;
			ddaAlgo(minx,miny,minx,maxy);
			ddaAlgo(minx,miny,maxx,miny);
			ddaAlgo(maxx,maxy,minx,maxy);
			ddaAlgo(maxx,maxy,maxx,miny);
			
		}
		glEnd();
		glFlush();
		printf("Continue? (y/n): ");
		char inpu;
		scanf("%c", &inpu);
		getchar();
		if(inpu=='n') break;
		else if(inpu=='y') continue;
	}
	printf("Exit? (y/n): ");
	char inp;
	scanf("%c", &inp);
	getchar();
	if(inp=='y') return;
	else printpath(qu);
}
int cnt=-1;
void printgrid(const int queen[8][2]) {
	int grid[8][8];
	cnt++;
	for(int i=0;i<8;i++) {
	
		for(int j=0;j<8;j++) {
			if(grid[i][j]!=1) grid[i][j]=0;

		}
		grid[queen[i][0]][queen[i][1]]=1;
	}
	for(int i=0;i<8;i++) {
		for(int j=0;j<8;j++) {
			printf("%d ", grid[i][j]);
			glBegin(GL_POINTS);
				setColor(7);
				double minx=i*bias-bias/2.0;
				double miny=j*bias-bias/2.0;
				double maxx=i*bias+bias/2.0;
				double maxy=j*bias+bias/2.0;
				ddaAlgo(minx,miny,minx,maxy);
				ddaAlgo(minx,miny,maxx,miny);
				ddaAlgo(maxx,maxy,minx,maxy);
				ddaAlgo(maxx,maxy,maxx,miny);
				glFlush();
				glEnd();
			if(grid[i][j]==1) {
				for(double dk=bias/2.0;dk>=0.0;dk--) {
					glBegin(GL_POINTS);
					setColor(cnt);
					double minx=i*bias-dk;
					double miny=j*bias-dk;
					double maxx=i*bias+dk;
					double maxy=j*bias+dk;
					ddaAlgo(minx,miny,minx,maxy);
					ddaAlgo(minx,miny,maxx,miny);
					ddaAlgo(maxx,maxy,minx,maxy);
					ddaAlgo(maxx,maxy,maxx,miny);
					glFlush();
					glEnd();
				}
				
			}
		}
		printf("\n");
	}
	/*for(int i=0;i<8;i++) {
		int qx = queen[i][0];
		int qy = queen[i][1];
		// Horizontal and vertical
		for(int j=0;j<8;j++) {
			grid[qx][j]++;
			grid[j][qy]++;
		}
		grid[qx][qy]--;
		grid[qx][qy]--;
		// Diagonal

		for(int j=qx+1,k=qy+1;j<8 && k<8;j++, k++) {
			grid[j][k]++;
		}
		for(int j=qx-1,k=qy+1;j>=0 && k<8;j--, k++) {
			grid[j][k]++;
		}
		for(int j=qx-1,k=qy-1;j>=0 && k>=0;j--, k--) {
			grid[j][k]++;
		}
		for(int j=qx+1,k=qy-1;j<8 && k>=0;j++, k--) {
			grid[j][k]++;
		}
	}
	for(int i=0;i<8;i++) {
		for(int j=0;j<8;j++) {
			printf("%d ", grid[i][j]);
		}
		printf("\n");
	}*/
}

int calc_sum(int queen[8][2]) {
	int grid[8][8];
	for(int i=0;i<8;i++) {
		for(int j=0;j<8;j++) {
			grid[i][j]=0;
		}
	}
	for(int i=0;i<8;i++) {
		int qx = queen[i][0];
		int qy = queen[i][1];
		// Horizontal and vertical
		for(int j=0;j<8;j++) {
			grid[qx][j]++;
			grid[j][qy]++;
		}
		grid[qx][qy]--;
		// Diagonal

		for(int j=qx+1,k=qy+1;j<8 && k<8;j++, k++) {
			grid[j][k]++;
		}
		for(int j=qx-1,k=qy+1;j>=0 && k<8;j--, k++) {
			grid[j][k]++;
		}
		for(int j=qx-1,k=qy-1;j>=0 && k>=0;j--, k--) {
			grid[j][k]++;
		}
		for(int j=qx+1,k=qy-1;j<8 && k>=0;j++, k--) {
			grid[j][k]++;
		}
	}
	// Calculating sum
	int sum=0;
	for(int i=0;i<8;i++) {
		sum+=grid[queen[i][0]][queen[i][1]];
	}
	return sum;
}

void solve() {
	int newqueen[8][2];
	queens cur = pq.top();
	if(cur.sum==8) {
		printf("Solution: \n");
		printgrid(cur.qarray);
		printpath(cur);
		return;
	}
	for(int i=0;i<8;i++) {
		newqueen[i][0] = cur.qarray[i][0];
		newqueen[i][1] = cur.qarray[i][1];
	}
	//printf("%s\n", "Make a move");
	//printgrid(pq.top().qarray);

	pq.pop();
	for(int i=0;i<8;i++) {
		int qx = newqueen[i][0];
		int qy = newqueen[i][1];
		if(newqueen[i][0]+1 < 8 && safe(newqueen, newqueen[i][0]+1, newqueen[i][1])) {
			newqueen[i][0]++;
			int gentemp = genMask(newqueen);
			if(repCheck(gentemp)) {
				int tmpsum = calc_sum(newqueen);
				queue <moves> tmpqueue = cur.st;
				tmpqueue.push(moves(i, newqueen[i][0]-1,newqueen[i][1],newqueen[i][0],newqueen[i][1]));
				pq.push(queens(newqueen, tmpsum, tmpqueue));
				v.push_back(gentemp);

			}
			newqueen[i][0]--;
		}
		//deb
		if(newqueen[i][1]+1 < 8 && safe(newqueen, newqueen[i][0], newqueen[i][1]+1)) {
			newqueen[i][1]++;
			int gentemp = genMask(newqueen);
			if(repCheck(gentemp)) {
				int tmpsum = calc_sum(newqueen);
				queue <moves> tmpqueue = cur.st;
				tmpqueue.push(moves(i, newqueen[i][0],newqueen[i][1]-1,newqueen[i][0],newqueen[i][1]));
				pq.push(queens(newqueen, tmpsum, tmpqueue));
				v.push_back(gentemp);
			}
			newqueen[i][1]--;
		}
		//deb
		if(newqueen[i][0]-1 >= 0 && safe(newqueen, newqueen[i][0]-1, newqueen[i][1])) {
			newqueen[i][0]--;
			int gentemp = genMask(newqueen);
			if(repCheck(gentemp)) {
				int tmpsum = calc_sum(newqueen);
				queue <moves> tmpqueue = cur.st;
				tmpqueue.push(moves(i, newqueen[i][0]+1,newqueen[i][1],newqueen[i][0],newqueen[i][1]));
				pq.push(queens(newqueen, tmpsum, tmpqueue));
				v.push_back(gentemp);
			}
			newqueen[i][0]++;
		}
		//deb
		if(newqueen[i][1]-1 >= 0 && safe(newqueen, newqueen[i][0], newqueen[i][1]-1)) {
			newqueen[i][1]--;
			int gentemp = genMask(newqueen);
			if(repCheck(gentemp)) {
				int tmpsum = calc_sum(newqueen);
				queue <moves> tmpqueue = cur.st;
				tmpqueue.push(moves(i, newqueen[i][0],newqueen[i][1]+1,newqueen[i][0],newqueen[i][1]));
				pq.push(queens(newqueen, tmpsum, tmpqueue));
				v.push_back(gentemp);
			}
			newqueen[i][1]++;
		}
		//deb
		if(newqueen[i][0]+1 < 8 && newqueen[i][1]+1 < 8 && safe(newqueen, newqueen[i][0]+1, newqueen[i][1]+1)) {
			newqueen[i][0]++;
			newqueen[i][1]++;
			int gentemp = genMask(newqueen);
			if(repCheck(gentemp)) {
				int tmpsum = calc_sum(newqueen);
				queue <moves> tmpqueue = cur.st;
				tmpqueue.push(moves(i, newqueen[i][0]-1,newqueen[i][1]-1,newqueen[i][0],newqueen[i][1]));
				pq.push(queens(newqueen, tmpsum, tmpqueue));
				v.push_back(gentemp);
			}
			newqueen[i][0]--;
			newqueen[i][1]--;
		}
		//deb
		if(newqueen[i][0]-1 >= 0 && newqueen[i][1]+1 < 8 && safe(newqueen, newqueen[i][0]-1, newqueen[i][1]+1)) {
			newqueen[i][0]--;
			newqueen[i][1]++;
			int gentemp = genMask(newqueen);
			if(repCheck(gentemp)) {
				int tmpsum = calc_sum(newqueen);
				queue <moves> tmpqueue = cur.st;
				tmpqueue.push(moves(i, newqueen[i][0]+1,newqueen[i][1]-1,newqueen[i][0],newqueen[i][1]));
				pq.push(queens(newqueen, tmpsum, tmpqueue));
				v.push_back(gentemp);
//							printf("%d %d %d %d\n", newqueen[i][0]+1,newqueen[i][1]-1,newqueen[i][0],newqueen[i][1]);

			}
			newqueen[i][0]++;
			newqueen[i][1]--;
		}
		//deb
		if(newqueen[i][0]+1 < 8 && newqueen[i][1]-1 >= 0 && safe(newqueen, newqueen[i][0]+1, newqueen[i][1]-1)) {
			newqueen[i][0]++;
			newqueen[i][1]--;
			int gentemp = genMask(newqueen);
			if(repCheck(gentemp)) {
				int tmpsum = calc_sum(newqueen);
				queue <moves> tmpqueue = cur.st;
				tmpqueue.push(moves(i, newqueen[i][0]-1,newqueen[i][1]+1,newqueen[i][0],newqueen[i][1]));
				pq.push(queens(newqueen, tmpsum, tmpqueue));
				v.push_back(gentemp);
			}
			newqueen[i][0]--;
			newqueen[i][1]++;
		}
		//deb
		if(newqueen[i][0]-1 >= 0 && newqueen[i][1]-1 >= 0 && safe(newqueen, newqueen[i][0]-1, newqueen[i][1]-1)) {
			newqueen[i][0]--;
			newqueen[i][1]--;
			int gentemp = genMask(newqueen);
			if(repCheck(gentemp)) {
				int tmpsum = calc_sum(newqueen);
				queue <moves> tmpqueue = cur.st;
				tmpqueue.push(moves(i, newqueen[i][0]+1,newqueen[i][1]+1,newqueen[i][0],newqueen[i][1]));
				pq.push(queens(newqueen, tmpsum, tmpqueue));
				v.push_back(gentemp);
			}
			newqueen[i][0]++;
			newqueen[i][1]++;
		}
	}
	solve();
}

int main(int argc, char** argv) {
	int queen[8][2];
	initialize(argc, argv);	
    clearWindow();
// Guessing a random solution
	for(int i=0;i<8;i++) {
		queen[i][1]=i;
		queen[i][0]=rand()%8;
		printf("%d %d\n", queen[i][0],queen[i][1]);
	}
	int sum = calc_sum(queen);
	//printf("Sum = %d\n", sum);
	printgrid(queen);
	queue <moves> stck;
	pq.push(queens(queen, sum, stck));
	v.push_back(genMask(queen));
	solve();
	return 0;
}