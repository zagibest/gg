#include <iostream>
#include <GL/glut.h>

float playerX = 0.0f;
float playerY = 0.0f;
float playerVY = 0.0f;
float platformX = 0.0f;
float platformY = -0.8f;
float platformVX = 0.01f;

void init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    playerX = 0.0f;
    playerY = 0.0f;
    playerVY = 0.0f;
    platformX = 0.0f;
    platformY = -0.8f;
    platformVX = 0.01f;
}

void update()
{
    playerY += playerVY;
    playerVY -= 0.001f;

    platformX += platformVX;
    if (platformX > 1.0f)
    {
        platformX = -1.0f;
    }
    if (playerY <= platformY + 0.1f && playerX >= platformX - 0.5f && playerX <= platformX + 0.5f)
    {
        playerVY = 0.03f;
    }
}

void render()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(playerX - 0.1f, playerY - 0.1f);
    glVertex2f(playerX + 0.1f, playerY - 0.1f);
    glVertex2f(playerX + 0.1f, playerY + 0.1f);
    glVertex2f(playerX - 0.1f, playerY + 0.1f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(platformX - 0.5f, platformY - 0.1f);
    glVertex2f(platformX + 0.5f, platformY - 0.1f);
    glVertex2f(platformX + 0.5f, platformY + 0.1f);
    glVertex2f(platformX - 0.5f, platformY + 0.1f);
    glEnd();

    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
    if (key == ' ')
    {
        playerVY = 0.03f;
    }
}

// Main function
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Jumper");

    init();

    glutDisplayFunc(render);
    glutIdleFunc(update);
    glutKeyboardFunc(keyboard);

    glutMainLoop();

    return 0;
}
