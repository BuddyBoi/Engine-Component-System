#include "ComponentInventory.h"

CComponentInventory::CComponentInventory( std::shared_ptr<CGameObject> parent )
	: CComponent( "compInventory", parent, CompType_Inventory)
{

}

void CComponentInventory::Run()
{

}

void CComponentInventory::AddItem( const CItem & item, const int quantity )
{
	
}

void CComponentInventory::AddItem( const std::string & name, const int quantity )
{

}

void CComponentInventory::RemItem( const CItem & item, const int quantity )
{

}

void CComponentInventory::RemItem( const std::string & name, const int quantity )
{

}
