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

#include <std4esl/Plugin.h>
#include <std4esl/object/Int.h>
#include <std4esl/object/MapStringString.h>
#include <std4esl/object/SetInt.h>
#include <std4esl/object/SetString.h>
#include <std4esl/object/String.h>
#include <std4esl/object/VectorInt.h>
#include <std4esl/object/VectorPairStringString.h>
#include <std4esl/object/VectorString.h>

#include <esl/object/Object.h>

namespace std4esl {

void Plugin::install(esl::plugin::Registry& registry, const char* data) {
	esl::plugin::Registry::set(registry);

	/* *************** *
	 * builtin objects *
	 * *************** */
	registry.addPlugin<esl::object::Object>(
			"std/int",
			&object::Int::create);

	registry.addPlugin<esl::object::Object>(
			"std/map<string,string>",
			&object::MapStringString::create);

	registry.addPlugin<esl::object::Object>(
			"std/set<int>",
			&object::SetInt::create);

	registry.addPlugin<esl::object::Object>(
			"std/set<string>",
			&object::SetString::create);

	registry.addPlugin<esl::object::Object>(
			"std/string",
			&object::String::create);

	registry.addPlugin<esl::object::Object>(
			"std/vector<int>",
			&object::VectorInt::create);

	registry.addPlugin<esl::object::Object>(
			"std/vector<pair<string,string>>",
			&object::VectorPairStringString::create);

	registry.addPlugin<esl::object::Object>(
			"std/vector<string>",
			&object::VectorString::create);
}

} /* namespace std4esl */
