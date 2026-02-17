#ifndef CLOCK_H
#define CLOCK_H

#include "ReplacementAlgorithm.h"

class Clock : public ReplacementAlgorithm {

private:
    int pointer;

public:
    Clock(MemoryManager& manager);
    void accessPage(int page) override;
};

#endif
