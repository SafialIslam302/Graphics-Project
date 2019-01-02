#include<bits/stdc++.h>
#include<GL/glut.h>
#include<math.h>
#include<dos.h>
#include<time.h>
using namespace std;

#define PI 3.1415926535897932384626433832795
#define MaximumTheta 1.0
#define MinimumTheta 0.0009
#define MaximumRadious 10.5
#define MinimumRadious .9
#include "RGBpixmap.cpp"
using namespace std;

//DATATYPE DECLERATION
GLfloat IncrementTheta = 0.05;
GLint WindowSizX=640,WindowSizY=480;
GLfloat EyePosition_X=2.0,EyePosition_Y=1.3,EyePosition_Z= 2.0;
GLfloat Radious=3.3,ProRadious=3.0,InitialTheta1=0.716,InitialTheta2=0.403;
GLfloat Center_X=0.0,Center_Y=0.0,Center_Z=0.0;
GLfloat Up_X=0.0,Up_Y=1.0,Up_Z=0.0;
enum { ClockWise,AntiClockWise };
enum {Theta1,Theta2};
float Near=.05, Far=10.0,fova = 50.0;
GLint direction = AntiClockWise;
GLint PressMovenent=Theta1;

RGBpixmap pix[10];

//FUNCTION DECLEARATION
void CalculationX_Y_Z();
void CalculationTH1();
void CalculationTH2();
void Movenent();

long double tr[3]= {0,0,700};
long double theta[3]= {0,0,0};
long double th=0;
long double totheta=(3.1416/(long double)180.0);
int menu_id;
int stop=1,tree=1,start=0,ending=1;
float sf=2;
GLfloat speed=-0.05*sf;
int gear_no;
void light()
{
    GLfloat lightambient[]= {0.5f,0.5f,0.5f,1.0};
    GLfloat lightposition[]= {500.0f,200.0f,00.0f,0.0f};
    GLfloat lightdiffuse[]= {0.7f,0.7f,0.6f,1.0};
    GLfloat lightspecular[]= {0.5f,0.5f,0.5f,1.0};
    glLightfv(GL_LIGHT0,GL_POSITION,lightposition);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,lightdiffuse);
    glLightfv(GL_LIGHT0,GL_AMBIENT,lightambient);
    glLightfv(GL_LIGHT0,GL_SPECULAR,lightspecular);
}
void mat1()
{
    GLfloat ambient[]= {1.0f,0.0f,0.0f,1.0f};
    GLfloat diffuse[]= {1.0f,0.0f,0.0f,1.0f};
    GLfloat specular[]= {1.0f,0.0f,0.0f,1.0f};
    GLfloat shinness[]= {50.0f};
    GLfloat emission[]= {0.0f,0.0f,0.0f,1.0f};
    glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,ambient);
    glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,diffuse);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,specular);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS,shinness);
    glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,emission);
}
void mat2()
{
    GLfloat ambient[]= {0.1f,0.1f,0.1f,1.0f};
    GLfloat diffuse[]= {0.1f,0.2f,0.2f,1.0f};
    GLfloat specular[]= {0.2f,0.2f,0.2f,1.0f};
    GLfloat shinness[]= {10.0f};
    GLfloat emission[]= {0.0f,0.0f,0.0f,1.0f};
    glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,ambient);
    glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,diffuse);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,specular);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS,shinness);
    glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,emission);
}
void mat3()
{
    GLfloat ambient[]= {0.3f,0.3f,0.3f,1.0f};
    GLfloat diffuse[]= {0.4f,0.4f,0.4f,1.0f};
    GLfloat specular[]= {0.4f,0.4f,0.4f,1.0f};
    GLfloat shinness[]= {20.0f};
    GLfloat emission[]= {0.0f,0.0f,0.0f,1.0f};
    glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,ambient);
    glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,diffuse);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,specular);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS,shinness);
    glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,emission);
}
void mat4()
{
    GLfloat ambient[]= {0.7f,0.7f,0.9f,1.0f};
    GLfloat diffuse[]= {0.7f,0.7f,0.9f,1.0f};
    GLfloat specular[]= {0.7f,0.7f,0.9f,1.0f};
    GLfloat shinness[]= {10.0f};
    GLfloat emission[]= {0.0f,0.0f,0.0f,1.0f};
    glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,ambient);
    glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,diffuse);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,specular);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS,shinness);
    glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,emission);
}
void mat5()
{
    GLfloat ambient[]= {0.7f,0.7f,0.0f,1.0f};
    GLfloat diffuse[]= {0.7f,0.7f,0.0f,1.0f};
    GLfloat specular[]= {0.7f,0.7f,0.0f,1.0f};
    GLfloat shinness[]= {10.0f};
    GLfloat emission[]= {1.0f,1.0f,0.2f,1.0f};
    glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,emission);
    glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,ambient);
    glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,diffuse);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,specular);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS,shinness);
}
void mat6()
{
    GLfloat ambient[]= {0.05f,0.05f,0.05f,1.0f};
    GLfloat diffuse[]= {0.05f,0.05f,0.05f,1.0f};
    GLfloat specular[]= {0.05f,0.05f,0.05f,1.0f};
    GLfloat shinness[]= {10.0f};
    GLfloat emission[]= {0.0f,0.0f,0.0f,1.0f};
    glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,ambient);
    glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,diffuse);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,specular);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS,shinness);
    glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,emission);
}
void mat7()
{
    GLfloat ambient[]= {0.1f,0.7f,0.1f,1.0f};
    GLfloat diffuse[]= {0.1f,0.7f,0.1f,1.0f};
    GLfloat specular[]= {0.1f,0.7f,0.1f,1.0f};
    GLfloat shinness[]= {30.0f};
    GLfloat emission[]= {0.0f,0.0f,0.0f,1.0f};
    glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,ambient);
    glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,diffuse);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,specular);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS,shinness);
    glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,emission);
}
void mat8()
{
    GLfloat ambient[]= {0.4f,0.1f,0.1f,1.0f};
    GLfloat diffuse[]= {0.4f,0.1f,0.1f,1.0f};
    GLfloat specular[]= {0.4f,0.3f,0.1f,1.0f};
    GLfloat shinness[]= {30.0f};
    GLfloat emission[]= {0.0f,0.0f,0.0f,1.0f};
    glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,ambient);
    glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,diffuse);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,specular);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS,shinness);
    glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,emission);
}
void mat9()
{
    GLfloat ambient[]= {0.2f,0.8f,0.2f,1.0f};
    GLfloat diffuse[]= {0.2f,0.9f,0.2f,1.0f};
    GLfloat specular[]= {0.2f,0.8f,0.2,1.0f};
    GLfloat shinness[]= {30.0f};
    GLfloat emission[]= {0.0f,0.0f,0.0f,1.0f};
    glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,ambient);
    glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,diffuse);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,specular);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS,shinness);
    glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,emission);
}

