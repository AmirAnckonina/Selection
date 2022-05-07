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
	Person() { m_KeyID = 0; m_Name = ""; };
	Person(int i_KeyID, string i_Name) : m_KeyID(i_KeyID), m_Name(i_Name) {}
	Person(const Person& i_Person) {
		m_KeyID = i_Person.m_KeyID;
		m_Name.assign(i_Person.m_Name);
	}

	int GetKeyID() { return m_KeyID; }
	string GetName() { return m_Name; }
};
