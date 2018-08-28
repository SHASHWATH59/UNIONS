#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<time.h>
#define PI 3.1415926535897932384626433832795
void *font = GLUT_BITMAP_HELVETICA_18;//font style
void display();
void init();
void init1();
void rain();
void man1();
void sun();
void myinit();
void sunnyday();
void display2();
void display4();
void output(float x,float y,char *string)//string display function
{
	int len,i;
	glRasterPos2f(x,y);
	len=(int)strlen(string);
	for(i=0;i<len;i++)
	{
		glutBitmapCharacter(font,string[i]);
	}
}

void tree(void)//the tree on the first screen
{
	float i,k=3;
	float x=91,y=56;
	glPointSize(2.0);
	glBegin(GL_POLYGON);//c1
	for(i=0;i<=800;i=i+0.6)
	{
		  glColor3f(0,0.544,0);
		  glVertex2f(cos(i*3.14/360)*k+x,sin(i*3.14/360)*k*2+y);
	}
    	glEnd();
        glPointSize(2.0);
	glBegin(GL_POLYGON);//c2
	k=2;x=89,y=53;
        for(i=0;i<=800;i=i+0.6)
	{
		  glColor3f(0,0.544,0);
		  glVertex2f(cos(i*3.14/360)*k+x,sin(i*3.14/360)*k*2+y);
	}
    	glEnd();
	glPointSize(2.0);
	glBegin(GL_POLYGON);//c2
	k=2;x=93.5,y=53;
        for(i=0;i<=800;i=i+0.6)
	{
		  glColor3f(0,0.544,0);
		  glVertex2f(cos(i*3.14/360)*k+x,sin(i*3.14/360)*k*2+y);
	}
    	glEnd();
}
void draw(void)//background of first screen-house,hills,road,mud
{
    	int i;int f;
	float l=0,t,y,k;
	glClear(GL_COLOR_BUFFER_BIT);
   	glBegin(GL_QUADS);//road
   	glColor3f(0.8,0.4,0);//glColor3f(0.135,0.5618515,0);
	   glVertex2f(0,12);
	   glVertex2f(100,12);
	   glVertex2f(100,0);
	   glVertex2f(0,0);
	   glEnd();

	   glBegin(GL_QUADS);//hill
	   glColor3f(0,0.615,0);
	   glVertex2f(0,33);
	   glVertex2f(30,66);
	   glVertex2f(70,33);
	   glVertex2f(0,33);
	   glEnd();
	   glBegin(GL_QUADS);//hill2
	   glColor3f(0,0.615,0);
	   glVertex2f(30,33);
	   glVertex2f(80,66);
	   glVertex2f(100,33);
	   glVertex2f(50,33);
	   glEnd();
	   glBegin(GL_QUADS);//mud
	   glColor3f(0.335,0.7618515,0);
	   glVertex2f(0,33);
	   glVertex2f(100,33);
	   glVertex2f(100,12);
	   glVertex2f(0,12);
	   glEnd();
	   glBegin(GL_POLYGON);//tree
           glColor3f(0.5,0.3,0.3);
           glVertex2f(90,57);
	   glVertex2f(93,57);
           glVertex2f(93,26);
           glVertex2f(90,26);
           glEnd();
	glBegin(GL_QUADS);//house
	   glColor3f(0.8,0.8,0.8);
	   glVertex2f(0,50);
	   glVertex2f(28,50);
	   glVertex2f(28,13);
	   glVertex2f(0,13);
	   glEnd();

    	glBegin(GL_QUADS);//house2
	   glColor3f(0.6,0.6,0.6);
	   glVertex2f(28,50);
	   glVertex2f(34,55);
	   glVertex2f(34,17);
	   glVertex2f(28,13);
	glEnd();
	glBegin(GL_TRIANGLES);//roof
	   glColor3f(0.4,0,0);
	   glVertex2f(27,44);
	   glVertex2f(30,60);
	   glVertex2f(36,52);
	glEnd();
	glBegin(GL_QUADS);//roof2
	   glColor3f(0.6,0,0);
	   glVertex2f(0,60);
	   glVertex2f(30,60);
	   glVertex2f(27,44);
	   glVertex2f(0,44);
	glEnd();
	tree();
}
void head(float x2,float y2, float r)//head of the men
{
	float i;
	glBegin(GL_POLYGON);
	glColor3f(0.9411,0.7843,0.7372);
	for(i=0;i<=360;i++)
	{
		glVertex2f((sin((i*PI)/180)*r*0.6)+x2,(cos((i*PI)/180)*r)+y2);
	
	}
	glEnd();
}
void lips(float x2,float y2, float r)//lip of the men
{
	float i;
	glBegin(GL_POLYGON);
	glColor3f(0.8,0,0);
	for(i=0;i<=360;i++)
	{
		glVertex2f((sin((i*PI)/180)*r*0.6)+x2,(cos((i*PI)/180)*r)+y2);
	
	}
	glEnd();
}
void eye(float x2,float y2, float r)//eye of the men
{
	float i;

	glBegin(GL_POLYGON);

	glColor3f(0,0,0);
	for(i=0;i<=360;i++)
	{
		glVertex2f((sin((i*PI)/180)*r*0.6)+x2,(cos((i*PI)/180)*r)+y2);
	
	}
	glEnd();
}
void fall()//seed falling from the hand to the ground
{
	float i=0;
	glColor3f(0.0,0.0,0.0);
	glPointSize(6);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,0.0,0.0);
	while(i<15)
	{
		glColor3f(0.0,0.0,0.0);
		i=i+0.05;
		draw();man1();
		glColor3f(0.0,0.0,0.0);
		glPointSize(6);
		glBegin(GL_POINTS);
		glVertex2f(58,25-i);
		glVertex2f(58,24-i);
		glEnd();
		glFlush();
	}
	glColor3f(0.01,0.01,0.5);
	output(10,28,"PRESS Mouse left button");
	glFlush();
	man1();
}
void man()//moving the man from house to field
{
	
	int f,i;
	float l,t,y,k;
	glClear(GL_COLOR_BUFFER_BIT);
	while(l<50)
	{
		l=l+0.1;draw();
		glBegin(GL_QUADS);//body
			glColor3f(0.0,0.0,1.0);//396
	   		glVertex2f(2+l,28);
			glVertex2f(4.5+l,28);
	    		glVertex2f(4.5+l,19.9);
			glVertex2f(2+l,19.9);
		glEnd();
		glBegin(GL_QUADS);//hand
			glColor3f(0.9411,0.7843,0.7372);
	   		glVertex2f(4.2+l,25);
			glVertex2f(3.2+l,27);
	    		glVertex2f(4.2+l,18);
			glVertex2f(3.2+l,18);
		glEnd();
		glBegin(GL_QUADS);//leg
			glColor3f(0.8,0.8,0);
		    	glVertex2f(2+l,19.9);
			glVertex2f(4.5+l,19.9);
		    	glVertex2f(4.1+l,9);
			glVertex2f(2.6+l,9);
		glEnd();
		glBegin(GL_POLYGON);//foot
			glColor3f(0.1,0.1,0.1);
			glVertex2f(2.6+l,9);
			glVertex2f(5+l,8);
			glVertex2f(5+l,7);
			glVertex2f(4+l,7);
			glVertex2f(2.6+l,6.8);
		glEnd();
		head(3.3+l,30,2.21);
		lips(4.2+l,29,0.4);
	    	eye(4+l,31,0.4);
	 	glColor3f(0.9411,0.7843,0.7372);
		glBegin(GL_POLYGON);
			glVertex2f(4.5+l,26.5);
			glVertex2f(8+l,26.5);
			glVertex2f(4.5+l,25);
			glVertex2f(7+l,25);
			glVertex2f(7+l,25);
			glVertex2f(7.5+l,26);
			glVertex2f(7.5+l,26);
			glVertex2f(7.9+l,25);
			glVertex2f(7.9+l,25);
			glVertex2f(8+l,26.5);
		glEnd();
		glFlush();
	}
	man1();fall();man1();
}
void clouds()//clouds on the sky
{
	float i,k=1;
	float t,y;
	glPointSize(5.0);
    	glBegin(GL_POLYGON);//sun
	k=2.5;
        t=20,y=88;
	glColor3f(1,1,1);
	for(i=0;i<=800;i=i+0.6)
	{
		glVertex2f(cos(i*3.14/360)*k+t,sin(i*3.14/360)*k*2+y);
	}
	glEnd();
	glBegin(GL_POLYGON);//sun
	k=2.5;
        t=22,y=87;
	glColor3f(1,1,1);
	for(i=0;i<=800;i=i+0.6)
	{
		  glVertex2f(cos(i*3.14/360)*k+t,sin(i*3.14/360)*k*2+y);
	}
	glEnd();
	glBegin(GL_POLYGON);//sun
	k=2;
        t=18,y=87.6;
	glColor3f(1,1,1);
	for(i=0;i<=800;i=i+0.6)
	{
		  glVertex2f(cos(i*3.14/360)*k+t,sin(i*3.14/360)*k*2+y);
	
	}
	glEnd();
	glBegin(GL_POLYGON);//sun
	k=2.3;
        t=78,y=86;
	glColor3f(1,1,1);
	for(i=0;i<=800;i=i+0.6)
	{
		  glVertex2f(cos(i*3.14/360)*k+t,sin(i*3.14/360)*k*2+y);
	}
	glEnd();
	glBegin(GL_POLYGON);//sun
	k=2.5;
        t=76,y=86;
	glColor3f(1,1,1);
	for(i=0;i<=800;i=i+0.6)
	{
		glVertex2f(cos(i*3.14/360)*k+t,sin(i*3.14/360)*k*2+y);
	}
	glEnd();
	glBegin(GL_POLYGON);//sun
	k=2.1;
        t=74,y=85;
	glColor3f(1,1,1);
	for(i=0;i<=800;i=i+0.6)
	{
		glVertex2f(cos(i*3.14/360)*k+t,sin(i*3.14/360)*k*2+y);
	}
	glEnd();
}
void blackclouds()//clouds when raining
{
	float i,k=1;
	float t,y;
	glPointSize(5.0);
	glBegin(GL_POLYGON);//sun
		k=2.5;
        	t=23,y=88;
		glColor3f(0,0,0);
		for(i=0;i<=800;i=i+0.6)
		{
		  glVertex2f(cos(i*3.14/360)*k+t,sin(i*3.14/360)*k*2+y);
		}
	glEnd();
	glBegin(GL_POLYGON);//sun
		k=2.5;
        	t=22,y=88;
		glColor3f(0,0,0);
		for(i=0;i<=800;i=i+0.6)
		{
		  glVertex2f(cos(i*3.14/360)*k+t,sin(i*3.14/360)*k*2+y);
		}
	glEnd();
	glBegin(GL_POLYGON);//sun
		k=2.5;
        	t=25,y=87;
		glColor3f(0,0,0);
		for(i=0;i<=800;i=i+0.6)
		{
		  glVertex2f(cos(i*3.14/360)*k+t,sin(i*3.14/360)*k*2+y);
		}
	glEnd();
	glBegin(GL_POLYGON);//sun
		k=2;
		t=19,y=87.6;
		glColor3f(0,0,0);
		for(i=0;i<=800;i=i+0.6)
		{
		  glVertex2f(cos(i*3.14/360)*k+t,sin(i*3.14/360)*k*2+y);
		}
		glEnd();
		glBegin(GL_POLYGON);//sun
	     	k=2.3;
        	t=78,y=86;
		glColor3f(0,0,0);
		for(i=0;i<=800;i=i+0.6)
		{
		  glVertex2f(cos(i*3.14/360)*k+t,sin(i*3.14/360)*k*2+y);
		}
		glEnd();
		glBegin(GL_POLYGON);//sun
	     	k=2.5;
        	t=76,y=86;
		glColor3f(0,0,0);
		for(i=0;i<=800;i=i+0.6)
		{
		  glVertex2f(cos(i*3.14/360)*k+t,sin(i*3.14/360)*k*2+y);
		}
		glEnd();
		glBegin(GL_POLYGON);//sun
		k=2.1;
        	t=74,y=85;
		glColor3f(0,0,0);
		for(i=0;i<=800;i=i+0.6)
		{
		  glVertex2f(cos(i*3.14/360)*k+t,sin(i*3.14/360)*k*2+y);
		}
		glEnd();
}
void man1()//men when the seed is falling
{
	draw();clouds();
	glBegin(GL_QUADS);//body
		glColor3f(0.0,0.0,1.0);
   		glVertex2f(2+50,28);
		glVertex2f(4.5+50,28);
    		glVertex2f(4.5+50,19.9);
		glVertex2f(2+50,19.9);
	glEnd();
	glBegin(GL_QUADS);//hand
		glColor3f(0.9411,0.7843,0.7372);
   		glVertex2f(4.2+50,25);
		glVertex2f(3.2+50,27);
    		glVertex2f(4.2+50,18);
		glVertex2f(3.2+50,18);
	glEnd();
	glBegin(GL_QUADS);//leg
		glColor3f(0.8,0.8,0);
	    	glVertex2f(2+50,19.9);
		glVertex2f(4.5+50,19.9);
	    	glVertex2f(4.1+50,9);
		glVertex2f(2.6+50,9);
	glEnd();
	glBegin(GL_POLYGON);//foot
		glColor3f(0.1,0.1,0.1);
		glVertex2f(2.6+50,9);
		glVertex2f(5+50,8);
		glVertex2f(5+50,7);
		glVertex2f(4+50,7);
		glVertex2f(2.6+50,6.8);
	glEnd();
	head(3.3+50,30,2.21);
	lips(4.2+50,29,0.4);
    	eye(4+50,31,0.4);
 	glBegin(GL_POLYGON);glColor3f(0.9411,0.7843,0.7372);
		glVertex2f(4.5+50,26.5);
		glVertex2f(8+50,26.5);
		glVertex2f(4.5+50,25);
		glVertex2f(7+50,25);
		glVertex2f(7+50,25);
		glVertex2f(7.5+50,26);
		glVertex2f(7.5+50,26);
		glVertex2f(7.9+50,25);
		glVertex2f(7.9+50,25);
		glVertex2f(8+50,26.5);
	glEnd();
}
void man2()
{
	glBegin(GL_QUADS);//body
		glColor3f(0.0,0.0,1.0);
   		glVertex2f(2+20,28);
		glVertex2f(4.5+20,28);
    		glVertex2f(4.5+20,19.9);
		glVertex2f(2+20,19.9);
	glEnd();
	glBegin(GL_QUADS);//hand
		glColor3f(0.9411,0.7843,0.7372);
   		glVertex2f(4.2+20,25);
		glVertex2f(3.2+20,27);
    		glVertex2f(4.2+20,18);
		glVertex2f(3.2+20,18);
	glEnd();
	glBegin(GL_QUADS);//leg
		glColor3f(0.8,0.8,0);
	    	glVertex2f(2+20,19.9);
		glVertex2f(4.5+20,19.9);
	    	glVertex2f(4.1+20,9);
		glVertex2f(2.6+20,9);
	glEnd();
	glBegin(GL_POLYGON);//foot
		glColor3f(0.1,0.1,0.1);
		glVertex2f(2.6+20,9);
		glVertex2f(5+20,8);
		glVertex2f(5+20,7);
		glVertex2f(4+20,7);
		glVertex2f(2.6+20,6.8);
	glEnd();
	head(3.3+20,30,2.21);
	lips(4.2+20,29,0.4);
    	eye(4+20,31,0.4);
 	glBegin(GL_POLYGON);glColor3f(0.9411,0.7843,0.7372);
		glVertex2f(4.5+20,26.5);
		glVertex2f(8+20,26.5);
		glVertex2f(4.5+20,25);
		glVertex2f(7+20,25);
		glVertex2f(7+20,25);
		glVertex2f(7.5+20,26);
		glVertex2f(7.5+20,26);
		glVertex2f(7.9+20,25);
		glVertex2f(7.9+20,25);
		glVertex2f(8+20,26.5);
	glEnd();
}
float i;
void line()//line between the ground and sky in second screen
{
	glColor3f(0.6,0.9,0.9);
	glBegin(GL_POLYGON);
	glVertex2f(200,50);
	glVertex2f(200,400);
	glVertex2f(-100,400);
	glVertex2f(-100,50);
	glEnd();
	glFlush();

	glColor3f(0.5,0.2,0);//0.135,0.5618515,0
	glBegin(GL_POLYGON);
	glVertex2f(200,50);
	glVertex2f(200,-400);
	glVertex2f(-100,-400);
	glVertex2f(-200,50);
	glEnd();

}
void mouse(int btn,int state,int x,int y)//mouse function-from first page to second page
{
	if(btn==GLUT_LEFT_BUTTON&&state==GLUT_DOWN)
	{
		init();display2();
	}
}
void display2()//seed at the ground in the second screen
{	
	line();
	float i,k=2;
	float t=85,y=13;
	glPointSize(5.0);
    	glBegin(GL_POLYGON);//1lower
	k=1.2;
        t=50,y=20;
	glColor3f(0,0,0);
	for(i=0;i<=800;i=i+0.6)
	{
		glVertex2f(cos(i*3.14/360)*k+t,sin(i*3.14/360)*k*2+y);
	}
	glEnd();
	glBegin(GL_POLYGON);//2dupper
	k=1.2;
        t=50,y=24;
	glColor3f(0,0,0);
	for(i=0;i<=800;i=i+0.6)
	{
		glVertex2f(cos(i*3.14/360)*k+t,sin(i*3.14/360)*k*2+y);
	}
	glEnd();
	//glLineWidth(5);
	glBegin(GL_POLYGON);//3back
	k=2.0;
        t=50.3,y=22;
	glColor3f(0,0,0);
	for(i=0;i<=190;i=i+0.6)
	{
		glVertex2f(cos(i*3.14/360)*k+t,sin(i*3.14/360)*k*2+y);
	}
	glEnd();
	glBegin(GL_POLYGON);//3back
	k=2.0;
        t=50.3,y=21;
	glColor3f(0,0,0);
	for(i=0;i<=190;i=i+0.6)
	{
		glVertex2f(cos(i*3.14/360)*k+t,sin(i*3.14/360)*k*2+y);
	}
	glEnd();
	glBegin(GL_POLYGON);//3back
	k=2.0;
        t=50.3,y=20;
	glColor3f(0,0,0);
	for(i=0;i<=190;i=i+0.6)
	{
		glVertex2f(cos(i*3.14/360)*k+t,sin(i*3.14/360)*k*2+y);
	}
	glEnd();
	glBegin(GL_POLYGON);//3back
	k=2.0;
        t=49.5,y=19;
	glColor3f(0,0,0);
	for(i=0;i<=190;i=i+0.6)
	{
		glVertex2f(cos(i*3.14/360)*k+t,sin(i*3.14/360)*k*2+y);
	}
	glEnd();
	glBegin(GL_POLYGON);//3back
	k=1.0;
        t=51.3,y=22;
	glColor3f(0,0,0);
	for(i=0;i<=800;i=i+0.6)
	{
		glVertex2f(cos(i*3.14/360)*k+t,sin(i*3.14/360)*k*2+y);
	}
	glEnd();
	glBegin(GL_POLYGON);//3back
	k=1.0;
        t=51.3,y=21;
	glColor3f(0,0,0);
	for(i=0;i<=800;i=i+0.6)
	{
		glVertex2f(cos(i*3.14/360)*k+t,sin(i*3.14/360)*k*2+y);
	}
	glEnd();
	glBegin(GL_POLYGON);//3back
	k=1.0;
        t=50.9,y=20;
	glColor3f(0,0,0);
	for(i=0;i<=800;i=i+0.6)
	{
		glVertex2f(cos(i*3.14/360)*k+t,sin(i*3.14/360)*k*2+y);
	}
	glEnd();
	glColor3f(0.0,0.0,1.0);
	output(40,70,"press RIGHT mouse button");
	glFlush();
}
void display3()//third screen-seed after the rain-rocks and bushes
{
	line();
	float i,k=2;
	float t=85,y=13;
	glPointSize(5.0);
    	glBegin(GL_POLYGON);//1lower
	k=1.2;
        t=50,y=20;
	glColor3f(0,0,0);
	for(i=0;i<=800;i=i+0.6)
	{
		glVertex2f(cos(i*3.14/360)*k+t,sin(i*3.14/360)*k*2+y);
	}
	glEnd();
	glBegin(GL_POLYGON);//2dupper
	k=1.2;
        t=50,y=24;
	glColor3f(0,0,0);
	for(i=0;i<=800;i=i+0.6)
	{
		glVertex2f(cos(i*3.14/360)*k+t,sin(i*3.14/360)*k*2+y);
	}
	glEnd();
	//glLineWidth(5);
	glBegin(GL_POLYGON);//3back
	k=2.0;
        t=50.3,y=22;
	glColor3f(0,0,0);
	for(i=0;i<=190;i=i+0.6)
	{
	  glVertex2f(cos(i*3.14/360)*k+t,sin(i*3.14/360)*k*2+y);
	}
	glEnd();
	glBegin(GL_POLYGON);//3back
	k=2.0;
        t=50.3,y=21;
	glColor3f(0,0,0);
	for(i=0;i<=190;i=i+0.6)
	{
		glVertex2f(cos(i*3.14/360)*k+t,sin(i*3.14/360)*k*2+y);
	
	}
	glEnd();
	glBegin(GL_POLYGON);//3back
	k=2.0;
        t=50.3,y=20;
	glColor3f(0,0,0);
	for(i=0;i<=190;i=i+0.6)
	{
		  glVertex2f(cos(i*3.14/360)*k+t,sin(i*3.14/360)*k*2+y);
	}
	glEnd();
	glBegin(GL_POLYGON);//3back
	k=2.0;
        t=49.5,y=19;
	glColor3f(0,0,0);
	for(i=0;i<=190;i=i+0.6)
	{
		 glVertex2f(cos(i*3.14/360)*k+t,sin(i*3.14/360)*k*2+y);
	}
	glEnd();
	glBegin(GL_POLYGON);//3back
	k=1.0;
        t=51.3,y=22;
	glColor3f(0,0,0);
	for(i=0;i<=800;i=i+0.6)
	{
		glVertex2f(cos(i*3.14/360)*k+t,sin(i*3.14/360)*k*2+y);
	}
	glEnd();
	glBegin(GL_POLYGON);//3back
	k=1.0;
        t=51.3,y=21;
	glColor3f(0,0,0);
	for(i=0;i<=800;i=i+0.6)
	{
		glVertex2f(cos(i*3.14/360)*k+t,sin(i*3.14/360)*k*2+y);
	}
	glEnd();
	glBegin(GL_POLYGON);//3back
	k=1.0;
        t=50.9,y=20;
	glColor3f(0,0,0);
	for(i=0;i<=800;i=i+0.6)
	{
		  glVertex2f(cos(i*3.14/360)*k+t,sin(i*3.14/360)*k*2+y);
	}
	glEnd();
	glColor3f(0,1,0);glLineWidth(2);	
	glBegin(GL_POLYGON);
		glVertex2f(70,50);
		glVertex2f(71,50);
		glVertex2f(71,60);
		glVertex2f(70.5,50.5);
		glVertex2f(70,60);
	glEnd();
//rocks
	float m=3;
	float o=91,p=56;
	glPointSize(2.0);
	glBegin(GL_POLYGON);//c1
	for(i=0;i<=800;i=i+0.6)
	{	
		glColor3f(0.25,0.215,0.25);
		glVertex2f(cos(i*3.14/360)*m+o,sin(i*3.14/360)*m*2+p);
	}
    	glEnd();
	glBegin(GL_POLYGON);//c1
	o=100,p=56;
        for(i=0;i<=800;i=i+0.6)
	{
		glColor3f(0.25,0.215,0.25);
		glVertex2f(cos(i*3.14/360)*m+o,sin(i*3.14/360)*m*2+p);
	}
    	glEnd();
	o=97,p=56;
	glBegin(GL_POLYGON);
        for(i=0;i<=800;i=i+0.6)
	{
		  glColor3f(0.25,0.215,0.25);
		  glVertex2f(cos(i*3.14/360)*m+o,sin(i*3.14/360)*m*2+p);
	}
    	glEnd();
	o=97,p=60;
	glBegin(GL_POLYGON);
        for(i=0;i<=800;i=i+0.6)
	{
		  glColor3f(0.25,0.215,0.25);
		  glVertex2f(cos(i*3.14/360)*m+o,sin(i*3.14/360)*m*2+p);
	}
    	glEnd();
	o=94,p=60;
	glBegin(GL_POLYGON);
        for(i=0;i<=800;i=i+0.6)
	{
		  glColor3f(0.25,0.215,0.25);
		  glVertex2f(cos(i*3.14/360)*m+o,sin(i*3.14/360)*m*2+p);
	}
    	glEnd();
	glColor3f(0.0,1.0,0.0);
	glBegin(GL_POLYGON);
		
		glVertex2f(90,50);
		glVertex2f(91,50);
		glVertex2f(91,60);
		glVertex2f(90.5,50.5);
		glVertex2f(90,60);
	glEnd();
	glBegin(GL_POLYGON);
		
		glVertex2f(95,60);
		glVertex2f(96,60);
		glVertex2f(96,70);
		glVertex2f(95.5,60.5);
		glVertex2f(95,70);
	glEnd();
	clouds();
	glBegin(GL_LINES);//root
	glColor3f(0.6,0.2,0);
	for(i=0;i<=5;i++)
	{
		glVertex2f(50,20);
		glVertex2f(50+i,10);
	}
	glEnd();
	sun();
	glColor3f(0.0,0.0,1.0);
	output(40,80,"PRESS S for growth");glFlush();
}
float m=0;
void sun()//sun in the third screen
{
	float z,k=1.5;
	float t=85,y=13;
	glPointSize(5.0);
    	glBegin(GL_POLYGON);//sun
	k=5;
        t=70,y=80;
	glColor3f(0.8,0.9,0);
	for(z=0;z<=800;z=z+0.6)
	{
		glVertex2f((cos(z*3.14/360)*k+t),(sin(z*3.14/360)*k*2+y));
	}
	glEnd();
}
void display4()//final page with message
{
	line();
	float i,k=2;
	float t=85,y=13;
		glPointSize(5.0);
    	glBegin(GL_POLYGON);//1lower
	     k=1.2;
        t=50,y=20;
	glColor3f(0,0,0);
	for(i=0;i<=800;i=i+0.6)
	{
		glVertex2f(cos(i*3.14/360)*k+t,sin(i*3.14/360)*k*2+y);
	}
	glEnd();
	glBegin(GL_POLYGON);//2upper
	k=1.2;
        t=50,y=24;
	glColor3f(0,0,0);
	for(i=0;i<=800;i=i+0.6)
	{
		 glVertex2f(cos(i*3.14/360)*k+t,sin(i*3.14/360)*k*2+y);
	}
	glEnd();
	//glLineWidth(5);
	glBegin(GL_POLYGON);//3back
	k=2.0;
        t=50.3,y=22;
	glColor3f(0,0,0);
	for(i=0;i<=190;i=i+0.6)
	{
		glVertex2f(cos(i*3.14/360)*k+t,sin(i*3.14/360)*k*2+y);
	}
	glEnd();
	glBegin(GL_POLYGON);//3back
	k=2.0;
        t=50.3,y=21;
	glColor3f(0,0,0);
	for(i=0;i<=190;i=i+0.6)
	{
		  glVertex2f(cos(i*3.14/360)*k+t,sin(i*3.14/360)*k*2+y);
	}
	glEnd();
	glBegin(GL_POLYGON);//3back
	k=2.0;
        t=50.3,y=20;
	glColor3f(0,0,0);
	for(i=0;i<=190;i=i+0.6)
	{
		glVertex2f(cos(i*3.14/360)*k+t,sin(i*3.14/360)*k*2+y);
	}
	glEnd();
	glBegin(GL_POLYGON);//3back
	k=2.0;
        t=49.5,y=19;
	glColor3f(0,0,0);
	for(i=0;i<=190;i=i+0.6)
	{
		glVertex2f(cos(i*3.14/360)*k+t,sin(i*3.14/360)*k*2+y);
	}
	glEnd();
	glBegin(GL_POLYGON);//3back
	k=1.0;
        t=51.3,y=22;
	glColor3f(0,0,0);
	for(i=0;i<=800;i=i+0.6)
	{
		glVertex2f(cos(i*3.14/360)*k+t,sin(i*3.14/360)*k*2+y);
	}
	glEnd();
	glBegin(GL_POLYGON);//3back
	k=1.0;
        t=51.3,y=21;
	glColor3f(0,0,0);
	for(i=0;i<=800;i=i+0.6)
	{
		glVertex2f(cos(i*3.14/360)*k+t,sin(i*3.14/360)*k*2+y);
	}
	glEnd();
	glBegin(GL_POLYGON);//3back
	k=1.0;
        t=50.9,y=20;
	glColor3f(0,0,0);
	for(i=0;i<=800;i=i+0.6)
	{
		glVertex2f(cos(i*3.14/360)*k+t,sin(i*3.14/360)*k*2+y);
	}
	glEnd();
	glColor3f(0,1,0);glLineWidth(2);	
	glBegin(GL_POLYGON);
		glVertex2f(70,50);
		glVertex2f(70,70);
		glVertex2f(73,50);
		glVertex2f(73,70);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(50,26);
		glVertex2f(50,26.5);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(50,26.5);
		glVertex2f(50.5,28);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(50.5,28);
		glVertex2f(50,33);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(50,33);
		glVertex2f(51,37);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(51,37);
		glVertex2f(50,42);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(50,42);
		glVertex2f(50.5,44);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(50.5,44);
		glVertex2f(51,50);
	glEnd();
//left second
	glBegin(GL_LINES);
		glVertex2f(49.7,26);
		glVertex2f(49.7,28);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(49.7,28);
		glVertex2f(49.9,30);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(49.9,30);
		glVertex2f(49.6,33);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(49.6,33);
		glVertex2f(49.7,35);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(49.7,35);
		glVertex2f(50.6,38);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(50.6,38);
		glVertex2f(49.7,40);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(49.7,40);
		glVertex2f(49.6,42);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(49.6,42);
		glVertex2f(50,45);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(50,45);
		glVertex2f(50.3,50);
	glEnd();
//sampling starting left
	glColor3f(0,0,0);
	glBegin(GL_LINES);
		glVertex2f(50.3,50);
		glVertex2f(50.3,53);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(50.3,53);
		glVertex2f(50.5,54);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(50.5,54);
		glVertex2f(50.5,55);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(50.5,55);
		glVertex2f(50.3,56);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(50.3,56);
		glVertex2f(50,57);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(50,57);
		glVertex2f(50,58);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(50,58);
		glVertex2f(50.3,59);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(50.3,59);
		glVertex2f(50.5,62);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(50.5,62);
		glVertex2f(50,64);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(50,64);
		glVertex2f(50,70);
	glEnd();
//sampling right side
	glBegin(GL_LINES);
		glVertex2f(51,50);
		glVertex2f(51,53);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(51,53);
		glVertex2f(51.3,54);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(51.3,54);
		glVertex2f(51,56);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(51,56);
		glVertex2f(51,57);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(51,57);
		glVertex2f(51.3,59);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(51.3,59);
		glVertex2f(51,63);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(51,63);
		glVertex2f(51.3,65);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(51.3,65);
		glVertex2f(51,68);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(51,68);
		glVertex2f(51.2,70);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(51.2,70);
		glVertex2f(50,70);
	glEnd();
//leaf1
	glBegin(GL_LINES);
		glVertex2f(51.1,68);
		glVertex2f(53,69);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(53,69);
		glVertex2f(55.5,69.5);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(54,69.5);
		glVertex2f(54.3,70);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(51,68.2);
		glVertex2f(54,68.5);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(54,68.5);
		glVertex2f(56,68.6);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(56,68.6);
		glVertex2f(56.2,70);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(56.2,70);
		glVertex2f(56.5,72);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(51,68.2);
		glVertex2f(52,69);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(52,69);
		glVertex2f(53,71);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(53,71);
		glVertex2f(54,70.8);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(54,70.8);
		glVertex2f(55,71);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(55,71);
		glVertex2f(56.5,72);
	glEnd();
//leaf2 left
	glBegin(GL_LINES);
		glVertex2f(50,64);
		glVertex2f(48,66);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(48.3,66);
		glVertex2f(47,63);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(48.3,66);
		glVertex2f(45,67);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(48.7,66);
		glVertex2f(49,65);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(47,66);
		glVertex2f(46,64);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(48.3,66);
		glVertex2f(47.9,68.5);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(47.9,68.5);
		glVertex2f(47.5,68.4);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(47.5,68.4);
		glVertex2f(47.1,68.1);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(47.1,68.1);
		glVertex2f(46.8,67.9);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(46.8,67.9);
		glVertex2f(45.0,67.1);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(47,63);
		glVertex2f(46.5,62.6);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(46.5,62.6);
		glVertex2f(46.0,63);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(46.0,63);
		glVertex2f(45.0,67.1);
	glEnd();
//root
	glBegin(GL_LINES);//root
	glColor3f(0.6,0.2,0);
	for(i=0;i<=5;i++)
	{
		glVertex2f(50,20);
		glVertex2f(50+i,10);
	}
	glEnd();
	float m=3;
	float o=91,p=56;
	glPointSize(2.0);
	glBegin(GL_POLYGON);//c1
	for(i=0;i<=800;i=i+0.6)
	{
		glColor3f(0.25,0.215,0.25);
		glVertex2f(cos(i*3.14/360)*m+o,sin(i*3.14/360)*m*2+p);
	}
    	glEnd();
	glBegin(GL_POLYGON);//c1
	o=100,p=56;
        for(i=0;i<=800;i=i+0.6)
	{
		glColor3f(0.25,0.215,0.25);
		glVertex2f(cos(i*3.14/360)*m+o,sin(i*3.14/360)*m*2+p);
	}
    	glEnd();
	o=97,p=56;
	glBegin(GL_POLYGON);
        for(i=0;i<=800;i=i+0.6)
	{	
		glColor3f(0.25,0.215,0.25);
		glVertex2f(cos(i*3.14/360)*m+o,sin(i*3.14/360)*m*2+p);
	}
    	glEnd();
	o=97,p=60;
	glBegin(GL_POLYGON);
        for(i=0;i<=800;i=i+0.6)
	{
		glColor3f(0.25,0.215,0.25);
		glVertex2f(cos(i*3.14/360)*m+o,sin(i*3.14/360)*m*2+p);
	}
    	glEnd();
	o=94,p=60;
	glBegin(GL_POLYGON);
        for(i=0;i<=800;i=i+0.6)
	{
		glColor3f(0.25,0.215,0.25);
		glVertex2f(cos(i*3.14/360)*m+o,sin(i*3.14/360)*m*2+p);
	}
    	glEnd();
	glColor3f(0.0,1.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(90,50);
		glVertex2f(91,50);
		glVertex2f(91,60);
		glVertex2f(90.5,50.5);
		glVertex2f(90,60);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2f(95,60);
		glVertex2f(96,60);
		glVertex2f(96,70);
		glVertex2f(95.5,60.5);
		glVertex2f(95,70);
	glEnd();
	m=1.0,o=50,p=50;
	glBegin(GL_POLYGON);
        for(i=0;i<=800;i=i+0.6)
	{
	  glColor3f(0.25,0.215,0.25);
	  glVertex2f(cos(i*3.14/360)*m+o,sin(i*3.14/360)*m*2+p);
	}
    	glEnd();
	m=0.5,o=51,p=50;
	glBegin(GL_POLYGON);
        for(i=0;i<=800;i=i+0.6)
	{
	  glColor3f(0.25,0.215,0.25);
	  glVertex2f(cos(i*3.14/360)*m+o,sin(i*3.14/360)*m*2+p);
	}
    	glEnd();
	m=0.5,o=52,p=51;
	glBegin(GL_POLYGON);
        for(i=0;i<=800;i=i+0.6)
	{
	  glColor3f(0.25,0.215,0.25);
	  glVertex2f(cos(i*3.14/360)*m+o,sin(i*3.14/360)*m*2+p);
	}
    	glEnd();
	m=0.5,o=52,p=51;
	glBegin(GL_POLYGON);
        for(i=0;i<=800;i=i+0.6)
	{
	  glColor3f(0.25,0.215,0.25);
	  glVertex2f(cos(i*3.14/360)*m+o,sin(i*3.14/360)*m*2+p);
	}
    	glEnd();
	m=1,o=49,p=51;
	glBegin(GL_POLYGON);
        for(i=0;i<=800;i=i+0.6)
	{
		  glColor3f(0.45,0.215,0.25);
		  glVertex2f(cos(i*3.14/360)*m+o,sin(i*3.14/360)*m*2+p);
	}
    	glEnd();
	m=1,o=0,p=51;
	glBegin(GL_POLYGON);
        for(i=0;i<=800;i=i+0.6)
	{
	  glColor3f(0.45,0.215,0.25);
	  glVertex2f(cos(i*3.14/360)*m+o,sin(i*3.14/360)*m*2+p);
	}
    	glEnd();
	m=1.5,o=4,p=51;
	glBegin(GL_POLYGON);
        for(i=0;i<=800;i=i+0.6)
	{
	  glColor3f(0.45,0.415,0.25);
	  glVertex2f(cos(i*3.14/360)*m+o,sin(i*3.14/360)*m*2+p);
	}
    	glEnd();
	m=2,o=2,p=53;
	glBegin(GL_POLYGON);
        for(i=0;i<=800;i=i+0.6)
	{
	  glColor3f(0.45,0.215,0.25);
	  glVertex2f(cos(i*3.14/360)*m+o,sin(i*3.14/360)*m*2+p);
	}
    	glEnd();
	m=3,o=0,p=54;
	glBegin(GL_POLYGON);
        for(i=0;i<=800;i=i+0.6)
	{
	  glColor3f(0.45,0.215,0.25);
	  glVertex2f(cos(i*3.14/360)*m+o,sin(i*3.14/360)*m*2+p);
	}
    	glEnd();
	/*glColor3f(1,0.0,0.0);
	output(40,95,"SAVE PLANTS SAVE LIFE");
	glColor3f(1,0.0,0.0);
	output(37,90,"PLANT ONE SEED TODAY ITSELF");*/
	glColor3f(0.0,0.0,1.0);
	output(60,10,"press c for conclusion");
	glFlush();
}
void display5()//conclusion page
{
	init1();
	glBegin(GL_POLYGON);
	glColor3f(1.0,0.0,0.0);
		glVertex2f(35,30);
		glVertex2f(65,30);
		glVertex2f(65,80);
		glVertex2f(35,80);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1.0,1.0,1.0);
		glVertex2f(37,32);
		glVertex2f(67,32);
		glVertex2f(67,78);
		glVertex2f(37,78);
	glEnd();
	man2();
	glColor3f(0,0.0,0.0);
	output(49,70,"-PLEDGE-");
	glColor3f(0.0,0.0,1.0);
	output(40,64,"I will save and protect my greenary");
	output(40,60,"for my coming generation.");
	glColor3f(0.0,0.0,1.0);
	output(40,55,"I will plant");
	output(40,50,"one seed today itself");
	glColor3f(0.0,0.0,1.0);
	output(60,10,"press RIGHT mouse button for exit/goback");
	glFlush();
}
	