void drawCircle(float radius,int a)
{
    for (int i=0; i <= 360; i=i+a)
    {
        float degInRad = i*0.0174532926;
        glVertex3f(cos(degInRad)*radius,sin(degInRad)*radius,0);
    }
}

void drawHorCircle(GLfloat radius,GLfloat height)
{
    glBegin(GL_TRIANGLES);

    for(int i=0; i<=360; i=i+2)
    {
        float degInRad = i*0.0174532926,degInRad1 = (i+2)*0.0174532926;

        glVertex3f(cos(degInRad)*radius,height,sin(degInRad)*radius);
        glVertex3f(cos(degInRad1)*radius,height,sin(degInRad1)*radius);
        glVertex3f(0,height,0);
    }
    glEnd();
}

void drawSquareHor(GLfloat s,GLfloat height,int a=0)
{
    glPushMatrix();
    if(a==1)
        glTranslated(0,0,s*2*a);
    glBegin(GL_QUADS);

    glVertex3f(-s,height,-s);
    glVertex3f(s,height,-s);
    glVertex3f(s,height,s);
    glVertex3f(-s,height,s);
    glEnd();
    glPopMatrix();
}

void drawtree(GLfloat h,GLfloat x,GLfloat y)
{
    glPushMatrix();
    mat8();
    glTranslated(x,0,y);
    glRotated(-90,1,0,0);
    GLUquadricObj *obj=gluNewQuadric();
    gluCylinder(obj,10*h,10*h,60*h,10,5);
    glPopMatrix();
    glPushMatrix();
    mat9();
    glTranslated(x,60*h,y);
    glRotated(-90,1,0,0);
    glutSolidCone(60*h,150*h,20,20);
    glPopMatrix();
}

