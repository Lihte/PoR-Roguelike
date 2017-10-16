#include <vector>
#include <Core/States/AState.h>
#include <Core/Core_types.h>

class StateHandler {
	
	std::vector<AState*> _mStack;
	std::vector<AState*> _mDead;

protected:

public:

	StateHandler();

	virtual ~StateHandler();

	bool IsEmpty(void);

	void AddActiveState(AState* state);

	void AddInactiveState(AState* state);

	AState& GetActiveState(void);

	void InactivateActiveState(void);

	void DropActiveState(void);

	void ResetActiveState(void);

	void RemoveActiveState(void);

	void SetActiveState(typeStateID stateId);

	void Cleanup(void);
};