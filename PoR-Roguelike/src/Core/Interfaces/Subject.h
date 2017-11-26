#pragma once
#include "Oberver.h"

class Subject {
public:
	Subject();
	virtual ~Subject();

	virtual void addOberver(IObserver* pObserver);
	virtual void removeOberver(IObserver* pObserver);

protected:
	virtual void notify(Event event);

private:
	std::vector<IObserver*> m_Observers;
};