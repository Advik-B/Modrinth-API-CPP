#ifndef MODRINTHSTRUCTS_HPP
#define MODRINTHSTRUCTS_HPP

#include <string>
#include <optional>

namespace modrinth {
    using std::string;
    using std::optional;
    using std::nullopt;

    struct ProjectDonationURL {
        string id;
        string platform;
        string url;
    };

    struct ProjectLicense {
        string id;
        string name;
        optional<string> url = nullopt;
    };
};

#endif //MODRINTHSTRUCTS_HPP
