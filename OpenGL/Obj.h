#include <iostream>
using namespace std;
class Objeto 
{
private:
	int x,y,z,rotate =30;
	int r=0, g=0, b=1,a=0;
public:
	Objeto() {}
	~Objeto() {}
	void setX(int num) { x = num; }
	void setY(int num) { y = num; }
	void setZ(int num) { z = num; }
	void setRGB(int r, int g, int b) { this->r = r; this->g = g; this->b = b; }
	void setRGBA(int r, int g, int b, int a) { this->r = r; this->g = g; this->b = b; this->a = a; }
	void setRotate(int rotate) {this->rotate = rotate;}
	int getR() {return r;}
	int getG() {return g;}
	int getB() {return b;}
	int getA() {return a; }
	int getX() {return x;}
	int getY() {return y;}
	int getZ() {return z;}
	int getRotate() {return rotate;}
	virtual void mostrar() {}
};

class Teacup : public Objeto
{
public:
	Teacup(int x, int y, int z) {
		setX(x);
		setY(y);
		setZ(z);
	}
	Teacup(int x, int y, int z,int r,int g,int b) {
		setX(x);
		setY(y);
		setZ(z);
		setRGB(r, g, b);
	}
	~Teacup() {}
	void mostrar();
};

class Teapot : public Objeto
{
public:
	Teapot(int x, int y, int z) {
		setX(x);
		setY(y);
		setZ(z);
	}
	Teapot(int x, int y, int z, int r, int g, int b) {
		setX(x);
		setY(y);
		setZ(z);
		setRGB(r, g, b);
	}
	Teapot() {}
	~Teapot() {}
	 void mostrar();
};

class SolidCube : public Objeto
{
private:
	int size = 1.3;
public:
	SolidCube(int x, int y, int z) {
		setX(x);
		setY(y);
		setZ(z);
	}
	SolidCube(int x, int y, int z, int r, int g, int b) {
		setX(x);
		setY(y);
		setZ(z);
		setRGB(r, g, b);
	}
	~SolidCube() {}
	void setSize(int size) { this->size = size; }
	void mostrar();
};

class SolidSphere : public Objeto
{
public:
	SolidSphere(int x, int y, int z) {
		setX(x);
		setY(y);
		setZ(z);
	}
	SolidSphere(int x, int y, int z, int r, int g, int b) {
		setX(x);
		setY(y);
		setZ(z);
		setRGB(r, g, b);
	}
	~SolidSphere() {}
	void mostrar();
};

class Quadrado : public Objeto
{
public:
	Quadrado(int x, int y, int z) {
		setX(x);
		setY(y);
		setZ(z);
	}
	Quadrado(int x, int y, int z, int r, int g, int b) {
		setX(x);
		setY(y);
		setZ(z);
		setRGB(r, g, b);
	}
	~Quadrado() {}
	void mostrar();
};

class Cubo : public Objeto
{
public:
	GLfloat cor[4] = { -1, 0, 0, 1 };
	Cubo(int x, int y, int z) {
		setX(x);
		setY(y);
		setZ(z);
	}
	Cubo(int x, int y, int z, int r, int g, int b, int a) {
		setX(x);
		setY(y);
		setZ(z);
		//setRGBA(r, g, b,a);
		setCor(r, g, b, a);
	}
	~Cubo() {}
	void setCor(float r, float g, float b, float a) {
		cor[0] = r;
		cor[1] = g;
		cor[2] = b;
		cor[3] = a;
	}
	float* getCor() {
		return cor;
	}
	void mostrar();
};

class Esfera : public Objeto
{
public:
	GLfloat cor[4] = { -1, 0, 0, 1 };
	Esfera(int x, int y, int z) {
		setX(x);
		setY(y);
		setZ(z);
	}
	Esfera(int x, int y, int z, int r, int g, int b, int a) {
		setX(x);
		setY(y);
		setZ(z);
		//setRGBA(r, g, b,a);
		setCor(r, g, b, a);
	}
	~Esfera() {}
	void setCor(float r, float g, float b, float a) {
		cor[0] = r;
		cor[1] = g;
		cor[2] = b;
		cor[3] = a;
	}
	float* getCor() {
		return cor;
	}
	void mostrar();
};

