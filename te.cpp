#include <GL/glut.h>
#include <cmath>

const int WIDTH = 800;
const int HEIGHT = 600;

// player position and speed
double xPos = 0;
double yPos = 0;
double xSpeed = 0;
double ySpeed = 0;

// platform positions
const int NUM_PLATFORMS = 5;
double platformXPos[NUM_PLATFORMS];
double platformYPos[NUM_PLATFORMS];

void init()
{
    // set the initial player position and speed
    xPos = WIDTH / 2;
    yPos = HEIGHT / 2;
    xSpeed = 0;
    ySpeed = 0;

    // initialize the platform positions
    for (int i = 0; i < NUM_PLATFORMS; i++)
    {
        platformXPos[i] = rand() % WIDTH;
        platformYPos[i] = rand() % HEIGHT;
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // draw the player
    glBegin(GL_QUADS);
    glVertex2f(xPos - 10, yPos - 10);
    glVertex2f(xPos + 10, yPos - 10);
    glVertex2f(xPos + 10, yPos + 10);
    glVertex2f(xPos - 10, yPos + 10);
    glEnd();

    // draw the platforms
    for (int i = 0; i < NUM_PLATFORMS; i++)
    {
        glBegin(GL_QUADS);
        glVertex2f(platformXPos[i] - 50, platformYPos[i] - 10);
        glVertex2f(platformXPos[i] + 50, platformYPos[i] - 10);
        glVertex2f(platformXPos[i] + 50, platformYPos[i] + 10);
        glVertex2f(platformXPos[i] - 50, platformYPos[i] + 10);
        glEnd();
    }

    glutSwapBuffers();
}

void update(int value)
{
    // update the player position based
    // on the current speed
    xPos += xSpeed;
    yPos += ySpeed;

    // update the player speed based on gravity
    ySpeed -= 0.1;

    // check for collisions with the platforms
    for (int i = 0; i < NUM_PLATFORMS; i++)
    {
        // check if the player is on the platform
        if (xPos > platformXPos[i] - 50 &&
            xPos < platformXPos[i] + 50 &&
            yPos > platformYPos[i] - 10 &&
            yPos < platformYPos[i] + 10)
        {
            // if so, stop the player from falling
            ySpeed = 0;
        }
    }

    // check for collisions with the walls
    if (xPos < 0)
    {
        xPos = 0;
        xSpeed = 0;
    }

    if (xPos > WIDTH)
    {
        xPos = WIDTH;
        xSpeed = 0;
    }

    if (yPos < 0)
    {
        yPos = 0;
        ySpeed = 0;
    }

    if (yPos > HEIGHT)
    {
        yPos = HEIGHT;
        ySpeed = 0;
    }

    glutPostRedisplay();
    glutTimerFunc(1000 / 60, update, 0);
}

void keyboard(unsigned char key, int x, int y)
{
    // check for the space bar
    if (key == ' ')
    {
        // if the space bar is pressed, jump
        ySpeed = 10;
    }
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Jumper");

    glutDisplayFunc(display);
    glutTimerFunc(1000 / 60, update, 0);

    glutKeyboardFunc(keyboard);

    init();

    glutMainLoop();

    return 0;
}
