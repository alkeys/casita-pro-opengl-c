//
// Created by alex on 2/03/23.
//

/**
 *  ▄▀▀█▄▄   ▄▀▀▄ ▀▀▄      ▄▀▀█▄   ▄▀▀▄ ▄▀▀▄  ▄▀▀█▀▄   ▄▀▀▀▀▄     ▄▀▀█▄▄▄▄  ▄▀▀▀▀▄
▐ ▄▀   █ █   ▀▄ ▄▀     ▐ ▄▀ ▀▄ █   █    █ █   █  █ █    █     ▐  ▄▀   ▐ █ █   ▐
  █▄▄▄▀  ▐     █         █▄▄▄█ ▐  █    █  ▐   █  ▐ ▐    █       █▄▄▄▄▄     ▀▄
  █   █        █        ▄▀   █    █   ▄▀      █        █        █    ▌  ▀▄   █
 ▄▀▄▄▄▀      ▄▀        █   ▄▀      ▀▄▀     ▄▀▀▀▀▀▄   ▄▀▄▄▄▄▄▄▀ ▄▀▄▄▄▄    █▀▀▀
█    ▐       █         ▐   ▐              █       █  █         █    ▐    ▐
▐            ▐                            ▐       ▐  ▐         ▐
         ▄▀▀▄ ▄▀▄  ▄▀▀▀▀▄   ▄▀▀▄▀▀▀▄  ▄▀▀█▄   ▄▀▀▄ ▀▄
        █  █ ▀  █ █      █ █   █   █ ▐ ▄▀ ▀▄ █  █ █ █
        ▐  █    █ █      █ ▐  █▀▀█▀    █▄▄▄█ ▐  █  ▀█
          █    █  ▀▄    ▄▀  ▄▀    █   ▄▀   █   █   █
        ▄▀   ▄▀     ▀▀▀▀   █     █   █   ▄▀  ▄▀   █
        █    █             ▐     ▐   ▐   ▐   █    ▐
        ▐    ▐                               ▐
 */

#include "ventana.h"

#include "GL/glut.h"
#include "GL/gl.h"
#include "ventana.h"
#include "GL/freeglut.h"
#include "math.h"
#include "lib/util.h"

void iniciar() {
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 600, 0, 600);

}

void iniciarGraficos() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.42, 0.82, 0.82, 1);
    crearSol();
    mountCrear(0, 100);
    calle();
    crearCasa();
    Carro(100, 100, 50, 40, 0.97, 0.25, 0.43);
    generarnubes(100, 480, 1, 1, 1);
    generarnubes(160, 520, 1, 1, 1);
    generarnubes(250, 460, 1, 1, 1);
    generarnubes(350, 450, 1, 1, 1);
    generarnubes(500, 450, 1, 1, 1);
    generarnubes(240, 400, 1, 1, 1);
    arboles(50, 100, 10);
    arboles(300, 100, 10);
    carnetDibujo(320,100);
    glFlush();
}

void carnetDibujo(float x, float y) {
    //la altura sera de 15pix max
    //leta A
    dda(x,y,x+5,y+15,0,0,0);
    dda(x+5,y+15,x+10,y,0,0,0);
    dda(x+2.5,y+7.5,x+8.5,y+7,0,0,0);
    //
    //letra m
    x+=15;
    dda(x,y,x+5,y+15,0,0,0);
    dda(x+5,y+15,x+10,y+7,0,0,0);
    dda(x+10,y+7,x+15,y+15,0,0,0);
    dda(x+15,y+15,x+20,y,0,0,0);
    //
    //uno
    x+=30;
    dda(x,y,x,y+15,0,0,0);
    dda(x-5,y,x+5,y,0,0,0);
    dda(x-5,y+7,x,y+15,0,0,0);
    //
    //ocho
    x+=10;
    dda(x,y,x,y+15,0,0,0);
    dda(x,y+15,x+10,y+15,0,0,0);
    dda(x,y,x+10,y,0,0,0);
    dda(x,y+7,x+10,y+7,0,0,0);
    dda(x+10,y,x+10,y+15,0,0,0);
    //
    //cero
    x+=15;
    dda(x,y,x,y+15,0,0,0);
    dda(x,y+15,x+10,y+15,0,0,0);
    dda(x,y,x+10,y,0,0,0);
    dda(x+10,y,x+10,y+15,0,0,0);
    //
    //cero
    x+=15;
    dda(x,y,x,y+15,0,0,0);
    dda(x,y+15,x+10,y+15,0,0,0);
    dda(x,y,x+10,y,0,0,0);
    dda(x+10,y,x+10,y+15,0,0,0);
    //
    //siete
    x+=20;
    dda(x,y,x,y+15,0,0,0);
    dda(x-5,y+10,x,y+15,0,0,0);
    dda(x-5,y+7,x+5,y+7,0,0,0);
    //
}


void arboles(float x, float y, int l) {
    rectangulo(x, y, l * 2, l * 4, 0.46, 0.34, 0.28);
    triangulo(x - l * 4, y + l * 4, l * 5, 0.44, 0.78, 0.55);
}


void mountCrear(float x, float y) {
    int n = 37; // número inicial
    float x1 = x; // coordenada x inicial
    float y1 = y; // coordenada y inicial
    glColor3f(0.26, 0.58, 0.06);
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    /**
     * Congettura di Collatz para las montañas
     */
    do {
        glVertex2f(x, y + n + 250);
        if (n % 2 == 0) {
            //par se divide ente 2
            n = n / 2;
        } else {
            //impar multiplica por3 y se le suma 1
            n = (n * 3) + 1;
        }

        x += 40;
    } while (n != 1);
    glVertex2f(600, 0);
    glEnd();

}

