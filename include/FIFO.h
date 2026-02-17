#ifndef FIFO_H
#define FIFO_H

#include "ReplacementAlgorithm.h"

class FIFO : public ReplacementAlgorithm {

private:
    int pointer;

public:
    FIFO(MemoryManager& manager);
    void accessPage(int page) override;
};

#endif
