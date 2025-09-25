#pragma once

#include "System.h"
#include <memory>

class RenderSystem : public System
{
public:
  void update(std::vector<std::unique_ptr<Entity>>& entities) override
  {
    for (auto& entity : entities)
    {
      /*auto pos = entity->getComponent<Position>();
      auto sprite = entity->getComponent<Sprite>();
      GET COMPONENT DEBE ESTAR EN EL ECS*/
      /*if (pos && sprite)
      {
        
      }*/
    }
  }
};