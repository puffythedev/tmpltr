#include <tmpltr.hpp>

void handleNew(char* name) {
    bool exists = fs::exists(home);

    if (!exists) {
        fs::create_directories(home);
    }

    fs::path destination = home / name;
    fs::create_directories(destination);

    fs::path source = fs::current_path();

    try {
        fs::copy(
            source,
            destination,
            fs::copy_options::recursive |
            fs::copy_options::copy_symlinks |
            fs::copy_options::overwrite_existing
        );
    } catch (const fs::filesystem_error& e) {
        std::println("Copy failed: {}", e.what());
        return;
    }

    std::println("Template {} created!", name);
}