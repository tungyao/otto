#include "request.h"
#include "stdlib.h"

char *get_referer() {
    return getenv("HTTP_REFERER");
}

char *get_user_agent() {
    return getenv("HTTP_USER_AGENT");
}

char *get_path_info() {
    return getenv("PATH_INFO");
}

char *get_query_string() {
    return getenv("QUERY_STRING");
}

char *get_remote_addr() {
    return getenv("REMOTE_ADDR");
}

char *get_method() {
    return getenv("REQUEST_METHOD");
}

char *get_server_name() {
    return getenv("SERVER_NAME");
}

char *get_server_port() {
    return getenv("SERVER_PORT");
}
