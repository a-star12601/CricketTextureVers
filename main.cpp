#include<GL/glut.h>
#include<windows.h>
#include<mmsystem.h>
#include<stdio.h>

void display();
void display2();
void reshape(int,int);

void timer(int);
void mySpecialFunc(int,int, int);
void drawText(int x,int y,char text[],int len);
void intro();
void intro2();
void dispcase(int);
void keys(unsigned char key,int x,int y);
void timer2(int);
void createGLUTMenus();
void processMenuEvents(int);

int disp=0,barm=0,actarm=0;
float dist=40,jump=0;
float f1=0, f2=0.023, f3=0.839;

void init(void)
{
GLfloat mat_specular[] = { 1,1,1,1};
   GLfloat mate[] = { 0,0,0,1 };
   GLfloat light_position[] = { 0, 10.0, 10.0, 0.0 };
   GLfloat acolor[] = { 0,0,0,1 };
   GLfloat dcolor[] = { 1,1,1,1 };
   GLfloat scolor[] = { 1,1,1,1 };
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_SMOOTH);

   glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_specular);
   glMaterialfv(GL_FRONT, GL_EMISSION,mate);
   glLightfv(GL_LIGHT0, GL_POSITION, light_position);
   glLightfv(GL_LIGHT0, GL_AMBIENT, acolor);
   glLightfv(GL_LIGHT0, GL_DIFFUSE, dcolor);
   glLightfv(GL_LIGHT0, GL_SPECULAR, scolor);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE);
   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);
   glEnable(GL_DEPTH_TEST);
}
int main(int argc,char**argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowSize(1200,700);

    glutCreateWindow("Cricket Project");

    glutReshapeFunc(reshape);
    glutSpecialFunc(mySpecialFunc);
    glutKeyboardFunc(keys);
    glutDisplayFunc(intro);
    createGLUTMenus();
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
}

void createGLUTMenus() {

	int menu;
	menu = glutCreateMenu(processMenuEvents);

	glutAddMenuEntry("Pakistan",1);
	glutAddMenuEntry("New Zealand",2);
	glutAddMenuEntry("Australia",3);
	glutAddMenuEntry("West Indies",4);
	glutAddMenuEntry("England",5);
	glutAddMenuEntry("South Africa",6);
	glutAddMenuEntry("Sri Lanka",7);

	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void processMenuEvents(int option) {

	switch (option) {
		case 1: f1=0;
                    f2=0.4;
                    f3=0.054;
                    break;
		case 2: f1=0.2;
                    f2=0.2;
                    f3=0.2;
                    break;
		case 3: f1=0.913;
                    f2=0.803;
                    f3=0.254;
                    break;
		case 4: f1=0.619;
                    f2=0.011;
                    f3=0;
                    break;
		case 5: f1=0.031;
                    f2=0;
                    f3=0.458;
                    break;
		case 6: f1=0.066;
                    f2=0.839;
                    f3=0;
                    break;
        default:f1=0.;
                    f2=0.023;
                    f3=0.839;
                    break;
	}
}
int scene=0;

void keys(unsigned char key,int x,int y ){
    if(key==13){
    switch(scene){
    case 0: glutDisplayFunc(intro2);
                 break;
    case 1: glutDisplayFunc(intro2);
                 break;
    case 2:PlaySound(TEXT("India.wav"),NULL,SND_ASYNC);
                glutDisplayFunc(display2);
                glutTimerFunc(0,timer2,0);
                break;
    default:exit(0);
    }

    scene<2?scene++:1;
     glutPostRedisplay();
     }
     else if(key==27){
    scene!=0?scene--:1;
    switch(scene){
    case 0: glutDisplayFunc(intro);
                 break;
    case 1: glutDisplayFunc(intro2);
                 break;
    case 2:
        glutDisplayFunc(display);
                glutTimerFunc(0,timer,0);
                break;
    default:exit(0);
    }
     glutPostRedisplay();
     }
}



void intro(){
     glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
        glPushMatrix();
            glColor3f(0.498, 0, 1);
            glTranslatef(0,0,-41);
            glBegin(GL_QUADS);
            glVertex3f(-50,50,0);
            glVertex3f(50,50,0);
            glColor3f(0.882, 0, 1);
            glVertex3f(50,-50,0);
            glVertex3f(-50,-50,0);
        glEnd();
        glPopMatrix();
    glColor3f(1,1,1);
    drawText(300,500,"Cricket 3D",10);
    drawText(200,400,"USN",3);
    drawText(400,400,"Name",4);
    drawText(200,350,"4NM19CS144",10);
    drawText(400,350,"R Anuroop",10);
    drawText(200,300,"4NM19CS164",10);
    drawText(400,300,"Sabarinath",10);
    drawText(270,190,"Under the guidance of",21);
    drawText(260,160,"Professor Pradeep Kanchan",25);
    drawText(260,130,"Assistant Professor Gd-III",26);
    drawText(280,100,"NMAMIT,Nitte",12);
    drawText(270,60,"Press ENTER to Continue",23);
        glutSwapBuffers();

}
void intro2(){
     glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
        glPushMatrix();
            glColor3f(0.498, 0, 1);
            glTranslatef(0,0,-41);
            glBegin(GL_QUADS);
            glVertex3f(-50,50,0);
            glVertex3f(50,50,0);
            glColor3f(0.882, 0, 1);
            glVertex3f(50,-50,0);
            glVertex3f(-50,-50,0);
        glEnd();
        glPopMatrix();
    glColor3f(1,1,1);
    drawText(300,500,"Introduction",12);
    drawText(100,400,"Our project is a simulation of 2011 Cricket World Cup.We have encorporated features such as Team selection, ",107);
    drawText(100,350,"Shot selection and camera angles.The 2011 ICC Cricket World Cup was the tenth Cricket World Cup.",100);
    drawText(100,300," It was played in India, Sri Lanka, and Bangladesh.  India won the tournament, defeating Sri Lanka by 6 wickets",112);
    drawText(100,250,"  in the final at Wankhede Stadium in Mumbai, thus becoming the first country to win the Cricket World Cup final",112);
    drawText(100,200," on home soil.",14);
    drawText(270,60,"Press ENTER to Continue",23);
        glutSwapBuffers();

}


void drawText(int x,int y,char text[],int len){
glMatrixMode( GL_PROJECTION );
glPushMatrix();
glLoadIdentity();
gluOrtho2D( 0, 700, 0, 700 );
glMatrixMode( GL_MODELVIEW );
glPushMatrix();
glLoadIdentity();
glRasterPos2i( x,y);  // move in 10 pixels from the left and bottom edges
for ( int i = 0; i < len; ++i ) {
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
}
glPopMatrix();

glMatrixMode( GL_PROJECTION );
glPopMatrix();
glMatrixMode( GL_MODELVIEW );
}





float angle=0;
float arm=0;

void objectaxis(){                      // show the axes for the object
    glPushMatrix();                     //reference axis
        glColor3f(1.0,0.0,0.0); // red x
        glBegin(GL_LINES);
        glVertex3f(-4.0, 0.0f, 0.0f);
        glVertex3f(4.0, 0.0f, 0.0f);
        glEnd();
    glPopMatrix();
    glPushMatrix();
        glColor3f(0.0,1.0,0.0); // green y
        glBegin(GL_LINES);
        glVertex3f(0.0, -4.0f, 0.0f);
        glVertex3f(0.0, 4.0f, 0.0f);
        glEnd();
    glPopMatrix();
    glPushMatrix();
        glColor3f(0.0,0.0,1.0); // blue z
        glBegin(GL_LINES);
        glVertex3f(0.0, 0.0f ,-4.0f );
        glVertex3f(0.0, 0.0f ,4.0f );
        glEnd();
    glPopMatrix();
}

int audhand=1;

void audience(float a1,float a2,float a3,int x){
    glPushMatrix();
    glTranslatef(0,0.8,0);
    glColor3f(1,0.7,0.7);
    glScalef(1,1.5,1);
    glutSolidSphere(0.25,10,10);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glColor3f(a1,a2,a3);
    glScalef(1.4,1,0);
    glutSolidCube(1);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glRotatef((x==-1?90:180),1,0,0);
    glPushMatrix();
    glTranslatef(0.6,-0.5,0);
    glColor3f(1,0.7,0.7);
    glScalef(0.3,1.3,0);
    glutSolidCube(1);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.6,-0.5,0);
    glColor3f(1,0.7,0.7);
    glScalef(0.3,1.3,0);
    glutSolidCube(1);
    glEnd();
    glPopMatrix();
    glPopMatrix();
}

