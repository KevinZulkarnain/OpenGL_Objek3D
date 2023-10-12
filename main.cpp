#include <GL/glut.h>

GLfloat vertices[][3] = {
    {-0.5, -0.5, -1.0},  // Titik A
    {0.5, -0.5, -1.0},   // Titik B
    {0.5, 0.5, -1.0},    // Titik C
    {-0.5, 0.5, -1.0},   // Titik D
    {-0.5, -0.5, 0.5},   // Titik E
    {0.5, -0.5, 0.5},    // Titik F
    {0.5, 0.5, 0.5},     // Titik G
    {-0.5, 0.5, 0.5}     // Titik H
};


GLfloat colors[][3] = {
    {0.0, 0.0, 0.0},
    {1.0, 0.0, 0.0},
    {1.0, 1.0, 0.0},
    {0.0, 1.0, 0.0},
    {0.0, 0.0, 1.0},
    {1.0, 0.0, 1.0},
    {1.0, 1.0, 1.0},
    {0.0, 1.0, 1.0}
};

GLfloat angleX = 0.0f;
GLfloat angleY = 0.0f;

void polygon(int a, int b, int c, int d) {
    glBegin(GL_POLYGON);
    glColor3fv(colors[a]);
    glVertex3fv(vertices[a]);
    glColor3fv(colors[b]);
    glVertex3fv(vertices[b]);
    glColor3fv(colors[c]);
    glVertex3fv(vertices[c]);
    glColor3fv(colors[d]);
    glVertex3fv(vertices[d]);
    glEnd();
}

void drawEdges() {
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f); // Warna hitam untuk garis

    // Menggambar garis sudut
    glVertex3fv(vertices[0]);
    glVertex3fv(vertices[1]);
    glVertex3fv(vertices[1]);
    glVertex3fv(vertices[2]);
    glVertex3fv(vertices[2]);
    glVertex3fv(vertices[3]);
    glVertex3fv(vertices[3]);
    glVertex3fv(vertices[0]);

    glVertex3fv(vertices[4]);
    glVertex3fv(vertices[5]);
    glVertex3fv(vertices[5]);
    glVertex3fv(vertices[6]);
    glVertex3fv(vertices[6]);
    glVertex3fv(vertices[7]);
    glVertex3fv(vertices[7]);
    glVertex3fv(vertices[4]);

    glVertex3fv(vertices[0]);
    glVertex3fv(vertices[4]);
    glVertex3fv(vertices[1]);
    glVertex3fv(vertices[5]);
    glVertex3fv(vertices[2]);
    glVertex3fv(vertices[6]);
    glVertex3fv(vertices[3]);
    glVertex3fv(vertices[7]);


    // Menambahkan garis tengah kedua sisi atas
    glVertex3fv(vertices[0]);
    glVertex3fv(vertices[2]);
    glVertex3fv(vertices[1]);
    glVertex3fv(vertices[3]);

    // Menggambar garis penutup bawah
    glVertex3fv(vertices[4]);
    glVertex3fv(vertices[5]);
    glVertex3fv(vertices[6]);
    glVertex3fv(vertices[7]);

    // Menambahkan garis tengah kedua sisi bawah
    glVertex3fv(vertices[4]);
    glVertex3fv(vertices[6]);
    glVertex3fv(vertices[5]);
    glVertex3fv(vertices[7]);

    glEnd();
}


void colorCube() {
    glBegin(GL_QUADS);

    // Sisi depan
    glColor3f(0.7f, 0.4f, 0.1f); // Warna coklat cerah
    glVertex3fv(vertices[0]);
    glVertex3fv(vertices[1]);
    glVertex3fv(vertices[2]);
    glVertex3fv(vertices[3]);

    // Sisi belakang
    glColor3f(0.7f, 0.4f, 0.1f); // Warna coklat cerah
    glVertex3fv(vertices[4]);
    glVertex3fv(vertices[5]);
    glVertex3fv(vertices[6]);
    glVertex3fv(vertices[7]);

    // Sisi kiri
    glColor3f(0.7f, 0.4f, 0.1f); // Warna coklat cerah
    glVertex3fv(vertices[0]);
    glVertex3fv(vertices[3]);
    glVertex3fv(vertices[7]);
    glVertex3fv(vertices[4]);

    // Sisi kanan
    glColor3f(0.7f, 0.4f, 0.1f); // Warna coklat cerah
    glVertex3fv(vertices[1]);
    glVertex3fv(vertices[2]);
    glVertex3fv(vertices[6]);
    glVertex3fv(vertices[5]);

    // Sisi atas
    glColor3f(0.7f, 0.4f, 0.1f); // Warna coklat cerah
    glVertex3fv(vertices[3]);
    glVertex3fv(vertices[2]);
    glVertex3fv(vertices[6]);
    glVertex3fv(vertices[7]);

    // Sisi bawah
    glColor3f(0.7f, 0.4f, 0.1f); // Warna coklat cerah
    glVertex3fv(vertices[0]);
    glVertex3fv(vertices[1]);
    glVertex3fv(vertices[5]);
    glVertex3fv(vertices[4]);

    glEnd();

    drawEdges();
}

void display() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Warna latar belakang putih
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDisable(GL_CULL_FACE); // Menonaktifkan culling
	

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

	
	glLineWidth(2.0f); // Mengatur ketebalan garis
    glTranslatef(0.0f, 0.0f, -5.0f);
    glRotatef(angleX, 1.0f, 0.0f, 0.0f);
    glRotatef(angleY, 0.0f, 1.0f, 0.0f);
    


    colorCube();
    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2.0, 2.0, -2.0, 2.0, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
}

void specialKeys(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_RIGHT:
            angleY += 5.0f;
            break;
        case GLUT_KEY_LEFT:
            angleY -= 5.0f;
            break;
        case GLUT_KEY_UP:
            angleX += 5.0f;
            break;
        case GLUT_KEY_DOWN:
            angleX -= 5.0f;
            break;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Kardus Lab 3D");

    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutSpecialFunc(specialKeys);

    glutMainLoop();

    return 0;
}

