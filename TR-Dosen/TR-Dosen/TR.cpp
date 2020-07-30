#include<Windows.h>
#include<gl/glut.h>
#include <math.h>

void init(void);
void tampil(void);
void mouse(int button, int state, int x, int y);
void mouseMotion(int x, int y);
void keyboard(unsigned char, int, int);
void ukuran(int, int);
void idle();
void timer(int value);

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;
int is_depth;
const double PI = 3.141592653589793;
float titik;
int i, radius, jumlah_titik, x_tengah, y_tengah, n;
float angle = 0;
int gerak = 50;
bool atas = true;



void init(void)
{
	GLfloat light_ambient[] = { 0.3, 0.3, 0.3, 1.0 };
	GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 0.0 };
	GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat lightpos[] = {0.0, 0.3, 0.3,0.0};
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, lightpos);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	is_depth = 1;
	glMatrixMode(GL_MODELVIEW);
	glPointSize(4.0f);
	glLineWidth(1.0f);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(250, 80);
	glutCreateWindow("TR Dosen");
	init();
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);
	glutKeyboardFunc(keyboard);
	glutReshapeFunc(ukuran);
	glutDisplayFunc(tampil);
	glutMainLoop();
	return 0;
}

void timer(int value)
{
	if (atas) {
		gerak += 1;
	}
	else {
		gerak -= 1;
	}
	if (gerak > 1) {
		atas = false;
	}
	else if (gerak < -1) {
		atas = true;
	}
	glutPostRedisplay();
	glutTimerFunc(50, timer, 50);
}

