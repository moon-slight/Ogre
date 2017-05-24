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
    Ogre::Entity* ogreBall[9];
    Ogre::SceneNode* ballNode[9];
    Ogre::String ballString[9];

	//crreate nine balls
	for( int i = 0; i < 9; ++i )
	{
		Ogre::StringStream ballSteam;
		ballSteam << (i + 1);
		ballString[i] = Ogre::String("Ball") + ballSteam.str();

	    // Create Entities
		ogreBall[i] = mSceneMgr->createEntity(ballString[i], "ball.mesh");
		ogreBall[i]->setMaterialName(ballString[i]);

		// Create SceneNodes and attach the Entities to them
		if( i == 0 )
		{
			ballNode[i] = mSceneMgr->getRootSceneNode()->createChildSceneNode(ballString[i]);
			ballNode[i]->rotate(Ogre::Vector3(0,0,1),Ogre::Degree(30));
			ballNode[i]->translate(Ogre::Vector3(1000,-1500,0));
		}
		else
		{
			ballNode[i] = ballNode[i-1]->createChildSceneNode(ballString[i]);

			// Set transformations
			ballNode[i]->rotate(Ogre::Vector3(0,0,1),Ogre::Degree(30));
			ballNode[i]->translate(Ogre::Vector3(500+i*100,0,0));
		}

		ballNode[i]->attachObject(ogreBall[i]);
	}
 
    // Set the scene's ambient light
    mSceneMgr->setAmbientLight(Ogre::ColourValue(0.1f, 0.1f, 0.1f));

	// Create a Light, set its position and color
    Ogre::Light* light = mSceneMgr->createLight("MainLight");
	//node = mSceneMgr->getRootSceneNode()->createChildSceneNode("light", Ogre::Vector3(0, 0, -5));
	//node->attachObject(light);
    //light->setPosition(1000.0f, 4000.0f, 2500.0f);
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
