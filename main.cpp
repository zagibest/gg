#include <iostream>
#include <GL/glut.h>

int playerX = 800 / 2;
int playerY = 0;
int playerSize = 20;

int gravity = 1;
int jumpVelocity = 20;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 1, 0);
    glBegin(GL_QUADS);
    glVertex2i(playerX - playerSize / 2, playerY - playerSize / 2);
    glVertex2i(playerX + playerSize / 2, playerY - playerSize / 2);
    glVertex2i(playerX + playerSize / 2, playerY + playerSize / 2);
    glVertex2i(playerX - playerSize / 2, playerY + playerSize / 2);
    glEnd();

    glutSwapBuffers();
}

void update()
{
    playerY += gravity;
    if (playerY < 0)
        playerY = 0;

    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
    if (key == ' ')
    {
        playerY += jumpVelocity;
    }
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Jumper");

    glutDisplayFunc(display);
    glutIdleFunc(update);

    glutKeyboardFunc(keyboard);

    glutMainLoop();

    return 0;
}