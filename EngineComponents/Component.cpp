#include "Component.h"

CComponent::CComponent()
{}

CComponent::CComponent( std::string name, std::shared_ptr<CGameObject> parent, EComponentType compType )
	: name( name ), type( compType ), gameObject( parent )
{

}

void CComponent::Run()
{
	return;
}

std::shared_ptr<CGameObject> CComponent::GetGameObject()
{
	return this->gameObject;
}

EComponentType CComponent::GetType()
{
	return this->type;
}

std::string CComponent::GetName()
{
	return this->name;
}
