#include "pch.h"
#include "Avatar.h"
#include "Texture.h"
#include "Vector2f.h"

Avatar::Avatar()
	: m_Speed { 250.0f }
	, m_AccuSec{}
	, m_Framerate{ 1 / 5.0f}
{
	m_pIdleSprite = new Texture{ "Resources/PoppyIdle.png" };
	m_IdleSrc = Rectf{ 500.f, 500.f, m_pIdleSprite->GetWidth() / 2.0f, m_pIdleSprite->GetHeight() };
	m_Shape = Rectf{ 500.f, 500.f, m_pIdleSprite->GetWidth(), m_pIdleSprite->GetHeight() };
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
