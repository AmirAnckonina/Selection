#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <random>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

class Person {
	int m_KeyID;
	string m_Name;

public:
	int GetKeyID() { return m_KeyID; }
	string GetName() { return m_Name; }
};
