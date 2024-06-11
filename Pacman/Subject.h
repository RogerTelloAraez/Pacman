#pragma once

#include <vector>

class Observer;
class Subject
{
	std::vector<Observer*> observers;
};

