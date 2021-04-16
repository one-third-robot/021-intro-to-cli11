#include <CLI/CLI.hpp>
#include <stdio.h>

// how to run
// $ ./build/cli11-positional-option target device port

int main(int argc, char* argv[]) {
    CLI::App    app{ "CLI11 example program: to show how to use options" };
    std::string filename = "cli11-demo";

    // positional arguments, do not mess the positions
    std::string target;
    app.add_option("target", target, "target url")->required();
    std::string device;
    app.add_option("device", device, "device name")->required();

    // make the argument optional: just do not have "->required()"
    int port;
    app.add_option("port", port, "device port");

    // lastly, use this to parse the arguments
    CLI11_PARSE(app, argc, argv);

    // --------------------------------------------------------------------
    // main program starts from here
    printf("target: %s\n", target.c_str());
    printf("device: %s\n", device.c_str());
    printf("  port: %d\n", port);

    return 0;
}
