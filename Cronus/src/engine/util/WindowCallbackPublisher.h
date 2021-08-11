#pragma once

#include <vector>
#include <util/WindowCallbackObserver.h>

class WindowCallbackPublisher {
protected:
	std::vector<WindowCallbackObserver*> m_observers;
public:
	virtual void RegisterObserver(WindowCallbackObserver* observer) = 0;
	virtual void UnregisterObserver(WindowCallbackObserver* observer) = 0;
	virtual std::vector<WindowCallbackObserver*> GetObservers() {
		return m_observers;
	}
};