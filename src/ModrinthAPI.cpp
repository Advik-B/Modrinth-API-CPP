#include "ModrinthAPI.hpp"

modrinth::ModrinthAPI::ModrinthAPI(const string &identifier, const optional<string> &token) {
    this->identifier = identifier;
    this->token = token;
}

modrinth::ModrinthAPI::~ModrinthAPI() = default;