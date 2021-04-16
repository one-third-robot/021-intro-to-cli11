#include <CLI/CLI.hpp>
#include <iostream>

// how to run
// $ ./build/cli11-positional-option -t target -d device -p port

int main(int argc, char** argv) {
    CLI::App app{ "App description" };

    std::string target;
    app.add_option("-t", target, "target url")->required();
    std::string device;
    app.add_option("-d", device, "device name")->required();

    int port = 1111;  // it has a default value
    app.add_option("-p", port, "device port");

    CLI11_PARSE(app, argc, argv);

    // main program starts from here
    printf("target: %s\n", target.c_str());
    printf("device: %s\n", device.c_str());
    printf("  port: %d\n", port);

    return 0;
}
