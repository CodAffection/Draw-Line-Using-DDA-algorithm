// Author : youtube channel-dotnetmob
// Date : 30-Apr-2015
// Description : program for drawing line using dda algorithm

#include<graphics.h>
#include<stdio.h>

#define round(a) ((int)(a+0.5))

void dda(int xa,int ya,int xb,int yb)
{
	int dx=xb-xa,dy=yb-ya,steps,k,xin,yin;
	if(abs(dx)>abs(dy))
	  steps=abs(dx);
	else
	  steps=abs(dy);
	xin=dx/(float)steps;
	yin=dy/(float)steps;

	putpixel(round(xa),round(ya),GREEN);
	for(k=0;k<steps;k++)
	{
	  xa+=xin;
	  ya+=yin;
	  putpixel(round(xa),round(ya),GREEN);
	}
}

void main()
{
	int gd=DETECT,gm,x1,x2,y1,y2;

	do
	{
	//#change this line according to your BGI directory
	//can be found in your installation folder
	initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
	printf("[width : %d]\n[height : %d]\n",getmaxx(),getmaxy());
	printf("enter start coordinate : ");
	scanf("%d%d",&x1,&y1);
	printf("enter end coordinate : ");
	scanf("%d%d",&x2,&y2);
	clrscr();
	cleardevice();
	dda(x1,y1,x2,y2);

	printf("Press 'y' for try again ...");
	}
	while(getch()=='y');
}