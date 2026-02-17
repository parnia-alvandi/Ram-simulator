#ifndef PAGE_TABLE_H
#define PAGE_TABLE_H

#include <vector>

class PageTable {

private:
    std::vector<int> table;

public:
    PageTable(int size);

    void setFrame(int page, int frameIndex);
    int getFrame(int page) const;
};

#endif
