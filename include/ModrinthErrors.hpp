#ifndef MODRINTHERRORS_HPP
#define MODRINTHERRORS_HPP

#include <exception>
#include <string>

namespace modrinth {
    class ModrinthAPIError : public std::exception {
    public:
        explicit ModrinthAPIError(const std::string &message);

        const char *what() const noexcept override;
    private:
        std::string message;
    };

}

#endif //MODRINTHERRORS_HPP
