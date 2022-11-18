#include "jsonfile.h"
#include <fstream>
#include <iostream>

std::string JsonFile::JsonFileToString(const std::string& path) {
    std::ifstream file_stream(path);
	std::string file_string(std::istreambuf_iterator<char>{file_stream}, std::istreambuf_iterator<char>{});
    return file_string;
}

nlohmann::json JsonFile::StringToJson(const std::string& original_string) {
    nlohmann::json res = nlohmann::json::parse(original_string);
    return res;
}

std::string JsonFile::JsonToString(const nlohmann::json& json, const int space_count) {
    return json.dump(space_count);
}