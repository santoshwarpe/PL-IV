#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<math.h>
#define pi 3.14
#define e 2.718282

void sinewave(float a,float F)
{
      int t,midx,midy;
      float xt,xt1;

      outtextxy(100,320,"x(t) = A sin(2*pi*F*t) ");
      outtextxy(200,350,"Sine Wave");
      outtextxy(600,250," t ");
      outtextxy(275,250,"(0,0)");
      outtextxy(275,40,"x(t)");

      midx=getmaxx()/2;
      midy=getmaxy()/2;

      for(t=0;t<midx;t++)
      {
	    xt=a*sin(2*pi*F*t);
	    putpixel(t+midx,xt+midy,15);
	    if(t!=0)
		line(t+midx-1,xt1+midy,t+midx,xt+midy);
	    xt1=xt;
      }
      line(0,midy,midx*2,midy);
      line(midx,0,midx,midy*2);
}

void cosinewave(float a,float F)
{
      int t,midx,midy;
      float xt,xt1;
      outtextxy(100,320,"x(t) = A cos(2*pi*F*t) ");
      outtextxy(200,350,"Cosine Wave");
      outtextxy(600,250," t ");
      outtextxy(275,250,"(0,0)");
      outtextxy(275,40,"x(t)");

      midx=getmaxx()/2;
      midy=getmaxy()/2;

      for(t=0;t<midx;t++)
      {
	    xt=a*cos((2*pi*F*t)-pi);
	    putpixel(t+midx,xt+midy,15);
	    if(t!=0)
		line(t+midx-1,xt1+midy,t+midx,xt+midy);
	    xt1=xt;
      }

      line(0,midy,midx*2,midy);
      line(midx,0,midx,midy*2);
}

void expowave(float a)
{
      int t,i,midx,midy;
      float xt,xt1;

      outtextxy(100,320,"x(t) = A (e^-t) ");
      outtextxy(150,350,"Exponential Wave");
      outtextxy(600,250," t ");
      outtextxy(275,250,"(0,0)");
      outtextxy(275,40,"x(t)");

      midx=getmaxx()/2;
      midy=getmaxy()/2;

      for(t=0;t<midx;t++)
      {
	    xt=-a*pow(e,-(float)t/100);
	    putpixel(t+midx,xt+midy,15);
	    if(t!=0)
		line(t+midx-1,xt1+midy,t+midx,xt+midy);
	    xt1=xt;
      }

      line(0,midy,midx*2,midy);
      line(midx,0,midx,midy*2);
}

void randomwave(float a)
{
      int t,i,midx,midy;
      float xt,xt1;

      outtextxy(100,320,"x(t) = rand() % a ");
      outtextxy(150,350,"Random Wave");
      outtextxy(600,250," t ");
      outtextxy(275,250,"(0,0)");
      outtextxy(275,40,"x(t)");

      midx=getmaxx()/2;
      midy=getmaxy()/2;
      randomize();
      for(t=0;t<midx;t++)
      {
	    xt=-rand()%(int)a;
	    putpixel(t+midx,xt+midy,15);
	    if(t!=0)
		line(t+midx-1,xt1+midy,t+midx,xt+midy);
	    xt1=xt;
      }

      line(0,midy,midx*2,midy);
      line(midx,0,midx,midy*2);
}

void squarewave(float a,float w)
{
      int t,midx,midy;

      outtextxy(200,350,"Square Wave");
      outtextxy(600,250," t ");
      outtextxy(275,250,"(0,0)");
      outtextxy(275,40,"x(t)");

      midx=getmaxx()/2;
      midy=getmaxy()/2;

      for(t=0;t<midx;t++)
      {
	     if(t%(int)w>=(w/2))
		   putpixel(t+midx,a+midy,15);
	     else
		   putpixel(t+midx,midy-a,15);
	     if(t%(int)w==0 || t%(int)w==w/2)
		   line(t+midx,midy+a,t+midx,midy-a);

      }
      line(0,midy,midx*2,midy);
      line(midx,0,midx,midy*2);
}


void triwave(float a,float w)
{
      int t,midx,midy,temp;

      outtextxy(200,350,"Triangular Wave");
      outtextxy(600,250," t ");
      outtextxy(275,250,"(0,0)");
      outtextxy(275,40,"x(t)");

      midx=getmaxx()/2;
      midy=getmaxy()/2;

      temp=0;

      for(t=0;t<midx;t++)
      {

	     if(temp>=a)
		  temp=0;
	     else if(temp<0)
		  temp=a;
	     if(t%(int)w>=(w/2))
	     {
		   putpixel(t+midx,midy-temp,15);
		   temp--;
	     }
	     else
	     {
		   putpixel(t+midx,midy-temp,15);
		   temp++;
	     }
      }
      line(0,midy,midx*2,midy);
      line(midx,0,midx,midy*2);
}


