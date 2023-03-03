//
// Created by alex on 2/03/23.
//

#ifndef CASAPRO_VENTANA_H
#define CASAPRO_VENTANA_H
void iniciar();
void iniciarGraficos();
void calle();
void senalTransito();
void generarHumo(float x,float y,float orientacionHumo,int cantLineas,float R, float G, float B);
void Carro(float x, float y, int xL, int yL,float R,float G,float B);
void crearCasa();
void crearSol();
void keyEvent(unsigned  char c ,int x,int y);
void mouseEvent(int boton,int estado,int x,int y);
void mountCrear(float  x,float y);
void arboles(float x,float y,int l);
void generarnubes(float x, float y, float R, float G, float B);
void generarHumoCasa(float x, float y, int cantLineas, float R, float G, float B);

#endif //CASAPRO_VENTANA_H
