#pragma once
#include "Resource.h"
#include "Vector2f.h"

class Texture;
class Axe : public Resource
{
public:
	Axe(float x, float y);
	Axe(const Vector2f& pos);
	virtual ~Axe();

	Axe(const Axe& other) = delete;
	Axe& operator=(const Axe& rhs) = delete;
	Axe(Axe&& other) = delete;
	Axe& operator=(Axe&& rhs) = delete;

	virtual const Rectf& GetShape() override;
	virtual const Vector2f& GetPosition() override;
	virtual void Draw() override;
	virtual void RemoveFromGame() override;
	virtual void PutIntoGame() override;
	virtual bool IsRemoved() override;

private:
	Texture* m_pAxeSprite{};
	Rectf m_Shape{};
	Vector2f m_Position{};

	bool m_Remove{};
};