void sinedtswave(float a,float F,float fs)
{
      int n,midx,midy;
      float xn;

      outtextxy(100,320,"x(n) = A sin(2*pi*n*F/fs) ");
      outtextxy(200,350,"Sine Wave");
      outtextxy(600,250," n ");
      outtextxy(275,250,"(0,0)");
      outtextxy(275,40,"x(n)");

      midx=getmaxx()/2;
      midy=getmaxy()/2;

      for(n=0;n<midx;n=n+5)
      {
	    xn=a*sin(2*pi*n*F/fs);
	    putpixel(n+midx,xn+midy,15);
	    line(n+midx,xn+midy,n+midx,midy);
      }

      line(0,midy,midx*2,midy);
      line(midx,0,midx,midy*2);
}

void cosinedtswave(float a,float F,float fs)
{
      int n,midx,midy;
      float xn;
      outtextxy(100,320,"x(n) = A cos(2*pi*n*F/fs) ");
      outtextxy(200,350,"Cosine Wave");
      outtextxy(600,250," n ");
      outtextxy(275,250,"(0,0)");
      outtextxy(275,40,"x(n)");

      midx=getmaxx()/2;
      midy=getmaxy()/2;

      for(n=0;n<midx;n=n+5)
      {
	    xn=a*cos((2*pi*n*F/fs)-pi);
	    putpixel(n+midx,xn+midy,15);
	    line(n+midx,xn+midy,n+midx,midy);
      }

      line(0,midy,midx*2,midy);
      line(midx,0,midx,midy*2);
}


void expodtswave(float a,float fs)
{
      int n,i,midx,midy;
      float xn;

      outtextxy(100,320,"x(n) = A (e^-(n/fs)) ");
      outtextxy(150,350,"Exponential Wave");
      outtextxy(600,250,"n");
      outtextxy(275,250,"(0,0)");
      outtextxy(275,40,"x(n)");

      midx=getmaxx()/2;
      midy=getmaxy()/2;

      for(n=0;n<midx;n=n+5)
      {
	    xn=-a*pow(e,-((float)n/fs));
	    putpixel(n+midx,xn+midy,15);
	    line(n+midx,xn+midy,n+midx,midy);
      }

      line(0,midy,midx*2,midy);
      line(midx,0,midx,midy*2);
}

void randomdtswave(float a)
{
      int i,midx,midy,n;
      float xn;

      outtextxy(150,350,"Random Wave");
      outtextxy(600,250,"n");
      outtextxy(275,250,"(0,0)");
      outtextxy(275,40,"x(n)");

      midx=getmaxx()/2;
      midy=getmaxy()/2;
      randomize();
      for(n=0;n<midx;n=n+5)
      {
	    xn=-rand()%(int)a;
	    putpixel(n+midx,xn+midy,15);
	    line(n+midx,xn+midy,n+midx,midy);
      }

      line(0,midy,midx*2,midy);
      line(midx,0,midx,midy*2);
}


void squaredtswave(float a,float w)
{
      int n,midx,midy;

      outtextxy(200,350,"Square Wave");
      outtextxy(600,250," n ");
      outtextxy(275,250,"(0,0)");
      outtextxy(275,40,"x(n)");

      midx=getmaxx()/2;
      midy=getmaxy()/2;

      for(n=0;n<midx;n=n+5)
      {
	     if(n%(int)w>=(w/2))
	     {
		   putpixel(n+midx,a+midy,15);
		   line(n+midx,a+midy,n+midx,midy);
	     }
	     else
	     {
		   putpixel(n+midx,midy-a,15);
		   line(n+midx,midy-a,n+midx,midy);
	     }
      }
      line(0,midy,midx*2,midy);
      line(midx,0,midx,midy*2);
}


void tridtswave(float a,float w)
{
      int n,midx,midy,temp;

      outtextxy(200,350,"Triangular Wave");
      outtextxy(600,250," n ");
      outtextxy(275,250,"(0,0)");
      outtextxy(275,40,"x(n)");

      midx=getmaxx()/2;
      midy=getmaxy()/2;

      temp=0;
      for(n=0;n<midx;n=n+5)
      {
	     if(temp>=a)
		   temp=0;
	     else if(temp<0)
		   temp=a;
	     if(n%(int)w>=(w/2))
	     {
		   putpixel(n+midx,midy-temp,15);
		   line(n+midx,midy-temp,n+midx,midy);
		   temp=temp-5;
	     }
	     else
	     {
		   putpixel(n+midx,midy-temp,15);
		   line(n+midx,midy-temp,n+midx,midy);
		   temp=temp+5;
	     }
      }
      line(0,midy,midx*2,midy);
      line(midx,0,midx,midy*2);
}


