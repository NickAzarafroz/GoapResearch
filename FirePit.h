#pragma once
#include "Resource.h"
#include "Vector2f.h"

class Texture;
class FirePit : public Resource
{
public:
	FirePit(float x, float y);
	FirePit(const Vector2f& pos);
	virtual ~FirePit();

	FirePit(const FirePit& other) = delete;
	FirePit& operator=(const FirePit& rhs) = delete;
	FirePit(FirePit&& other) = delete;
	FirePit& operator=(FirePit&& rhs) = delete;

	virtual const Rectf& GetShape() override;
	virtual const Vector2f& GetPosition() override;
	virtual void Draw() override;
	virtual void RemoveFromGame() override;
	virtual void PutIntoGame() override;
	virtual bool IsRemoved() override;

private:
	Texture* m_pFirePitSprite{};
	Rectf m_Shape{};
	Vector2f m_Position{};

	bool m_Remove{};
};

