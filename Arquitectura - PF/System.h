#pragma once
#include <vector>
#include "Entity.h"

class System
{
public:
  virtual void update(std::vector<std::unique_ptr<Entity>>& entities) = 0;
  virtual ~System() = default;
};