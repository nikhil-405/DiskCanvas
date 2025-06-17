#include "FileNode.h"
using namespace std;

FileNode::~FileNode() {
    delete firstChild;
    delete nextSibling;
}

void FileNode::accumulateSize() {
    if (!isDirectory) return;

    size = 0;
    for (FileNode* child = firstChild; child; child = child->nextSibling) {
        child->accumulateSize();
        size += child->size;
    }
}