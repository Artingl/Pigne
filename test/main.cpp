#include <pigne/Engine.h>
#include <pigne/Mesh.h>

Mesh*mesh;

void update();

int main(int argc, char*argv[])
{
    Engine*engine = getEngineInstance();
    engine->initEngine(argc, argv);

    mesh = new Mesh(64);

    mesh->addVertex(new Vertex(new Vec4(255, 0, 0, 255), new Vec3(0, 0, 0), new Vec2(0, 0)));
    mesh->addVertex(new Vertex(new Vec4(255, 0, 0, 255), new Vec3(100, 0, 0), new Vec2(0, 0)));
    mesh->addVertex(new Vertex(new Vec4(255, 0, 0, 255), new Vec3(100, 100, 0), new Vec2(0, 0)));
    mesh->addVertex(new Vertex(new Vec4(255, 0, 0, 255), new Vec3(0, 100, 0), new Vec2(0, 0)));

    engine->getWindow()->setUpdateHandler(&update);
    engine->getWindow()->createWindow();

    return 0;
}

void update()
{
    Window*window = getEngineInstance()->getWindow();
    Camera*camera = getEngineInstance()->getCamera();
    Renderer*renderer = getEngineInstance()->getRenderer();

    camera->orthographic(0, window->getSize()->x, window->getSize()->y, 0, -1, 1);

    if (!mesh->hasPrepared())
    {
        mesh->prepare();
    }

    mesh->render(new Vec3(10, 40, 0));

}
