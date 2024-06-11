#pragma once

enum Event {
	EVENT_SMALL_DOT_INTERSECTED,
	EVENT_BIG_DOT,
	EVENT_EAT_GHOST,
	EVENT_GHOST_EATED_PLAYER,
};

class Observer
{
public:
	virtual ~Observer();
	virtual void onNotiy(Event aEvent);
};