void quadall(GLfloat arr[4][3],GLfloat ar[3],int a=0)
{
    glNormal3fv(ar);
    glVertex3fv(arr[0]);
    glVertex3fv(arr[1]);
    glVertex3fv(arr[2]);
    glVertex3fv(arr[3]);

    if(a==0)
    {
        for(int i=0; i<4; i++)
        {
            arr[i][2]=-arr[i][2];
        }
        ar[2]=-ar[2];
        glNormal3fv(ar);
        glVertex3fv(arr[0]);
        glVertex3fv(arr[1]);
        glVertex3fv(arr[2]);
        glVertex3fv(arr[3]);
    }
}

void tri(GLfloat arr[3][3],GLfloat ar[3],int a=0)
{
    glNormal3fv(ar);
    glVertex3fv(arr[0]);
    glVertex3fv(arr[1]);
    glVertex3fv(arr[2]);
    glVertex3fv(arr[2]);
    if(a==0)
    {
        for(int i=0; i<3; i++)
        {
            arr[i][2]=-arr[i][2];
        }
        ar[2]=-ar[2];
        glNormal3fv(ar);
        glVertex3fv(arr[0]);
        glVertex3fv(arr[1]);
        glVertex3fv(arr[2]);
        glVertex3fv(arr[2]);
    }
}

void lines(GLfloat arr[2][3],int a=0)
{
    glVertex3fv(arr[0]);
    glVertex3fv(arr[1]);
    if(a==0)
    {
        for(int i=0; i<2; i++)
        {
            arr[i][2]=-arr[i][2];
        }
        glVertex3fv(arr[0]);
        glVertex3fv(arr[1]);
    }
}

void wheels()
{
    glColor3f(0.1,0.1,0.1);
    mat3();
    glPushMatrix();
    glRotated(theta[1],0,1,0);
    glTranslated(-80+tr[0],20+tr[1],-51+tr[2]);
    glBegin(GL_POLYGON);
    drawCircle(18,20);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glRotated(theta[1],0,1,0);
    glTranslated(70+tr[0],20+tr[1],-51+tr[2]);
    glBegin(GL_POLYGON);
    drawCircle(18,20);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glRotated(theta[1],0,1,0);
    glTranslated(-80+tr[0],20+tr[1],51+tr[2]);
    glBegin(GL_POLYGON);
    drawCircle(18,20);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glRotated(theta[1],0,1,0);
    glTranslated(70+tr[0],20+tr[1],51+tr[2]);
    glBegin(GL_POLYGON);
    drawCircle(18,20);
    glEnd();
    glPopMatrix();
    glColor3f(0.2,0.2,1);
    mat2();
    glPushMatrix();
    glRotated(theta[1],0,1,0);
    glTranslated(-80+tr[0],20+tr[1],-50+tr[2]);
    glScaled(1.0,1.0,2.0);
    glutSolidTorus(4,20,30,30);
    glPopMatrix();
    glPushMatrix();
    glRotated(theta[1],0,1,0);
    glTranslated(70+tr[0],20+tr[1],-50+tr[2]);
    glScaled(1.0,1.0,2.0);
    glutSolidTorus(4,20,30,30);
    glPopMatrix();
    glPushMatrix();
    glRotated(theta[1],0,1,0);
    glTranslated(-80+tr[0],20+tr[1],50+tr[2]);
    glScaled(1.0,1.0,2.0);
    glutSolidTorus(4,20,30,30);
    glPopMatrix();
    glPushMatrix();
    glRotated(theta[1],0,1,0);
    glTranslated(70+tr[0],20+tr[1],50+tr[2]);
    glScaled(1.0,1.0,2.0);
    glutSolidTorus(4,20,30,30);
    glPopMatrix();
}

