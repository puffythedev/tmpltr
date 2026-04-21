#include <utils/utils.hpp>
#include <iostream>

char* Utils::getHome() {
    return getenv("HOME") != nullptr ? getenv("HOME") : getenv("USERPROFILE");
}