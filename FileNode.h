#pragma once
#include <string>
#include <vector>
#include <memory>
#include <cstdint>
using namespace std;

struct FileNode {
    string name;
    uint64_t size = 0;
    bool isDirectory = false;
    string fileType;

    FileNode* firstChild = nullptr;
    FileNode* nextSibling= nullptr;

    // constructor
    FileNode(string n, string ft, bool isDir)
      : name(move(n)), 
        fileType(move(ft)),
        isDirectory(isDir) {}
    
    // destructor
    ~FileNode();

    // size function
    void accumulateSize();
};