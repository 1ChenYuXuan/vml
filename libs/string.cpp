
#include "string.hpp"

const std::set<char> SYMBOL = {' ', '(', ')', '[', ']', '{', '}', '~',
                               '<', '>', ';', '/', '=', '-',
                               '*'};

std::vector<std::string> good_str(const std::string& utf8_str)
{
    std::vector<std::string> char_list;
    const unsigned char* bytes = reinterpret_cast<const unsigned char*>(utf8_str.data());
    size_t len = utf8_str.size();
    size_t i = 0;

    while (i < len) {
        unsigned char current_byte = bytes[i];
        size_t char_byte_len = 1;

        if ((current_byte & 0x80) == 0) {
            char_byte_len = 1;
        } else if ((current_byte & 0xE0) == 0xC0) {
            if (i + 1 >= len || (bytes[i+1] & 0xC0) != 0x80) {
                throw std::invalid_argument("Invalid UTF-8 encoding: 2-byte character missing subsequent byte");
            }
            char_byte_len = 2;
        } else if ((current_byte & 0xF0) == 0xE0) {
            if (i + 2 >= len || (bytes[i+1] & 0xC0) != 0x80 || (bytes[i+2] & 0xC0) != 0x80) {
                throw std::invalid_argument("Invalid UTF-8 encoding: 3-byte character missing subsequent bytes");
            }
            char_byte_len = 3;
        } else if ((current_byte & 0xF8) == 0xF0) {
            if (i + 3 >= len || (bytes[i+1] & 0xC0) != 0x80 || (bytes[i+2] & 0xC0) != 0x80 || (bytes[i+3] & 0xC0) != 0x80) {
                throw std::invalid_argument("Invalid UTF-8 encoding: 4-byte character missing subsequent bytes");
            }
            char_byte_len = 4;
        } else {
            throw std::invalid_argument("Invalid UTF-8 encoding: Invalid leading byte");
        }

        char_list.push_back(utf8_str.substr(i, char_byte_len));
        i += char_byte_len;
    }

    return char_list;
}

std::vector<std::string> split(const std::string& s, char sep) {
    std::vector<std::string> result;
    std::string::size_type start = 0;
    std::string::size_type end = s.find(sep);
    while (end != std::string::npos) {
        result.emplace_back(s, start, end - start);
        start = end + 1;
        end = s.find(sep, start);
    }
    result.push_back(s.substr(start));
    return result;
}

std::string join(const std::vector<std::string>& strs, const std::string& sep) {
    std::string result;
    for (size_t i = 0; i < strs.size(); ++i) {
        result += strs[i];
        if (i != strs.size() - 1)
            result += sep;
    }
    return result;
}

bool is_digit(const std::string& str) {
    return !str.empty() && std::all_of(str.begin(), str.end(), [](unsigned char c) {
        return std::isdigit(c);
    });
}

void ltrim(std::string& s) {
    s.erase(s.begin(), std::find_if_not(s.begin(), s.end(), [](unsigned char c) {
        return std::isspace(c);
    }));
}

void rtrim(std::string& s) {
    s.erase(std::find_if_not(s.rbegin(), s.rend(), [](unsigned char c) {
        return std::isspace(c);
    }).base(), s.end());
}

void trim(std::string& s) {
    ltrim(s);
    rtrim(s);
}

// split_string_and_reserve_string
std::vector<std::string> ssars(const std::string& str)
{
    std::vector<std::string> split_str;
    std::string temp;
    bool is_string = false;
    for (int index = 0; index < str.length(); ++index) {
        char str_char = str[index];
        if (str_char == '"'){
            if (is_string)
            {
                temp.push_back('"');
                split_str.push_back(temp);
                temp.clear();
            } else {
                temp.push_back('"');
            }
            is_string = !is_string;
        } else if (str_char == ' ' && !is_string) {
            if (!temp.empty()) {
                split_str.push_back(temp);
                temp.clear();
            }
        } else {
            temp.push_back(str_char);
        }
    }
    if (is_string && !temp.empty()) {
        split_str.push_back(temp);
        temp.clear();
    }
    if (!temp.empty())
        split_str.push_back(temp);
    split_str.erase(
        std::remove_if(split_str.begin(), split_str.end(), [](const std::string& s) {
            return s.empty();
        }),
        split_str.end()
    );
    return split_str;
}

// split_string_and_reserve_string_and_split_symbol
std::vector<std::string> ssarsass(const std::string& str)
{
    std::vector<std::string> split_str;
    std::string temp;
    bool is_string = false;
    for (int index = 0; index < str.length(); ++index) {
        char str_char = str[index];
        if (str_char == '"'){
            if (is_string)
            {
                temp.push_back('"');
                split_str.push_back(temp);
                temp.clear();
            } else {
                temp.push_back('"');
            }
            is_string = !is_string;
        } else if (SYMBOL.count(str_char) && !is_string) {
            std::string symbol_str(1, str_char);
             if (!temp.empty()) {
                 split_str.push_back(temp);
                 temp.clear();
             }
             split_str.push_back(symbol_str);
         } else {
            temp.push_back(str_char);
        }
    }
    if (is_string && !temp.empty()) {
        split_str.push_back(temp);
        temp.clear();
    }
    if (!temp.empty())
        split_str.push_back(temp);
    split_str.erase(
        std::remove_if(split_str.begin(), split_str.end(), [](const std::string& s) {
            return s.empty();
        }),
        split_str.end()
    );
    return split_str;
}
