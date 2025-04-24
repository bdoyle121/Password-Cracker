#ifndef MD5_H
#define MD5_H

#include <string>

/**
 * Computes the MD5 hash of the given string and returns
 * the hexadecimal digest (32 hex characters).
 */
std::string md5Hash(const std::string& input);

#endif // MD5_H