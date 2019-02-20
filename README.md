# S05_TestingGrounds
_Unreal Engine C++ Developer_ section 5 
stealth fps **TestingGrounds**

Ben and Sam continue imparting Unreal Engine and C++ coding knowledge in section 5, our 4th project.

Will be using this **README** to store relevant and helpful information.

#### Onward and Upward!

## Unreal Info
### Modules

>Modules are the building blocks of UE4. The engine is implemented as a large collection of modules, and games supply their own modules to augment them. 
[-Unreal Docs](https://docs.unrealengine.com/en-us/Programming/UnrealBuildSystem/ModuleFiles)

We add the __AIModule__ and __GameplayTasks__ to the project via _ProjectName.Build.cs_ file in order to access the Behavior Tree Tasks (_UBTTaskNode_ class).

### Behavior Trees

Unreal's AI Tool 
- **Behavior Tree** (BT) - AI's processor - node based tree, makes decisions and then acts on them
- **Blackboard** - AI's memory - stores key values for the Behavior Tree to use

Custom BT nodes can be created in BP or C++.
For creating own nodes in c++:
- Add "AIModule" & "GameplayTasks" modules to $Project.Build.cs _PublicDependencyModuleNames_
- Inherit from _UBTTaskNode_
- Override virtual ExecuteTask(...) method
- Return Success `return EBTNodeResult::Succeeded;` for it to work in UE

 
.
