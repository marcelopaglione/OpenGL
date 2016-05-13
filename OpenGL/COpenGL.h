#include "config.h"
#include <vector>
namespace OpenGL {

class COpenGL {
	private:
		int Height;
		int Width;
		bool FullScreen;
		string Title;
		int PosX;
		int PosY;
		int selectedMenu;
		int window;

		double ObsX;
		double ObsY;
		double ObsZ;
		double FAspect;
		double Near;
		double Far;
	public:
		COpenGL();
		~COpenGL();

		Luz4d luzAmbiente;
		Luz4d luzDifusa;
		Luz4d luzEspecular;
		Vetor4d posicaoLuz;

		void InitOpenGL(int* argC, char **argV);
		void setWindowGL(string title, int heigth, int width, int posx, int posy, bool fullscreen);
		void setRenderFunc(void func(void));
		void setResize();
		void setObserver(double x, double y, double z, double zoom);
		void setMenu(void func());
		int getSelectedMenu();
		void setKeyboardFunc(void func(unsigned char Tecla, int X, int Y));
		void setMouseFunc(void func(int button, int state, int x, int y));
		void setLight(bool OnOff);
		void Loop();
		void setFAspect();

	};
};