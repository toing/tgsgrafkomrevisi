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
    //Memebuat Objek kepala
    glColor3ub(205, 133, 63); //body color
    gluSphere(pObj, 2.5f, 26, 13);

    glPushMatrix();
    glColor3ub(0.0f, 0.0f, 0.0f);
    glTranslatef(-1.0, -0.20, 2.4f);
    gluSphere(pObj, 0.4f, 26, 13); //mata kiri
    glTranslatef(2.0, 0.0, 0.0f);
    gluSphere(pObj, 0.4f, 26, 13); //mata kanan
    glPopMatrix();

    //telinga
    glPushMatrix();
    glColor3ub(205, 133, 63); //body color
    glTranslatef(-2.2f, -0.50f, 0.30f);
    gluSphere(pObj, 0.6f, 26, 13); //Telinga kiri
    glTranslatef(4.4f, 0.0f, 0.0f);
    gluSphere(pObj, 0.6f, 26, 13); //telinga kanan
    glPopMatrix();

    //Topi
    glColor3ub(20, 50, 100); //hat color
    glPushMatrix();
    glRotatef(240.0f, 1.0f, 0.0f, 0.0f);
    glDisable(GL_CULL_FACE);
    gluCylinder(pObj, 3.0f, 0.0f, 6.0f, 26, 1);
    gluCylinder(pObj, 3.0f, 4.0f, 0.5f, 26, 1);
    glEnable(GL_CULL_FACE);
    glPopMatrix();

    //leher dan kaki
    glColor3ub(205, 133, 63);
    glPushMatrix();
    glRotatef(90.0f, 1.0, 0.0, 0.0f);
    glDisable(GL_CULL_FACE);
    gluCylinder(pObj, 0.5f, 0.5f, 20.0f, 26, 13);
    glTranslatef(0.0f, 0.0f, 29.0f);
    glPopMatrix();

    //Tangan
    //Membuat objek tangan kiri
    glColor3ub(205, 133, 63); //body color
    glPushMatrix();
    glTranslatef(0.0f, -3.6f, 0.0f);
    glRotatef(160.0f, 1.0, 0.0, 1.0f);
    gluCylinder(pObj, 0.5f, 0.5f, 9.0f, 26, 13);
    glTranslatef(0.0f, 0.0f, 13.0f);
    glPopMatrix();
    //Membuat objek tangan kanan
    glColor3ub(205, 133, 63); //body color
    glPushMatrix();
    glTranslatef(0.0f, -3.6f, 0.0f);
    glRotatef(160.0f, 1.0, 0.0, -1.0f);
    gluCylinder(pObj, 0.5f, 0.5f, 9.0f, 26, 13);
    glTranslatef(0.0f, 0.0f, 13.0f);
    glPopMatrix();
        glColor3ub(10, 10, 10);
    glBegin(GL_TRIANGLES);
    {
        M3DVector3f vPoints[3] = {
            {3.0f, -3.50f, -0.70f},
            { 3.40f, -10.0f, -3.10f},
            {-3.0f, -3.50f, -0.70f}
        };

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
        glVertex3fv(vPoints[0]);
        glVertex3fv(vPoints[1]);
        glVertex3fv(vPoints[2]);
    }
    {
        M3DVector3f vPoints[3] = {
            {-3.0f, -3.50f, -0.70f},
            {3.40f, -10.0f, -3.10f},
            { -3.40f, -10.0f, -3.10f}
        };

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
        glVertex3fv(vPoints[0]);
        glVertex3fv(vPoints[1]);
        glVertex3fv(vPoints[2]);
    }

    glEnd();

    //rok
    glColor3ub(92, 51, 10);
    glPushMatrix();
    glTranslatef(0.0f, -2.0f, 0.0f);
    glRotatef(90, 1.0f, 0.0f, 0.0f);
    gluCylinder(pObj, 0.0f, 7.0f, 13.0f, 26, 13);
    glPopMatrix();
    //sabuk
    glPushMatrix();
    glColor3ub(0, 0, 0);
    glTranslatef(0.0f, -10.3f, 0.0f);
    glRotatef(90, 1.0f, 0.0f, 0.0f);
    gluCylinder(pObj, 3.3f, 3.5f, 0.8f, 26, 13);
    glPopMatrix();

    glPopMatrix();
    glutSwapBuffers();
}
void SetupRC() {
    // Menetukan nilai coordinat dan pencahayaan
    GLfloat ambientLight[] = {0.3f, 0.3f, 0.3f, 1.0f};
    GLfloat diffuseLight[] = {0.7f, 0.7f, 0.7f, 1.0f};
    GLfloat specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat specref[] = {1.0f, 1.0f, 1.0f, 1.0f};

    glEnable(GL_DEPTH_TEST);
    glFrontFace(GL_CCW); 
    glEnable(GL_CULL_FACE); 

    // Enable lighting
    glEnable(GL_LIGHTING);

    // Mengatur cahaya pada objek
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
    glEnable(GL_LIGHT0);


    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);


    glMaterialfv(GL_FRONT, GL_SPECULAR, specref);
    glMateriali(GL_FRONT, GL_SHININESS, 128);

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glEnable(GL_NORMALIZE);
}

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
int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutCreateWindow(".:Orang-Orangan Sawah 3D");
    glutReshapeFunc(ChangeSize);
    glutSpecialFunc(SpecialKeys);
    glutDisplayFunc(RenderScene);
    SetupRC();
    glutMainLoop();

    return 0;
}

