//main.cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

static void die(const std::string& m) {
    std::cerr << m << std::endl;
    std::exit(1);
}

int main(int argc, char** argv) {
    if (argc != 4) die("usage: ./sed <filename> <s1> <s2>");
    const std::string inname = argv[1];
    const std::string s1 = argv[2];
    const std::string s2 = argv[3];
    if (s1.empty()) die("error: s1 must not be empty");

    std::ifstream in(inname.c_str(), std::ios::in | std::ios::binary);
    if (!in) die("error: cannot open input file");
    std::ostringstream buf;
    buf << in.rdbuf();
    std::string content = buf.str();

    std::ofstream out((inname + ".replace").c_str(), std::ios::out | std::ios::binary);
    if (!out) die("error: cannot open output file");

    std::string::size_type pos = 0;
    std::string::size_type prev = 0;
    while (true) {
        pos = content.find(s1, prev);
        if (pos == std::string::npos) break;
        out << content.substr(prev, pos - prev);
        out << s2;
        prev = pos + s1.size();
    }
    out << content.substr(prev);
    return 0;
}
