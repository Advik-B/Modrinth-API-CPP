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
        if (data.contains("requested_status") && !data["requested_status"].is_null()) {
            project.requested_status = static_cast<ProjectRequestedStatus>(data["requested_status"]);
        }
        if (data.contains("additional_categories") && !data["additional_categories"].is_null()) {
            for (const auto &category : data["additional_categories"]) {
                project.additional_categories->push_back(category);
            }
        }
        if (data.contains("issues_url") && !data["issues_url"].is_null()) {
            project.issues_url = data["issues_url"];
        }
        if (data.contains("source_url") && !data["source_url"].is_null()) {
            project.source_url = data["source_url"];
        }
        if (data.contains("wiki_url") && !data["wiki_url"].is_null()) {
            project.wiki_url = data["wiki_url"];
        }
        if (data.contains("discord_url") && !data["discord_url"].is_null()) {
            project.discord_url = data["discord_url"];
        }
        if (data.contains("donation_urls") && !data["donation_urls"].is_null()) {
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
        return project;
    }
};

