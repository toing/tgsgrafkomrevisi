#include <windows.h>
#include <GL/glut.h>

typedef float M3DVector3f[3];
// puteran
static GLfloat xRot = 0.0f;
static GLfloat yRot = 0.0f;

void m3dFindNormal(M3DVector3f result, const M3DVector3f point1, const M3DVector3f point2,
        const M3DVector3f point3) {
    M3DVector3f v1, v2;
}

void RenderScene(void) {
    GLUquadricObj *pObj;
    M3DVector3f vNormal;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    glTranslatef(0.0f, 10.0f, 0.0f);
    glRotatef(xRot, 1.0f, 0.0f, 0.0f);
    glRotatef(yRot, 0.0f, 1.0f, 0.0f);

    // Mengatur warna
    glColor3ub(128, 128, 128);
    pObj = gluNewQuadric();
    gluQuadricNormals(pObj, GLU_SMOOTH);
    
    // Kontrol menggunakan key board untuk menggerakan objek

    void SpecialKeys(int key, int x, int y) {

        if (key == GLUT_KEY_LEFT)
            yRot -= 5.0f;

        if (key == GLUT_KEY_RIGHT)
            yRot += 5.0f;

        glutPostRedisplay();
    }

    void ChangeSize(int w, int h) {
        GLfloat fAspect;
        GLfloat lightPos[] = {-50.f, 50.0f, 100.0f, 1.0f};

        if (h == 0)
            h = 1;

        glViewport(0, 0, w, h);

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();

        fAspect = (GLfloat) w / (GLfloat) h;
        gluPerspective(45.0f, fAspect, 1.0f, 225.0f);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
        glTranslatef(0.0f, 0.0f, -50.0f);
    }