void audience2(){
    glPushMatrix();
    audience(1,0,0,audhand);
    glTranslatef(-1.5,0,0);
    audience(0,0,1,-audhand);
    glPopMatrix();
}

audiencerow(int h,int x){
glPushMatrix();
glTranslatef(-23+x,h,-35+x);
audience2();
for(int i=0;i<25;i++){
glTranslatef(3,0,0);
audience2();
}
glPopMatrix();
}

GLUquadricObj *p = gluNewQuadric(); //cylindepointer

void playerframe(float c1,float c2,float c3){
glPushMatrix();             //BATSMAN left thigh
            glTranslatef(0.3,0.5,0.2);
            glRotatef(90, 1.0, 0.0, -0.8);
            gluCylinder(p, 0.18,0.15,0.7, 10, 10);
            glEnd();
        glPopMatrix();
        glPushMatrix();             //BATSMAN THIGH2
            glTranslatef(0.3,0.5,-0.1);
            glRotatef(90, 1.0, 0.0, -0.5);
            glRotatef(30, 1.0, 0.0, 0);
            gluCylinder(p, 0.18,0.15,0.7, 10, 10);
            glEnd();
        glPopMatrix();
        glPushMatrix();             //BATSMAN leg1
            glTranslatef(-0,0.05,0.45);
            glRotatef(90, 1.0, 0.0, 0.3);
            gluCylinder(p, 0.15,0.1,0.9, 10, 10);
            glEnd();
        glPopMatrix();
        glPushMatrix();             //BATSMAN leg2
            glTranslatef(-0.1,0.05,-0.3);
            glRotatef(90, 1.0, 0.0, 0.3);
            gluCylinder(p, 0.15,0.1,0.9, 10, 10);
            glEnd();
        glPopMatrix();
        glPushMatrix();             //BATSMAN foot2
            glTranslatef(0.05,-0.8,-0.2);
            glScalef(2.3,1.2,1);
            glColor3f(1,1,1);
            glutSolidSphere(0.1,10,3);
            glEnd();
        glPopMatrix();
        glPushMatrix();             //BATSMAN foot1
            glTranslatef(0.15,-0.8,0.5);
            glScalef(2.3,1.2,1);
            glColor3f(1,1,1);
            glutSolidSphere(0.1,10,3);
            glEnd();
        glPopMatrix();
        glColor3f(c1,c2,c3);
        glPushMatrix();             //BATSMAN butt
            glRotatef(90,0,1,0);
            glRotatef(90,1,0,0);
            glScalef(1.6,1,1);
            glTranslatef(0,0.3,-0.7);
            gluCylinder(p, 0.23,0.2,0.3, 10, 10);
            glEnd();
        glPopMatrix();
        glTranslatef(0.3,-0.1,0);
        glRotatef(20, 0.0, 0.0, 1.0);
        glPushMatrix();             //BATSMAN chest
            glRotatef(90,0,1,0);
            glRotatef(90,1,0,0);
            glScalef(1.7,1,1);
            glTranslatef(0,0.3,-1.5);
            gluCylinder(p, 0.26,0.2,0.8, 10, 10);
            glEnd();
        glPopMatrix();
        glPushMatrix();             //BATSMAN head
            glTranslatef(0.3,1.8,0);
            glScalef(0.5,0.7,0.5);
            glColor3f(1,0.7,0.7);
            glutSolidSphere(0.35,10,10);
            glEnd();
        glPopMatrix();
                glPushMatrix();             //BATSMAN eyes
            glTranslatef(0.15,1.8,0.1);
            glColor3f(0,0,0);
            glutSolidSphere(0.02,10,10);
            glEnd();
        glPopMatrix();
        glPushMatrix();             //BATSMAN eyes
            glTranslatef(0.15,1.8,-0.1);
            glColor3f(0,0,0);
            glutSolidSphere(0.02,10,10);
            glEnd();
        glPopMatrix();
        glPushMatrix();             //BATSMAN mouth
            glTranslatef(0.18,1.7,0);
            glColor3f(1,0,0);
            glScalef(1,0.7,1.5);
            glutSolidSphere(0.05,10,10);
            glEnd();
        glPopMatrix();
        glPushMatrix();             //BATSMAN hair
            glRotatef(90,0,1,0);
            glRotatef(90,1,0,0);
            glTranslatef(0,0.3,-1.95);
            glColor3f(0,0,0);
            //gluCylinder(p, 0.18,0.17,0.11, 10, 10);
            glScalef(1,1,0.6);
            glutSolidSphere(0.2,10,10);
            glEnd();
        glPopMatrix();glPushMatrix();             //BATSMAN hair
            glRotatef(90,0,1,0);
            glTranslatef(0,1.8,0.4);
            glColor3f(0,0,0);
            //gluCylinder(p, 0.18,0.17,0.11, 10, 10);
            glScalef(1,1,0.6);
            glutSolidSphere(0.2,10,10);
            glEnd();
        glPopMatrix();

        }

