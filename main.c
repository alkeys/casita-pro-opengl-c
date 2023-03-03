#include <stdio.h>
#include "GL/gl.h"
#include "GL/glut.h"
#include "ventana.h"
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

int main(int argc,char** argv) {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowPosition(500,200);
    glutInitWindowSize(600,600);
    glutCreateWindow("Casita Pro");

    iniciar();
    glutDisplayFunc(iniciarGraficos);
    glutKeyboardFunc(keyEvent);
    glutMouseFunc(mouseEvent);
    glutMainLoop();return 0;
}
