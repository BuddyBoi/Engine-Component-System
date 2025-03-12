#pragma once
#include "Objects.h"

#include <memory>
#include <string>

class CComponent
{
public:	
	CComponent();
	CComponent( int id, std::shared_ptr<CGameObject> parent, EComponentType compType );

	virtual void Run();
	int GetInstance();
	void SetGameObject( std::shared_ptr<CGameObject> gameObject );
	std::shared_ptr<CGameObject> GetGameObject();
	EComponentType GetType();
	std::string GetTag(); //unused
private:
	int instance = 0; //index in Object's comp list
	std::string tag = "none"; //unused
	EComponentType type = CompType_Invalid;
	std::shared_ptr<CGameObject> gameObject; //parent game object
};