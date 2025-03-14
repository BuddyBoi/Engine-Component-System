#pragma once
#include "Objects.h"
#include "Vector2D.h"

class CGameObjectManager
{
public:
	CGameObjectManager();
	CGameObjectManager( const int id );
	int GetInstance() const;
	std::vector<std::shared_ptr<CGameObject>> GetGameObjects();
	std::shared_ptr<CGameObject> GetGameObject( const int id );
	std::shared_ptr<CGameObject> GetGameObject( const std::string& tag );
	void CreateGameObject( const std::string& name, const EObjectType type = ObjType_Invalid, const Vector2D& pos = { 0.0f, 0.0f } );
private:
	int instance = 0;
	std::vector<std::shared_ptr<CGameObject>> objects{};
};