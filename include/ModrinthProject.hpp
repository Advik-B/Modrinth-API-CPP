#ifndef MODRINTHPROJECT_HPP
#define MODRINTHPROJECT_HPP

#include <string>
#include <optional>
#include <vector>
#include <cstdint>
#include <ctime>
#include "ModrinthEnums.hpp"
#include "ModrinthStructs.hpp"

namespace modrinth {

    using std::string;
    using std::optional;
    using std::vector;
    using std::nullopt;

    typedef vector<string> stringArray;
    typedef vector<ProjectDonationURL> DonationURLArray;

    class Project {
        public:
            string name;
            string title;
            string description;
            vector<string> categories;
            ProjectSide client_side;
            ProjectSide server_side;
            string body;
            ProjectStatus status;
            int64_t followers;
            int64_t downloads;
            string team;
            string id;
            optional<string> requested_status = nullopt;
            optional<stringArray> additional_categories = nullopt;
            optional<string> issues_url = nullopt;
            optional<string> source_url = nullopt;
            optional<string> wiki_url = nullopt;
            optional<string> discord_url = nullopt;
            optional<DonationURLArray> donation_url = nullopt;
            optional<string> icon_url = nullopt;
            optional<int64_t> color = nullopt;
            optional<string> thread_id = nullopt;
            optional<ProjectMonitizationStatus> monitization_status = nullopt;
            optional<string> monitization_type = nullopt;
            optional<string> queued = nullopt;
    };
}

#endif //MODRINTHPROJECT_HPP
