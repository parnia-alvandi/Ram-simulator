#include "PageTable.h"

PageTable::PageTable(int size) {
    table.resize(size, -1);
}

void PageTable::setFrame(int page, int frameIndex) {
    if (page >= 0 && page < table.size())
        table[page] = frameIndex;
}

int PageTable::getFrame(int page) const {
    if (page >= 0 && page < table.size())
        return table[page];
    return -1;
}
