#pragma once

#include <string>
#include <iostream>

class Brain
{
    protected:
        std::string ideas[100];
    public:
        Brain();
        Brain(const Brain& other);
        virtual ~Brain(); //This ensures correct polymorphic cleanup. (and parent and child)
        Brain& operator=(const Brain& other);

};