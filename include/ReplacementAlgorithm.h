#ifndef REPLACEMENT_ALGORITHM_H
#define REPLACEMENT_ALGORITHM_H

class MemoryManager;

class ReplacementAlgorithm {

protected:
    MemoryManager& memory;

public:
    ReplacementAlgorithm(MemoryManager& manager);
    virtual ~ReplacementAlgorithm() = default;

    virtual void accessPage(int page) = 0;
};

#endif
