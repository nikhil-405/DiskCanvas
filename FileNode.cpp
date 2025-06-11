#include "FileNode.h"
using namespace std;

void FileNode::accumulateSize() {
    if (!isDirectory) return;

    size = 0;
    for (auto& child : children) {
        child->accumulateSize();
        size += child->size;
    }
}