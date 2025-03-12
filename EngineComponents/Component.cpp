#include "Component.h"

CComponent::CComponent()
{}

CComponent::CComponent( int id, std::shared_ptr<CGameObject> parent, EComponentType compType ) : instance( id ), type( compType ), gameObject( parent )
{

}

void CComponent::Run()
{
	return;
}

int CComponent::GetInstance()
{
	return this->instance;
}

void CComponent::SetGameObject( std::shared_ptr<CGameObject> gameObject )
{
	this->gameObject = gameObject;
}

std::shared_ptr<CGameObject> CComponent::GetGameObject()
{
	return this->gameObject;
}

EComponentType CComponent::GetType()
{
	return this->type;
}

std::string CComponent::GetTag()
{
	return this->tag;
}
