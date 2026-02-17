#include <iostream>
#include "MemoryManager.h"

MemoryManager::MemoryManager(int frameCount)
    : frames(frameCount), pageTable(100), pageFaults(0) {}

bool MemoryManager::isPageLoaded(int page) const {
    return pageTable.getFrame(page) != -1;
}

void MemoryManager::loadPage(int page) {
    int freeIndex = findFreeFrame();
    if (freeIndex != -1) {
        frames[freeIndex].setPage(page);
        pageTable.setFrame(page, freeIndex);
        incrementPageFault();
    }
}

void MemoryManager::replacePage(int frameIndex, int newPage) {
    int oldPage = frames[frameIndex].getPage();
    pageTable.setFrame(oldPage, -1);

    frames[frameIndex].setPage(newPage);
    pageTable.setFrame(newPage, frameIndex);

    incrementPageFault();
}

int MemoryManager::findFreeFrame() const {
    for (int i = 0; i < frames.size(); i++) {
        if (frames[i].getPage() == -1)
            return i;
    }
    return -1;
}

int MemoryManager::getFrameCount() const {
    return frames.size();
}

Frame& MemoryManager::getFrame(int index) {
    return frames[index];
}

const std::vector<Frame>& MemoryManager::getFrames() const {
    return frames;
}

void MemoryManager::incrementPageFault() {
    pageFaults++;
}

int MemoryManager::getPageFaults() const {
    return pageFaults;
}

void MemoryManager::printMemory() const {
    std::cout << "Memory: ";
    for (const auto& frame : frames) {
        std::cout << frame.getPage() << " ";
    }
    std::cout << std::endl;
}
