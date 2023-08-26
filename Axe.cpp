#include "pch.h"
#include "Axe.h"
#include "Texture.h"

Axe::Axe(float x, float y) : m_Position{ x, y }, m_Remove{ false }
{
	m_pAxeSprite = new Texture{ "Resources/Axe.png" };
	m_Shape = Rectf{ x, y, m_pAxeSprite->GetWidth() / 2.f, m_pAxeSprite->GetHeight() / 2.f };
}

Axe::Axe(const Vector2f& pos) : m_Position{ pos }, m_Remove{ false }
{
	m_pAxeSprite = new Texture{ "Resources/Axe.png" };
	m_Shape = Rectf{ pos.x, pos.y, m_pAxeSprite->GetWidth() / 2.f, m_pAxeSprite->GetHeight() / 2.f };
}

Axe::~Axe()
{
	delete m_pAxeSprite;
}

const Rectf& Axe::GetShape()
{
	return m_Shape;
}

const Vector2f& Axe::GetPosition()
{
	return m_Position;
}

void Axe::Draw()
{
	if(!m_Remove) m_pAxeSprite->Draw(m_Shape);
}

void Axe::RemoveFromGame()
{
	m_Remove = true;
}

void Axe::PutIntoGame()
{
	m_Remove = false;
}

bool Axe::IsRemoved()
{
	return m_Remove;
}

