/*
-----------------------------------------------------------------------------
Filename:    TutorialApplication.cpp
-----------------------------------------------------------------------------

This source file is part of the
   ___                 __    __ _ _    _ 
  /___\__ _ _ __ ___  / / /\ \ (_) | _(_)
 //  // _` | '__/ _ \ \ \/  \/ / | |/ / |
/ \_// (_| | | |  __/  \  /\  /| |   <| |
\___/ \__, |_|  \___|   \/  \/ |_|_|\_\_|
      |___/                              
      Tutorial Framework
      http://www.ogre3d.org/tikiwiki/
-----------------------------------------------------------------------------
*/
#include "TutorialApplication.h"

//-------------------------------------------------------------------------------------
TutorialApplication::TutorialApplication(void)
{

}
//-------------------------------------------------------------------------------------
TutorialApplication::~TutorialApplication(void)
{

}

//-------------------------------------------------------------------------------------
void TutorialApplication::createScene(void)
{
    // create your scene here :)
    // Create Entities
    Ogre::Entity* ogreHead1 = mSceneMgr->createEntity("Head1", "ogrehead.mesh");
    Ogre::Entity* ogreHead2 = mSceneMgr->createEntity("Head2", "ogrehead.mesh");
 
    // Create SceneNodes and attach the Entities to them
    Ogre::SceneNode* headNode1 = mSceneMgr->getRootSceneNode()->createChildSceneNode("HeadNode1");
    Ogre::SceneNode* headNode2 = mSceneMgr->getRootSceneNode()->createChildSceneNode("HeadNode2");
    headNode1->attachObject(ogreHead1);
    headNode2->attachObject(ogreHead2);

    // Set transformations
	headNode1->scale(Ogre::Vector3(1,1,1));
	headNode1->rotate(Ogre::Vector3(0,1,0), Ogre::Degree(-90));
	headNode1->translate(Ogre::Vector3(20,0,-20));

	headNode2->scale(Ogre::Vector3(1,1,0.5));
	headNode2->rotate(Ogre::Vector3(0,1,0), Ogre::Degree(90));
	headNode2->translate(Ogre::Vector3(-10,0,10));
 
    // Set the scene's ambient light
    mSceneMgr->setAmbientLight(Ogre::ColourValue(0.5f, 0.5f, 0.5f));

	// Create a Light, set its position and color
    Ogre::Light* light = mSceneMgr->createLight("MainLight");
    light->setPosition(20.0f, 80.0f, 50.0f);
	light->setSpecularColour(Ogre::ColourValue::White);
}



#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#define WIN32_LEAN_AND_MEAN
#include "windows.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
    INT WINAPI WinMain( HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT )
#else
    int main(int argc, char *argv[])
#endif
    {
        // Create application object
        TutorialApplication app;

        try {
            app.go();
        } catch( Ogre::Exception& e ) {
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
            MessageBox( NULL, e.getFullDescription().c_str(), "An exception has occured!", MB_OK | MB_ICONERROR | MB_TASKMODAL);
#else
            std::cerr << "An exception has occured: " <<
                e.getFullDescription().c_str() << std::endl;
#endif
        }

        return 0;
    }

#ifdef __cplusplus
}
#endif
