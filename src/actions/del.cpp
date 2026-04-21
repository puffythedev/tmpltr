#include <tmpltr.hpp>

void handleDel(char* name) {
    fs::path source = home / name;

    if (!fs::exists(source) || !fs::is_directory(source)) {
        std::println("Template '{}' does not exist!", name);
        return;
    }

    try {
        fs::remove(source);
    } catch (const fs::filesystem_error& e) {
        std::println("Deletion failed: {}", e.what());
        return;
    }

    std::println("Template {} deleted!", name);
}