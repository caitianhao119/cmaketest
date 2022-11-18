#include <json.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include "config.h"
#include <jsonfile.h>

using json = nlohmann::json;

int main() {
	// std::string file_name = "/Users/BobbyCai/Documents/cmaketest/json_test/test.json";
	std::string file_name = std::string(FILE_ROOT_PATH) + "/test.json";

	std::string file_string = JsonFile::JsonFileToString(file_name);
	nlohmann::json file_json = JsonFile::StringToJson(file_string);
	std::string res = JsonFile::JsonToString(file_string, 0);
	std::cout << res << std::endl;
	std::cout << file_json << std::endl;
	return 0;
}