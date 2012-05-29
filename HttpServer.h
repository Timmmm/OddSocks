#pragma once

#include <string>

using namespace std;

// Prints the authentication form. If isInvalidPassword is true, we say "Invalid password" on the page.
string printAuthenticationRequest(bool isInvalidPassword = false);

// They succeeded. Redirect to defectiveyeti?
string printAuthenticationSuccess();
