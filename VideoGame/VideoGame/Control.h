#pragma once

#include "Escenario.h"
#include"Jugador.h"
#include "ACajas.h"
#include "Enemigo.h"
#include "Calavera.h"
#include <vector>
//#include"ArrEnemigos.h"

class Controladora
{
public:
	Controladora() {
		oEscenario = new Escenario();
		oJugador = new Jugador(50, 50);//Aqui es donde el jugador iniciara la partida
		

		oArrBombas = new ACajas();
		oEnemigo = new Enemigo();

		cant = 0;
		//oCalavera = new Calavera * [cant];

		//oArrEnemigos = new ArrEnemigos();
			

		nivel = 1;
	}
	~Controladora();
	void CambiarNivel() {
		oEscenario->generarMatriz();
	}

	/*void crear_enemigos(){
		oArrEnemigos->crearEnemigos();
	}*/

	void agregarBomba() {
		oArrBombas->crear_una_bomba(oJugador->getX(), oJugador->getY());
	}

	void disminuir_Vidas_Por_Bomba() {
		int PuntaIzquierda, PuntaDerecha, CentroInicioY, CentroFinalY, PuntaSuperior, PuntaInferior,
			CentroInicioX, CentroFinalX;
		///////////////////////////-------------------------//////////////////////////////////
		for (int i = 0;i < oArrBombas->getarregloBombas().size();i++) {

			PuntaIzquierda = oArrBombas->getarregloBombas().at(i)->getX() - 100;
			PuntaDerecha = oArrBombas->getarregloBombas().at(i)->getX() + 150;
			PuntaSuperior = oArrBombas->getarregloBombas().at(i)->getY() - 100;
			PuntaInferior = oArrBombas->getarregloBombas().at(i)->getY() + 150;
			CentroInicioY = oArrBombas->getarregloBombas().at(i)->getY();
			CentroInicioX = oArrBombas->getarregloBombas().at(i)->getX();
			CentroFinalX = oArrBombas->getarregloBombas().at(i)->getX() + 50;
			CentroFinalY = oArrBombas->getarregloBombas().at(i)->getY() + 50;
			
			if (oArrBombas->getarregloBombas().at(i)->getEstado() == Estado::explosion) {
				oJugador->disminuirvidas(PuntaIzquierda, PuntaDerecha, CentroInicioY, CentroFinalY, PuntaSuperior, PuntaInferior,
					CentroInicioX, CentroFinalX);
			}
		}


	}

	void disminuir_Vidas_Por_Enemigo(){
		if(oJugador->retornarRectangulo().IntersectsWith(oEnemigo->retornarRectangulo())){
			oJugador->disminuirVidas();
		}
	}

	void dibujar(Graphics^ g, Bitmap^ bmpBase, Bitmap^ bmpSolido, Bitmap^ bmpBomba, Bitmap^ bmpExplosion, Bitmap^ bmpDestruible, Bitmap^ bmpJugador ,Bitmap^bmpEnemigo ) {
		oEscenario->PintarBase(g, bmpBase);
		oEscenario->PintarMatriz(g, bmpSolido, bmpDestruible);

		oJugador->moverJugador(g, bmpJugador, oEscenario->getmatriz());
		
		oArrBombas->dibujar_una_bomba(g, bmpBomba, bmpExplosion, oJugador->getX(), oJugador->getY(), oEscenario->getmatriz());
		



		oEnemigo->dibujar(g, bmpEnemigo,  oEscenario->getmatriz());
		oEnemigo->animar();

		disminuir_Vidas_Por_Enemigo();



		disminuir_Vidas_Por_Bomba();
	}

	
	/*void crear_enemigos_y_mejoras(){
		oArrEnemigos->crearEnemigos();
	}*/
	



	Jugador* getoJugador() {
		return oJugador;
	}
	
	Enemigo* getoEnemigo() {
		return oEnemigo;
	}

	/*ArrEnemigos  *getoArrEnemigos(){
		return oArrEnemigos;
	}*/

	int getNivel() {
		return nivel;
	}
	




	/*

	//////////////////////////////////////////////////
	void MoverGatos(Graphics^ g)
	{
		for (int i = 0;i < cant;i++) {
			if (oCalavera[i]->GetX() > oJugador->GetX())
				oCalavera[i]->Mover(Direccion::Izquierda, g);

			else if (oCalavera[i]->GetX() < oJugador->GetX())
				oCalavera[i]->Mover(Direccion::Derecha, g);



			if (oCalavera[i]->GetY() > oJugador->GetY())
				oCalavera[i]->Mover(Direccion::Arriba, g);

			else if (oCalavera[i]->oJugador() < paloma->GetY())
				oCalavera[i]->Mover(Direccion::Abajo, g);
		}
	}

	void MostrarCalaveras(Graphics^ g, Bitmap^ img)
	{
		for (int i = 0;i < cant;i++) {
			oCalavera[i]->Mostrar(g, img);
		}
		//oJugador->MoverBalas();
	}

	void AgregarGatos(int n)//agregando elementos a un arreglo 
	{
		for (int m = 0;m < n;m++) {

			Calavera** aux = new Calavera * [cant + 1];

			for (int i = 0;i < cant;i++)
				aux[i] = oCalavera[i];

			aux[cant] = new Calavera();

			oCalavera = aux;
			cant++;
		}
	}

	////////////////////////////////////////////////////////////////////////

	*/


private:
	Escenario* oEscenario;
	Jugador* oJugador;
	ACajas* oArrBombas;
	Enemigo *oEnemigo;
	//Calavera** oCalavera;  // 
	





	int cant;
	//ArrEnemigos *oArrEnemigos;
	int nivel;

};


