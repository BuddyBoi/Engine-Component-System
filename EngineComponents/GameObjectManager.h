#pragma once
#include "Objects.h"

class CGameObjectManager
{
public:
	CGameObjectManager();
	CGameObjectManager( const int id );
	int GetInstance() const;
	std::vector<std::shared_ptr<CGameObject>> GetGameObjects();
	std::shared_ptr<CGameObject> GetGameObject( const int id );
	std::shared_ptr<CGameObject> GetGameObject( const std::string& tag );
	void CreateGameObject( const std::string& name, const EObjectType type = ObjType_Invalid );
private:
	int instance = 0;
	std::vector<std::shared_ptr<CGameObject>> objects{};
};