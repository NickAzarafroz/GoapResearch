#pragma once
struct Vector2f;
class Resource
{
public:
	Resource() = default;
	virtual ~Resource() = default;

	Resource(const Resource& other) = delete;
	Resource& operator=(const Resource& rhs) = delete;
	Resource(Resource&& other) = delete;
	Resource& operator=(Resource&& rhs) = delete;

	virtual const Rectf& GetShape() = 0;
	virtual const Vector2f& GetPosition() = 0;
	virtual void Draw() = 0;
	virtual void RemoveFromGame() = 0;
	virtual void PutIntoGame() = 0;
	virtual bool IsRemoved() = 0;
};

