#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
int startAngle,endAngle,linexO,lineyO,linexT,lineyT;
int x = 320, y = 277,xinc=0,yinc=0,xprev,yprev,state=0;
void symmetric(int midx, int midy){
	line(midx-50,midy-35,midx-50,midy+35);
	line(midx-50,midy+35,midx+50,midy+35);
	line(midx+50,midy+35,midx+50,midy-35);
	line(midx-50,midy-35,midx-12,midy-35);
	line(midx+12,midy-35,midx+50,midy-35);

	line(midx+74,midy-60,midx+74, midy);
	line(midx+74,midy-60,midx+54,midy-60);
	line(midx+74,midy+60,midx+74, midy);
	line(midx+74,midy+60,midx+54,midy+60);
	line(midx-74,midy-60,midx-74, midy);
	line(midx-74,midy-60,midx-54,midy-60);
	line(midx-74,midy+60,midx-74, midy);
	line(midx-74,midy+60,midx-54,midy+60);

	line(midx+100,midy-60,midx+100,midy);
	line(midx+100,midy+60,midx+100,midy);
	line(midx-100,midy-60,midx-100,midy);
	line(midx-100,midy+60,midx-100,midy);

	rectangle(midx+124,midy-60,midx+180,midy-24);
	rectangle(midx+124,midy+60,midx+180,midy+24);
	rectangle(midx-124,midy+60,midx-180,midy+24);
	rectangle(midx-124,midy-60,midx-180,midy-24);

	line(midx+124,midy,midx+180,midy);
	line(midx-124,midy,midx-180,midy);

	line(midx,midy-150,midx+30,midy-150);
	line(midx,midy-150,midx-30,midy-150);
	line(midx,midy+150,midx-30,midy+150);
	line(midx,midy+150,midx+30,midy+150);

	line(midx,midy-126,midx+30,midy-126);
	line(midx,midy-126,midx-30,midy-126);
	line(midx,midy+126,midx+30,midy+126);
	line(midx,midy+126,midx-30,midy+126);

	line(midx,midy+60,midx+30,midy+60);
	line(midx,midy-60,midx+30,midy-60);
	line(midx,midy+60,midx-30,midy+60);
	line(midx,midy-60,midx-30,midy-60);

	line(midx+30,midy+126,midx+30,midy+60);
	line(midx+30,midy-126,midx+30,midy-60);
	line(midx-30,midy+126,midx-30,midy+60);
	line(midx-30,midy-126,midx-30,midy-60);

	rectangle(midx+54,midy-174,midx+100,midy-84);
	rectangle(midx+54,midy+174,midx+100,midy+84);
	rectangle(midx-54,midy-174,midx-100,midy-84);
	rectangle(midx-54,midy+174,midx-100,midy+84);

	rectangle(midx+124,midy-174,midx+200,midy-141);
	rectangle(midx+124,midy-117,midx+200,midy-84);
	rectangle(midx+124,midy+174,midx+200,midy+141);
	rectangle(midx+124,midy+117,midx+200,midy+84);
	rectangle(midx-124,midy-174,midx-200,midy-141);
	rectangle(midx-124,midy-117,midx-200,midy-84);
	rectangle(midx-124,midy+174,midx-200,midy+141);
	rectangle(midx-124,midy+117,midx-200,midy+84);

	line(midx+30,midy-150,midx+30,midy-196);
	line(midx-30,midy-150,midx-30,midy-196);
	line(midx+30,midy+150,midx+30,midy+196);
	line(midx-30,midy+150,midx-30,midy+196);

	line(midx+30,midy-196,midx+224,midy-196);
	line(midx-30,midy-196,midx-224,midy-196);
	line(midx+30,midy+196,midx+224,midy+196);
	line(midx-30,midy+196,midx-224,midy+196);

	line(midx+224,midy-196,midx+224,midy-60);
	line(midx+224,midy+196,midx+224,midy+60);
	line(midx-224,midy-196,midx-224,midy-60);
	line(midx-224,midy+196,midx-224,midy+60);

	line(midx+224,midy-60,midx+204,midy-60);
	line(midx+204,midy-60,midx+204,midy);
	line(midx+224,midy+60,midx+204,midy+60);
	line(midx+204,midy+60,midx+204,midy);
	line(midx-224,midy-60,midx-204,midy-60);
	line(midx-204,midy-60,midx-204,midy);
	line(midx-224,midy+60,midx-204,midy+60);
	line(midx-204,midy+60,midx-204,midy);

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
int checkCollision(){
	int i,j,xloop = xinc*10+x , yloop = yinc * 10 + y;
	if(xinc<0){
		xloop--;
	}else if(xinc>0){
		xloop++;
	}
	if(yinc<0){
		yloop--;
	}else if(yinc>0){
		yloop++;
	}
	if(yinc==0){
		for(i=1;i<=10;i++){
			if(getpixel(xloop,yloop-i)==15){
				return 1;
			}
			if(getpixel(xloop,yloop+i)==15){
				return 1;
			}
		}
		return 0;
	}else
	{
		for(i=1;i<=10;i++){
			if(getpixel(xloop-i,yloop)==15){
				return 1;
			}
			if(getpixel(xloop+i,yloop)==15){
				return 1;
			}
		}
		return 0;
	}
}
void angleCheck(){
	//not moving state is 0
	if(state==0){
		startAngle = 225;
		endAngle = 135;
		linexO=x-8;
		lineyO=y+6;
		linexT=x-8;
		lineyT=y-7;
	}
	if(state >= 1&&state<10){
		if(xinc>0){
			startAngle = 45;
			endAngle = 315;
			linexO=x+8;
			lineyO=y-6;
			linexT=x+8;
			lineyT=y+7;
		}else if(xinc<0){
			startAngle = 225;
			endAngle = 135;
			linexO=x-8;
			lineyO=y+6;
			linexT=x-8;
			lineyT=y-7;
		}else if(yinc>0){
			startAngle = 320;
			endAngle = 230;
			linexO=x-7;
			lineyO=y+8;
			linexT=x+7;
			lineyT=y+8;
		}else if(yinc<0){
			startAngle = 135;
			endAngle = 45;
			linexO=x+7;
			lineyO=y-8;
			linexT=x-7;
			lineyT=y-8;
		}
	}else if(state == 10){
		startAngle = 0;
		endAngle = 360;
		if(xinc>0){
			linexO = x+10;
			lineyO = y;
		}else if(xinc<0){
			linexO = x-10;
			lineyO = y;
		}else if(yinc>0){
			linexO = x;
			lineyO = y+10;
		}else if(yinc<0){
			linexO = x;
			lineyO = y-10;
		}
		linexT=linexO;
		lineyT=lineyO;
	}
}
void pacman(){
	angleCheck();
	//display
	ellipse(x,y,startAngle,endAngle,10,10);
	line(x,y,linexO,lineyO);
	line(x,y,linexT,lineyT);
}
void pacmanClear(){
	setcolor(0);
	ellipse(x,y,startAngle,endAngle,10,10);
	line(x,y,linexO,lineyO);
	line(x,y,linexT,lineyT);
}
void main(){
	int gd = DETECT, gm;
	char inp=' ';
	int coll;
	initgraph(&gd, &gm, "C:\\TC\\BGI");
	maze();
	//rectangle(10,10,630,450);
	while(1){
		x += xinc;
		y += yinc;
		setcolor(3);
		pacman();
		if(inp!=' '){
			if(state==10){
				state = 1;
			}else{
				state++;
			}
		}
		if(kbhit()){
			inp = getch();
			if(inp=='w'){
				xinc = 0;
				yinc = -1;
			}else if(inp == 's'){
				xinc = 0;
				yinc = 1;
			}else if(inp == 'a'){
				xinc = -1;
				yinc = 0;
			}else if(inp == 'd'){
				xinc = 1;
				yinc = 0;
			}else if(inp == 'q'){
				break;
			}else{
				continue;
			}
		}


		delay(40);
		pacmanClear();
		if(xinc!=0){
			if(checkCollision()==1){
				xinc = 0;
			}
		}
		if(yinc!=0){
			if(checkCollision()==1){
				yinc = 0;
			}
		}
	}
	getch();
	closegraph();
}
