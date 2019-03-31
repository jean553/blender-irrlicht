#include <irrlicht.h>

#include <iostream>

using namespace irr;

/**
 *
 */
int main() {

    IrrlichtDevice *device = createDevice(
        video::EDT_OPENGL,
        core::dimension2d<u32>(1080, 768),
        32,
        false,
        false,
        false,
        0
    );

    video::IVideoDriver* driver = device->getVideoDriver();
    scene::ISceneManager* smgr = device->getSceneManager();

    scene::IMesh* sink = smgr->getMesh("resources/sink/sink.obj");
    scene::IMeshSceneNode* sinkNode = smgr->addMeshSceneNode(sink);
    sinkNode->setPosition(core::vector3df(0.95, 2, 1.3));
    sinkNode->setRotation(core::vector3df(0, 0, 0));
    sinkNode->setMaterialTexture(0, driver->getTexture("resources/sink/sink.png") );
    sinkNode->setMaterialFlag(video::EMF_LIGHTING, false);

    scene::IMesh* firstTable = smgr->getMesh("resources/table/table.obj");
    scene::IMeshSceneNode* firstTableNode = smgr->addMeshSceneNode(firstTable);
    firstTableNode->setPosition(core::vector3df(1.5, -2.0, 1.3));
    firstTableNode->setMaterialTexture(0, driver->getTexture("resources/table/table.png") );
    firstTableNode->setMaterialFlag(video::EMF_LIGHTING, false);

    scene::IMesh* secondTable = smgr->getMesh("resources/table/table.obj");
    scene::IMeshSceneNode* secondTableNode = smgr->addMeshSceneNode(secondTable);
    secondTableNode->setPosition(core::vector3df(-1.5, 2, 1.3));
    secondTableNode->setMaterialTexture(0, driver->getTexture("resources/table/table.png") );
    secondTableNode->setMaterialFlag(video::EMF_LIGHTING, false);

    scene::IMesh* ground = smgr->getMesh("resources/ground/ground.obj");
    scene::IMeshSceneNode* groundNode = smgr->addMeshSceneNode(ground);
    groundNode->setPosition(core::vector3df(0, 0, 0));
    groundNode->setMaterialTexture(0, driver->getTexture("resources/ground/ground.png") );
    groundNode->setMaterialFlag(video::EMF_LIGHTING, false);

    scene::ICameraSceneNode* camera = smgr->addCameraSceneNode();
    camera->setPosition(core::vector3df(0, 0, 10));
    camera->setTarget(core::vector3df(0, 0, 0));
    camera->setUpVector(core::vector3df(0, 0, -1));

    while(device->run()) {

        driver->beginScene(
            true,
            true,
            video::SColor(255, 0, 0, 0)
        );

        smgr->drawAll();

        driver->endScene();
    }

    device->drop();

    return EXIT_SUCCESS;
}
