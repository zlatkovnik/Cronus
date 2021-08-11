#include "core/CoreEngine.h"

#include "core/Scene.h"


int main()
{
    Scene scene;
    CoreEngine engine(&scene);
    engine.Start(800, 600, "Cronus");
}
