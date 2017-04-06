
#define GLUT_DISABLE_ATEXIT_HACK
#include <windows.h>
#include<GL/glut.h>
#include <stdlib.h>
#include <math.h>
//user for the basket 
GLUquadricObj *zz;
//delear the menu
int menu,lmenu; 
//declear of the material of the body 
float no_mat[] = {0.0f, 0.0f, 0.0f, 1.0f};
float no_mat1[] = {0.6f, 0.7f, 0.0f, 1.0f};
float mat_ambient[] = {1.0f, 0.0f, 0.0f, 1.0f};
float mat_ambient_shoulder[] = {0.8f, 0.7f, 0.6f, 1.0f};
float mat_ambient_hip[] = {1.0f, 0.0f, 0.0f, 1.0f};
float mat_ambient_color[] = {0.8f, 0.7f, 0.6f, 1.0f};

float mat_ambient1[] = {1.0f, 0.9f, 0.8f, 1.0f};
float mat_ambient2[] = {1.0f, 1.0f, 1.0f, 1.0f};

float mat_diffuse[] = {0.8f, 0.7f, 0.6f, 1.0f};
float mat_diffuse1[] = {0.0f, 0.0f, 0.0f, 1.0f};
float mat_specular[] = {0.8f, 0.7f, 0.6f, 1.0f};
float no_shininess[] = {0.0f};
float low_shininess []= {5.0f};
float high_shininess []= {100.0f};
float mat_emission[] = {0.3f, 0.2f, 0.2f, 0.0f};

//declear some flag that is used to move the robot up/down
float uper = 0,gaodu = 0;
double x = 0.0;
//declear the flag and angle that is used for rotation 
static int angle = 0, angle1 = 0, neck = 0, lshoulder = 0, lelbow = 0, rshoulder = 0, relbow = 0, lft = 0, rft=0,brt=0,
lhips = 0, rhips = 0, lfoot = 0, rfoot = 0, flagneck = 0, flaglshoulder = 0,t=0, cdflag=0, rflag=0, dflag=0,dkflag=1; 
flaglelbow = 0, flagrshoulder = 0, flagrelbow = 0, flaglhips = 0,
flagrhips = 0, flaglfoot = 0, flagrfoot = 0,flag = 0,flaglft = 1,flagrft = 1;//rotate motion

