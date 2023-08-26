#include "pch.h"
#include "FirePit.h"
#include "Texture.h"

FirePit::FirePit(float x, float y) : m_Position{ x, y }, m_Remove{ true }
{
	m_pFirePitSprite = new Texture{ "Resources/FirePit.png" };
	m_Shape = Rectf{ x, y, m_pFirePitSprite->GetWidth() / 4.f, m_pFirePitSprite->GetHeight() / 4.f };
}

FirePit::FirePit(const Vector2f& pos) : m_Position{ pos }, m_Remove{ true }
{
	m_pFirePitSprite = new Texture{ "Resources/FirePit.png" };
	m_Shape = Rectf{ pos.x, pos.y, m_pFirePitSprite->GetWidth() / 4.f, m_pFirePitSprite->GetHeight() / 4.f };
}

FirePit::~FirePit()
{
	delete m_pFirePitSprite;
}

const Rectf& FirePit::GetShape()
{
	return m_Shape;
}

const Vector2f& FirePit::GetPosition()
{
	return m_Position;
}

void FirePit::Draw()
{
	if (!m_Remove) m_pFirePitSprite->Draw(m_Shape);
}

void FirePit::RemoveFromGame()
{
	m_Remove = true;
}

void FirePit::PutIntoGame()
{
	m_Remove = false;
}

bool FirePit::IsRemoved()
{
	return m_Remove;
}
