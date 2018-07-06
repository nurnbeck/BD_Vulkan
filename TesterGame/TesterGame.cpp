#include "TesterGame.h"
#include "BDEngine/Globals.h"


TesterGame::TesterGame()
{
	RenderableObject.Load( "D:\\BeamDogVulkan\\BeamDogVulkan\\TesterGame\\Meshes\\utah-teapot.obj" );
}


TesterGame::~TesterGame()
{
}

void TesterGame::Run()
{
	InitSystems();

}

void TesterGame::InitSystems()
{
	m_engine.InitVulkan();

	m_engine.GameLoop();
}

