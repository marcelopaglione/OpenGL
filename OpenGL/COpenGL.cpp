#include "COpenGL.h"
#include "Objetos.h"

namespace OpenGL {

	double faspect = 0;
	COpenGL::COpenGL() {};
	COpenGL::~COpenGL() {};

	void COpenGL::InitOpenGL(int* argC, char **argV) {
		glutInit(argC, argV);
		glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE|GLUT_DEPTH);
	};

	void COpenGL::setWindowGL(string title, int heigth, int width, 	
							  int posx, int posy, bool fullscreen) {
		this->FullScreen = fullscreen;
		this->Height = heigth;
		this->Width = width;
		this->PosX = posx;
		this->PosY = posy;
		glutInitWindowSize(this->Height, this->Width);
		glutInitWindowPosition(this->PosX, this->PosY);
		this->window = glutCreateWindow(title.c_str());
		this->Near = 0.5f;
		this->Far = 500.0f;
	};

	void COpenGL::setRenderFunc(void func(void)) {
		glutDisplayFunc(func);
	};
	
	void COpenGL::Loop() {
		glutMainLoop();
	};
	
	void COpenGL::setFAspect() {
		FAspect = faspect;
	}
	//função Local de Calculo
	void AlteraTamanhoJanela(GLsizei w, GLsizei h) {
		if (h == 0) h = 1;
		glViewport(0, 0, w, h);
		// Inicializa o sistema de coordenadas
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		faspect = (w / h);
		gluPerspective(45, (w / h), 0.5, 500.0);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	};


	void COpenGL::setResize() {

		
		glutReshapeFunc(AlteraTamanhoJanela);
	};

	void COpenGL::setObserver(double x, double y, double z, double zoom) {
			
			this->ObsX = x; this->ObsY = y; this->ObsZ = z;
		
			glMatrixMode(GL_PROJECTION);
		    glLoadIdentity();
			gluPerspective(zoom, this->FAspect, this->Near, this->Far);	 

			/*
			gluPerspective( GLdouble fovy, GLdouble aspect, GLdouble zNear, GLdouble zFar );
			fovy é o ângulo, em graus, na direção y (usada para determinar a "altura" do volume de visualização); 
			aspect é a razão de aspecto que determina a área de visualização na direção x, e seu valor é a razão em x (largura) e y (altura); 
			zNear, que sempre tem que ter um valor positivo maior do que zero, é a distância do observador até o plano de corte mais próximo (em z); 
			zFar, que também sempre tem que ter um valor positivo maior do que zero, é a distância do observador até o plano de corte mais afastado (em z).
			*/

			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			gluLookAt(this->ObsX,this->ObsY,this->ObsZ, 0,0,0, 0,1,0);
		
			glutPostRedisplay();

	}

	void COpenGL::setKeyboardFunc(void func(unsigned char Tecla,int X, int Y)) {
		glutKeyboardFunc(func);
	};

	void COpenGL::setMouseFunc( void func(int button, int state, int x, int y)) {
		glutMouseFunc(func);
	};

	
	void COpenGL::setLight(bool OnOff) {
		if (OnOff) {
			GLfloat luzAmbiente[4]={1,1,1,1.0}; 
			GLfloat luzDifusa[4]={1,1,1, 1.0 };	   // "cor" 
			GLfloat luzEspecular[4]= {1.0, 1.0, 1.0, 1.0};// "brilho" 
			GLfloat posicaoLuz[4]={10.0, 10.0, -10.0, 1.0};
			// Capacidade de brilho do material
			GLfloat especularidade[4] = { 0.0,1.0,1.0,1.0 }; //Reflete a cor do objeto
			GLint especMaterial = 100;
 			// Especifica que a cor de fundo da janela será preta
			glClearColor(1.0f, 0.8f, 0.5f, 1.0f);
			// Habilita o modelo de colorização de Gouraud
			glShadeModel(GL_SMOOTH);
			// Define a refletância do material 
			glMaterialfv(GL_FRONT, GL_SPECULAR, especularidade);
			// Define a concentração do brilho
			glMateriali(GL_FRONT, GL_SHININESS, especMaterial);
			// Ativa o uso da luz ambiente 
			glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);
			// Define os parâmetros da luz de número 0
			glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente); 
			glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
			glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );
			glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz );
			// Habilita a definição da cor do material a partir da cor corrente
			glEnable(GL_COLOR_MATERIAL);
			//Habilita o uso de iluminação
			glEnable(GL_LIGHTING);  
			// Habilita a luz de número 0
			glEnable(GL_LIGHT1);

		}
		else {
			glDisable(GL_LIGHTING);
			glDisable(GL_LIGHT0);
		}
		glutPostRedisplay();
	}

};
