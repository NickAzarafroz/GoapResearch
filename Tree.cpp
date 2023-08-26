#include "pch.h"
#include "Tree.h"
#include "Texture.h"

Tree::Tree(float x, float y) : m_Position{ x, y }, m_Remove{ false }
{
	m_pTreeSprite = new Texture{ "Resources/Tree.png" };
	m_Shape = Rectf{ x, y, m_pTreeSprite->GetWidth(), m_pTreeSprite->GetHeight() };
}

Tree::Tree(const Vector2f& pos) : m_Position{ pos }, m_Remove{ false }
{
	m_pTreeSprite = new Texture{ "Resources/Tree.png" };
	m_Shape = Rectf{ pos.x, pos.y, m_pTreeSprite->GetWidth(), m_pTreeSprite->GetHeight() };
}

Tree::~Tree()
{
	delete m_pTreeSprite;
}

const Rectf& Tree::GetShape()
{
	return m_Shape;
}

const Vector2f& Tree::GetPosition()
{
	return m_Position;
}

void Tree::Draw()
{
	if(!m_Remove) m_pTreeSprite->Draw(m_Shape);
}

void Tree::RemoveFromGame()
{
	m_Remove = true;
}

void Tree::PutIntoGame()
{
	m_Remove = false;
}

bool Tree::IsRemoved()
{
	return m_Remove;
}
