#include "FIFO.h"
#include "MemoryManager.h"

FIFO::FIFO(MemoryManager& manager)
    : ReplacementAlgorithm(manager), pointer(0) {}

void FIFO::accessPage(int page) {

    if (memory.isPageLoaded(page))
        return;

    int freeIndex = memory.findFreeFrame();

    if (freeIndex != -1) {
        memory.loadPage(page);
    } else {
        memory.replacePage(pointer, page);
        pointer = (pointer + 1) % memory.getFrameCount();
    }
}
