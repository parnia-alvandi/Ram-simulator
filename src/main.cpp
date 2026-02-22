#include <iostream>
#include <vector>
#include <string>

#include "MemoryManager.h"
#include "ReplacementAlgorithm.h"
#include "FIFO.h"
#include "LRU.h"
#include "Optimal.h"
#include "Clock.h"

using namespace std;

int main() {

    int frames;
    int choice;

    cout << "===== RAM Simulator =====" << endl;
    cout << "Enter number of frames: ";
    cin >> frames;

    cout << "\nChoose Algorithm:\n";
    cout << "1. FIFO\n";
    cout << "2. LRU\n";
    cout << "3. Optimal\n";
    cout << "4. Clock\n";
    cout << "Choice: ";
    cin >> choice;

    MemoryManager manager(frames);

    ReplacementAlgorithm* algorithm = nullptr;

    switch(choice) {
        case 1: algorithm = new FIFO(manager); break;
        case 2: algorithm = new LRU(manager); break;
        case 3: algorithm = new Optimal(manager); break;
        case 4: algorithm = new Clock(manager); break;
        default:
            cout << "Invalid choice!" << endl;
            return 0;
    }

    vector<int> pages = {7,0,1,2,0,3,0,4,2,3,0,3,2};

    if (choice == 3) {
        dynamic_cast<Optimal*>(algorithm)->setFuturePages(pages);
    }

    for (int page : pages) {
        cout << "Accessing page " << page << ": ";
        algorithm->accessPage(page);
        manager.printMemory();
    }

    cout << "\nTotal Page Faults: "<< manager.getPageFaults() << endl;

    delete algorithm;
    return 0;
}
