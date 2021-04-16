#include <CLI/CLI.hpp>
#include <iostream>

// how to run
// $ ./build/cli11-dash-option -t target -d device -p port

int main(int argc, char** argv) {
    CLI::App app{ "CLI11 example: use dash options" };

    std::string target;
    app.add_option("-t", target, "target url")->required();
    std::string device;
    app.add_option("-d", device, "device name")->required();

    int port = 1111;  // it has a default value
    // adding "true" here so "argv[0] --help" will show its default value
    app.add_option("-p", port, "device port", true);

    CLI11_PARSE(app, argc, argv);

    // main program starts from here
    printf("target: %s\n", target.c_str());
    printf("device: %s\n", device.c_str());
    printf("  port: %d\n", port);

    return 0;
}