void keyEvent(unsigned char c, int x, int y) {
    if (c) {
        generarHumoCasa(530, 345, 4, 1, 1, 1);
        glFlush();
    }
}

void mouseEvent(int boton, int estado, int x, int y) {
    if (boton == GLUT_LEFT_BUTTON && estado == GLUT_DOWN) {
        senalTransito();
        glFlush();
    }

}

void crearSol() {
    crearCirculo(400, 500, 60, 1, 1, 0);
}

void crearCasa() {
    ///CREANDO CASA
    rectangulo(520, 101, 60, 150, 0.35, 0.31, 0.83);
    //para delantera
    rectangulo(420, 101, 100, 150, 0.46, 0.42, 0.94);
    //chimenea
    rectangulo(550, 250, 30, 100, 0.19, 0.21, 0.17);
    //techo
    triangulo(420, 250, 75, 0.19, 0.21, 0.17);
    //puerta
    rectangulo(450, 101, 20, 50, 1, 1, 1);
    //ventanas
    rectangulo(490, 150, 20, 30, 1, 1, 1);
    cruz(500, 165, 10, 15);
    rectangulo(550, 150, 20, 30, 1, 1, 1);
    cruz(560, 165, 12, 15);
    ////
    crearCirculo(470, 230, 20, 0.65, 0.42, 0.94);

////////////////////////////////
}

void Carro(float x, float y, int xL, int yL, float R, float G, float B) {
    int cabesaL = xL + 50;
    //carroceria
    rectangulo(x, y, xL + 50, yL, R, G, B);
    rectangulo(x + cabesaL, y, 60, yL + 50, R, G, B);
    //carroceria
    //ventana
    rectangulo(x + cabesaL + 25, y + 50, 30, 25, 1, 1, 1);
    //ruedas
    crearCirculo(x + 30, y, 25, 1, 1, 1);
    crearCirculo(x + 30, y, 15, 0, 0, 0);
    crearCirculo(x + cabesaL + 30, y, 25, 1, 1, 1);
    crearCirculo(x + cabesaL + 30, y, 15, 0, 0, 0);
    //escape
    rectangulo(x + cabesaL, y + yL, 10, 70, 0.14, 0.14, 0.14);
    generarHumo(x + cabesaL + 5, y + yL + 38, -4, 1, 0.72, 0.75, 0.71);

}

void generarHumo(float x, float y, float orientacionHumo, int cantLineas, float R, float G, float B) {
    int xAux = x;
    double curva;
    double curva2;
/**
 * se genrara humo con la funcion seno es mejor que la de parabola
 */
    for (int j = 0; j < cantLineas; ++j) {
        x = xAux + 5 * j;
        for (float i = 5; i < 100; i += 5) {
            curva = sqrt(x * i);
            crearCirculo(x, y + curva, 5, R, G, B);
            x += orientacionHumo;
        }
    }
}


void generarHumoCasa(float x, float y, int cantLineas, float R, float G, float B) {
    float xAux = x;
    double curva;
    double curva2;
    x = y;
    y = xAux;

/**
 * se genrara humo con la funcion seno es mejor que la de parabola
 */    glColor3f(R, G, B);
    for (int i = 0; i < cantLineas; ++i) {
        for (float x1 = -1.0f; x1 < 20; x1 += 0.9) {
            curva = y + sin(2 * M_PI * x + x1) * 4 + 30;
            curva2 = x + x1 * 6 + 15;
            crearCirculo(curva, curva2, 5, 1, 1, 1);
        }
        y += i * 5;
    }

}


void generarnubes(float x, float y, float R, float G, float B) {
    float a = 9;
    float b = 3;
    for (float theta = 0; theta < 100; theta += 10) {
        float fx = x + a * cos(theta) * 3;
        float fy = y + b * sin(theta) * 3;
        crearCirculo(fx, fy, 20, R, G, B);

    }
}

void calle() {
    glColor3f(0.15, 0.16, 0.16);
    glBegin(GL_QUADS);
    glVertex2f(0, 100);
    glVertex2f(600, 100);
    glVertex2f(600, 0);
    glVertex2f(0, 0);
    /**
     * LINEA CENTRA DE CALLE
     * */
    glColor3f(1, 1, 1);

    for (int i = 20; i < 600; i += 60) {
        glVertex2f(i, 51);
        glVertex2f((i + 40), 51);
        glVertex2f((i + 40), 49);
        glVertex2f(i, 49);
    }
    /**
     * lineas de la orilla de calle
     */
    glColor3f(1, 1, 1);
    glVertex2f(0, 1.5);
    glVertex2f((600), 1.5);
    glVertex2f(600, 0);
    glVertex2f(0, 0);

    glVertex2f(0, 101);
    glVertex2f((600), 101);
    glVertex2f(600, 99);
    glVertex2f(0, 99);
    /////////////////////////////

    glEnd();

}

void senalTransito() {
    /**
     * la calle termina en y=100
     */
    glColor3f(1, 1, 1);
    glBegin(GL_QUADS);
    glVertex2f(60, 180);
    glVertex2f(65, 180);
    glVertex2f(65, 100);
    glVertex2f(60, 100);
    glEnd();
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(30, 200);
    glVertex2f(30, 225);
    glVertex2f(50, 250);
    glVertex2f(75, 250);
    glVertex2f(95, 225);
    glVertex2f(95, 200);
    glVertex2f(75, 180);
    glVertex2f(50, 180);
    glEnd();
    glColor3f(1, 1, 1);
    glRasterPos2f(45, 210);
    glutBitmapString(GLUT_BITMAP_8_BY_13, "ALTO");
    glFlush();

}