//initialization function,declear 3 different light including sunlight, white soptlight, red spotlight and yellow spotlight 
void init(void)
{
    GLfloat ambient[]	= { 0.2, 0.2, 0.2, 1.0 };
    GLfloat diffuse[]	= { 0.4, 0.4, 0.4, 1.0 };
    GLfloat position[]	= { 3.0, 10.0, 4.0, 1.0 };
    GLfloat specular[]  = {0.5 , 0.5 , 0.5 , 0.0};
    
    
    
    glClearColor(0.2,0.2,0.2,0.2);
    
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
    
    
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);

   
   
   GLfloat ambientLight[] = {0.8f, 0.8f, 0.8f, 1.0f};
   GLfloat ambientLight2[] = {0.9f, 0.1f, 0.1f, 1.0f};
   GLfloat ambientLight3[] = {0.7f, 0.7f, 0.1f, 1.0f};
	GLfloat lightPos1[] = {0.0f, 16.0f, 0.0f, 1.0f};
 	GLfloat specular1[] = {1.0f, 1.0f, 1.0f, 1.0f};
 	GLfloat specref[] = {1.0f, 1.0f, 1.0f, 1.0f};
 	GLfloat spotDir[] = {-2.0f, 0.0f, -2.0f};

      glLightfv(GL_LIGHT1,GL_DIFFUSE,ambientLight);
      glLightfv(GL_LIGHT1,GL_SPECULAR,specular1);
      glLightfv(GL_LIGHT1,GL_POSITION,lightPos1);
       glLightfv(GL_LIGHT1,GL_SPOT_DIRECTION,spotDir);
      glLightf(GL_LIGHT1,GL_SPOT_CUTOFF,60.0f);
      
       glLightfv(GL_LIGHT2,GL_DIFFUSE,ambientLight2);
      glLightfv(GL_LIGHT2,GL_SPECULAR,specular1);
      glLightfv(GL_LIGHT2,GL_POSITION,lightPos1);
       glLightfv(GL_LIGHT2,GL_SPOT_DIRECTION,spotDir);
      glLightf(GL_LIGHT2,GL_SPOT_CUTOFF,60.0f);
      
       glLightfv(GL_LIGHT3,GL_DIFFUSE,ambientLight3);
      glLightfv(GL_LIGHT3,GL_SPECULAR,specular1);
      glLightfv(GL_LIGHT3,GL_POSITION,lightPos1);
    glLightfv(GL_LIGHT3,GL_SPOT_DIRECTION,spotDir);
      glLightf(GL_LIGHT3,GL_SPOT_CUTOFF,60.0f);
      
      
   
}
//draw the body of the robot, it's a cube.
void draw_body(void)
{
    glPushMatrix();
    glTranslatef(0,1.5+uper*0.15,0);
    glScalef(0.5,1,0.4);
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
    glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);

    glutSolidCube(4);
    glScalef(1/0.5,1,1/0.4);
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient2);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_ambient2);
    glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
    glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
    glTranslatef(0.1,0,0.8);
	glScalef(0.1,0.8,0.1);
    glutSolidCube(2);
    glScalef(1/0.1,1/0.8,1/0.1);
    glTranslatef(0.5,0,0);
    glScalef(0.1,0.8,0.1);
    glutSolidCube(2);
    glScalef(1/0.1,1/0.8,1/0.1);
    glTranslatef(0.0,0,-1.6);
    glScalef(0.1,1.5,0.1);
    glutSolidCube(2);
    glScalef(1/0.1,1/1.5,1/0.1);
    glTranslatef(-0.8,0,0);
    glScalef(0.1,1.5,0.1);
    glutSolidCube(2);
    
    glPopMatrix();
}
//draw the left shoulder of the robot
void draw_leftshoulder(void)
{
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_AMBIENT,  mat_ambient_shoulder);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
    glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
   
    glTranslatef(1.5, 3+uper*0.15,0);
    glRotatef(lshoulder, 1, 0, 0);
    
    glTranslatef(0, -0.9, 0);
    glScalef(0.6, 1.3, 0.4);
    glutSolidCube(2);
    
    glScalef(1 / 0.6, 1 / 1.3, 1 / 0.4);
    glTranslatef(0, -1.4, 0);
    glRotatef(lelbow, 1,0, 40);
    glutWireSphere(0.4, 200, 500);
    
   
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_color);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
    glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
   
    
    glScalef(0.4, 1*1.3, 0.5);
    glTranslatef(0, -1.4, 0);
    glutSolidCube(2);
    
    glScalef(0.7, 0.5, 0.4);
    glTranslatef(0, -3, 0);
    glutSolidCube(2);

    glPopMatrix();
}
//draw the right shoulder of the robot
void draw_rightshoulder(void)
{
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_AMBIENT,  mat_ambient_shoulder);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
    glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
    glTranslatef(-1.5,2.7+uper*0.15,0);
    glRotatef(rshoulder,1,0,0);
    
    glTranslatef(0,-0.5,0);
    glScalef(0.6, 1.3, 0.4);
    glutSolidCube(2);
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_color);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
    glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
    glScalef(1 / 0.6, 1 / 1.3, 1 / 0.4);
    glTranslatef(0,-1.4,0);
    glRotatef(relbow,1,0,0);
    glutWireSphere(0.4,200,500);
    
    glScalef(0.4,1.3,0.5);
    glTranslatef(0,-1.4,0);
    glutSolidCube(2);
    
    glScalef(0.7, 0.5, 0.4);
    glTranslatef(0, -3, 0);
    glutSolidCube(2);
    
    glTranslatef(0,3.5,0);
    glRotatef(neck,0,0,1);
    glTranslatef(0,1,0);
    glutSolidCube(1.4);

    glPopMatrix();
}

//draw the head and hair of the robot