void sidepannel()  // For the car body
{
    glPushMatrix();
    glRotated(theta[1],0,1,0);
    glTranslated(tr[0],tr[1],tr[2]);
    glColor3f(1,0,0);
    mat1();
    glBegin(GL_QUADS);
    GLfloat arr[4][3]= {{-120,15,-50},{-120,55,-50},{120,55,-50},{120,15,-50}};
    GLfloat ar[3]= {0,0,-1.0};
    quadall(arr,ar);
    GLfloat arr2[4][3]= {{120,15,-50},{120,55,-50},{120,55,50},{120,15,50}};
    GLfloat ar2[3]= {1.0,0.0,0.0};
    quadall(arr2,ar2,1);
    GLfloat arr3[4][3]= {{-120,15,-50},{-120,35,-50},{-125,35,-46},{-125,15,-46}};
    GLfloat ar3[3]= {-1.0,0.0,-1.0};
    quadall(arr3,ar3);
    GLfloat arr4[4][3]= {{-125,35,-46},{-125,15,-46},{-130,15,-41},{-130,35,-41}};
    GLfloat ar4[3]= {-1.0,0.0,-1.0};
    quadall(arr4,ar4);
    GLfloat arr5[4][3]= {{-130,15,-41},{-130,35,-41},{-130,35,41},{-130,15,41}};
    GLfloat ar5[3]= {-1.0,0.0,0.0};
    quadall(arr5,ar5,1);
    GLfloat arr6[4][3]= {{-125,35,-46},{-130,35,-41},{-130,35,0},{-125,35,0}};
    GLfloat ar6[3]= {0.0,1.0,0.0};
    quadall(arr6,ar6);
    GLfloat arr7[4][3]= {{-120,35,-50},{-125,35,-46},{-125,35,0},{-120,35,0}};
    GLfloat ar7[3]= {0.0,1.0,0.0};
    quadall(arr7,ar7);
    GLfloat arr8[4][3]= {{-120,35,-50},{-120,35,-30},{-120,55,-25},{-120,55,-50}};
    GLfloat ar8[3]= {-1.0,0.0,0.0};
    quadall(arr8,ar8);
    glColor3f(0,0,0);
    mat6();
    GLfloat arr10[4][3]= {{-119.9,54.6,-40},{-119.9,35,-32},{-119.9,35,32},{-119,54.6,40}};
    GLfloat ar10[3]= {-1.0,0.0,0.0};
    quadall(arr10,ar10,1);
    mat5();
    GLfloat arr9[4][3]= {{-120.2,38,-45},{-120.2,38,-34},{-120.2,52,-30},{-120.2,52,-45}};
    GLfloat ar9[3]= {-1.0,0.0,0.0};
    quadall(arr9,ar9);
    mat1();
    GLfloat arr11[4][3]= {{-120,55,-50},{-115,60,-45},{-45,65,-40},{-45,55,-50}};
    GLfloat ar11[3]= {0,1,-1};
    quadall(arr11,ar11);
    GLfloat arr12[4][3]= {{-120,55,-50},{-115,60,-45},{-115,60,45},{-120,55,50}};
    GLfloat ar12[3]= {-1,0,1};
    quadall(arr12,ar12,1);
    GLfloat arr13[4][3]= {{-115,60,-45},{-45,65,-40},{-45,65,40},{-115,60,45}};
    GLfloat ar13[3]= {-0.1,0,1};
    quadall(arr13,ar13,1);
    GLfloat arr14[4][3]= {{-45,65,-40},{-45,55,-50},{120,55,-50},{124,65,-40}};
    GLfloat ar14[3]= {0,1,-1};
    quadall(arr14,ar14);
    GLfloat arr15[4][3]= {{120,55,-50},{124,65,-40},{124,65,40},{120,55,50}};
    GLfloat ar15[3]= {0.2,-1,0};
    quadall(arr15,ar15,1);
    GLfloat arr16[3][3]= {{-45,65,-40},{-5,65,-40},{-5,85,-30}};
    GLfloat ar16[3]= {0,0.6,-1};
    tri(arr16,ar16);
    GLfloat arr17[4][3]= {{-5,65,-40},{-5,85,-30},{42,83,-31},{42,65,-40}};
    GLfloat ar17[3]= {0,0.6,-1};
    quadall(arr17,ar17);
    GLfloat arr18[3][3]= {{42,83,-31},{42,65,-40},{100,65,-40}};
    GLfloat ar18[3]= {0,0.6,-1};
    tri(arr18,ar18);
    GLfloat arr19[4][3]= {{42,83,-31},{100,65,-40},{100,65,40},{42,83,31}};
    GLfloat ar19[3]= {0.6,0,1};
    quadall(arr19,ar19,1);
    GLfloat arr20[4][3]= {{-5,85,-30},{42,83,-31},{42,83,31},{-5,85,30}};
    GLfloat ar20[3]= {0,1,0};
    quadall(arr20,ar20,1);
    GLfloat arr21[4][3]= {{-45,65,-40},{-5,85,-30},{-5,85,30},{-45,65,40}};
    GLfloat ar21[3]= {0,1,0};
    quadall(arr21,ar21,1);
    GLfloat arr22[4][3]= {{100,65,-40},{100,65,40},{124,65,40},{124,65,-40}};
    GLfloat ar22[3]= {0,1,0};
    quadall(arr22,ar22,1);
    mat4();
    GLfloat arr23[4][3]= {{-45.1,65,-38},{-9.1,83,-29},{-9.1,83,29},{-45.1,65,38}};
    GLfloat ar23[3]= {-0.6,0,1};
    quadall(arr23,ar23,1);
    GLfloat arr24[3][3]= {{-40,65.1,-40.1},{-5,65.1,-40.1},{-5,82.1,-31.6}};
    GLfloat ar24[3]= {0,0.6,-1};
    tri(arr24,ar24);
    GLfloat arr25[4][3]= {{-5,65.1,-40.1},{-5,82.1,-31.6},{40,81.1,-32.1},{40,65,-40.1}};
    GLfloat ar25[3]= {0,0.6,-1};
    quadall(arr25,ar25);
    GLfloat arr26[3][3]= {{57,76.1,-35.6},{57,65.1,-40},{92,65.1,-40.1}};
    GLfloat ar26[3]= {0,0.6,-1};
    tri(arr26,ar26);
    GLfloat arr27[4][3]= {{53.9,80,-26},{97,66,-32},{97,66,32},{53.9,80,26}};
    GLfloat ar27[3]= {0.6,0,1};
    quadall(arr27,ar27,1);
    mat3();
    GLfloat arr28[4][3]= {{120,16,-49.5},{-120,16,-49.5},{-120,16,49.5},{120,16,49.5}};
    GLfloat ar28[3]= {0,-1,0};
    quadall(arr28,ar28);
    mat6();
    GLfloat arr29[4][3]= {{-130.1,20,-28},{-130.1,30,-28},{-130.1,30,28},{-130.1,20,28}};
    GLfloat ar29[3]= {-1,0,0};
    quadall(arr29,ar29);
    GLfloat arr30[4][3]= {{120.1,25,-28},{120.1,35,-28},{120.1,35,28},{120.1,25,28}};
    GLfloat ar30[3]= {1,0,0};
    quadall(arr30,ar30);
    GLfloat arr31[4][3]= {{-55,21,50.1},{-55,19,50.1},{45,19,50.1},{45,21,50.1}};
    GLfloat ar31[3]= {0,-1,0};
    quadall(arr31,ar31);
    GLfloat arr32[4][3]= {{-55,23,50.1},{-55,27,50.1},{45,27,50.1},{45,23,50.1}};
    GLfloat ar32[3]= {0,-1,0};
    quadall(arr32,ar32);
    glEnd();
    glPopMatrix();
}

