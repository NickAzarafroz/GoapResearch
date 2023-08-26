#include "pch.h"
#include "Game.h"
#include "Avatar.h"
#include "FirePitGoal.h"
#include "Planner.h"
#include "Action.h"
#include "Axe.h"
#include "Tree.h"
#include "FirePit.h"
#include <iostream>
#include <random>

Game::Game( const Window& window ) 
	:m_Window{ window }
{
	Initialize( );
}

Game::~Game( )
{
	Cleanup( );
}

void Game::Initialize( )
{
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_real_distribution<float> distr(0.f, 1000.f);

	m_pPoppyAvatar = new Avatar();
	m_pDesiredWorldState = new FirePitGoal("HasFirePit");
	m_pPlanner = new Planner();

	for (int i{}; i < 5; ++i)
	{
		float randomX = distr(eng);
		float randomY = distr(eng);

		Resource* pAxe = new Axe(randomX, randomY);
		m_pAxeResources.push_back(pAxe);
	}

	for (int i{}; i < 5; ++i)
	{
		float randomX = distr(eng);
		float randomY = distr(eng);

		Resource* pTree = new Tree(randomX, randomY);
		m_pTreeResources.push_back(pTree);
	}

	Resource* pFirePit = new FirePit(1000.f, 500.f);
	m_pFirepitResources.push_back(pFirePit);

	std::pair<std::string, bool> current1{ "HasAxe", false };
	std::pair<std::string, bool> current2{ "AxeAvailable", true };

	std::pair<std::string, bool> current3{ "HasSticks", false };
	std::pair<std::string, bool> current4{ "SticksAvailable", false };

	m_pPoppyAvatar->AddCurrentStates(current1);
	m_pPoppyAvatar->AddCurrentStates(current2);
	m_pPoppyAvatar->AddCurrentStates(current3);
	m_pPoppyAvatar->AddCurrentStates(current4);

	m_pCurrentPlan = m_pPlanner->Plan(m_pPoppyAvatar, m_pDesiredWorldState);
}

void Game::Cleanup( )
{
	delete m_pPoppyAvatar;
	delete m_pDesiredWorldState;
	delete m_pPlanner;

	for (const auto& resource : m_pAxeResources)
	{
		delete resource;
	}

	for (const auto& resource : m_pTreeResources)
	{
		delete resource;
	}

	for (const auto& resource : m_pFirepitResources)
	{
		delete resource;
	}
}

void Game::Update(float elapsedSec)
{
	m_pPoppyAvatar->Update(elapsedSec);

	if (!m_pCurrentPlan.empty())
	{
		if (m_pCurrentPlan[0]->GetName() == "GetAxe")
		{
			m_pCurrentPlan[0]->ExecuteAction(m_pPoppyAvatar, m_pAxeResources, elapsedSec);
		}

		if (m_pCurrentPlan[0]->GetName() == "ChopTree")
		{
			m_pCurrentPlan[0]->ExecuteAction(m_pPoppyAvatar, m_pTreeResources, elapsedSec);
		}

		if (m_pCurrentPlan[0]->GetName() == "BuildFirePit")
		{
			m_pCurrentPlan[0]->ExecuteAction(m_pPoppyAvatar, m_pFirepitResources, elapsedSec);
		}

		if (m_pCurrentPlan[0]->IsCompleted())
		{
			m_pCurrentPlan.erase(m_pCurrentPlan.begin());
		}
	}
	else
	{
		m_pCurrentPlan = m_pPlanner->Plan(m_pPoppyAvatar, m_pDesiredWorldState);
	}
}

void Game::Draw( ) const
{
	ClearBackground();
	m_pPoppyAvatar->Draw();

	for (const auto& resource : m_pAxeResources)
	{
		resource->Draw();
	}

	for (const auto& resource : m_pTreeResources)
	{
		resource->Draw();
	}

	for (const auto& resource : m_pFirepitResources)
	{
		resource->Draw();
	}
}

void Game::ProcessKeyDownEvent( const SDL_KeyboardEvent & e )
{
	//std::cout << "KEYDOWN event: " << e.keysym.sym << std::endl;
}

void Game::ProcessKeyUpEvent( const SDL_KeyboardEvent& e )
{
	//std::cout << "KEYUP event: " << e.keysym.sym << std::endl;
}

void Game::ProcessMouseMotionEvent( const SDL_MouseMotionEvent& e )
{
	//std::cout << "MOUSEMOTION event: " << e.x << ", " << e.y << std::endl;
}

void Game::ProcessMouseDownEvent( const SDL_MouseButtonEvent& e )
{
	//std::cout << "MOUSEBUTTONDOWN event: ";
	//switch ( e.button )
	//{
	//case SDL_BUTTON_LEFT:
	//	std::cout << " left button " << std::endl;
	//	break;
	//case SDL_BUTTON_RIGHT:
	//	std::cout << " right button " << std::endl;
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	std::cout << " middle button " << std::endl;
	//	break;
	//}
}

void Game::ProcessMouseUpEvent( const SDL_MouseButtonEvent& e )
{
	//std::cout << "MOUSEBUTTONUP event: ";
	//switch ( e.button )
	//{
	//case SDL_BUTTON_LEFT:
	//	std::cout << " left button " << std::endl;
	//	break;
	//case SDL_BUTTON_RIGHT:
	//	std::cout << " right button " << std::endl;
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	std::cout << " middle button " << std::endl;
	//	break;
	//}
}

void Game::ClearBackground( ) const
{
	glClearColor(0.0f, 0.5f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}