int shot=0;
void playerrotate(float c1,float c2,float c3,int f){
        glColor3f(c1,c2,c3);
glPushMatrix();             //BATSMAN shoulderchest
            glTranslatef(0.3,1.38,0);
            glScalef(0.7,0.7,1.3);
            glutSolidSphere(0.35,10,10);
            glEnd();
        glPopMatrix();
        glPushMatrix();             //BATSMAN arm2
            glTranslatef(0.3,1.4,-0.35);
            glRotatef(90, 1.0, 0.0,0);
            glRotatef(40, 1, -0.5,0);
            gluCylinder(p, 0.15,0.1,0.5, 10, 10);
            glEnd();
        glPopMatrix();
        glPushMatrix();             //BATSMAN arm1
            glTranslatef(0.3,1.4,0.3);
            glRotatef(90, 1.0, 0.0,0);
            glRotatef(40, -1,-1,0);
            gluCylinder(p, 0.15,0.1,0.5, 10, 10);
            glEnd();
        glPopMatrix();
        glPushMatrix();             //BATSMAN forearm1
            glTranslatef(0.1,1.1,0.5);
            glRotatef(90, 1.0, 0.0,0);
            glRotatef(70, 1,-1,1);
            glColor3f(1,0.7,0.7);
            gluCylinder(p, 0.12,0.1,0.6, 10, 10);
            glEnd();
        glPopMatrix();
        glPushMatrix();             //BATSMAN forearm2
            glTranslatef(0.2,1.1,-0.6);
            glRotatef(90, 1.0, 0.0,0);
            glRotatef(70, -1,-1,-0.5);
            glColor3f(1,0.7,0.7);
            gluCylinder(p, 0.12,0.1,0.6, 10, 10);
            glEnd();
        glPopMatrix();
        if(!f)
            glColor3f(1,1,1);
        glPushMatrix();             //BATSMAN hand1
            glTranslatef(-0.1,0.78,0);
            glutSolidSphere(0.13,10,10);
            glEnd();
        glPopMatrix();
        glPushMatrix();             //BATSMAN hand2
            glTranslatef(-0.1,0.78,-0.1);
            glutSolidSphere(0.13,10,10);
            glEnd();
        glPopMatrix();
        glColor3f(c1,c2,c3);
        }

void fielder(int x,int y,int z,int ang,int v1,int v2,int v3){
    glPushMatrix();
    glTranslatef(x,y,z);
    glRotatef(ang,v1,v2,v3);
    //objectaxis();
    glRotatef(2,1,0,0);
    playerframe(f1,f2,f3);
    glTranslatef(0.2,1.5,.1);
    glRotatef(-25, 0,0, 1);
    //objectaxis();
    glTranslatef(-0.2,-1.5,-0.1);
    playerrotate(f1,f2,f3,1);
    glEnd();
    glPopMatrix();

}

