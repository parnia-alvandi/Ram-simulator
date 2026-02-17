#ifndef FRAME_H
#define FRAME_H

class Frame {

private:
    int pageNumber;
    bool referenceBit;

public:
    Frame();

    int getPage() const;
    void setPage(int page);

    bool getReferenceBit() const;
    void setReferenceBit(bool value);
};

#endif
