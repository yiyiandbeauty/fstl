#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QtOpenGL/QGLWidget>
#include <QtOpenGL/QGLShaderProgram>
#include <QMatrix4x4>

class GLMesh;
class Mesh;

class Canvas : public QGLWidget
{
    Q_OBJECT

public:
    Canvas(const QGLFormat& format, QWidget* parent=0);

    void initializeGL();
    void paintGL();
    ~Canvas();

public slots:
    void load_mesh(Mesh* m);


protected:
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);


private:
    void draw_mesh();

    QMatrix4x4 transform_matrix() const;
    QMatrix4x4 view_matrix() const;

    QGLShaderProgram mesh_shader;
    QGLShaderProgram quad_shader;

    GLMesh* mesh;

    QVector3D center;
    float scale;
    float tilt;
    float yaw;

    QPoint mouse_pos;
};

#endif // CANVAS_H