void umpire(){

        glPushMatrix();
        glTranslatef(-0.2,0.6,10);
        glRotatef(90,1,0,0);
        glColor3f(0,0,0);           //UMPIRE leg1
        glScalef(1.5,1,1);
        gluCylinder(p, 0.1,0.1,3, 10, 10);
        glEnd();
    glPopMatrix();
        glPushMatrix();
        glTranslatef(0.2,0.6,10);
        glRotatef(90,1,0,0);
        glColor3f(0,0,0);           //UMPIRE leg2
        glScalef(1.5,1,1);
        gluCylinder(p, 0.1,0.1,3, 10, 10);
        glEnd();
    glPopMatrix();
        glPushMatrix();
        glTranslatef(0,1.6,10);
        glRotatef(90,1,0,0);
        glColor3f(1,0,0);           //UMPIRE chest
        glScalef(1.5,1,1);
        gluCylinder(p, 0.2,0.2,1, 10, 10);
        glEnd();
    glPopMatrix();
        glPushMatrix();
        glTranslatef(0,1.8,10);
        glColor3f(1,0.7,0.7);           //UMPIRE head
        glScalef(1,1.5,1);
        glutSolidSphere(0.2,10,10);
        glEnd();
    glPopMatrix();
        glPushMatrix();
        glTranslatef(0,1.95,10);
        glRotatef(90,0,0,1);
        glRotatef(90,0,1,0);
        glColor3f(0,0,0);           //UMPIRE hat
        gluCylinder(p, 0.2,0.2,0.3, 10, 10);
        glEnd();
    glPopMatrix();
        glPushMatrix();             //UMPIRE eyes
            glTranslatef(0.1,1.85,9.8);
            glColor3f(0,0,0);
            glutSolidSphere(0.02,10,10);
            glEnd();
        glPopMatrix();
        glPushMatrix();             //UMPIRE eyes
            glTranslatef(-0.1,1.85,9.8);
            glColor3f(0,0,0);
            glutSolidSphere(0.02,10,10);
            glEnd();
        glPopMatrix();
        glPushMatrix();             //UMPIRE mouth
            glTranslatef(0,1.75,9.75);
            glColor3f(1,0,0);
            glScalef(1,0.7,1.5);
            glutSolidSphere(0.05,10,10);
            glEnd();
        glPopMatrix();
        glPushMatrix();
        glTranslatef(0,1.95,10);
        glRotatef(90,0,0,1);
        glRotatef(90,0,1,0);
        glColor3f(0,0,0);           //UMPIRE hat base
        gluCylinder(p, 0.3,0.3,0.05, 10, 10);
        glEnd();
    glPopMatrix();
        glPushMatrix();
        glTranslatef(-0.4,1.6,10);
        glRotatef(90,1,0,0);
        glRotatef(-10,0,1,0);
        glColor3f(1,0,0);           //UMPIRE hand1
        glScalef(1.2,1,1);
        gluCylinder(p, 0.1,0.1,1, 10, 10);
        glEnd();
    glPopMatrix();
        glPushMatrix();
        glTranslatef(0.4,1.6,10);
        glRotatef(90,1,0,0);
        glRotatef(10,0,1,0);
        glColor3f(1,0,0);           //UMPIRE hand2
        glScalef(1.2,1,1);
        gluCylinder(p, 0.1,0.1,1, 10, 10);
        glEnd();
    glPopMatrix();
        glPushMatrix();
        glTranslatef(0.6,0.5,10);
        glColor3f(1,0.7,0.7);           //UMPIRE fist
        glutSolidSphere(0.12,10,10);
        glEnd();
    glPopMatrix();
     glPushMatrix();
        glTranslatef(-0.6,0.5,10);
        glColor3f(1,0.7,0.7);           //UMPIRE fist
        glutSolidSphere(0.12,10,10);
        glEnd();
    glPopMatrix();
}

void wicket(int pos){
    glPushMatrix();                                     //wicket
        glColor3f(1,1,1);
        glScalef(0.08,1.3,0.1);
        glTranslatef(0,-0.2,pos);
        glutSolidCube(1.0);
        glTranslatef(2,0,0);
        glutSolidCube(1.0);
        glTranslatef(-4,0,0);
        glutSolidCube(1.0);
        glEnd();
    glPopMatrix();
    }
void bails(float pos){
    glPushMatrix();
    glTranslatef(-0.08,0.38,pos);
    glScalef(1.7,1,1);
    glutSolidCube(0.05);
    glTranslatef(0.1,0,0);
    glutSolidCube(0.05);
    glEnd();
    glPopMatrix();
}