void trees()
{
    drawtree(1,0,400);   // first height, second x position, third y position
    drawtree(1.1,80,300);
    drawtree(0.5,-800,900);
    drawtree(2.8,-500,-100);
    drawtree(0.6,450,350);
    drawtree(2.7,300,-200);
    drawtree(2,600,-800);
    drawtree(1.6,750,-650);
    drawtree(1.9,250,-1000);
    drawtree(2.3,-600,-800);
    drawtree(1.6,830,1300);
    drawtree(2.7,820,-880);
    drawtree(1,-880,950);
    drawtree(3,-300,-1200);
}

float cx=0,cy=.2,cz=10, ox=0,oy=0,oz=0;
float angel=0, dis=cz, disHead=cz;
float angelHead = 0;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();

    glColor3f(1.0,0.0,0.0);
    gluLookAt(cx,cy,cz,ox,oy,oz,0,1,0);
    glMatrixMode(GL_MODELVIEW);
    //mat2();
    drawHorCircle(900,-0.2);
    mat7();

    drawHorCircle(630,-0.1);
    drawSquareHor(2500,-0.3);
    drawSquareHor(2500,-0.3,1);

    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D,2);
    glEnable(GL_TEXTURE_2D);
    trees();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    wheels();
    sidepannel();
    light();

    glPopMatrix();

    glFlush();
    glutSwapBuffers();
}

