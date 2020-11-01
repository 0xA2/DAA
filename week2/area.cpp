#include <iostream>

const double pi = 3.14159265358979323846;

double intersectionArea(double sx, double sy, double sl, double cx, double cy, double cr){

		// Square and circle completely seperate
		if( (cx+cr)<=sx || (cy+cr)<=sy || (cx-cr)>=(sx+sl) || (cy-cr)>=(sy+sl) ){
			return 0;
		}
		// Square inside circle
		if( ((sx-cx)*(sx-cx)+(sy-cy)*(sy-cy))<=cr*cr && ((sx+sl-cx)*(sx+sl-cx)+(sy-cy)*(sy-cy))<=cr*cr  && ((sx-cx)*(sx-cx)+(sy+sl-cy)*(sy+sl-cy))<=cr*cr  && ((sx+sl-cx)*(sx+sl-cx)+(sy+sl-cy)*(sy+sl-cy))<=cr*cr  ){
			return sl*sl;
		}
		// Circle inside square
		if( (cx-cr)>sx && (cy-cr)>sy && (cx+cr)<(sx+sl) && (cy+cr)<(sy+sl) ){
			return pi*cr*cr;
		}
		// Partial intersection
		double area = 0.0;
		if(sl >= 0.0031337){
			// upper - left
			area += intersectionArea(sx,sy+(sl/2),sl/2,cx,cy,cr);
			// upper - right
			area += intersectionArea(sx+(sl/2),sy+(sl/2),sl/2,cx,cy,cr);
			// lower - left
			area += intersectionArea(sx,sy,sl/2,cx,cy,cr);
			// lower - right
			area += intersectionArea(sx+(sl/2),sy,sl/2,cx,cy,cr);
		}
		return area;
}


int main(){
	int cases;
	std::cin >> cases;
	double sx,sy,sl,cx,cy,cr;
	for(int i = 0; i<cases; i++){
		std::cin >> sx;
		std::cin >> sy;
		std::cin >> sl;
		std::cin >> cx;
		std::cin >> cy;
		std::cin >> cr;
		std::cout << intersectionArea(sx,sy,sl,cx,cy,cr) << std::endl;
	}
	return 0;
}