float topangle=0;
void mySpecialFunc(int key, int x, int y){
	switch (key) {
    case GLUT_KEY_RIGHT:
        angle += 1;
        if (angle > 360) angle = 0.0;
		break;
    case GLUT_KEY_LEFT:
        angle -= 1;
        if (angle > 360) angle = 0.0;
	    break;case GLUT_KEY_UP:
        topangle += 0.1;
        if (topangle > 5) topangle = 0.0;
		break;
    case GLUT_KEY_DOWN  :
        topangle -= 0.1;
        if (topangle <0 ) topangle = 0.0;
        break;
	}
	glutPostRedisplay();
}
float y=0,z=0;
void display(){
    init();
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glScalef(1,1.5,1);
    glTranslatef(0.0,0.0,-8.0);
    glPushMatrix();                                     //sky
        glColor3f(0.439, 0.772, 0.984);
        glTranslatef(0,0,-41);
        glBegin(GL_QUADS);
            glVertex3f(-50,50,0);
            glVertex3f(50,50,0);
            glVertex3f(50,-50,0);
            glVertex3f(-50,-50,0);
        glEnd();
    glPopMatrix();
    glTranslatef(0,-topangle,0);
    glPushMatrix();                                     //stands
        glColor3f(0.4,0.4,0.4);
        glTranslatef(0,0,-40);
        glBegin(GL_QUADS);
            glVertex3f(-50,7,0);
            glVertex3f(50,7,0);
            glVertex3f(50,-50,0);
            glVertex3f(-50,-50,0);
        glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,0,-1);
    audiencerow(1,0);
    audiencerow(2,-1);
    audiencerow(3,-2);
    audiencerow(4,-3);
    audiencerow(5,-3.3);
    audiencerow(6,-4);
    glPopMatrix();
    glRotatef(angle, 0.0, 1.0, 0.0);
    glPushMatrix();                                     //grass
        glColor3f(0.333, 0.486, 0.333);
        glBegin(GL_POLYGON);
        glVertex3f(-50,-1,-50);
        glVertex3f(50,-1,-50);
        glVertex3f(50,-1,50);
        glVertex3f(-50,-1,50);
        glEnd();
    glPopMatrix();
    glPushMatrix();                                     //pitch
        glColor3f(0.945, 0.878, 0.674);
        glBegin(GL_POLYGON);
        glVertex3f(-2,-0.9,-2);
        glVertex3f(2,-0.9,-2);
        glVertex3f(2,-0.9,10);
        glVertex3f(-2,-0.9,10);
        glEnd();
    glPopMatrix();
    //objectaxis();
    glPushMatrix();           //BAtSMAN MAIN
        glColor3f(0, 0.439, 0.921);
        playerframe(0, 0.439, 0.921);
        glTranslatef(0.2,1.5,.1);
        if(shot==1)
            glRotatef(-60,0,1,0);
        glRotatef(arm,-0.5, 1.0, 0);
        glTranslatef(-0.2,-1.5,-0.1);
        playerrotate(0, 0.439, 0.921,0);
        glPushMatrix();             //BATSMAN bat
            glTranslatef(-0.2,0.6,-0.7);
            glRotatef(20,0,0,-1);
            glRotatef(70,1,0,0);
            glScalef(0.2,1.3,0.1);
            glColor3f(0.721, 0.643, 0.537);
            glutSolidCube(1);
            glEnd();
        glPopMatrix();

    glPopMatrix();
    glPushMatrix();
        glColor3f(0, 0.439, 0.921);
        glTranslatef(1,0,9);
        playerframe(0, 0.439, 0.921);
        playerrotate(0, 0.439, 0.921,0);
        glPushMatrix();             //BATSMAN bat
            glTranslatef(-0.4,0.3,0.7);
            glRotatef(20,0,0,-1);
            glRotatef(-50,1,0,0);
            glScalef(0.2,1.3,0.1);
            glColor3f(0.721, 0.643, 0.537);
            glutSolidCube(1);
            glEnd();
        glPopMatrix();
    glPopMatrix();
    glPushMatrix();
    glPopMatrix();
    wicket(-15);
    wicket(95);
    bails(-1.5);
    bails(9.5);
    umpire();
    glColor3f(f1,f2,f3);
    fielder(0,0,-5,90,0,1,0);
    fielder(-4,0,-4,120,0,1,0);
    fielder(-4,0,35,270,0,1,0);
    fielder(-30,0,10,180,0,1,0);
    fielder(9,0,30,-70,0,1,0);
    fielder(-20,0,30,240,0,1,0);
    fielder(30,0,20,0,0,1,0);
    fielder(9,0,-20,70,0,1,0);
    fielder(35,0,-5,30,0,1,0);
    fielder(-10,0,-20,120,0,1,0);

    glPushMatrix();
    glTranslatef(0,1,10);
    if(z>-9.5)
        glTranslatef(0,y,z);
    else
        if(shot==1)
        glTranslatef(9.5+z,-0.2,-18.4-z);
        else
        glTranslatef(-9.5-z,y,-18.4-z);
    glColor3f(1,1,1);
    glutSolidSphere(0.15,10,10);
    glEnd();
    glPopMatrix();

    glutSwapBuffers();

}

void reshape(int w,int h){
glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60,1,1.0,70.0);
    glRotatef(10,1,0,0);
    glTranslatef(0,-1,0);
    glMatrixMode(GL_MODELVIEW);
}


int c=0,df=0;
void timer(int){
     /*
     if(df==1&&arm<=60){
        y=0,z=0,arm=0,df=0,dist=40;

        glutPostRedisplay();
    }
    else{
    */
    glutPostRedisplay();
    glutTimerFunc(1000/60,timer,0);
    c+=1;
    if(c%15==0)
    audhand*=-1;
    z-=0.3;
 if(z>-9.5){
    y-=0.02;
    }
    else if(y<8){
        y+=0.2;
        if (angle< 160)
        angle += 5;
    }
    if(df==0)
    if(arm<180)
        arm+=3;
    else
        df=1;
    else
        if(arm>60)
            arm-=4;

    }
 //   }


