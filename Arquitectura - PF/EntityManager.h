#pragma once

#include <vector>
#include "Entity.h"
#include <memory>
#include <unordered_map>
#include <typeindex>

class EntityManager
{
private:
  std::vector<std::unique_ptr<Entity>> entities;
  std::unordered_map<int, std::unordered_map<std::type_index, std::shared_ptr<void>>> entityComponents;
public:

  Entity* createEntity()
  {
    int id = entities.size();
    entities.push_back(std::make_unique<Entity>(id));
    return entities.back().get();
  }

  void destroyEntity(int entityId)
  {
    entities.erase(entities.begin() + entityId);
  }

  template <typename T>
  std::shared_ptr<T> getComponent(int entityId)
  {
    auto& componentsMap = entityComponents[entityId];
    auto it = componentsMap.find(std::type_index(typeid(T)));
    if (it != componentsMap.end())
    {
      return std::static_pointer_cast<T>(it->second);
    }
    return nullptr;
  }

  template <typename T>
  void addComponent(int entityId, std::shared_ptr<T> component)
  {
    entityComponents[entityId][std::type_index(typeid(T))] = component;
  }

  std::vector<std::unique_ptr<Entity>>& getEntities()
  {
    return entities;
  }
};