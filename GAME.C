#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include "maze.h"
int startAngle,endAngle,linexO,lineyO,linexT,lineyT;
int x = 150, y = 300,xinc=0,yinc=0,xprev,yprev,state=0;
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
	//int xmin = 10, ymin = 10, xmax = 630, ymax = 450;
	//int midx = ( xmin + xmax ) / 2 , midy = ( ymin + ymax ) / 2;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
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
		//

		//
		if(getpixel(x+11,y)>0){
			if(xinc>0){
				xinc=0;
			}
			if(getpixel(x,y-11)>0){
				if(yinc < 0){
					yinc = 0;
				}
			}else if(getpixel(x,y+11)>0){
				if(yinc>0){
					yinc = 0;
				}
			}
		}else if(getpixel(x-11,y)>0){
			if(xinc<0){
				xinc = 0;
			}
			if(getpixel(x,y-11)>0){
				if(yinc < 0){
					yinc = 0;
				}
			}else if(getpixel(x,y+11)>0){
				if(yinc>0){
					yinc = 0;
				}
			}
		}else if(getpixel(x,y-11)>0){
			if(yinc < 0){
				yinc = 0;
			}
			if(getpixel(x+11,y)>0){
				if(xinc>0){
					xinc=0;
				}
			}else if(getpixel(x-11,y)>0){
				if(xinc<0){
					xinc = 0;
				}
			}
		}else if(getpixel(x,y+11)>0){
			if(yinc>0){
				yinc = 0;
			}
			if(getpixel(x+11,y)>0){
				if(xinc>0){
					xinc=0;
				}
			}else if(getpixel(x-11,y)>0){
				if(xinc<0){
					xinc = 0;
				}
			}
		}
		delay(40);
		pacmanClear();
	}
	getch();
	closegraph();
}
