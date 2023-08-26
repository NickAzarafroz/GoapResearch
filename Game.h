#pragma once
#include <vector>
class Avatar;
class Goal;
class Texture;
class Action;
class Planner;
class Resource;
class Game final
{
public:
	explicit Game( const Window& window );
	Game(const Game& other) = delete;
	Game& operator=(const Game& other) = delete;
	Game( Game&& other) = delete;
	Game& operator=(Game&& other) = delete;
	~Game();

	void Update( float elapsedSec );
	void Draw( ) const;

	// Event handling
	void ProcessKeyDownEvent( const SDL_KeyboardEvent& e );
	void ProcessKeyUpEvent( const SDL_KeyboardEvent& e );
	void ProcessMouseMotionEvent( const SDL_MouseMotionEvent& e );
	void ProcessMouseDownEvent( const SDL_MouseButtonEvent& e );
	void ProcessMouseUpEvent( const SDL_MouseButtonEvent& e );

private:
	// DATA MEMBERS
	const Window m_Window;

	Avatar* m_pPoppyAvatar;
	Goal* m_pDesiredWorldState;
	Planner* m_pPlanner;

	std::vector<Resource*> m_pAxeResources;
	std::vector<Resource*> m_pTreeResources;
	std::vector<Resource*> m_pFirepitResources;

	std::vector<Action*> m_pCurrentPlan;

	// FUNCTIONS
	void Initialize( );
	void Cleanup( );
	void ClearBackground( ) const;
};