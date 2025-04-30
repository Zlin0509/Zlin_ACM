#include "2/testlib.h"
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    registerTestlibCmd(argc, argv);
    while (!inf.eof() && !ouf.eof()) {
        string actual = inf.readString();
        string expected = ouf.readString();
        if (actual != expected) {
            quitf(_wa, "Mismatch at some point: expected \"%s\", but got \"%s\"", expected.c_str(), actual.c_str());
        }
    }
    if (!inf.eof() || !ouf.eof()) {
        quitf(_wa, "One file has more elements than the other.");
    }
    quitf(_ok, "Output is correct");
    return 0;
}