#pragma once
#include <vector>
#include <array>

struct Vector2f;
class Texture;
class Avatar
{
public:
	Avatar();
	~Avatar();

	Avatar(const Avatar& other) = delete;
	Avatar& operator=(const Avatar& rhs) = delete;
	Avatar(Avatar&& other) = delete;
	Avatar& operator=(Avatar&& rhs) = delete;

	void Draw() const;
	void Update(float elapsedSec);

	void SetPosition(const Vector2f& pos);

	Vector2f GetPosition();
	Rectf GetShape();
	
private:
	Texture* m_pIdleSprite;

	Rectf m_IdleSrc;
	Rectf m_Shape;

	float m_Speed;
	float m_AccuSec;
	float m_Framerate;

	void UpdateIdle(float elapsedSec);
};

