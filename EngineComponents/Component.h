#pragma once
#include "Objects.h"

class CComponent
{
public:	
	CComponent();
	CComponent( std::string name, std::shared_ptr<CGameObject> parent, EComponentType compType );
	virtual void Run();
	std::shared_ptr<CGameObject> GetGameObject();
	EComponentType GetType();
	std::string GetName();
private:
	std::string name = "none";
	EComponentType type = CompType_Invalid;
	std::shared_ptr<CGameObject> gameObject; //parent game object
};