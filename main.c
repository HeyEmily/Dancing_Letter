#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/freeglut.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<math.h>
char text[10];
int pause=0;
int nFPS = 30;
float fRotateAngle = 0.f;
float fRotateColor = 0.00f;
clock_t startClock =0, curClock;
long long int prevF =0, curF=0;
int dipMode=1, dipRotate=0;
float n;

void drawPOLY()
{
    float h = sin(fRotateAngle/5);
    float random0 = sin(fRotateAngle)/10;
    float random1 = sin(fRotateAngle/3)/10;
    float random3 = sin(fRotateAngle/4)/10;
    float h1 = h/2;
    float h2 = h/2.5;
    float high2 = h2*0.7;
    n = cos(fRotateAngle/15)*1.5;
    float c = (sin(fRotateColor*2));
    float c1 = (cos(fRotateColor*4));
    float c2 = (cos(fRotateColor*3));
    glClearColor(0.5+c,0.3+c1,0.5+c2, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.95,0.6,0);
    glVertex2f((-0.6+n), (1.0+h+random0));
    glColor3f(0.8,0.5,0.3);
    glVertex2f((-0.6+n+(random3/1.2)), (0.6+h-(random1/5)));
    glVertex2f((-0.2+n), (0.6+h+(random0/2)));
    glVertex2f((0.2+n), (0.6+h));
    glColor3f(0.8,0.5,0.3);
    glVertex2f((0.6+n+(random1/1.2)), (0.6+h));
    glColor3f(0.95,0.6,0);
    glVertex2f((0.6+n), (1+h-(random0)/1.5));
    glEnd();
    
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.8,0.5,0.3);
    glVertex2f((-0.2+n ), (0.6+h+(random0/2)));
    glColor3f(0.8,0.5,0.3);
    glVertex2f((0.2+n ), (0.6+h));
    glColor3f(0.35,0.3,0.55);
    glVertex2f((0.2+n ), (-0.6+h1));
    glColor3f(0.35,0.3,0.55);
    glVertex2f((-0.2+n ), (-0.6+h1));
    glEnd();
    
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.05,0.1,0.9);
    glVertex2f((0.6+n), (-1.0+high2));
    glVertex2f((0.6+n), (-0.6+h2));
    glColor3f(0.35,0.3,0.55);
    glVertex2f((0.2+n), (-0.6+h1));
    glColor3f(0.35,0.3,0.55);
    glVertex2f((-0.2+n), (-0.6+h1));
    glVertex2f((-0.6+n), (-0.6+h1));
    glColor3f(0.05,0.1,0.9);
    glVertex2f((-0.6+n), (-1.0+h1));
    glEnd();
}  

