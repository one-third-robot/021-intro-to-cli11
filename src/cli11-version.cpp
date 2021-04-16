#include <CLI/CLI.hpp>
#include <stdio.h>

using namespace std;

static void show_version(void) {
#ifdef _REPO_NAME
    printf("  repo name : %s\n", _REPO_NAME);
#endif
#ifdef _GIT_BRANCH
    printf("     branch : %s\n", _GIT_BRANCH);
#endif
#ifdef _GIT_TAG
    printf("version tag : %s\n", _GIT_TAG);
#endif
#ifdef _GIT_COMMIT
    printf("commit hash : %s\n", _GIT_COMMIT);
#endif
#if (!defined _REPO_NAME) || (!defined _GIT_BRANCH) || (!defined _GIT_TAG) \
    || (!defined _GIT_COMMIT)
    printf("not a Git repo\n");
#endif
}
static void show_author(void) {
#ifdef _GIT_COMMIT_AUTHOR
    printf("  author : %s\n", _GIT_COMMIT_AUTHOR);
#endif
#ifdef _GIT_COMMIT_EMAIL
    printf("   email : %s\n", _GIT_COMMIT_EMAIL);
#endif
#if (!defined _GIT_COMMIT_AUTHOR) || (!defined _GIT_COMMIT_EMAIL)
    printf("not a Git repo\n");
#endif
}

// assumeing we want to run the program like this:
// ./build/cli11-demo target device port

int main(int argc, char* argv[]) {
    CLI::App    app{ "CLI11 example program: to show how to use options" };
    std::string filename = "cli11-demo";

    // --------------------------------------------------------------------
    // add some group options
    auto build_info_option = app.add_option_group("build information");
    auto version_flag =
        build_info_option->add_flag("--version", "show version information");
    auto authoer_flag =
        build_info_option->add_flag("--author", "show author information");
    build_info_option->parse_complete_callback([&] {
        if (*version_flag) {
            show_version();
            exit(EXIT_SUCCESS);
        }
        if (*authoer_flag) {
            show_author();
            exit(EXIT_SUCCESS);
        }
    });

    CLI11_PARSE(app, argc, argv);
    printf("main starts from here\n");

    return 0;
}