void Bangunan()
{
	//DepanKiri
	glBegin(GL_QUADS);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(-80,-20,-40);
	glVertex3f(-20,-20,-40);
	glVertex3f(-20,20,-40);
	glVertex3f(-80,20,-40);
	glEnd();

	//DepanTengah
	glBegin(GL_QUADS);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(-20,-15,-30);
	glVertex3f(20,-15,-30);
	glVertex3f(20,20,-30);
	glVertex3f(-20,20,-30);
	glEnd();
	//kiri
	glBegin(GL_QUADS);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(-20,-20,-30);
	glVertex3f(-20,-20,-40);
	glVertex3f(-20,20,-40);
	glVertex3f(-20,20,-30);
	glEnd();
	//kanan
	glBegin(GL_QUADS);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(20,-20,-30);
	glVertex3f(20,-20,-40);
	glVertex3f(20,20,-40);
	glVertex3f(20,20,-30);
	glEnd();

	//DepanKanan
	glBegin(GL_QUADS);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(20,-20,-40);
	glVertex3f(80,-20,-40);
	glVertex3f(80,20,-40);
	glVertex3f(20,20,-40);
	glEnd();

	//SampingKiri
	glBegin(GL_QUADS);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(-80,-20,-40);
	glVertex3f(-80,-20,-110);
	glVertex3f(-80,20,-110);
	glVertex3f(-80,20,-40);
	glEnd();

	//SampingKanan
	glBegin(GL_QUADS);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(80,-20,-40);
	glVertex3f(80,-20,-110);
	glVertex3f(80,20,-110);
	glVertex3f(80,20,-40);
	glEnd();
	
	//SampingKiri
	glBegin(GL_QUADS);
	glColor3f(0.8,0.8,0.8);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(-80,-20,-40);
	glVertex3f(-80,-20,-110);
	glVertex3f(-80,20,-110);
	glVertex3f(-80,20,-40);
	glEnd();

	//Belakang
	glBegin(GL_QUADS);
	glColor3f(0.8,0.8,0.8);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(-80,-20,-110);
	glVertex3f(80,-20,-110);
	glVertex3f(80,20,-110);
	glVertex3f(-80,20,-110);
	glEnd();

	//LantaiBesar
	glBegin(GL_QUADS);
	glColor3f(0.6,0.6,0.6);
	glVertex3f(-80,-20,-110);
	glVertex3f(80,-20,-110);
	glVertex3f(80,-20,-40);
	glVertex3f(-80,-20,-40);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.6,0.6,0.6);
	glVertex3f(-80,-15,-110);
	glVertex3f(80,-15,-110);
	glVertex3f(80,-15,-40);
	glVertex3f(-80,-15,-40);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.6,0.6,0.6);
	glVertex3f(-80,-20,-109.999);
	glVertex3f(80,-20,-109.999);
	glVertex3f(80,-15,-109.999);
	glVertex3f(-80,-15,-109.999);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.6,0.6,0.6);
	glVertex3f(-80,-20,-40.999);
	glVertex3f(80,-20,-40.999);
	glVertex3f(80,-15,-40.999);
	glVertex3f(-80,-15,-40.999);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.6,0.6,0.6);
	glVertex3f(-80,-20,-109.999);
	glVertex3f(-80,-15,-109.999);
	glVertex3f(-80,-15,-40.999);
	glVertex3f(-80,-20,-40.999);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.6,0.6,0.6);
	glVertex3f(80,-20,-109.999);
	glVertex3f(80,-15,-109.999);
	glVertex3f(80,-15,-40.999);
	glVertex3f(80,-20,-40.999);
	glEnd();

	//LantaiKecilMencuatKedepan
	glBegin(GL_QUADS);
	glColor3f(0.6,0.6,0.6);
	glVertex3f(-20,-15,-40);
	glVertex3f(20,-15,-40);
	glVertex3f(20,-15,-30);
	glVertex3f(-20,-15,-30);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3f(0.6,0.6,0.6);
	glVertex3f(-20,-20,-40);
	glVertex3f(20,-20,-40);
	glVertex3f(20,-20,-30);
	glVertex3f(-20,-20,-30);
	glEnd();
	
	
	//Tangga
	glBegin(GL_QUADS);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(-20,-15,-30);
	glVertex3f(20,-15,-30);
	glVertex3f(20,-15,-28);
	glVertex3f(-20,-15,-28);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.6,0.6,0.6);
	glVertex3f(-20,-15,-28);
	glVertex3f(20,-15,-28);
	glVertex3f(20,-16,-28);
	glVertex3f(-20,-16,-28);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.6,0.6,0.6);
	glVertex3f(-20,-15,-30);
	glVertex3f(-20,-20,-30);
	glVertex3f(-20,-20,-28);
	glVertex3f(-20,-15,-28);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.6,0.6,0.6);
	glVertex3f(20,-15,-30);
	glVertex3f(20,-20,-30);
	glVertex3f(20,-20,-28);
	glVertex3f(20,-15,-28);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(-20,-16,-28);
	glVertex3f(20,-16,-28);
	glVertex3f(20,-16,-26);
	glVertex3f(-20,-16,-26);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.6,0.6,0.6);
	glVertex3f(-20,-16,-26);
	glVertex3f(20,-16,-26);
	glVertex3f(20,-17,-26);
	glVertex3f(-20,-17,-26);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.6,0.6,0.6);
	glVertex3f(-20,-16,-28);
	glVertex3f(-20,-20,-28);
	glVertex3f(-20,-20,-26);
	glVertex3f(-20,-16,-26);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.6,0.6,0.6);
	glVertex3f(20,-16,-28);
	glVertex3f(20,-20,-28);
	glVertex3f(20,-20,-26);
	glVertex3f(20,-16,-26);
	glEnd();


	glBegin(GL_QUADS);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(-20,-17,-26);
	glVertex3f(20,-17,-26);
	glVertex3f(20,-17,-24);
	glVertex3f(-20,-17,-24);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.6,0.6,0.6);
	glVertex3f(-20,-17,-24);
	glVertex3f(20,-17,-24);
	glVertex3f(20,-18,-24);
	glVertex3f(-20,-18,-24);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.6,0.6,0.6);
	glVertex3f(-20,-17,-26);
	glVertex3f(-20,-20,-26);
	glVertex3f(-20,-20,-24);
	glVertex3f(-20,-17,-24);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.6,0.6,0.6);
	glVertex3f(20,-17,-26);
	glVertex3f(20,-20,-26);
	glVertex3f(20,-20,-24);
	glVertex3f(20,-17,-24);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(-20,-18,-24);
	glVertex3f(20,-18,-24);
	glVertex3f(20,-18,-22);
	glVertex3f(-20,-18,-22);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.6,0.6,0.6);
	glVertex3f(-20,-18,-22);
	glVertex3f(20,-18,-22);
	glVertex3f(20,-19,-22);
	glVertex3f(-20,-19,-22);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.6,0.6,0.6);
	glVertex3f(-20,-18,-24);
	glVertex3f(-20,-20,-24);
	glVertex3f(-20,-20,-22);
	glVertex3f(-20,-18,-22);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.6,0.6,0.6);
	glVertex3f(20,-18,-24);
	glVertex3f(20,-20,-24);
	glVertex3f(20,-20,-22);
	glVertex3f(20,-18,-22);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(-20,-19,-22);
	glVertex3f(20,-19,-22);
	glVertex3f(20,-19,-20);
	glVertex3f(-20,-19,-20);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.6,0.6,0.6);
	glVertex3f(-20,-19,-20);
	glVertex3f(20,-19,-20);
	glVertex3f(20,-20,-20);
	glVertex3f(-20,-20,-20);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.6,0.6,0.6);
	glVertex3f(-20,-19,-22);
	glVertex3f(-20,-20,-22);
	glVertex3f(-20,-20,-20);
	glVertex3f(-20,-19,-20);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.6,0.6,0.6);
	glVertex3f(20,-19,-22);
	glVertex3f(20,-20,-22);
	glVertex3f(20,-20,-20);
	glVertex3f(20,-19,-20);
	glEnd();

}


