#include "EntityManager.h"
#include "SystemManager.h"
#include "ComponentManager.h"

class ECS
{
private:
  EntityManager entityManager;
  ComponentManager componentManager;
  SystemManager systemManager;

public:
  Entity* createEntity()
  {
    return entityManager.createEntity();
  }

  void destroyEntity(int entityId)
  {
    entityManager.destroyEntity(entityId);
  }

  void addSystem(std::shared_ptr<System> system) 
  {
    systemManager.addSystem(system);
  }

  void update()
  {
    systemManager.updateSystems(entityManager.getEntities());
  }

  template<typename T>
  void AddComponent(Entity entity, T component)
  {
    componentManager->AddComponent<T>(entity, component)
  }

  ComponentManager& getComponentManager()
  {
    return componentManager;
  }
};