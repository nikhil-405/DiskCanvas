#pragma once
#include <string>
#include <vector>
#include <memory>
#include <cstdint>
using namespace std;

struct FileNode {
    string name;
    uint64_t size = 0;
    string fileType = "";
    bool isDirectory = false;
    vector<unique_ptr<FileNode>> children;

    FileNode(string name_, string fileType_, bool isDir)
      : name(move(name_)), fileType(move(fileType_)), isDirectory(isDir) {}

    void accumulateSize();
};