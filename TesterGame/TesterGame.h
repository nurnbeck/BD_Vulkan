#pragma once

#include <BDEngine/Window.h>
#include <BDEngine/BeamDogVulkan.h>

class TesterGame
{
public:
	TesterGame();
	~TesterGame();

	void Run();

private:

	void InitSystems();

	//member variables
	BDEngine::BeamDog m_engine;
};

