#include <tmpltr.hpp>
#include <iostream>

void handleMV (char* nold, char* nnew) {
    fs::path source = home / nold;
    fs::path dest = home / nnew;

    if (!fs::exists(source) || !fs::is_directory(source)) {
        std::println("Template '{}' does not exist!", nold);
        return;
    }
    
    if (fs::exists(source) && fs::is_directory(source)) {
        std::print("Template '{}' already exists!\nAre you sure you want to continue? (y/n) ", nold);
        char c;
        std::cin >> c;
        if(c != 'y' && c != 'Y')
            return;
    }

    try {
        fs::rename(source, dest);
    } catch (const fs::filesystem_error& e) {
        std::println("Rename failed: {}", e.what());
        return;
    }

    std::println("Template '{}' renamed to '{}' !", nold, nnew);
}