void draw_head(void)
{
    glPushMatrix();
 
    
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_color);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
    glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
    
    glTranslatef(0,3+uper*0.15,0);
    glTranslatef(0,1,0);
    glScalef(0.7,0.6,0.6);
    glRotatef(neck,0,0,1);
  //  glutWireSphere(1,50,50);
  	glutSolidCube(2);
  	
  	glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse1);
    glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
    glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
    
    glTranslatef(0.6,0.3,1.2);
    glutWireSphere(0.1,50,50);
    glTranslatef(-0.6,0,0);
    glutWireSphere(0.1,50,50);
    glTranslatef(0,-0.7,0);
    glScalef(0.7,0.1,0.2);
    glutSolidCube(1);
    glScalef(1/0.7,1/0.1,1/0.2);
    glTranslatef(0,0.4,-1.2);
   
    
    glTranslatef(0,1,0);
    glScalef(1,0.5,1);
  //  glutWireSphere(1,50,50);
  
   
  	glColor3f(1.0f,1.0f,1.0f);
  	glutSolidCube(1.4);
    
    glPopMatrix();
}
//draw leftfoot of the robot
void draw_leftfoot(void)
{
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_hip);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
    glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
    
    glTranslatef(-0.6,-0.7,0);
    glRotatef(lfoot,1,0,0);
    glTranslatef(0,-0.7+uper*0.3,uper*0.1);
    glScalef(0.5,1.5,0.5);
    glutSolidCube(2);
    
    glScalef(1/0.5,1/1.5,1/0.5);
   //  glScalef(1,1.7,1); 
    glTranslatef(0,-1.5,0);
    glRotatef(lhips,1,0,0);
    glutWireSphere(0.4,200,500);
   
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_color);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
    glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
    
    
    glTranslatef(0,-1.9,0);
    glScalef(0.4,1.5,0.5);
    glutSolidCube(2);
    glScalef(1/0.4,1/1.5,1/0.5); 
    
    
   
   
    glTranslatef(0,-1.35,0.4);
     glRotatef(lft,1,0,0);
    glScalef(0.4,0.15,1);
    
     glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
    glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
    
    glutSolidCube(2);
   
    glPopMatrix();
}
//draw right foot of the robot
void draw_rightfoot(void)
{
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_hip);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
    glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
    
    glTranslatef(0.6,-0.7,0);
    glRotatef(rfoot,1,0,0);
    glTranslatef(0,-0.7+uper*0.3,uper*0.1);
    glScalef(0.5,1.5,0.5);
    glutSolidCube(2);
    
    glScalef(1/0.5,1/1.5,1/0.5);
    glTranslatef(0,-1.5,0);
    glRotatef(rhips,1,0,0);
    glutWireSphere(0.4,200,500);
    
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_color);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
    glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
    
    glTranslatef(0,-1.9,0);
    glScalef(0.4,1.5,0.5);
    glutSolidCube(2);
    
    glScalef(1/0.4,1/1.5,1/0.5); 
   
    glTranslatef(0,-1.35,0.4);
     glRotatef(rft,1,0,0);
    glScalef(0.4,0.15,1);
    
     glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
    glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
   
    glutSolidCube(2);
     
    
    glPopMatrix();
}
//draw a basket stands
void draw_basket(void){
	glPushMatrix();
	zz = gluNewQuadric();
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient1);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
    glTranslatef(0,10,9);
    glScalef(0.1,2.4,0.1);
    glutSolidCube(10);
    glScalef(1/0.1,1/2.4,1/0.1);
    glTranslatef(0,12,0.3);
    glRotatef(90,1,0,0);
    glTranslatef(0,-1.8,3.5+brt);
    gluCylinder (zz, 1.3, 1.0, 3.0, 32, 32);
	glPopMatrix();
}
//display function declearation
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glPushMatrix();
     
     
    glRotatef(angle,0,1,0);
    draw_basket();
 
    glTranslatef(0,4+gaodu,0+x);
    glRotatef(angle1,0,1,0);
    draw_body();
    
    draw_head();

    
    draw_leftshoulder();
    draw_rightshoulder();
    
    draw_leftfoot();
    draw_rightfoot();
   
    glPopMatrix();
    glutSwapBuffers();
}

