#include "Objetos.h"
#include "GL\freeglut.h"
#include <iostream>
#include <string>

namespace OpenGL {
	class Objeto {
		private:
			int x;
			int y;
		public:
			Objeto(){};
			~Objeto(){};
			virtual void print();
	};
}

