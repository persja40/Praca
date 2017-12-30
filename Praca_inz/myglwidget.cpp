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
        angle += 360;
    while (angle > 360)
        angle -= 360;
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

void MyGLWidget::copy(){
    updateGL();
}

void MyGLWidget::initializeGL()
{
    qglClearColor(Qt::white);
}

void MyGLWidget::paintGL()
{
    clear();
    draw();
    drawLines();
}

void MyGLWidget::resizeGL(int width, int height)
{
    int side = qMax(width, height);
    glViewport((width - side) / 2, (height - side) / 2, side, side);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
#ifdef QT_OPENGL_ES_1
    glOrthof(-1.5, +1.5, -1.5, +1.5, 1.0, 15.0);
#else
    glOrtho(-1.5, +1.5, -1.5, +1.5, 1.0, 15.0);
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
        setXRotation(xRot + 0.5 * dy);
        setYRotation(yRot + 0.5 * dx);
    } else if (event->buttons() & Qt::RightButton) {
        setXRotation(xRot + 0.5 * dy);
        setZRotation(zRot + 0.5 * dx);
    }

    lastPos = event->pos();
}

void MyGLWidget::draw()
{
    glLineWidth(3);
    glColor3ub(0,0,0);
//bottom
    glBegin(GL_LINES);
        glVertex3f(-0.5,-0.5,-0.5);
        glVertex3f(-0.5,0.5,-0.5);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(-0.5,-0.5,-0.5);
        glVertex3f(0.5,-0.5,-0.5);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(0.5,0.5,-0.5);
        glVertex3f(-0.5,0.5,-0.5);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(0.5,0.5,-0.5);
        glVertex3f(0.5,-0.5,-0.5);
    glEnd();
//top
    glBegin(GL_LINES);
        glVertex3f(-0.5,-0.5,0.5);
        glVertex3f(-0.5,0.5,0.5);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(-0.5,-0.5,0.5);
        glVertex3f(0.5,-0.5,0.5);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(0.5,0.5,0.5);
        glVertex3f(-0.5,0.5,0.5);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(0.5,0.5,0.5);
        glVertex3f(0.5,-0.5,0.5);
    glEnd();
//columns
    glBegin(GL_LINES);
        glVertex3f(-0.5,-0.5,-0.5);
        glVertex3f(-0.5,-0.5,0.5);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(-0.5,0.5,-0.5);
        glVertex3f(-0.5,0.5,0.5);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(0.5,-0.5,-0.5);
        glVertex3f(0.5,-0.5,0.5);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(0.5,0.5,-0.5);
        glVertex3f(0.5,0.5,0.5);
    glEnd();
}

void MyGLWidget::drawLines(){
    while(!points.try_lock());
    glLineWidth(3);
    for(unsigned int p=0; p<beginsp.size();p++){
        glColor3ub(get<0>(colorsp[p]), get<1>(colorsp[p]), get<2>(colorsp[p]));
        for(unsigned int l=0; l<beginsp[0].size(); l++){
            tup3<double> b=beginsp[p][l];
            tup3<double> e=endsp[p][l];
            glBegin(GL_LINES);
                glVertex3f(get<0>(b)-0.5, get<1>(b)-0.5, get<2>(b)-0.5);
                glVertex3f(get<0>(e)-0.5, get<1>(e)-0.5, get<2>(e)-0.5);
            glEnd();
        }
    }
    points.unlock();
}

void MyGLWidget::clear(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -10.0);
    glRotatef(xRot , 1.0, 0.0, 0.0);
    glRotatef(yRot , 0.0, 1.0, 0.0);
    glRotatef(zRot , 0.0, 0.0, 1.0);
}
