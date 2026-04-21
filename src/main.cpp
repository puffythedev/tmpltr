#include <print>
#include <cstring>
#include <filesystem>
#include <iostream>

#define TODO(x) std::println("{}:{}:{}: TODO: Implement {}", __FILE__, __LINE__, 0, x);

char* getHome() {
    return getenv("HOME") != nullptr ? getenv("HOME") : getenv("USERPROFILE");
}

void handleNew(char* name) {
    auto home = std::filesystem::path(getHome());

    home = home / ".config" / "tmpltr";
    bool exists = std::filesystem::exists(home);
    if (!exists) {
        std::filesystem::create_directories(home);
    }

    std::filesystem::path destination = home / name;

    std::filesystem::create_directories(destination);

    std::filesystem::path source = std::filesystem::current_path();

    try {
        std::filesystem::copy(
            source,
            destination,
            std::filesystem::copy_options::recursive |
            std::filesystem::copy_options::copy_symlinks |
            std::filesystem::copy_options::overwrite_existing
        );
    } catch (const std::filesystem::filesystem_error& e) {
        std::println("Copy failed: {}", e.what());
        return;
    }

    std::println("Template {} created!", name);
}

void handleUse(const char* name) {
    auto home = std::filesystem::path(getHome()) / ".config" / "tmpltr";
    std::filesystem::path source = home / name;

    if (!std::filesystem::exists(source) || !std::filesystem::is_directory(source)) {
        std::println("Template '{}' does not exist!", name);
        return;
    }

    std::filesystem::path destination = std::filesystem::current_path();
    std::filesystem::create_directories(destination);

    try {
        std::filesystem::copy(
            source,
            destination,
            std::filesystem::copy_options::recursive |
            std::filesystem::copy_options::copy_symlinks |
            std::filesystem::copy_options::overwrite_existing
        );
    } catch (const std::filesystem::filesystem_error& e) {
        std::println("Copy failed: {}", e.what());
        return;
    }

    std::println("Template '{}' applied!", name);
}

void handleDel(char* name) {
    auto home = std::filesystem::path(getHome()) / ".config" / "tmpltr";
    std::filesystem::path source = home / name;

    if (!std::filesystem::exists(source) || !std::filesystem::is_directory(source)) {
        std::println("Template '{}' does not exist!", name);
        return;
    }

    try {
        std::filesystem::remove(source);
    } catch (const std::filesystem::filesystem_error& e) {
        std::println("Deletion failed: {}", e.what());
        return;
    }

    std::println("Template {} deleted!", name);
}

void handleMV (char* nold, char* nnew) {
    auto home = std::filesystem::path(getHome()) / ".config" / "tmpltr";
    std::filesystem::path source = home / nold;
    std::filesystem::path dest = home / nnew;

    if (!std::filesystem::exists(source) || !std::filesystem::is_directory(source)) {
        std::println("Template '{}' does not exist!", nold);
        return;
    }
    
    if (std::filesystem::exists(source) && std::filesystem::is_directory(source)) {
        std::print("Template '{}' already exists!\nAre you sure you want to continue? (y/n) ", nold);
        char c;
        std::cin >> c;
        if(c != 'y' && c != 'Y')
            return;
    }

    try {
        std::filesystem::rename(source, dest);
    } catch (const std::filesystem::filesystem_error& e) {
        std::println("Rename failed: {}", e.what());
        return;
    }

    std::println("Template '{}' renamed to '{}' !", nold, nnew);
}

int main(int argc, char** argv) {
    if(argc < 3) {
        std::println("Usage: tmpl <new/use/del/mv> [values...]");
        return 1;
    }

    if(strcmp(argv[1], "new") == 0) handleNew(argv[2]);
    if(strcmp(argv[1], "use") == 0) handleUse(argv[2]);
    if(strcmp(argv[1], "del") == 0) handleDel(argv[2]);
    if(strcmp(argv[1], "mv" ) == 0) handleMV (argv[2], argv[3]);

    return 0;
}