void reshape(int w,int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-20,20,-20,20,-20,20);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt (8.0, 8.0, 6, 0.0, 4, 0.0, 0.0, 1.0, 0.0);
}
//declear the key function to enable and disable different types of light
void keyboard(unsigned char key,int x,int y)
{
    
        if(key=='w'|key=='W'){
        
        	glDisable(GL_LIGHT0);
        	glDisable(GL_LIGHT1);
        	glDisable(GL_LIGHT2);
        	glDisable(GL_LIGHT3);
        	glEnable(GL_LIGHT1);
        	glutPostRedisplay();
        	
        }
        if(key=='r'|key=='R'){
        
        	glDisable(GL_LIGHT0);
        	glDisable(GL_LIGHT1);
        	glDisable(GL_LIGHT2);
        	glDisable(GL_LIGHT3);
        	glEnable(GL_LIGHT2);
        	glutPostRedisplay();
       
        }
        if(key=='y'|key=='Y'){
        
        	glDisable(GL_LIGHT0);
        	glDisable(GL_LIGHT1);
        	glDisable(GL_LIGHT2);
        	glDisable(GL_LIGHT3);
        	glEnable(GL_LIGHT3);
        	glutPostRedisplay();
      
        }
	
}
void idle(void){
	//preparing motion
		if(dkflag==1){
  		if(flag==0){
    	  	lfoot-=1;
        	lhips+=2;
        	rfoot-=1;
        	rhips+=2;
        	  if(lelbow!=-85){
        	  
        		lshoulder-=15;
        	    lelbow-=17;
      		  }
      		  if(rshoulder!=-27*6){
      		  
        	   rshoulder-=27;
        	   relbow-=10;
      		  }
        	  	uper-=0.1;
        	  	rft-=1;
        	  	lft-=1;
        	    glutPostRedisplay();
        	if(lfoot<=-30)flag=1;
			 //rise+dunk
			  }else if(flag==1){
			  	if(lfoot<=0){
					lfoot+=5;
		        	lhips-=7;
					lft+=5;
				   }
        		if(rfoot<=0){
					rfoot+=5;
		        	rhips-=7;
		        	rft+=5;
		        	 
      		  }
        	  if(uper>0)uper+=0.2;
        	  else uper=0;
			  if(gaodu<10.5){
			  	gaodu+=1.4-0.1*t; 
			  	t++;
			  
			  	}
			  		
			  		if(gaodu>10.5){
			  			if(angle<80)angle=(angle+2)%360;
			  		if(relbow<-20){
			  			relbow+=2;
			  			rshoulder+=3;
			  		}
			  			brt+=0.2;
			  		if(brt=0.8)brt=0;
			  		if(relbow>=-20){
					  
					  
					
					  if(angle>=80)flag=2;
					  }
			  		} 
			  		}
			  //launch
			  	else if(flag==2){
				  	if(gaodu>0)
					  {	
					  		gaodu+=1.4-0.05*t; 
				  			t++;
				  		}
				   if(lfoot<0)lfoot+=2.5;
        	  if(lhips>0)lhips-=5;
        	  if(rfoot<0)rfoot+=2.5;
        	  if(rhips>0)rhips-=5;
        	  if(lelbow!=0){
        	  
        		lshoulder+=3;
        	  	lelbow+=5;
      		  }
      		  if(rshoulder<=0)
      		  
        	   rshoulder+=5;
        	 
      		  
      		  if(relbow<=0) relbow+=5;
        	  
        	  	rft=0;
        	  	lft=0;
        	     //re initialization
				  if(gaodu<=0){
				  	uper = 0,gaodu = 0;
				  	angle = 0, neck = 0, lshoulder = 0, lelbow = 0, rshoulder = 0, relbow = 0, lft = 0, rft=0,
					lhips = 0, rhips = 0, lfoot = 0, rfoot = 0, flagneck = 0, flaglshoulder = 0,t=0,
					flaglelbow = 0, flagrshoulder = 0, flagrelbow = 0, flaglhips = 0,brt=0,
					flagrhips = 0, flaglfoot = 0, flagrfoot = 0,flag = 0,flaglft = 1,flagrft = 1;
				  }
				  
				  }
			  	 glutPostRedisplay();
			
        }
		
}

