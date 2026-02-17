#ifndef OPTIMAL_H
#define OPTIMAL_H

#include "ReplacementAlgorithm.h"
#include <vector>

class Optimal : public ReplacementAlgorithm {

private:
    std::vector<int> futurePages;
    int currentIndex;

public:
    Optimal(MemoryManager& manager);
    void setFuturePages(const std::vector<int>& pages);
    void accessPage(int page) override;
};

#endif
