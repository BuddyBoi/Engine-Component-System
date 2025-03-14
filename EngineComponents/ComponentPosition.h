#pragma once
#include "Objects.h"
#include "Vector2D.h"

class CComponentPosition : public CComponent
{
public:
    CComponentPosition( int id, std::shared_ptr<CGameObject> parent, const Vector2D& pos );
    void Run() override;
    Vector2D GetPosition() const;
    void SetPosition( const Vector2D& pos );
    void Move( const Vector2D& pos );
    void Move( const float x, const float y );
private:
    Vector2D position{};
};