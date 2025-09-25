#pragma once
#include <vector>
#include <memory>
#include "System.h"

class SystemManager
{
private:
  std::vector<std::shared_ptr<System>> systems;

public:
  void addSystem(std::shared_ptr<System> system)
  {
    systems.push_back(system);
  }

  void updateSystems(std::vector<std::unique_ptr<Entity>>& entities)
  {
    for (auto& system : systems)
    {
      system->update(entities);
    }
  }
};