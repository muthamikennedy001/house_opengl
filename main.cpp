#include <GL/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the roof
    GLfloat roof[6] = {-0.5f, 0.0f, 0.5f, 0.0f, 0.0f, 0.5f};
    glColor3f(0.5f, 0.0f, 0.0f);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, roof);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glDisableClientState(GL_VERTEX_ARRAY);

    // Draw the square base
    GLfloat square[8] = {-0.5f, -0.5f, -0.5f, 0.0f, 0.5f, 0.0f, 0.5f, -0.5f};
    glColor3f(0.5f, 0.5f, 0.5f);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, square);
    glDrawArrays(GL_QUADS, 0, 4);
    glDisableClientState(GL_VERTEX_ARRAY);

    // Draw the door
    GLfloat door[8] = {-0.1f, -0.5f, -0.1f, -0.2f, 0.1f, -0.2f, 0.1f, -0.5f};
    glColor3f(0.0f, 0.0f, 0.0f);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, door);
    glDrawArrays(GL_QUADS, 0, 4);
    glDisableClientState(GL_VERTEX_ARRAY);

    // Draw the windows
    GLfloat window1[8] = {
        -0.5f, -0.25f,
        -0.5f, -0.05f,
        -0.3f, -0.05f,
        -0.3f, -0.25f};
    GLfloat window2[8] = {
        0.3f, -0.25f,
        0.3f, -0.05f,
        0.5f, -0.05f,
        0.5f, -0.25f};

    glColor3f(245.0f / 255.0f, 245.0f / 255.0f, 220.0f / 255.0f);

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, window1);
    glDrawArrays(GL_QUADS, 0, 4);
    glVertexPointer(2, GL_FLOAT, 0, window2);
    glDrawArrays(GL_QUADS, 0, 4);
    glDisableClientState(GL_VERTEX_ARRAY);

    // define vertices for crosses in window 1
    GLfloat cross1[8] = {
        -0.5f, -0.25f,
        -0.3f, -0.05f,
        -0.5f, -0.05f,
        -0.3f, -0.25f};

    GLfloat cross2[8] = {
        0.3f, -0.25f,
        0.5f, -0.05f,
        0.3f, -0.05f,
        0.5f, -0.25f};

    glColor3f(0.0f, 0.0f, 0.0f); // black

    glBegin(GL_LINES);
    for (int i = 0; i < 8; i += 2)
    {
        glVertex2fv(&cross1[i]);
    }
    glEnd();

    glBegin(GL_LINES);
    for (int i = 0; i < 8; i += 2)
    {
        glVertex2fv(&cross2[i]);
    }
    glEnd();

    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("House");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
