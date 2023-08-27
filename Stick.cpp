#include "pch.h"
#include "Stick.h"
#include "Texture.h"

Stick::Stick(float x, float y) : m_Position{ x, y }, m_Remove{ false }
{
	m_pStickSprite = new Texture{ "Resources/Stick.png" };
	m_Shape = Rectf{ x, y, m_pStickSprite->GetWidth() / 2.f, m_pStickSprite->GetHeight() / 2.f };
}

Stick::Stick(const Vector2f& pos) : m_Position{ pos }, m_Remove{ false }
{
	m_pStickSprite = new Texture{ "Resources/Stick.png" };
	m_Shape = Rectf{ pos.x, pos.y, m_pStickSprite->GetWidth() / 2.f, m_pStickSprite->GetHeight() / 2.f };
}

Stick::~Stick()
{
	delete m_pStickSprite;
}

const Rectf& Stick::GetShape()
{
	return m_Shape;
}

const Vector2f& Stick::GetPosition()
{
	return m_Position;
}

void Stick::Draw()
{
	if (!m_Remove) m_pStickSprite->Draw(m_Shape);
}

void Stick::RemoveFromGame()
{
	m_Remove = true;
}

void Stick::PutIntoGame()
{
	m_Remove = false;
}

bool Stick::IsRemoved()
{
	return m_Remove;
}