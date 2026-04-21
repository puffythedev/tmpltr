#include <cstring>
#include <tmpltr.hpp>

int main(int argc, char** argv) {
    if(argc < 3) {
        std::println("Usage: tmpl <new/use/del/mv> [values...]");
        return 1;
    }

    home = Utils::getHome();
    home = home / ".config" / "tmpltr";
    
    if(strcmp(argv[1], "new") == 0) handleNew(argv[2]);
    if(strcmp(argv[1], "use") == 0) handleUse(argv[2]);
    if(strcmp(argv[1], "del") == 0) handleDel(argv[2]);
    if(strcmp(argv[1], "mv" ) == 0) handleMV (argv[2], argv[3]);
    else {
        std::println("Usage: tmpl <new/use/del/mv> [values...]");
        return 1;
    }

    return 0;
}

/*
 * @brief the user's Home path (C:\Users\YourName in windows & /home/yourname on linux)
 */
fs::path home;