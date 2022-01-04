#include <pigne/Mesh.h>

Mesh::Mesh(uint64_t size)
{
    this->size = size;
    this->pointer = 0;
    this->glBufId = -1;

    this->vertices = new double[size*3];
    this->texCoords = new double[size*2];
    this->colors = new double[size*4];
}

void Mesh::addVertex(Vertex*vertex)
{
    if (this->pointer > this->size)
    {
        getEngineInstance()->getDebugger()->printWarning("Mesh size is overflow! Maximum size of the Mesh is %llu", this->size);
        return;
    }

    uint64_t v2 = this->pointer<<1;
    uint64_t v3 = v2+this->pointer;
    uint64_t v4 = v3+this->pointer;

    this->vertices[v3] = vertex->vertices->x;
    this->vertices[v3+1] = vertex->vertices->y;
    this->vertices[v3+2] = vertex->vertices->z;

    this->texCoords[v2] = vertex->texCoords->x;
    this->texCoords[v2+1] = vertex->texCoords->y;

    this->colors[v4] =   vertex->colors->x / 255.0f;
    this->colors[v4+1] = vertex->colors->y / 255.0f;
    this->colors[v4+2] = vertex->colors->z / 255.0f;
    this->colors[v4+3] = vertex->colors->w / 255.0f;

    this->pointer++;
}

void Mesh::prepare()
{
    if(this->glBufId != -1)
        glDeleteLists(this->glBufId, 1);

    this->glBufId = glGenLists(1);
    glNewList(this->glBufId, GL_COMPILE);

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_DOUBLE, 0, this->vertices);

    glEnableClientState(GL_COLOR_ARRAY);
    glColorPointer(4, GL_DOUBLE, 0, this->colors);

    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glTexCoordPointer(2, GL_DOUBLE, 0, this->texCoords);

    glDrawArrays(GL_QUADS, 0, this->pointer);

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);

    glEndList();
}

bool Mesh::hasPrepared()
{
    return this->glBufId != -1;
}

void Mesh::render(Vec3*position)
{
    glPushMatrix();
    glTranslated(position->x, position->y, position->z);
    glCallList(this->glBufId);
    glPopMatrix();
}
