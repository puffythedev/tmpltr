#include <tmpltr.hpp>

void handleUse(const char* name) {
    fs::path source = home / name;

    if (!fs::exists(source) || !fs::is_directory(source)) {
        std::println("Template '{}' does not exist!", name);
        return;
    }

    fs::path destination = fs::current_path();
    fs::create_directories(destination);

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

    std::println("Template '{}' applied!", name);
}