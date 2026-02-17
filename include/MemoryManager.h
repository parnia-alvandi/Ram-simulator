#ifndef MEMORY_MANAGER_H
#define MEMORY_MANAGER_H

#include <vector>
#include "Frame.h"
#include "PageTable.h"

class MemoryManager {

private:
    std::vector<Frame> frames;
    PageTable pageTable;
    int pageFaults;

public:
    MemoryManager(int frameCount);

    bool isPageLoaded(int page) const;
    void loadPage(int page);
    void replacePage(int frameIndex, int newPage);

    int findFreeFrame() const;
    int getFrameCount() const;

    Frame& getFrame(int index);
    const std::vector<Frame>& getFrames() const;

    void incrementPageFault();
    int getPageFaults() const;

    void printMemory() const;
};

#endif