void display()//rain
{
	display2();
	i+=0.05;//move in decrements of 0.1 in x- axis
	glBegin(GL_LINES);
	if(i<50)
	{
	glColor3f(0,0,1);
	glVertex2f(10,100-i);//decrement x values keeping y constant
	glVertex2f(10,95-i);
	glVertex2f(20,100-i);//decrement x values keeping y constant
	glVertex2f(20,95-i);
	glVertex2f(30,100-i);//decrement x values keeping y constant
	glVertex2f(30,95-i);
	glVertex2f(10,50-i);//decrement x values keeping y constant
	glVertex2f(10,55-i);
	glVertex2f(30,50-i);//decrement x values keeping y constant
	glVertex2f(30,55-i);
	glVertex2f(40,70-i);//decrement x values keeping y constant
	glVertex2f(40,75-i);
	glVertex2f(70,35-i);//decrement x values keeping y constant
	glVertex2f(70,40-i);

	glVertex2f(50,100-i);//decrement y values keeping y constant
	glVertex2f(50,99-i);
	glVertex2f(60,100-i);//decrement y values keeping y constant
	glVertex2f(60,98-i);
	glVertex2f(80,100-i);//decrement y values keeping y constant
	glVertex2f(80,97-i);
	glVertex2f(55,50-i);//decrement y  values keeping y constant
	glVertex2f(55,59-i);
	glVertex2f(75,50-i);//decrement y values keeping y constant
	glVertex2f(75,56-i);
	glVertex2f(65,70-i);//decrement  y values keeping y constant
	glVertex2f(65,77-i);
	glVertex2f(52,35-i);//decrement y values keeping y constant
	glVertex2f(52,48-i);


	glVertex2f(52,100-i);//decrement y values keeping x constant
	glVertex2f(52,98-i);
	glVertex2f(67,100-i);//decrement y values keeping x constant
	glVertex2f(67,98-i);
	glVertex2f(82,100-i);//decrement y values keeping x constant
	glVertex2f(82,97-i);
	glVertex2f(59,50-i);//decrement y values keeping x constant
	glVertex2f(59,59-i);
	glVertex2f(72,50-i);//decrement y values keeping x constant
	glVertex2f(72,56-i);
	glVertex2f(61,70-i);//decrement y values keeping x constant
	glVertex2f(61,77-i);
	glVertex2f(58,35-i);//decrement y values keeping x constant
	glVertex2f(58,48-i);
	
	glVertex2f(32,100-i);//decrement y values keeping x constant
	glVertex2f(32,98-i);
	glVertex2f(27,100-i);//decrement y values keeping x constant
	glVertex2f(27,98-i);
	glVertex2f(12,100-i);//decrement y values keeping x constant
	glVertex2f(12,97-i);
	glVertex2f(29,50-i);//decrement y values keeping x constant
	glVertex2f(29,59-i);
	glVertex2f(23,50-i);//decrement y values keeping x constant
	glVertex2f(23,56-i);
	glVertex2f(11,70-i);//decrement y values keeping x constant
	glVertex2f(11,77-i);
	glVertex2f(8,35-i);//decrement y values keeping x constant
	glVertex2f(8,48-i);
	blackclouds();
	int b=0;
	glutPostRedisplay();
	}
	else
	{
		glFlush();display2();glFlush();sunnyday();glFlush();
	}
	glEnd();
	glFlush();
}
void sunnyday()//for lighting effect
{
	init();
	display3();
}
void keys(unsigned char key,int x,int y)//keboard function
{
	if(key=='p' || key=='P')//from front page to first page
	{	
		init();
		draw();
		man();
	}
	if(key=='s' || key=='S')//from third page to fourth page
	{	
		init();
		display4();
	}
	if(key=='c' || key=='C')//from third page to fourth page
	{	
		//init();
		glutDisplayFunc(display5);
		display5();
	}
}
void display1(void)//front page
{
	myinit();
	glClearColor(0.7,0.7,0.9,0);
	glBegin(GL_LINES);
	glColor3f(0.135,0.5618515,0);
		glVertex2f(12,3);
		glVertex2f(7,3);
	glEnd();
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,0.0,0.0);
	output(16,5,"K.S INSTITUTE OF TECHNOLOGY");
	glColor3f(1.0,1.0,1.0);
	output(14.5,11,"MINI PROJECT ON");
	output(16.5,8,"COMPUTER GRAPHICS AND VISUALIZATION");
	glColor3f(1.0,1.3,0.0);
	output(14.7,13,"SEED GERMINATION");
	glColor3f(0.3,0.5,0.5);
	output(23,21,"SHASHWATH G M -1KS15CS092");
	output(7,17,"PROJECT GUIDE");
	output(7,18,"----------------");
	output(7,19,"Mrs.VIJAYALAKSHMI MEKALI");
	glColor3f(0.01,0.01,0.5);
	output(15,23,"PRESS p for PLANT THE SEED");
	glFlush();
}	 
void myinit()//initialization for the first page
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.9564,0.9546,0.99999,0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
    	gluOrtho2D (24.0, 0.0,24.0, 0.0);
    	glMatrixMode(GL_MODELVIEW);
}
void init()//initialization for the rest pages
{
  	glClearColor(0,0.6,0.9,0.9);
 	glClear(GL_COLOR_BUFFER_BIT);
  	glMatrixMode (GL_PROJECTION);
  	glLoadIdentity ();
  	gluOrtho2D(0,100,0,100);
  	glMatrixMode (GL_MODELVIEW);
  	glLoadIdentity ();
}
void init1()//initialization for the conclusion page
{
  	glClearColor(0,0.8,0.0,0.9);
 	glClear(GL_COLOR_BUFFER_BIT);
  	glMatrixMode (GL_PROJECTION);
  	glLoadIdentity ();
  	gluOrtho2D(0,100,0,100);
  	glMatrixMode (GL_MODELVIEW);
  	glLoadIdentity ();
}
//menu function
void menuFunc(int sel)
{
	switch(sel)
	{
	case 1:init();glutDisplayFunc(display);  break;
	case 2:myinit();glutDisplayFunc(display1);  break;
	case 5: exit(0);
	}
	glutPostRedisplay();
}
void makemenu()
{
	myinit();
	glutCreateMenu(menuFunc);
	glutAddMenuEntry("RAIN & LIGHTING",1);
	glutAddMenuEntry("GO Back",2);
	glutAddMenuEntry("Quit",5);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}
int main(int argc,char **argv)//main function
{
     	glutInit(&argc,argv);
     	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50,50);
	glutInitWindowSize(1250,700);
	glutCreateWindow("project");
	myinit();
	glutDisplayFunc(display1);
	glutKeyboardFunc(keys);
	glutMouseFunc(mouse);
	makemenu();
	glutMainLoop();
	return 0;
}
