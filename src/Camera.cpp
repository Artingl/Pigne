#include <pigne/Camera.h>

Camera::Camera(Engine*engine)
{
    this->engine = engine;

    this->position = new Vec3(0, 0, 0);
    this->rotation = new Vec3(0, 0, 0);
}

void Camera::setPosition(Vec3*i)
{
    free((void*)this->position);
    this->position = i;

    glTranslatef(-this->position->x, -this->position->y, -this->position->z);
}

void Camera::setRotation(Vec3*i)
{
    free((void*)this->rotation);
    this->rotation = i;

    glRotatef(this->rotation->x, 1.0F, 0.0F, 0.0F);
    glRotatef(this->rotation->y, 0.0F, 1.0F, 0.0F);
    glRotatef(this->rotation->z, 0.0F, 0.0F, 1.0F);
}

void Camera::perspective(double FOV, double aspect, double zNear, double renderDistance)
{
    glMatrixMode(5889);
    glLoadIdentity();
    gluPerspective(FOV, aspect, zNear, renderDistance);
    glMatrixMode(5888);
    glLoadIdentity();
}

void Camera::orthographic(double left, double right, double bottom, double top, double zNear, double zFar)
{
    glMatrixMode(5889);
    glLoadIdentity();
    glOrtho(left, right, bottom, top, zNear, zFar);
    glMatrixMode(5888);
    glLoadIdentity();
}
