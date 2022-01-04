#ifndef MESH_H
#define MESH_H

#include <stdint.h>
#include <stdlib.h>

#include <pigne/Vec4.h>
#include <pigne/Vec3.h>
#include <pigne/Vec2.h>
#include <pigne/Engine.h>

#include <GL/glut.h>

class Vertex {
public:
    Vec4*colors;
    Vec3*vertices;
    Vec2*texCoords;

    Vertex(Vec4*colors0, Vec3*vertices0, Vec2*texCoords0) :
        colors(colors0), vertices(vertices0), texCoords(texCoords0) {}

};

class Mesh {
private:
    uint64_t size;
    uint64_t pointer;

    double* texCoords;
    double* vertices;
    double* colors;

    GLuint glBufId;

public:

    /*
     * Class constructor
     * */
    Mesh(uint64_t size);

    /*
     * Appends new Vertex structure to Mesh class
     * */
    void addVertex(Vertex*vertex);

    /*
     * Preparing mesh that will be able to render soon
     * */
    void prepare();

    /*
     * Has the mesh prepared
     * */
    bool hasPrepared();

    /*
     * Render the Mesh
     * */
    void render(Vec3*position);

};


#endif