void display2(){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    init();
    glScalef(1,1.5,1);
    glTranslatef(0.0,0.0,-8.0);
    glPushMatrix();                                     //sky
        glColor3f(0.439, 0.772, 0.984);
        glTranslatef(0,0,-50);
        glBegin(GL_QUADS);
            glVertex3f(-50,50,0);
            glVertex3f(50,50,0);
            glVertex3f(50,-50,0);
            glVertex3f(-50,-50,0);
        glEnd();
    glPopMatrix();
    glPushMatrix();                                     //stands
        glColor3f(0.4,0.4,0.4);
        glTranslatef(0,0,-49);
        glBegin(GL_QUADS);
            glVertex3f(-50,7,0);
            glVertex3f(50,7,0);
            glVertex3f(50,-50,0);
            glVertex3f(-50,-50,0);
        glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-5,0,-10);
    audiencerow(1,0);
    audiencerow(2,-1);
    audiencerow(3,-2);
    audiencerow(4,-3);
    audiencerow(5,-3.3);
    audiencerow(6,-4);
    glPopMatrix();
    glTranslatef(2,-1,-dist-5);
    glPushMatrix();                                     //grass
        glColor3f(0.333, 0.486, 0.333);
        glBegin(GL_POLYGON);
        glVertex3f(-50,-1,-50);
        glVertex3f(50,-1,-50);
        glVertex3f(50,-1,50);
        glVertex3f(-50,-1,50);
        glEnd();
    glPopMatrix();
    glPushMatrix();                                     //pitch
        glColor3f(0.945, 0.878, 0.674);
        glBegin(GL_POLYGON);
        glVertex3f(-2,-0.9,-2);
        glVertex3f(2,-0.9,-2);
        glVertex3f(2,-0.9,10);
        glVertex3f(-2,-0.9,10);
        glEnd();
    glPopMatrix();
    glPushMatrix();
        glColor3f(0, 0.439, 0.921);
        glTranslatef(1,0,9);
        playerframe(0, 0.439, 0.921);
        playerrotate(0, 0.439, 0.921,0);
        glPushMatrix();             //BATSMAN bat
            glTranslatef(-0.4,0.3,0.7);
            glRotatef(20,0,0,-1);
            glRotatef(-50,1,0,0);
            glScalef(0.2,1.3,0.1);
            glColor3f(0.721, 0.643, 0.537);
            glutSolidCube(1);
            glEnd();
        glPopMatrix();
    glPopMatrix();
    glPushMatrix();                                     //wickets bowling
        glColor3f(1,1,1);
        glTranslatef(0,0,9.5);
        glScalef(0.08,1.3,0.1);
        glTranslatef(0,-0.2,0);
        glutSolidCube(1.0);
        glTranslatef(2,0,0);
        glutSolidCube(1.0);
        glTranslatef(-4,0,0);
        glutSolidCube(1.0);
        glEnd();
    glPopMatrix();

        glPushMatrix();
        glTranslatef(-0.2,0.6,10);
        glRotatef(90,1,0,0);
        glColor3f(0,0,0);           //UMPIRE leg1
        glScalef(1.5,1,1);
        gluCylinder(p, 0.1,0.1,3, 10, 10);
        glEnd();
    glPopMatrix();
        glPushMatrix();
        glTranslatef(0.2,0.6,10);
        glRotatef(90,1,0,0);
        glColor3f(0,0,0);           //UMPIRE leg2
        glScalef(1.5,1,1);
        gluCylinder(p, 0.1,0.1,3, 10, 10);
        glEnd();
    glPopMatrix();
        glPushMatrix();
        glTranslatef(0,1.6,10);
        glRotatef(90,1,0,0);
        glColor3f(1,0,0);           //UMPIRE chest
        glScalef(1.5,1,1);
        gluCylinder(p, 0.2,0.2,1, 10, 10);
        glEnd();
    glPopMatrix();
        glPushMatrix();
        glTranslatef(0,1.8,10);
        glColor3f(1,0.7,0.7);           //UMPIRE head
        glScalef(1,1.5,1);
        glutSolidSphere(0.2,10,10);
        glEnd();
    glPopMatrix();
        glPushMatrix();
        glTranslatef(0,1.95,10);
        glRotatef(90,0,0,1);
        glRotatef(90,0,1,0);
        glColor3f(0,0,0);           //UMPIRE hat
        gluCylinder(p, 0.2,0.2,0.3, 10, 10);
        glEnd();
    glPopMatrix();
        glPushMatrix();
        glTranslatef(0,1.95,10);
        glRotatef(90,0,0,1);
        glRotatef(90,0,1,0);
        glColor3f(0,0,0);           //UMPIRE hat base
        gluCylinder(p, 0.3,0.3,0.05, 10, 10);
        glEnd();
    glPopMatrix();
        glPushMatrix();
        glTranslatef(-0.4,1.6,10);
        glRotatef(90,1,0,0);
        glRotatef(-10,0,1,0);
        glColor3f(1,0,0);           //UMPIRE hand1
        glScalef(1.2,1,1);
        gluCylinder(p, 0.1,0.1,1, 10, 10);
        glEnd();
    glPopMatrix();
        glPushMatrix();
        glTranslatef(0.4,1.6,10);
        glRotatef(90,1,0,0);
        glRotatef(10,0,1,0);
        glColor3f(1,0,0);           //UMPIRE hand2
        glScalef(1.2,1,1);
        gluCylinder(p, 0.1,0.1,1, 10, 10);
        glEnd();
    glPopMatrix();
        glPushMatrix();
        glTranslatef(0.6,0.5,10);
        glColor3f(1,0.7,0.7);           //UMPIRE fist
        glutSolidSphere(0.12,10,10);
        glEnd();
    glPopMatrix();
     glPushMatrix();
        glTranslatef(-0.6,0.5,10);
        glColor3f(1,0.7,0.7);           //UMPIRE fist
        glutSolidSphere(0.12,10,10);
        glEnd();
    glPopMatrix();
    glColor3f(f1,f2,f3);
    fielder(0,0,-5,90,0,1,0);
    fielder(-4,0,-4,120,0,1,0);
    fielder(-4,0,35,270,0,1,0);
    fielder(-30,0,10,180,0,1,0);
    fielder(9,0,30,-70,0,1,0);
    fielder(-20,0,30,240,0,1,0);
    fielder(30,0,20,0,0,1,0);
    fielder(9,0,-20,70,0,1,0);
    fielder(35,0,-5,30,0,1,0);
    fielder(-10,0,-20,120,0,1,0);

    glPushMatrix();           //BAtSMAN MAIN
        glColor3f(0, 0.439, 0.921);
        playerframe(0, 0.439, 0.921);
        glTranslatef(0.2,1.5,.1);
        glRotatef(arm,-0.5, 1.0, 0);
        glTranslatef(-0.2,-1.5,-0.1);
        playerrotate(0, 0.439, 0.921,0);
        glPushMatrix();             //BATSMAN bat
            glTranslatef(-0.2,0.6,-0.7);
            glRotatef(20,0,0,-1);
            glRotatef(70,1,0,0);
            glScalef(0.2,1.3,0.1);
            glColor3f(0.721, 0.643, 0.537);
            glutSolidCube(1);
            glEnd();
        glPopMatrix();

    glPopMatrix();
    glPushMatrix();
        glColor3f(0, 0.439, 0.921);
        glTranslatef(1,0,9);
        playerframe(0, 0.439, 0.921);
        playerrotate(0, 0.439, 0.921,0);
        glPushMatrix();             //BATSMAN bat
            glTranslatef(-0.4,0.3,0.7);
            glRotatef(20,0,0,-1);
            glRotatef(-50,1,0,0);
            glScalef(0.2,1.3,0.1);
            glColor3f(0.721, 0.643, 0.537);
            glutSolidCube(1);
            glEnd();
        glPopMatrix();
    glPopMatrix();
    glPushMatrix();                                     //wickets batting
        glColor3f(1,1,1);
        glScalef(0.08,1.3,0.1);
        glTranslatef(0,-0.2,-15);
        glutSolidCube(1.0);
        glTranslatef(2,0,0);
        glutSolidCube(1.0);
        glTranslatef(-4,0,0);
        glutSolidCube(1.0);
        glEnd();
    glPopMatrix();
    glTranslatef(-1,0,dist);
    if(jump>0)
        glTranslatef(0,jump,0);
    glRotatef(-90,0,1,0);
    glPushMatrix();
    glTranslatef(0.1,0,0);
    glRotatef(10,0,0,1);
    glPushMatrix();
    //glTranslatef(0,0,-0.2);
    glTranslatef(0,0.5,0);
    glRotatef(barm,0,0,1);
    glTranslatef(0,-0.5,0);
    glColor3f(f1,f2,f3);
        glPushMatrix();             //BATSMAN left thigh
            glTranslatef(0.3,0.5,0.2);
            glRotatef(90, 1.0, 0.0, -0.3);
            gluCylinder(p, 0.18,0.15,0.7, 10, 10);
            glEnd();
        glPopMatrix();
        glPushMatrix();             //BATSMAN leg1
            glTranslatef(0.1,0.05,0.25);
            glRotatef(90, 1.0, 0.0, 0.3);
            gluCylinder(p, 0.15,0.1,0.9, 10, 10);
            glEnd();
        glPopMatrix();
        glPushMatrix();             //BATSMAN foot1
            glTranslatef(0.15,-0.8,0.3);
            glScalef(2.3,1.2,1);
            glColor3f(1,1,1);
            glutSolidSphere(0.1,10,3);
            glEnd();
        glPopMatrix();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0,0.5,0);
        glRotatef(-barm,0,0,1);
        glTranslatef(0,-0.5,0);
        glColor3f(f1,f2,f3);
        glPushMatrix();             //BATSMAN THIGH2
            glTranslatef(0.3,0.5,-0.1);
            glRotatef(90, 1.0, 0.0, -0.5);
            glRotatef(30, 1.0, 0.0, 0);
            gluCylinder(p, 0.18,0.15,0.7, 10, 10);
            glEnd();
        glPopMatrix();
        glPushMatrix();             //BATSMAN leg2
            glTranslatef(-0.1,0.05,-0.3);
            glRotatef(90, 1.0, 0.0, 0.3);
            gluCylinder(p, 0.15,0.1,0.9, 10, 10);
            glEnd();
        glPopMatrix();
        glPushMatrix();             //BATSMAN foot2
            glTranslatef(0.05,-0.8,-0.2);
            glScalef(2.3,1.2,1);
            glColor3f(1,1,1);
            glutSolidSphere(0.1,10,3);
            glEnd();
        glPopMatrix();
        glPopMatrix();
    glPopMatrix();
        glTranslatef(0,-0.2,0);
        glColor3f(f1,f2,f3);
        glPushMatrix();             //BATSMAN butt
            glRotatef(90,0,1,0);
            glRotatef(90,1,0,0);
            glScalef(1.6,1,1);
            glTranslatef(0,0.3,-0.7);
            gluCylinder(p, 0.23,0.2,0.3, 10, 10);
            glEnd();
        glPopMatrix();
        glTranslatef(0.3,-0.1,0);
        glRotatef(20, 0.0, 0.0, 1.0);
        glPushMatrix();             //BATSMAN chest
            glRotatef(90,0,1,0);
            glRotatef(90,1,0,0);
            glScalef(1.7,1,1);
            glTranslatef(0,0.3,-1.5);
            gluCylinder(p, 0.26,0.2,0.8, 10, 10);
            glEnd();
        glPopMatrix();
        glPushMatrix();             //BATSMAN head
            glTranslatef(0.3,1.8,0);
            glScalef(0.5,0.7,0.5);
            glColor3f(1,0.7,0.7);
            glutSolidSphere(0.35,10,10);
            glEnd();
        glPopMatrix();
                glPushMatrix();             //BATSMAN eyes
            glTranslatef(0.15,1.8,0.1);
            glColor3f(0,0,0);
            glutSolidSphere(0.02,10,10);
            glEnd();
        glPopMatrix();
        glPushMatrix();             //BATSMAN eyes
            glTranslatef(0.15,1.8,-0.1);
            glColor3f(0,0,0);
            glutSolidSphere(0.02,10,10);
            glEnd();
        glPopMatrix();
        glPushMatrix();             //BATSMAN hair
            glRotatef(90,0,1,0);
            glRotatef(90,1,0,0);
            glTranslatef(0,0.3,-1.95);
            glColor3f(0,0,0);
            //gluCylinder(p, 0.18,0.17,0.11, 10, 10);
            glScalef(1,1,0.6);
            glutSolidSphere(0.2,10,10);
            glEnd();
        glPopMatrix();glPushMatrix();             //BATSMAN hair
            glRotatef(90,0,1,0);
            glTranslatef(0,1.8,0.4);
            glColor3f(0,0,0);
            //gluCylinder(p, 0.18,0.17,0.11, 10, 10);
            glScalef(1,1,0.6);
            glutSolidSphere(0.2,10,10);
            glEnd();
        glPopMatrix();

        glColor3f(f1,f2,f3);
        glPushMatrix();             //BATSMAN shoulderchest
            glTranslatef(0.3,1.38,0);
            glScalef(0.7,0.7,1.3);
            glutSolidSphere(0.35,10,10);
            glEnd();
        glPopMatrix();
    glPushMatrix();
        glTranslatef(0.1,1.3,-0.2);
        dist>26?glRotatef(0.6*barm,0,0,1):glRotatef(actarm,0,0,1);
        glTranslatef(-0.1,-1.3,0.2);
        glPushMatrix();             //BATSMAN arm2
            glTranslatef(0.3,1.4,-0.35);
            glRotatef(90, 1.0, 0.0,0);
            glRotatef(40, 1, -0.5,0);
            gluCylinder(p, 0.15,0.1,0.5, 10, 10);
            glEnd();
        glPopMatrix();
            glColor3f(1,0.7,0.7);
        glPushMatrix();             //BATSMAN forearm2
            glTranslatef(0.2,1.1,-0.6);
            glRotatef(90, 1.0, 0.0,0);
            glRotatef(-90, 0, 1,0);
            glColor3f(1,0.7,0.7);
            gluCylinder(p, 0.12,0.1,0.6, 10, 10);
            glEnd();
        glPopMatrix();
        glPushMatrix();             //BATSMAN hand2
            glTranslatef(-0.5,1.1,-0.6);
            glutSolidSphere(0.13,10,10);
            glEnd();
        glPopMatrix();
    glPopMatrix();
    glPushMatrix();
        glColor3f(f1,f2,f3);
        glTranslatef(0.1,1.3,-0.2);
        glRotatef(-0.6*barm,0,0,1);
        glTranslatef(-0.1,-1.3,0.2);
        glPushMatrix();             //BATSMAN arm1
            glTranslatef(0.3,1.4,0.3);
            glRotatef(90, 1.0, 0.0,0);
            glRotatef(40, -1,-1,0);
            gluCylinder(p, 0.15,0.1,0.5, 10, 10);
            glEnd();
        glPopMatrix();
            glColor3f(1,0.7,0.7);
        glPushMatrix();             //BATSMAN forearm1
            glTranslatef(0.1,1.1,0.5);
            glRotatef(90, 1.0, 0.0,0);
            glRotatef(-90, 0, 1,0);
            glColor3f(1,0.7,0.7);
            gluCylinder(p, 0.12,0.1,0.6, 10, 10);
            glEnd();
        glPopMatrix();
        glPushMatrix();             //BATSMAN hand1
            glTranslatef(-0.5,1.1,0.5);
            glutSolidSphere(0.13,10,10);
            glEnd();
        glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
}
int dir=1;
void timer2(int){
    c+=1;
    //if(dist<20&&dist>19.7)
         //PlaySound(TEXT("C:\\Users\\kalla\\Documents\\CB\\CGProj\\Dhoni.wav"),NULL,SND_ASYNC);
    if(dist<10){
         //PlaySound(TEXT("C:\\Users\\kalla\\Documents\\CB\\CGProj\\Dhoni.wav"),NULL,SND_ASYNC);
        glutDisplayFunc(display);
        glutTimerFunc(0,timer,0);
    }
    else{

    glutPostRedisplay();
    glutTimerFunc(1000/60,timer2,0);
    if(dist>10)
        dist-=0.2;
    if(dist==26)
        actarm=barm;
    if(dist<26&&dist>20){
        jump+=0.03;
        actarm-=3;
    }
    if(dist<20&&dist>10){
        jump-=0.02;
        actarm+=5.5;
    }

    //if(c%7==0)
    //audhand*=-1;
    if(dist>10)
      switch(dir){
        case 1: if(barm<50)
                        barm+=3;
                    else  dir=-1;
        break;
        case -1:
            if(barm>-50)
                        barm-=3;
                    else dir=1;
        break;
}
    }
}
