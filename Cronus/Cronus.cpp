#include "core/CoreEngine.h"

#include "../scenes/TestScene.h"


int main()
{
    Scene* scene = new TestScene();
    CoreEngine engine(scene);
    engine.Start(800, 600, "Cronus");
}
