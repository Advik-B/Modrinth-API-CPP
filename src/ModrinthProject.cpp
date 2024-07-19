#include "ModrinthProject.hpp"

namespace modrinth {

    bool aint_empty(const json &data, const string &key) {
        return data.contains(key) && !data[key].is_null();
    }

    Project Project::from_json(const json &data) {
        Project project;
        project.slug = data["slug"];
        project.title = data["title"];
        project.description = data["description"];
        for (const auto &category : data["categories"]) {
            project.categories.push_back(category);
        }
        project.client_side = static_cast<ProjectSide>(data["client_side"]);
        project.server_side = static_cast<ProjectSide>(data["server_side"]);
        project.body = data["body"];
        project.status = static_cast<ProjectStatus>(data["status"]);
        if (aint_empty(data, "requested_status")) {
            project.requested_status = static_cast<ProjectRequestedStatus>(data["requested_status"]);
        }
        if (aint_empty(data, "additional_categories")) {
            for (const auto &category : data["additional_categories"]) {
                project.additional_categories->push_back(category);
            }
        }
        if (aint_empty(data, "issues_url")) {
            project.issues_url = data["issues_url"];
        }
        if (aint_empty(data, "source_url")) {
            project.source_url = data["source_url"];
        }
        if (aint_empty(data, "wiki_url")) {
            project.wiki_url = data["wiki_url"];
        }
        if (aint_empty(data, "discord_url")) {
            project.discord_url = data["discord_url"];
        }
        if (aint_empty(data, "donation_urls")) {
            for (const auto &donation_url : data["donation_urls"]) {
                ProjectDonationURL object;
                object.url = donation_url["url"];
                object.id = donation_url["id"];
                object.platform = donation_url["platform"];
                project.donation_url->push_back(object);
            }
        }
        project.project_type = static_cast<ProjectType>(data["project_type"]);
        project.downloads = data["downloads"];
        if (aint_empty(data, "icon_url")) {
            project.icon_url = data["icon_url"];
        }
        if (aint_empty(data, "color")) {
            project.color = data["color"];
        }
        if (aint_empty(data, "thread_id")) {
            project.thread_id = data["thread_id"];
        }
        if (aint_empty(data, "monitization_status")) {
            project.monitization_status = static_cast<ProjectMonitizationStatus>(data["monitization_status"]);
        }
        project.id = data["id"];
        project.team = data["team"];
        project.published = data["published"];
        project.updated = data["updated"];
        if (aint_empty(data, "approved")) {
            project.approved = data["approved"];
        }
        if (aint_empty(data, "queued")) {
            project.queued = data["queued"];
        }
        project.followers = data["followers"];
        if (aint_empty(data, "license")) {
            project.license = static_cast<ProjectLicense>(data["license"]);
        }
        if (aint_empty(data, "versions")) {
            for (const auto &version : data["versions"]) {
                project.versions->push_back(version.value);
            }
        }
        if (aint_empty(data, "game_versions")) {
            for (const auto &game_version : data["game_versions"]) {
                project.game_versions->push_back(game_version.value);
            }
        }
        if (aint_empty(data, "loaders")) {
            for (const auto &loader : data["loaders"]) {
                project.loaders->push_back(loader.value);
            }
        }
        if (aint_empty(data, "gallery")) {
            for (const auto &gallery_image : data["gallery"]) {
                GalleryImage object;
                object.url = gallery_image["url"];
                object.featured = gallery_image["featured"];
                object.created = gallery_image["created"];
                object.ordering = gallery_image["ordering"];
                if (aint_empty(gallery_image, "title")) {
                    object.title = gallery_image["title"];
                }
                if (aint_empty(gallery_image, "description")) {
                    object.description = gallery_image["description"];
                }
                project.gallery->push_back(object);
            }
        }
        return project;
    }
};