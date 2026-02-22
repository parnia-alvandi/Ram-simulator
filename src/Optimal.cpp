#include "Optimal.h"
#include "MemoryManager.h"

Optimal::Optimal(MemoryManager& manager)
    : ReplacementAlgorithm(manager), currentIndex(0) {}

void Optimal::setFuturePages(const std::vector<int>& pages) {
    futurePages = pages;
}

void Optimal::accessPage(int page) {

    if (memory.isPageLoaded(page)) {
        currentIndex++;
        return;
    }

    int freeIndex = memory.findFreeFrame();
    if (freeIndex != -1) {
        memory.loadPage(page);
        currentIndex++;
        return;
    }

    int replaceIndex = 0;
    int farthest = -1;
    bool found = false;

    for (int i = 0; i < memory.getFrameCount(); i++) {
        int framePage = memory.getFrame(i).getPage();
        int j;

        for (j = currentIndex + 1; j < (int)futurePages.size(); j++) {
            if (futurePages[j] == framePage)
                break;
        }

        // If page never appears again, this is the best choice
        if (j == (int)futurePages.size()) {
            replaceIndex = i;
            found = true;
            break;
        }

        if (j > farthest) {
            farthest = j;
            replaceIndex = i;
        }
    }

    memory.replacePage(replaceIndex, page);
    currentIndex++;
}
