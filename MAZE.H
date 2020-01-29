#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void symmetric(int midx, int midy){
	rectangle(midx-50,midy-35,midx+50,midy+35);

	line(midx,midy-150,midx+30,midy-150);
	line(midx,midy-150,midx-30,midy-150);
	line(midx,midy+150,midx-30,midy+150);
	line(midx,midy+150,midx+30,midy+150);

	line(midx,midy-126,midx+30,midy-126);
	line(midx,midy-126,midx-30,midy-126);
	line(midx,midy+126,midx+30,midy+126);
	line(midx,midy+126,midx-30,midy+126);
	
	line(midx+30,midy+126,midx+30,midy+60);
	line(midx+30,midy-126,midx+30,midy-60);
	line(midx-30,midy+126,midx-30,midy+60);
	line(midx-30,midy-126,midx-30,midy-60);
	
	rectangle(midx+54,midy-174,midx+100,midy-84);
	rectangle(midx+54,midy+174,midx+100,midy+84);
	rectangle(midx-54,midy-174,midx-100,midy-84);
	rectangle(midx-54,midy+174,midx-100,midy+84);

	line(midx+30,midy-150,midx+30,midy-196);
	line(midx-30,midy-150,midx-30,midy-196);
	line(midx+30,midy+150,midx+30,midy+196);
	line(midx-30,midy+150,midx-30,midy+196);
	
	line(midx+30,midy-196,midx+200,midy-196);
	line(midx-30,midy-196,midx-200,midy-196);
	line(midx+30,midy+196,midx+200,midy+196);
	line(midx-30,midy+196,midx-200,midy+196);

}
void pallets(int xmin,int ymin, int xmax, int ymax){
	int i = xmin,j = ymin;
	while(j<ymax&&i<xmax){
		if(getpixel(i,j)==15){
			if(getpixel(i+1,j)==15){
				i+=5;
			}
			if(getpixel(i,j+1)==15){
				j+=5;
			}
		}else{
			circle(i,j,5);
			i+=20;
		}
		if(i>=xmax){
			j+=20;
			i = xmin;
		}else{
			i++;
		}
	}
}
void maze(){
	/**
		code to design maze
	**/
	int xmin = 10, ymin = 10, xmax = 630, ymax = 450; //coordinates of outer shell
	int midx = ( xmin + xmax ) / 2 , midy = ( ymin + ymax ) / 2;
	rectangle( xmin , ymin , xmax , ymax ); //outercover

	/**
		temporary lines to divide everything into quadrants
	**/

	//line( midx , ymin , midx , ymax );
	//line( xmin , midy , xmax , midy );
	//pallets(xmin,ymin,xmax,ymax);
	symmetric(midx,midy);
}