class Vidro : public Objeto
{
public:
	GLfloat cor[4] = { -1, 0, 0, 1 };
	Vidro(int x, int y, int z) {
		setX(x);
		setY(y);
		setZ(z);
	}
	Vidro(int x, int y, int z, int r, int g, int b, int a) {
		setX(x);
		setY(y);
		setZ(z);
		//setRGBA(r, g, b,a);
		setCor(r, g, b, a);
	}
	~Vidro() {}
	void setCor(float r, float g, float b, float a) {
		cor[0] = r;
		cor[1] = g;
		cor[2] = b;
		cor[3] = a;
	}
	float* getCor() {
		return cor;
	}
	void mostrar();
};

void Vidro::mostrar() {
	//variaveis
	float AlfaVidro = 0.25f;
	//
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glPushMatrix();
	glTranslatef(getX(), getY(), getZ());
	glRotatef(-89, 1, 0, 0);
	glMaterialfv(GL_FRONT, GL_EMISSION, getCor());
	//desenha vidro
	static float x = -2;
	static float delta = -0.2f;
	glPushMatrix();
	glTranslated(x, 0, 0);
	if ((x > 6) || (x < -4)) {
		delta *= -1;
	}
	x += delta;
	glColor4f(1, 1, 1, AlfaVidro);
	glBegin(GL_QUADS);
	glVertex3f(-8.0f, -8.0f, 0.0f);
	glVertex3f( 8.0f, -8.0f, 0.0f);
	glVertex3f( 8.0f,  8.0f, 0.0f);
	glVertex3f(-8.0f,  8.0f, 0.0f);
	glEnd();
	glPopMatrix();
	//
	glPopMatrix();
	Sleep(20);
	//glutSwapBuffers();
	
}

void Esfera::mostrar() {
	glMaterialfv(GL_FRONT, GL_EMISSION, getCor());
	glDisable(GL_BLEND);
	glPushMatrix();
	glTranslatef(getX(), getY(), getZ());
	glRotatef(getRotate(), 1, 1, 0);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glutSolidSphere(2, 8, 8);
	glPopMatrix();
}

void Cubo::mostrar() {
	glMaterialfv(GL_FRONT, GL_EMISSION, getCor());
	glDisable(GL_BLEND);
	glPushMatrix();
	glTranslatef(getX(), getY(), getZ());
	glRotatef(getRotate(), 1, 1, 0);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glutSolidCube(2);
	glPopMatrix();
}

void Quadrado::mostrar() {
	
	glPushMatrix();
	glColor3f(0.0, 0.5, 0.5);
	glTranslatef(getX(), getY(), getZ());
	glBegin(GL_QUADS);
		glVertex3i(-25, 0, 15);
		glVertex3i(-25, 50, 15);
		glVertex3i(50, 50, 15);
		glVertex3i(50, 0, 15);
		glRotatef(getRotate(), 1, 1, 0);
	glEnd();

	glColor3f(0.0, 0.5, 0.5);
	glutWireCylinder(5, 10, 8, 2);

	glPopMatrix();
}

void Teacup::mostrar() {
	glPushMatrix();
	glColor3f(getR(), getG(), getB());
	glTranslatef(getX(), getY(), getZ());	
	glRotatef(getRotate(), 0, 1, 0);
	glutSolidTeacup(2);
	glPopMatrix();
}

void Teapot::mostrar() {
	glPushMatrix();
	glColor3f(getR(), getG(), getB());
	glTranslatef(getX(), getY(), getZ());
	glRotatef(getRotate(), 0, 1, 0);
	glutSolidTeapot(1);
	glPopMatrix();
}

void SolidCube::mostrar() {
	glPushMatrix();
	glColor3f(getR(), getG(), getB());
	glRotatef(getRotate(), 0, 1, 0);
	glTranslatef(getX(), getY(), getZ());
	glutSolidCube(size);
	glPopMatrix();
}

void SolidSphere::mostrar() {
	glPushMatrix();
	glColor3f(getR(), getG(), getB());
	glTranslatef(getX(), getY(), getZ());
	glRotatef(getRotate(), 1, 1, 0);
	glutSolidSphere(1, 32, 32);
	glPopMatrix();
}