void Bulan()
{
	glPushMatrix();
	glColor3f(0.7,0.7,0.7);
	glTranslatef(120.0,60,-110.0);
	glutSolidSphere(20,50,50);
	glPopMatrix();
}



void tampil(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if (is_depth)
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	else
		glClear(GL_COLOR_BUFFER_BIT);

	Bangunan();
	Bulan();

	glutSwapBuffers();
}



void keyboard(unsigned char key, int x, int y){
	switch (key)
	{
	case 'w':
	case 'W':
		glTranslatef(0.0, 0.0, 3.0);
		break;
	case 'd':
	case 'D':
		glTranslatef(3.0, 0.0, 0.0);
		break;
	case 's':
	case 'S':
		glTranslatef(0.0, 0.0, -3.0);
		break;
	case 'a':
	case 'A':
		glTranslatef(-3.0, 0.0, 0.0);
		break;
	case '7':
		glTranslatef(0.0, 3.0, 0.0);
		break;
	case '9':
		glTranslatef(0.0, -3.0, 0.0);
		break;
	case '2':
		glRotatef(2.0, 1.0, 0.0, 0.0);
		break;
	case '8':
		glRotatef(-2.0, 1.0, 0.0, 0.0);
		break;
	case '6':
		glRotatef(2.0, 0.0, 1.0, 0.0);
		break;
	case '4':
		glRotatef(-2.0, 0.0, 1.0, 0.0);
		break;
	case '1':
		glRotatef(2.0, 0.0, 0.0, 1.0);
		break;
	case '3':
		glRotatef(-2.0, 0.0, 0.0, 1.0);
		break;
	case '5':
		if (is_depth)
		{
			is_depth = 0;
			glDisable(GL_DEPTH_TEST);
		}
		else
		{
			is_depth = 1;
			glEnable(GL_DEPTH_TEST);
		}
	}
	tampil();
}

void ukuran(int lebar, int tinggi)
{
	if (tinggi == 0) tinggi = 1;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(70.0, lebar / tinggi, 50.0, 1400.0);
	glTranslatef(0.0, -5.0, -150.0);
	glMatrixMode(GL_MODELVIEW);
}

void idle()
{
	if (!mouseDown)
	{
		xrot += 0.3f;
		yrot += 0.4f;
	}
	glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		mouseDown = true;
		xdiff = x - yrot;
		ydiff = -y + xrot;
	}
	else
		mouseDown = false;
}

void mouseMotion(int x, int y)
{
	glLoadIdentity();
	gluLookAt(0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	glRotated(xrot, 1.0f, 0.0f, 0.0f);
	glRotated(yrot, 0.0f, 1.0f, 0.0f);

	if (mouseDown)
	{
		yrot = x - xdiff;
		xrot = y + ydiff;
		glutPostRedisplay();
	}
}
