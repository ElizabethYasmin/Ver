#pragma once

#include "Control.h"" 
using namespace System; 
using namespace System::Drawing;


class Calavera {
public:

	Calavera(int x, int y) {
		//posicion del jugador
		this->x = x;
		this->y = y;
		
		//Animacion del sprite
		ancho = 63;
		alto = 63;
		

		

	}

	~Calavera();



	Rectangle retornarRectangulo() {
		return Rectangle(x , y, ancho, alto);;
	}



		void dibujarCalavera(Graphics^ g, Bitmap^ bmpManzana, int** matriz) {

			
			CDI = Rectangle(x , y + 30, (ancho - 30), (alto - 30));
			CAA = Rectangle(x, y + 30 , (ancho - 30), (alto - 30));

			Rectangle PorcionAUsar = Rectangle(ancho, alto, ancho, alto);
			Rectangle Aumento = Rectangle(x - 14, y, ancho, alto);///Dibujo del jugador --------------------------------
			g->DrawImage(bmpManzana, Aumento, PorcionAUsar, GraphicsUnit::Pixel);

		g->DrawRectangle(Pens::Transparent, CDI);
		g->DrawRectangle(Pens::Transparent, CAA);

	}


private:
	int x;
	int y;
	
	int ancho;
	int alto;
	Rectangle CDI;
	Rectangle CAA;
	

};


