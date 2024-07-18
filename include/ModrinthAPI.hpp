
#ifndef MODRINTHAPI_HPP
#define MODRINTHAPI_HPP

#include <optional>
#include <string>
#include <cpr/cpr.h>
#include <cpr/parameters.h>
#include <nlohmann/json.hpp>


namespace modrinth {

    using std::optional;
    using std::string;
    using std::nullopt;
    using nlohmann::json;

    const string version = "0.0.0";

    class ModrinthAPI {
    public:
        explicit ModrinthAPI(const string &identifier, const optional<string> &token = nullopt);
        ~ModrinthAPI();
    private:
        string identifier;
        optional<string> token = nullopt;
    };
}

#endif //MODRINTHAPI_HPP
