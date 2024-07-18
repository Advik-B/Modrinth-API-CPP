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

    struct GalleryImage {
        string url;
        bool featured;
        optional<string> title = nullopt;
        optional<string> description = nullopt;
        string created;
        int32_t ordering;
    };
};

#endif //MODRINTHSTRUCTS_HPP
