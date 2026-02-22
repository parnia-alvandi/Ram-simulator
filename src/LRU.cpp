#include "LRU.h"
#include "MemoryManager.h"
#include <algorithm>

LRU::LRU(MemoryManager& manager)
    : ReplacementAlgorithm(manager) {}

void LRU::accessPage(int page) {

    if (memory.isPageLoaded(page)) {
        usageOrder.erase(
            std::remove(usageOrder.begin(), usageOrder.end(), page),
            usageOrder.end()
        );
        usageOrder.push_back(page);
        return;
    }

    int freeIndex = memory.findFreeFrame();

    if (freeIndex != -1) {
        memory.loadPage(page);
        usageOrder.push_back(page);
    } else {
        int lruPage = usageOrder.front();
        usageOrder.erase(usageOrder.begin());

        int frameIndex = -1;
        for (int i = 0; i < memory.getFrameCount(); i++) {
            if (memory.getFrame(i).getPage() == lruPage) {
                frameIndex = i;
                break;
            }
        }

        if (frameIndex == -1) return; // safety check

        memory.replacePage(frameIndex, page);
        usageOrder.push_back(page);
    }
}
