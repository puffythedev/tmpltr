#pragma once

#include <utils/utils.hpp>
#include <filesystem>
#include <print>

namespace fs = std::filesystem;

extern fs::path home;

/*
 * @brief Creates a TODO print with message.
 */
#define TODO(x) std::println("{}:{}:{}: TODO: Implement {}", __FILE__, __LINE__, 0, x);

/**
 * @brief Handles the `use` subcommand
 * @param name name of the template to use
 */
void handleUse(const char* name);

/**
 * @brief Handles the `new` subcommand
 * @param name name of the template to create
 */
void handleNew(char* name);

/**
 * @brief Handles the `del` subcommand
 * @param name name of the template to use
 */
void handleDel(char* name);

/**
 * @brief Handles the `mv` subcommand
 * @param nold old name of the template
 * @param nnew new name of the template
 */
void handleMV (char* nold, char* nnew);