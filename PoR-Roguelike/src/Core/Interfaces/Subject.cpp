#include "Subject.h"

Subject::Subject(){}

Subject::~Subject(){}

void Subject::addOberver(IObserver * pObserver){
	m_Observers.push_back(pObserver);
}

void Subject::removeOberver(IObserver * pObserver){
	for (int i = 0; i < m_Observers.size(); ++i) {
		if (m_Observers[i] == pObserver) {
			m_Observers.erase(m_Observers.begin() + i);
			return;
		}
	}
}

void Subject::notify(Event event){
	for (auto it : m_Observers) {
		it->onNotify(event);
	}
}