#pragma once
#include "Components.h"
#include "Item.h"

class CComponentInventory : public CComponent
{
public:
    CComponentInventory( std::shared_ptr<CGameObject> parent );
    void Run() override;
    void AddItem( const CItem& item, const int quantity = 1 );
    void AddItem( const std::string& name, const int quantity = 1 );
    void RemItem( const CItem& item, const int quantity = 1 );
    void RemItem( const std::string& name, const int quantity = 1 );
private:
    std::vector<CItem> items;
};