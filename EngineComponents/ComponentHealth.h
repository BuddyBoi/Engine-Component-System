#pragma once
#include "Objects.h"
#include <memory>

class CComponentHealth : public CComponent
{
public:
    CComponentHealth( int id, std::shared_ptr<CGameObject> parent, float hp );
    void Run() override;
    float GetHealth() const;
    float GetHealthMax() const;
    void Hurt( const float& amt );
    void Heal( const float& amt );
    bool GetIsAlive() const;
private:
    float healthMax = 0.0f;
    float health = 0.0f;
};