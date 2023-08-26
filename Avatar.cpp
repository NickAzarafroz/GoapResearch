#include "pch.h"
#include "Avatar.h"
#include "Texture.h"
#include "Vector2f.h"
#include "Action.h"

Avatar::Avatar()
	: m_Speed { 250.0f }
	, m_AccuSec{}
	, m_Framerate{ 1 / 5.0f}
{
	m_pIdleSprite = new Texture{ "Resources/PoppyIdle.png" };
	m_IdleSrc = Rectf{ 500.f, 500.f, m_pIdleSprite->GetWidth() / 2.0f, m_pIdleSprite->GetHeight() };
	m_Shape = Rectf{ 500.f, 500.f, m_pIdleSprite->GetWidth(), m_pIdleSprite->GetHeight() };

	m_AvailableActions[0] = new Action{ "GetSticks", 10 };
	m_AvailableActions[0]->AddPrecondition("HasSticks", false);
	m_AvailableActions[0]->AddPrecondition("SticksAvailable", true);

	m_AvailableActions[0]->AddEffect("HasFirePit", false);
	m_AvailableActions[0]->AddEffect("HasSticks", true);


	m_AvailableActions[1] = new Action{ "GetAxe", 2 };
	m_AvailableActions[1]->AddPrecondition("HasAxe", false);
	m_AvailableActions[1]->AddPrecondition("AxeAvailable", true);

	m_AvailableActions[1]->AddEffect("HasLogs", false);
	m_AvailableActions[1]->AddEffect("HasAxe", true);

	m_AvailableActions[2] = new Action{ "ChopTree", 2 };
	m_AvailableActions[2]->AddPrecondition("HasLogs", false);
	m_AvailableActions[2]->AddPrecondition("HasAxe", true);

	m_AvailableActions[2]->AddEffect("HasFirePit", false);
	m_AvailableActions[2]->AddEffect("HasLogs", true);

	m_AvailableActions[3] = new Action{ "BuildFirePit", 2 };
	m_AvailableActions[3]->AddPrecondition("HasFirePit", false);
	m_AvailableActions[3]->AddPrecondition("HasLogs", true);

	m_AvailableActions[3]->AddEffect("HasFirePit", true);
	m_AvailableActions[3]->AddEffect("HasFirePit", true);

	m_AvailableActions[4] = new Action{ "BuildFirePit", 2 };
	m_AvailableActions[4]->AddPrecondition("HasFirePit", false);
	m_AvailableActions[4]->AddPrecondition("HasSticks", true);

	m_AvailableActions[4]->AddEffect("HasFirePit", true);
	m_AvailableActions[4]->AddEffect("HasFirePit", true);
}

Avatar::~Avatar()
{
	delete m_pIdleSprite;
}

void Avatar::Draw() const
{
	m_pIdleSprite->Draw(Point2f{m_Shape.left, m_Shape.bottom}, m_IdleSrc);
}

void Avatar::Update(float elapsedSec)
{
	UpdateIdle(elapsedSec);
}

void Avatar::SetPosition(const Vector2f& pos)
{
	m_Shape.left = pos.x;
	m_Shape.bottom = pos.y;
}

Vector2f Avatar::GetPosition()
{
	return Vector2f{ m_Shape.left, m_Shape.bottom };
}

Rectf Avatar::GetShape()
{
	return m_Shape;
}

const std::vector<std::pair<std::string, bool>>& Avatar::GetCurrentStates() const
{
	return m_CurrentStates;
}

const std::array<Action*, 5>& Avatar::GetAvailableActions() const
{
	return m_AvailableActions;
}

void Avatar::UpdateIdle(float elapsedSec)
{
	m_AccuSec += elapsedSec;
	if (m_AccuSec > m_Framerate)
	{
		m_IdleSrc.left += m_pIdleSprite->GetWidth() / 2.0f;
		if (m_IdleSrc.left > m_pIdleSprite->GetWidth())
		{
			m_IdleSrc.left = 0;
		}
		m_AccuSec -= m_Framerate;
	}
}