void main()
{
     int choice,ch;
     float F,a,w,fs;
     int gd=DETECT,gm;
     initgraph(&gd,&gm,"c:\\tc1\\bgi");

     do
     {
	  printf("\n\tYou can draw following waves ");
	  printf("\n\t\t1.CTS \n\t\t2.DTS \n\t\t3.Exit");
	  printf("\n\tEnter your choice : ");
	  scanf("%d",&choice);

	  switch(choice)
	  {
	      case 1:do
		     {
			 printf("\n\t\tYou can draw following waves ");
			 printf("\n\t\t\t1.Sine Wave \n\t\t\t2.Cosine Wave \n\t\t\t3.Exponential Wave \n\t\t\t4.Random Wave \n\t\t\t5.Square Wave \n\t\t\t6.Triangular Wave \n\t\t\t7.Exit");
			 printf("\n\t\tEnter your choice : ");
			 scanf("%d",&ch);

			 switch(ch)
			 {
			  case 1:printf("\n\t\tEnter the amplitude : ");
				 scanf("%f",&a);
				 printf("\n\t\tEnter the frequency : ");
				 scanf("%f",&F);
				 cleardevice();
				 sinewave(a,F);
				 getch();
				 cleardevice();
				 break;
			  case 2:printf("\n\t\tEnter the amplitude : ");
				 scanf("%f",&a);
				 printf("\n\t\tEnter the frequency : ");
				 scanf("%f",&F);
				 cleardevice();
				 cosinewave(a,F);
				 getch();
				 cleardevice();
				 break;
			  case 3:printf("\n\t\tEnter the amplitude : ");
				 scanf("%f",&a);
				 cleardevice();
				 expowave(a);
				 getch();
				 cleardevice();
				 break;
			  case 4:printf("\n\t\tEnter the amplitude : ");
				 scanf("%f",&a);
				 cleardevice();
				 randomwave(a);
				 getch();
				 cleardevice();
				 break;
			  case 5:printf("\n\t\tEnter the amplitude : ");
				 scanf("%f",&a);
				 printf("\n\t\tEnter the wavelength : ");
				 scanf("%f",&w);
				 cleardevice();
				 squarewave(a,w);
				 getch();
				 cleardevice();
				 break;
			  case 6:printf("\n\t\tEnter the amplitude : ");
				 scanf("%f",&a);
				 printf("\n\t\tEnter the wavelength : ");
				 scanf("%f",&w);
				 cleardevice();
				 triwave(a,w);
				 getch();
				 cleardevice();
				 break;
			  case 7:
				 break;
			 }
		     }while(ch!=7);
		     break;
	      case 2:do
		     {
			 printf("\n\t\tYou can draw following waves ");
			 printf("\n\t\t\t1.Sine Wave \n\t\t\t2.Cosine Wave \n\t\t\t3.Exponential Wave \n\t\t\t4.Random Wave \n\t\t\t5.Square Wave \n\t\t\t6.Triangular Wave \n\t\t\t7.Exit");
			 printf("\n\t\tEnter your choice : ");
			 scanf("%d",&ch);

			 switch(ch)
			 {
			  case 1:printf("\n\t\tEnter the amplitude : ");
				 scanf("%f",&a);
				 printf("\n\t\tEnter the frequency of CTS : ");
				 scanf("%f",&F);
				 printf("\n\t\tEnter the sampling frequency : ");
				 scanf("%f",&fs);
				 cleardevice();
				 sinedtswave(a,fs,F);
				 getch();
				 cleardevice();
				 break;
			  case 2:printf("\n\t\tEnter the amplitude : ");
				 scanf("%f",&a);
				 printf("\n\t\tEnter the frequency of CTS : ");
				 scanf("%f",&F);
				 printf("\n\t\tEnter the sampling frequency : ");
				 scanf("%f",&fs);
				 cleardevice();
				 cosinedtswave(a,fs,F);
				 getch();
				 cleardevice();
				 break;
			  case 3:printf("\n\t\tEnter the amplitude : ");
				 scanf("%f",&a);
				 printf("\n\t\tEnter the sampling frequency : ");
				 scanf("%f",&fs);
				 cleardevice();
				 expodtswave(a,fs);
				 getch();
				 cleardevice();
				 break;
			  case 4:printf("\n\t\tEnter the amplitude : ");
				 scanf("%f",&a);
				 cleardevice();
				 randomdtswave(a);
				 getch();
				 cleardevice();
				 break;
			  case 5:printf("\n\t\tEnter the amplitude : ");
				 scanf("%f",&a);
				 printf("\n\t\tEnter the wavelength : ");
				 scanf("%f",&w);
				 cleardevice();
				 squaredtswave(a,w);
				 getch();
				 cleardevice();
				 break;
			  case 6:printf("\n\t\tEnter the amplitude : ");
				 scanf("%f",&a);
				 printf("\n\t\tEnter the wavelength : ");
				 scanf("%f",&w);
				 cleardevice();
				 tridtswave(a,w);
				 getch();
				 cleardevice();
				 break;
			  case 7:
				 break;
			 }
		     }while(ch!=7);
		     break;
	      case 3:
		     break;

	   }
      }while(choice!=3);
      closegraph();
}