void movecar()
{
    if(start==1)
    {
        if(stop==1)
            theta[1]+=speed;
        if( theta[1] == -90 )
        {
            theta[1]=270;
        }
        tr[0]=sin((theta[1])*0.0174532926*0.00001)*700;
        tr[2]=cos((theta[1])*0.0174532926*0.00001)*700;
    }
    glutPostRedisplay();
}

void mouse(int btn, int state, int x, int y)
{
    if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        start=1;
    glutPostRedisplay();

}

void keyboard(unsigned char key,int x,int y)
{
    switch (key)
    {
    case 'q':
        exit(0);
        break;
    case ' ':
        stop+=1;
        stop%=2;
        break;
    case '1':
        speed=-0.05*sf;
        break;
    case '2':
        speed=-0.12*sf;
        break;
    case '3':
        speed=-0.20*sf;
        break;
    case '4':
        speed=-0.26*sf;
        break;
    case '5':
        speed=-0.72*sf;
        break;
    case '6':
        speed=0.05*sf;
        break;
    //Zoom In
    case 'Z':
        cx=cx+.08*cx;
        cz=cz+.08*cz;
        break;
    //Zoom Out
    case 'z':
        cx=cx-.08*cx;
        cz=cz-.08*cz;
        break;
    //Around the object
    case 'A':
        angel+=2;
        dis=sqrt(cx*cx+cz*cz);
        cx=dis*sin(angel*3.1416/180.0);
        cz=dis*cos(angel*3.1416/180.0);
        cout<<dis<<" "<<cx<<" "<<cz<<endl;
        break;
    //Around the object
    case 'a':
        angel-=2;
        dis=sqrt(cx*cx+cz*cz);
        cx=dis*sin(angel*3.1416/180.0);
        cz=dis*cos(angel*3.1416/180.0);
        cout<<dis<<" "<<cx<<" "<<cz<<endl;
        break;
    //Look Right
    case 'R':
        angelHead+=5;
        if(angelHead <= 90)
        {
            ox=disHead*sin(angelHead*3.1416/180.0);
            oz=disHead-disHead*cos(angelHead*3.1416/180.0);
        }
        break;
    //Look left
    case 'L':
        angelHead-=5;
        if(angelHead >= -90)
        {
            ox=disHead*sin(angelHead*3.1416/180.0);
            oz=disHead-disHead*cos(angelHead*3.1416/180.0);
        }
        break;
    //Look Down
    case 'D':
        angelHead-=5;
        if(angelHead >= -90)
        {
            oy=disHead*sin(angelHead*3.1416/180.0);
            oz=disHead-disHead*cos(angelHead*3.1416/180.0);
        }
        break;
    //Look Up
    case 'U':
        angelHead+=5;
        if(angelHead <= 90)
        {
            oy=disHead*sin(angelHead*3.1416/180.0);
            oz=disHead-disHead*cos(angelHead*3.1416/180.0);
        }
        break;
    }
    display();
}

void Init()
{
    glEnable(GL_TEXTURE_2D);

    pix[0].makeCheckImage();
    pix[0].setTexture(1);	// create texture int parameter as TextureName

    pix[1].readBMPFile("E:\\C AND C++ programs\\Graphics -Lab\\Graphics Project\\grass4.bmp");
    pix[1].setTexture(2);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(690, 690);
    glutCreateWindow("1407041");

    glutDisplayFunc(display);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_NORMALIZE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glPushMatrix();
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_DEPTH_TEST);
    //glLoadIdentity();
    glOrtho(-910,910,-910,910,-10000,10000);
    gluLookAt(0,130,800,0,0,0,0,1,0);
    glutIdleFunc(movecar);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    glClearColor(0.2,0.8,1,1.0);
    Init();
    glutMainLoop();
    glPopMatrix();
    return 0;
}