void drawLINE()
{
    float h = sin(fRotateAngle/5);
    float random0 = sin(fRotateAngle)/10;
    float random1 = sin(fRotateAngle/3)/10;
    float random3 = sin(fRotateAngle/4)/10;
    float h1 = h/2;
    float h2 = h/2.5;
    float high2 = h2*0.7;
    n = cos(fRotateAngle/15)*1.5;
    float c = (sin(fRotateColor*2));
    float c1 = (sin(fRotateColor*4));
    float c2 = (sin(fRotateColor*3));
    glClearColor(0.5+c, 0.3+c1, 0.5+c2, 1.0f); 
    glBegin(GL_LINE_LOOP);
    glColor3f(0.95,0.6,0);
    glVertex2f((-0.6+n), (1.0+h+random0));
    glColor3f(0.8,0.5,0.3);
    glVertex2f((-0.6+n+(random3/1.2)), (0.6+h-(random1/5)));
    glVertex2f((0.6+n), (1.0+h-(random0/1.5)));
    glVertex2f((-0.6+n), (1.0+h+random0));
    
    glVertex2f((0.6+n), (1.0+h-(random0/1.5)));
    glVertex2f((-0.6+n+(random3/1.2)), (0.6+h-(random1/5)));
    glVertex2f((-0.2+n), (0.6+h+(random0/2)));
    glVertex2f((0.6+n), (1.0+h-(random0/1.5)));
    glVertex2f((0.2+n), (0.6+h));
    glVertex2f((0.6+n), (1.0+h-(random0/1.5)));
    
    glColor3f(0.8,0.5,0.3);
    glVertex2f((0.2+n), (0.6+h));
    glVertex2f((0.6+n+(random1/1.2)), (0.6+h));
    glVertex2f((0.6+n), (1.0+h-(random0/1.5)));
    glColor3f(0.95,0.6,0);
    glVertex2f((-0.6+n+(random3/1.2)), (0.6+h-(random1/5)));
    glEnd();
    
    glBegin(GL_LINE_LOOP);
    glColor3f(0.8,0.5,0.3);
    glVertex2f((0.2+n ), (0.6+h));
    glColor3f(0.35,0.3,0.55);
    glVertex2f((-0.2+n ), (-0.6+h1));
    glColor3f(0.8,0.5,0.3);
    glVertex2f((-0.2+n ), (0.6+h+(random0/2)));
    glColor3f(0.8,0.5,0.3);
    glVertex2f((0.2+n ), (0.6+h));
    
    glColor3f(0.35,0.3,0.55);
    glVertex2f((0.2+n ), (-0.6+h1));
    glEnd();
    
    glBegin(GL_LINE_LOOP);
    glColor3f(0.05,0.1,0.9);
    glVertex2f((0.6+n), (-1.0+high2));
    glVertex2f((0.6+n), (-0.6+h2));
    glColor3f(0.35,0.3,0.55);
    glVertex2f((0.2+n), (-0.6+h1));
    glVertex2f((0.6+n), (-1.0+high2));
    glVertex2f((0.2+n), (-0.6+h1));
    glVertex2f((-0.2+n), (-0.6+h1));
    
    glVertex2f((0.6+n), (-1.0+high2));
    glVertex2f((-0.2+n), (-0.6+h1));
    glColor3f(0.35,0.3,0.55);
    glVertex2f((-0.6+n), (-0.6+h1));
    glVertex2f((0.6+n), (-1.0+high2));
    glColor3f(0.05,0.1,0.9);
    glVertex2f((-0.6+n), (-1.0+h1));
    glVertex2f((-0.6+n), (-0.6+h1));
    glEnd();
}  

void display(void)
{
    curF++;
    if (dipMode==1)
    {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
    else
    {
        glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    }
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(0.f,0.f,3.f,0.f,0.f,0.f,0.f,1.f,0.f);
    if(dipRotate==1)
    {
        glRotatef(fRotateAngle, 0.f,1.f,0.f);
    }
    if(dipMode==1){
        drawPOLY();
    }else{
        drawLINE();
    }strcpy(text, "PFS = 30\n");
    glColor3f(0.2,0.2,0.4);
    glRasterPos2f(-2, 2);
    glutBitmapString(GLUT_BITMAP_HELVETICA_18, (const unsigned char*)text);
    glutSwapBuffers();

    curClock = clock();
    float elapsed = (curClock-startClock)/(float)CLOCKS_PER_SEC;
    if(elapsed>1.0f)
    {
        float fps =(float)(curF-prevF)/elapsed;
        printf("fps:%f\n", fps);
        prevF =curF;
        startClock = curClock;
    }
}

void reshape(int w, int h)
{
    glViewport(0,0,w,h);
    float fAspect=((float)w)/h;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70.f, fAspect, 0.001f, 30.f);

}

void keyboard(unsigned char key, int x, int y)
{
    if(key==27)
    {
        printf("demonstration finished.\n");
        exit(EXIT_SUCCESS);
    }
    if(key=='m')
    {    dipMode = 1-dipMode;
         printf("Press m - Wire-Frame/Polygon Mode\n");
    }
    if(key=='r')
    {
        dipRotate = 1-dipRotate;
        printf("Press r - Rotation/Panning Mode\n");
    } 
    if(key=='p')
    {   pause = 1-pause;
        printf("Press p - Pause/Resume\n");
    }
}

void mouse(int button, int state, int x, int y)
{

    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        printf("push left mouse button.\n");
}

void timer(int v)
{
   if(!pause)
   {
    fRotateAngle +=1.f;
    fRotateColor +=0.01f;
   }
    glutPostRedisplay();
    glutTimerFunc(1000/nFPS, timer, v);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow((const char*)"Dancing I");

    glClearColor(0.8, 0.8, 0.9, 0.0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    //uncomment this if you only want to use wireframe mode1
    glPointSize(4.0);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_BLEND);
    glLineWidth(1.0);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
    glutTimerFunc(100, timer, nFPS);

    startClock = clock();

    glutMainLoop();

    return EXIT_SUCCESS;
}