//create a menu for change the material of robot 
void GetCurrentMenu(void)
{
int nMenu;
nMenu=glutGetMenu();
if(nMenu == menu)
 1;
}
//create a right mouse menu
void MenuFunc(int data)
{
	GetCurrentMenu();
	switch(data)
	{
		//enable sun light
		case 1:
		 glDisable(GL_LIGHT0);
        	glDisable(GL_LIGHT1);
        	glDisable(GL_LIGHT2);
        	glDisable(GL_LIGHT2);
        	glEnable(GL_LIGHT0);
        	glutPostRedisplay();
		
		break;
		//enable white spotlight
		case 2:
			glDisable(GL_LIGHT0);
        	glDisable(GL_LIGHT1);
        	glDisable(GL_LIGHT2);
        	glDisable(GL_LIGHT3);
        	glEnable(GL_LIGHT1);
        	glutPostRedisplay();
		if(dflag==0){
			uper = 0,gaodu = 0;
			angle = 0, neck = 0, lshoulder = 0, lelbow = 0, rshoulder = 0, relbow = 0, lft = 0, rft=0,
			lhips = 0, rhips = 0, lfoot = 0, rfoot = 0, flagneck = 0, flaglshoulder = 0,t=0,
			flaglelbow = 0, flagrshoulder = 0, flagrelbow = 0, flaglhips = 0,brt=0,
			flagrhips = 0, flaglfoot = 0, flagrfoot = 0,flag = 0,flaglft = 1,flagrft = 1;
				  }
				  	 glutPostRedisplay();
		break;
		//enable/disable the motion
		case 3:
			dkflag=!dkflag;
			if(dkflag==0){
				    uper = 0,gaodu = 0;
				    angle = 0, neck = 0, lshoulder = 0, lelbow = 0, rshoulder = 0, relbow = 0, lft = 0, rft=0,
					lhips = 0, rhips = 0, lfoot = 0, rfoot = 0, flagneck = 0, flaglshoulder = 0,t=0,
					flaglelbow = 0, flagrshoulder = 0, flagrelbow = 0, flaglhips = 0,brt=0,
					flagrhips = 0, flaglfoot = 0, flagrfoot = 0,flag = 0,flaglft = 1,flagrft = 1;
				  }
				  	 glutPostRedisplay();
			break;
		//disable all the light
		case 4:
			glDisable(GL_LIGHT0);
        	glDisable(GL_LIGHT1);
        	glDisable(GL_LIGHT2);
        	glDisable(GL_LIGHT3);
        	glutPostRedisplay();
			
			  	
			
	}
}
//create a menu used to control the material of robot
void LMenuFunc(int data)
{
	GetCurrentMenu();
	switch(data)
	{
		case 1:
			mat_ambient[0] = 1.0f;
			mat_ambient[1] = 0.0f;
			mat_ambient[2] = 0.0f;
			mat_ambient[3] = 0.0f;
			
			mat_ambient_shoulder[0] = 0.8f;
			mat_ambient_shoulder[1] = 0.7f;
			mat_ambient_shoulder[2] = 0.6f;
			mat_ambient_shoulder[3] = 0.5f;
			
			mat_ambient_hip[0] = 1.0f;
			mat_ambient_hip[1] = 0.0f;
			mat_ambient_hip[2] = 0.0f;
			mat_ambient_hip[3] = 0.0f;
			
			mat_ambient2[0]=1.0f;
			mat_ambient2[1]=1.0f;
			mat_ambient2[2]=1.0f;
			mat_ambient2[3]=1.0f;
			glutPostRedisplay();
		break;
		case 2:
			mat_ambient[0] = 0.9f;
			mat_ambient[1] = 0.8f;
			mat_ambient[2] = 0.9f;
			mat_ambient[3] = 0.8f;
			
			mat_ambient_shoulder[0] = 0.8f;
			mat_ambient_shoulder[1] = 0.7f;
			mat_ambient_shoulder[2] = 0.6f;
			mat_ambient_shoulder[3] = 0.5f;
			
			mat_ambient_hip[0] = 0.9f;
			mat_ambient_hip[1] = 0.8f;
			mat_ambient_hip[2] = 0.9f;
			mat_ambient_hip[3] = 0.8f;
			
			mat_ambient2[0] = 1.0f;
			mat_ambient2[1] = 0.0f;
			mat_ambient2[2] = 0.0f;
			mat_ambient2[3] = 0.0f;
			glutPostRedisplay();
		 break;
		case 3:
			mat_ambient[0] = 1.0f;
			mat_ambient[1] = 0.2f;
			mat_ambient[2] = 0.2f;
			mat_ambient[3] = 0.6f;
			
			mat_ambient_shoulder[0] = 1.0f;
			mat_ambient_shoulder[1] = 0.2f;
			mat_ambient_shoulder[2] = 0.2f;
			mat_ambient_shoulder[3] = 0.6f;
			
			mat_ambient2[0] = 0.6f;
			mat_ambient2[1] = 0.4f;
			mat_ambient2[2] = 0.1f;
			mat_ambient2[3] = 0.2f;
			
			mat_ambient_hip[0] = 0.8f;
			mat_ambient_hip[1] = 0.8f;
			mat_ambient_hip[2] = 0.8f;
			mat_ambient_hip[3] = 1.0f;
			
			glutPostRedisplay();
		break;
	
			
			  	
			
	}
}
//main function,declearation of different menu
int main(int argc,char** argv)
{
   
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RED| GLUT_DEPTH);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(100,100);
    glutCreateWindow(argv[0]);
    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutIdleFunc(idle);
  
	menu = glutCreateMenu(MenuFunc);
	
	glutAddMenuEntry("sun light",1);
	glutAddMenuEntry("spot light",2);
	glutAddMenuEntry("change motion status",3);
	glutAddMenuEntry("no light",4);
	glutAttachMenu(GLUT_RIGHT_BUTTON); 
	lmenu = glutCreateMenu(LMenuFunc);
	glutAddMenuEntry("change cloth 1",1);
	glutAddMenuEntry("change cloth 2",2);
	glutAddMenuEntry("change cloth 3",3);
	glutAttachMenu(GLUT_LEFT_BUTTON); 
    glutMainLoop();
    glEnable(GL_DEPTH_TEST);
    return 0;
}

