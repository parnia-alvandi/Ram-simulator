#ifndef LRU_H
#define LRU_H

#include "ReplacementAlgorithm.h"
#include <vector>

class LRU : public ReplacementAlgorithm {

private:
    std::vector<int> usageOrder;

public:
    LRU(MemoryManager& manager);
    void accessPage(int page) override;
};

#endif
