#pragma once
#include "Console.h"
#include "Objects.h"
#include "EntityManager.h"
#include "Components.h"

class CEngine
{
public:
	CEngine();
	void Setup();
	void Run();
private:
	CEntityManager EntityManager;
};