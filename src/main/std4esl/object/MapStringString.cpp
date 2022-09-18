/*
MIT License
Copyright (c) 2021-2022 Sven Lukas

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <std4esl/object/MapStringString.h>
#include <std4esl/Logger.h>

#include <stdexcept>

namespace std4esl {
namespace object {

namespace {
std::map<std::string, std::string> makeValue(const std::vector<std::pair<std::string, std::string>>& settings) {
	std::map<std::string, std::string> value;

	for(const auto& setting : settings) {
		if(value.count(setting.first) > 0) {
			throw std::runtime_error("Multiple definition of attribute '" + setting.first + "'");
		}
		value.insert(std::make_pair(setting.first, setting.second));
	}

	return value;
}
} /* anonymous namespace */

std::unique_ptr<esl::object::Object> MapStringString::create(const std::vector<std::pair<std::string, std::string>>& settings) {
	return std::unique_ptr<esl::object::Object>(new MapStringString(settings));
}

MapStringString::MapStringString(const std::vector<std::pair<std::string, std::string>>& settings)
: Value<std::map<std::string, std::string>>(makeValue(settings))
{ }

} /* namespace object */
} /* namespace std4esl */