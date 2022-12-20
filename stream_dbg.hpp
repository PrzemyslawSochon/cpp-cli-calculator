#pragma once
#include <string>
#include <string_view>

std::string consoleInputDebug();
bool confirm();
bool again();

std::string removeTrailingZeros(const double& value);