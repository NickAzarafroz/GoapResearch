#pragma once
#include "Resource.h"
#include "Vector2f.h"

class Texture;
class Tree : public Resource
{
public:
	Tree(float x, float y);
	Tree(const Vector2f& pos);
	virtual ~Tree();

	Tree(const Tree& other) = delete;
	Tree& operator=(const Tree& rhs) = delete;
	Tree(Tree&& other) = delete;
	Tree& operator=(Tree&& rhs) = delete;

	virtual const Rectf& GetShape() override;
	virtual const Vector2f& GetPosition() override;
	virtual void Draw() override;
	virtual void RemoveFromGame() override;
	virtual void PutIntoGame() override;
	virtual bool IsRemoved() override;

private:
	Texture* m_pTreeSprite{};
	Rectf m_Shape{};
	Vector2f m_Position{};

	bool m_Remove{};
};

