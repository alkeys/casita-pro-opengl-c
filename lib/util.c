//
// Created by alex on 2/03/23.
//
/**
 ▄▀▀█▄▄   ▄▀▀▄ ▀▀▄      ▄▀▀█▄   ▄▀▀▄ ▄▀▀▄  ▄▀▀█▀▄   ▄▀▀▀▀▄     ▄▀▀█▄▄▄▄  ▄▀▀▀▀▄
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



#include "util.h"
#include "GL/gl.h"
#include "math.h"
#include "stdio.h"

void cruz(float x, float y, int xL, int Ly) {

    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2f(x - xL, y);
    glVertex2f(x + xL, y);
    glVertex2f(x, y + Ly);
    glVertex2f(x, y - Ly);
    glEnd();
}

void triangulo(float x, float y, float l, float R, float G, float B) {
    /**
     * la funci se aumente por 50 por cada l
     */
    glColor3f(R, G, B);
    double lMax = l * 2;
    glBegin(GL_TRIANGLES);
    glVertex2f(x, y);
    glVertex2f((x * 2 + lMax) / 2, (y + lMax));
    glVertex2f(x + lMax, y);
    glEnd();
}

void rectangulo(float x, float y, int xL, int Ly, float R, float G, float B) {
    /**
     *
     */
    glColor3f(R, G, B);
    glBegin(GL_QUADS);
    glVertex2i(x, y + Ly);
    glVertex2i(x + xL, y + Ly);
    glVertex2i(x + xL, y);
    glVertex2i(x, y);
    glEnd();
}

void crearCirculo(float x, float y, int r, float R, float G, float B) {
//formula x2+y2=r2
//y=sqrt(r2-x2)
    r -= 2;
    double margenRadio, x2, y2;
    float abancePixel = 0.01;
    glColor3f(R, G, B);
    glBegin(GL_LINES);
    for (float i = -1; i < r; i += abancePixel) {
        margenRadio = (sqrt(pow(r, 2) - pow(i, 2)));

        //para el cuadrante 1 y 3
        glVertex2f(x + i, y + margenRadio);
        glVertex2f(x - i, y - margenRadio);
        //////////////
        //cuaqdrante 2 y 4
        glVertex2f(x - i, y + margenRadio);
        glVertex2f(x + i, y - margenRadio);
    }
    glEnd();
}

void lineasAlgoritmos(float x1, float y1, float x2, float y2) {
    float dx = x2 - x1;
    float dy = y2 - y1;
    float pasos,xIncrementos, yIncrementos, x = x1, y = y1;
    pasos= fabs(dx)> fabs(dy)? fabs(dx): fabs(dy);
    xIncrementos = dx / pasos;
    yIncrementos = dy / pasos;
    glBegin(GL_POINTS);
    for (int i = 0; i < pasos; ++i) {
        glVertex2f(x,y);
        x+=xIncrementos;
        y+=yIncrementos;
    }
    glEnd();
}










