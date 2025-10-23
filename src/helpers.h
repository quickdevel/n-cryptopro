#ifndef HELPERS_H
#define HELPERS_H

#include "stdafx.h"

void HandleError (Napi::Env env, const char *message);
void HandleArgumentError (Napi::Env env, const char *message);

std::string StringAcpToUtf8(std::string inString);
std::string StringUtf8ToAcp(std::string inString);
double FileTimeToUnixTimeMs(FILETIME& ft);

#endif
