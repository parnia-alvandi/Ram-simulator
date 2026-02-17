#include "Clock.h"
#include "MemoryManager.h"

Clock::Clock(MemoryManager& manager)
    : ReplacementAlgorithm(manager), pointer(0) {}

void Clock::accessPage(int page) {

    if (memory.isPageLoaded(page)) {
        for (int i = 0; i < memory.getFrameCount(); i++) {
            if (memory.getFrame(i).getPage() == page) {
                memory.getFrame(i).setReferenceBit(true);
                return;
            }
        }
    }

    int freeIndex = memory.findFreeFrame();
    if (freeIndex != -1) {
        memory.loadPage(page);
        memory.getFrame(freeIndex).setReferenceBit(true);
        return;
    }

    while (true) {
        if (!memory.getFrame(pointer).getReferenceBit()) {
            memory.replacePage(pointer, page);
            memory.getFrame(pointer).setReferenceBit(true);
            pointer = (pointer + 1) % memory.getFrameCount();
            break;
        }

        memory.getFrame(pointer).setReferenceBit(false);
        pointer = (pointer + 1) % memory.getFrameCount();
    }
}
