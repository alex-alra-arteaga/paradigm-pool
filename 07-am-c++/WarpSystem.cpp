/*
** EPITECH PROJECT, 2024
** WarpSystem.cpp
** File description:
** Paradigm Seminar, ex00
*/

#include "Federation.hpp"
#include "Borg.hpp"
#include "WarpSystem.hpp"

WarpSystem::QuantumReactor::QuantumReactor()
{
}

WarpSystem::Core::Core(WarpSystem::QuantumReactor *_coreReactor)
{
    this->_coreReactor = _coreReactor;
}