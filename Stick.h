#pragma once
#include "Resource.h"
#include "Vector2f.h"

class Texture;
class Stick : public Resource
{
public:
	Stick(float x, float y);
	Stick(const Vector2f& pos);
	virtual ~Stick();

	Stick(const Stick& other) = delete;
	Stick& operator=(const Stick& rhs) = delete;
	Stick(Stick&& other) = delete;
	Stick& operator=(Stick&& rhs) = delete;

	virtual const Rectf& GetShape() override;
	virtual const Vector2f& GetPosition() override;
	virtual void Draw() override;
	virtual void RemoveFromGame() override;
	virtual void PutIntoGame() override;
	virtual bool IsRemoved() override;

private:
	Texture* m_pStickSprite{};
	Rectf m_Shape{};
	Vector2f m_Position{};

	bool m_Remove{};
};

