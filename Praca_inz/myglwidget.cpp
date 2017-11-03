#include "myglwidget.h"

MyGLWidget::MyGLWidget(QWidget *parent)
    : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
    xRot = 0;
    yRot = 0;
    zRot = 0;
}

MyGLWidget::~MyGLWidget()
{
}

static void qNormalizeAngle(int &angle)
{
    while (angle < 0)
        angle += 360 * 16;
    while (angle > 360)
        angle -= 360 * 16;
}

void MyGLWidget::setXRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != xRot) {
        xRot = angle;
        emit xRotationChanged(angle);
        updateGL();
    }
}

void MyGLWidget::setYRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != yRot) {
        yRot = angle;
        emit yRotationChanged(angle);
        updateGL();
    }
}

void MyGLWidget::setZRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != zRot) {
        zRot = angle;
        emit zRotationChanged(angle);
        updateGL();
    }
}

void MyGLWidget::initializeGL()
{
//    qglClearColor(Qt::black);

//    glEnable(GL_DEPTH_TEST);
//    glEnable(GL_CULL_FACE);
//    glShadeModel(GL_SMOOTH);
//    glEnable(GL_LIGHTING);
//    glEnable(GL_LIGHT0);

//    static GLfloat lightPosition[4] = { 0, 0, 10, 1.0 };
//    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
}

void MyGLWidget::paintGL()
{
    clear();
    draw();
}

void MyGLWidget::resizeGL(int width, int height)
{
    int side = qMin(width, height);
    glViewport((width - side) / 2, (height - side) / 2, side, side);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
#ifdef QT_OPENGL_ES_1
    glOrthof(-2, +2, -2, +2, 1.0, 15.0);
#else
    glOrtho(-2, +2, -2, +2, 1.0, 15.0);
#endif
    glMatrixMode(GL_MODELVIEW);
}

void MyGLWidget::mousePressEvent(QMouseEvent *event)
{
    lastPos = event->pos();
}

void MyGLWidget::mouseMoveEvent(QMouseEvent *event)
{
    int dx = event->x() - lastPos.x();
    int dy = event->y() - lastPos.y();
    if (event->buttons() & Qt::LeftButton) {
        setXRotation(xRot + 8 * dy);
        setYRotation(yRot + 8 * dx);
    } else if (event->buttons() & Qt::RightButton) {
        setXRotation(xRot + 8 * dy);
        setZRotation(zRot + 8 * dx);
    }

    lastPos = event->pos();
}

void MyGLWidget::draw()
{
//    qglColor(Qt::red);
//    glBegin(GL_QUADS);
//        glNormal3f(0,0,-1);
//        glVertex3f(-1,-1,0);
//        glVertex3f(-1,1,0);
//        glVertex3f(1,1,0);
//        glVertex3f(1,-1,0);

//    glEnd();
//    glBegin(GL_TRIANGLES);
//        glNormal3f(0,-1,0.707);
//        glVertex3f(-1,-1,0);
//        glVertex3f(1,-1,0);
//        glVertex3f(0,0,1.2);
//    glEnd();
//    glBegin(GL_TRIANGLES);
//        glNormal3f(1,0, 0.707);
//        glVertex3f(1,-1,0);
//        glVertex3f(1,1,0);
//        glVertex3f(0,0,1.2);
//    glEnd();
//    glBegin(GL_TRIANGLES);
//        glNormal3f(0,1,0.707);
//        glVertex3f(1,1,0);
//        glVertex3f(-1,1,0);
//        glVertex3f(0,0,1.2);
//    glEnd();
//    glBegin(GL_TRIANGLES);
//        glNormal3f(-1,0,0.707);
//        glVertex3f(-1,1,0);
//        glVertex3f(-1,-1,0);
//        glVertex3f(0,0,1.2);
//    glEnd();
    glLineWidth(0.1);
    glColor3ub(255, 0, 0);
    glBegin(GL_LINES);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(15, 0, 0);
    glEnd();

}

void MyGLWidget::drawLines(vector<tup3<double>>begin,vector<tup3<double>>end,vector<tup3<int>>color){
    glLineWidth(0.1);
    for(unsigned int i=0; i<begin.size();i++){
        tup3<double> b=begin[i];
        tup3<double> e=end[i];
        tup3<int> c= color[i];
        glColor3ub(get<0>(c), get<1>(c), get<2>(c));
        glBegin(GL_LINES);
            glVertex3f(get<0>(b), get<1>(b), get<2>(b));
            glVertex3f(get<0>(e), get<1>(e), get<2>(e));
        glEnd();
    }
}

void MyGLWidget::clear(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -10.0);
    glRotatef(xRot / 16.0, 1.0, 0.0, 0.0);
    glRotatef(yRot / 16.0, 0.0, 1.0, 0.0);
    glRotatef(zRot / 16.0, 0.0, 0.0, 1.0);
}
