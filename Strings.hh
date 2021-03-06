#pragma once

#include <stdint.h>
#include <sys/types.h>

#include <string>
#include <vector>


bool starts_with(const std::string& s, const std::string& start);
bool ends_with(const std::string& s, const std::string& end);

std::string string_printf(const char* fmt, ...);
std::wstring wstring_printf(const wchar_t* fmt, ...);
std::string string_vprintf(const char* fmt, va_list va);
std::wstring wstring_vprintf(const wchar_t* fmt, va_list va);

uint8_t value_for_hex_char(char x);

#define DEBUG 0
#define INFO 1
#define WARNING 2
#define ERROR 3

int log_level();
void set_log_level(int new_level);
void log(int level, const char* fmt, ...);

std::vector<std::string> split(const std::string& s, char delim);
std::vector<std::string> split_context(const std::string& s, char delim);
std::string join(const std::vector<std::string>& items,
    const std::string& delim);

size_t skip_whitespace(const std::string& s, size_t offset);
size_t skip_whitespace(const char* s, size_t offset);
size_t skip_non_whitespace(const std::string& s, size_t offset);
size_t skip_non_whitespace(const char* s, size_t offset);
size_t skip_word(const std::string& s, size_t offset);
size_t skip_word(const char* s, size_t offset);

std::string string_for_error(int error);

enum class TerminalFormat {
  END        = -1,
  NORMAL     = 0,
  BOLD       = 1,
  UNDERLINE  = 4,
  BLINK      = 5,
  INVERSE    = 7,
  FG_BLACK   = 30,
  FG_RED     = 31,
  FG_GREEN   = 32,
  FG_YELLOW  = 33,
  FG_BLUE    = 34,
  FG_MAGENTA = 35,
  FG_CYAN    = 36,
  FG_GRAY    = 37,
  FG_WHITE   = 38,
  BG_BLACK   = 40,
  BG_RED     = 41,
  BG_GREEN   = 42,
  BG_YELLOW  = 43,
  BG_BLUE    = 44,
  BG_MAGENTA = 45,
  BG_CYAN    = 46,
  BG_GRAY    = 47,
  BG_WHITE   = 48,
};

void print_color_escape(FILE* stream, TerminalFormat color, ...);

void print_indent(FILE* stream, int indent_level);

enum PrintDataFlags {
  UseColor = 1, // use terminal escape codes to show differences
  PrintAscii = 2, // print ascii view on the right
  PrintFloat = 4, // print float view on the right
  PrintDouble = 8, // print double view on the right
  ReverseEndian = 16, // floats/doubles should be byteswapped
};

void print_data(FILE* stream, const void* _data, uint64_t size,
    uint64_t address = 0, const void* _prev = NULL,
    uint64_t flags = PrintDataFlags::PrintAscii);
void print_data(FILE* stream, const std::string& data, uint64_t address = 0,
    const void* prev = NULL, uint64_t flags = PrintDataFlags::PrintAscii);

std::string parse_data_string(const std::string& s, std::string* mask = NULL);
std::string format_data_string(const std::string& data, const std::string* mask = NULL);

std::string format_time(struct timeval* tv = NULL);
std::string format_size(size_t size, bool include_bytes = false);
