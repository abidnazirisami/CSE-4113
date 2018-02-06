#define max_point 640
#define AXIS 0
#define DIAGONAL 1

void menu();
void clearWindow();
void initialize(int argc, char** argv);
int roundUp(double in);
int selectZone(double x1, double y_1, double x2, double y2);
void setColor(int zone);
void ddaAlgo(double x1, double y_1, double x2, double y2);
void randomDisplay();
void randomDisplay2();
int direction(int d, int zone);
void midpointAlgo(double x1, double y_1, double x2, double y2);
void midpoint();
void dda();
void menu();
void randomLines();
void symmetricMidpoint(double x1, double y_1, double x2, double y2);
void drawPoint(int x, int y, int zone);
void symMenu() ;
void drawBoxes() ;
void drawSymBox(int zone);
int calcbits(int x, int y, int l, int r, int b, int t);
void clipMenu();
void cyrus_beck(double x1, double y_1, double x2, double y2, double xmin, double xmax, double ymin, double ymax);
void cymenu();
