#include "Frame.h"

Frame::Frame() : pageNumber(-1), referenceBit(false) {}

int Frame::getPage() const {
    return pageNumber;
}

void Frame::setPage(int page) {
    pageNumber = page;
}

bool Frame::getReferenceBit() const {
    return referenceBit;
}

void Frame::setReferenceBit(bool value) {
    referenceBit = value;
}
