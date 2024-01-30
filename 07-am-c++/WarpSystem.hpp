/*
** EPITECH PROJECT, 2024
** WarpSystem.hpp
** File description:
** Paradigm Seminar, ex00
*/

namespace WarpSystem
{
    class QuantumReactor {
    public:
        QuantumReactor();
        // ~QuantumReactor();
        bool isStable() { return _stability; };
        void setStability(bool stability) { _stability = stability; };

    private:
        bool _stability = true;
        int _quantumFlux = 0;
    };

    class Core {
    public:
        Core(QuantumReactor *_coreReactor);
        // ~Core();
        QuantumReactor *checkReactor(void) { return _coreReactor; }
        void setStability(bool stability) { _coreReactor->setStability(stability); };
        bool isStable() { return _coreReactor->isStable(); };

    private:
        QuantumReactor *_coreReactor;
    };
};