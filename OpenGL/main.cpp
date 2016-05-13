#include "COpenGL.h"
#include "Obj.h"
#include<vector>

using namespace OpenGL;

int Rotate = 0;

double x = 0, y = 0, z = -10;

int tipoobj = 2;
bool luz = true;
float zoom = 0;
float ratio;
float AlfaVidro = 0.25f;
float AlfaVidroCubo = 0.25f;

vector <Objeto*> objetosDesenho;

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	for (int i = 0; i < objetosDesenho.size(); i++) {
		objetosDesenho[i]->setRotate(Rotate);
		objetosDesenho[i]->mostrar();
		//cout << i << endl;
	}
	glutSwapBuffers();
}



void teclado(unsigned char Tecla, int X, int Y) {
   switch (Tecla) {
        case 27: exit(0);
            break; // encerra programa com a Tecla ESC
        case 'a': Rotate += 5;	    break;
        case 'q': Rotate += 3;	    break;
        case 's': Rotate -= 5 ;      break;
		case 'w': Rotate -= 3;      break;
        case 'z': zoom += 60;
            cout << "zoom in" << endl;
            break;
        case 'x': zoom -= 60;
            cout << "zoom out" << endl;
            break;
    }
    glutPostRedisplay();
}

void GerenciaMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON) {
		if (state == GLUT_DOWN) { // Zoom-in
			if (zoom >= 10) zoom -= 5;
		}
	}
	if (button == GLUT_RIGHT_BUTTON) {
		if (state == GLUT_DOWN) { // Zoom-out
			if (zoom <= 130) zoom += 5;
		}
	}
    glutPostRedisplay();
}

void init(void) {

	GLfloat color_mat[] = { 1.0, 0.0, 0.0, 1.0 };
	GLfloat mat_specular[] = { 1.0, 0.0, 0.0, 0.0 };
	GLfloat mat_shininess[] = { 10.0 };
	GLfloat light_position[] = { 0, 0, 0, -3 };

	glShadeModel(GL_SMOOTH);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMaterialfv(GL_FRONT, GL_EMISSION, color_mat);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	//glLightfv(GL_LIGHT0, GL_SPECULAR, light_position);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_BITS);
}

void reshape(int w, int h) {
	if (h == 0)h = 1;
	ratio = 1.0f*w / h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(70, ratio, 2, 500);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//arruma o angulo da visão nos tres primeiros parâmetros EX: -2.4, 3, 10
	//gluLookAt(-2.4, 3, 10, 0, 0, 0, 0.0f, 1.0f, 0.0f);
	gluLookAt(10, 3, 20, 0, 0, 0, 0.0f, 1.0f, 0.0f);
}


int main(int argc, char* argv[]) {
    /*COpenGL *projeto = new COpenGL();
    projeto->InitOpenGL(&argC, argV);
    projeto->setWindowGL("Teste de Programa", 800, 600, 100, 100, false);
    projeto->setResize();
	projeto->setMouseFunc(GerenciaMouse);
    projeto->setLight(true);
    projeto->setObserver(0, 0, 10, zoom);
    projeto->setKeyboardFunc(teclado);

	objetosDesenho.push_back(new Cubo(0,0,0));
	/*
	objetosDesenho.push_back(new Teacup(0, 0, -2, 0, 0, 1));
	objetosDesenho.push_back(new Teapot(0, 0, 2, 1, 0, 0));
	SolidCube* solidCube = new SolidCube(0, 2, 0, 0, 1, 0);
	solidCube->setSize(2);
	objetosDesenho.push_back(solidCube);
	objetosDesenho.push_back(new SolidSphere(0, -2, 0, 1, 1, 0));
	objetosDesenho.push_back(new SolidCube(0, 5, 0, 0, 1, 1));
	objetosDesenho.push_back(new Teacup(0, -3, -2, 1, 0, 1));
	objetosDesenho.push_back(new Teapot(4, 0, -4, 1, 1, 0));
	
	
    projeto->setRenderFunc(display);
    projeto->Loop();
	free(projeto);(*/

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(640, 480);

	glutCreateWindow("Computacao grafica - Transparencias");
	//-1, 0, 0, 1

	//X,Y,Z,R,G,B,A
	objetosDesenho.push_back(new Esfera( 0, 0, 0, -1, 0, -1, 0.5));
	objetosDesenho.push_back(new Esfera( 4, 0, 0,  0,-1, -1, 0.5));
	objetosDesenho.push_back(new Esfera(-4, 0, 0,  0, 0.4, -1, 0.5));

	objetosDesenho.push_back(new Cubo( 0, 0, 10, -1, 0, -1, 0.4));
	objetosDesenho.push_back(new Cubo( 4, 0, 10, 0, -1, -1, 0.4));
	objetosDesenho.push_back(new Cubo(-4, 0, 10, 0, 0.4, -1, 0.4));

	objetosDesenho.push_back(new Vidro(0, 0, 5, 1, 1, 1, 0.0 ));


	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(teclado);
	glutIdleFunc(display);
	glutMainLoop();
};

