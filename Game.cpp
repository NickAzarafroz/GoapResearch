#include "pch.h"
#include "Game.h"
#include "Avatar.h"
#include "FirePitGoal.h"
#include "Planner.h"
#include "Action.h"
#include <iostream>

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
	m_pPoppyAvatar = new Avatar();
	m_pDesiredWorldState = new FirePitGoal("HasFirePit");
	m_pPlanner = new Planner();

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
}

void Game::Update(float elapsedSec)
{
	m_pPoppyAvatar->Update(elapsedSec);
}

void Game::Draw( ) const
{
	ClearBackground();
	m_pPoppyAvatar->Draw();
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


