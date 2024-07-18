#include "ModrinthErrors.hpp"

namespace modrinth {
    ModrinthAPIError::ModrinthAPIError(const std::string &message) {
        this->message = message;
    }

    const char *ModrinthAPIError::what() const noexcept {
        return message.c_str();
    }
}
