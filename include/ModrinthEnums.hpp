
#ifndef MODRINTHPROJECTTYPE_HPP
#define MODRINTHPROJECTTYPE_HPP

namespace modrinth {
    enum class ProjectType {
        MOD = 0,
        MODPACK = 1,
        RESOURCE_PACK = 2,
        SHADER = 3,
    };

    enum class ProjectSide {
        REQUIRED = 0,
        OPTIONAL = 1,
        UNSUPPORTED = 2,
    };

    enum class ProjectStatus {
        APPROVED = 0,
        ARCHIVED = 1,
        REJECTED = 2,
        DRAFT = 3,
        UNLISTED = 4,
        PROCESSING = 5,
        WITHHELD = 6,
        SCHEDULED = 7,
        PRIVATE = 8,
        UNKNOWN = 9,
    };

    enum class ProjectRequestedStatus {
        APPROVED = 0,
        ARCHIVED = 1,
        UNLISTED = 2,
        PRIVATE = 3,
        DRAFT = 4,
    };

    enum class ProjectMonitizationStatus {
        MONITIZED = 0,
        DEMONITIZED = 1,
        FORCED_DEMONITIZED = 2,
    };
}


#endif //MODRINTHPROJECTTYPE_HPP
