#include<windows.h>
#include<GL/glut.h>
#include<stdio.h>
#include <stdlib.h>
#include <math.h>

GLfloat vertices[] = {
    0.0f, 0.7f, 0.0f,   // Top vertex (red)
   -0.3f, 0.1f, 0.0f,   // Bottom-left vertex (green)
    0.3f, 0.1f, 0.0f    // Bottom-right vertex (blue)
};

void drawSquare() {
    glBegin(GL_POLYGON);

    // Vertex 1 (top-left)
    glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(-0.2f, 0.1f);

    // Vertex 2 (top-right)

    glVertex2f(0.2f, 0.1f);

    // Vertex 3 (bottom-right)
    glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(0.2f, -0.3f);

    // Vertex 4 (bottom-left)
	 glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(-0.2f, -0.3f);

    glEnd();
}

void drawOutline() {
    // blue outline (right side)
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_LINES);
    glVertex2f(0.2f, 0.1f);
    glVertex2f(0.2f, -0.3f);
    glEnd();

    // Green outline (bottom side)
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(0.2f, -0.3f);
    glVertex2f(-0.2f, -0.3f);
    glEnd();

    // Blue outline (left side)
    glColor3f(1.0f, 0.0f, 1.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.2f, -0.3f);
    glVertex2f(-0.2f, 0.1f);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_TRIANGLES);

    // Triangle (roof of the hut)
    glColor3f(0.0f, 0.0f, 1.0f); // blue for the top part of the triangle
    glVertex3fv(&vertices[0]);
    glColor3f(1.0f, 0.0f, 0.0f); // red for the bottom-left part of the triangle
    glVertex3fv(&vertices[3]);
    glColor3f(0.0f, 1.0f, 0.0f); // red for the bottom-right part of the triangle
    glVertex3fv(&vertices[6]);

    glEnd();

    // Draw the lower part of the hut (square with outline)
    glTranslatef(0.0f,- 0.00f, 0.0f); // Move down and adjust as needed
    drawSquare();
    drawOutline();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("MY HUT");

    // Set the display function
    glutDisplayFunc(display);

    // Set the clear color (background color)
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black background

    glutMainLoop();
    return 0;
}
