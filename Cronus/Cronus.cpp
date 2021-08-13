#include "core/CoreEngine.h"

#include "../scenes/TestScene/TestScene.h"


int main()
{
    Scene* scene = new TestScene();
    CoreEngine engine(scene);
    engine.Start(1600, 1280, "Cronus");
}
