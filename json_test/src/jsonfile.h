#include <string>
#include <nlohmann/json.hpp>


class JsonFile {
public:
    static std::string JsonFileToString(const std::string& path);
    static nlohmann::json StringToJson(const std::string& original_string);
    static std::string JsonToString(const nlohmann::json& json, const int space_count);
};