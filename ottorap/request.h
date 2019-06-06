#ifndef REQUEST_H
#define REQUEST_H

char *get_referer();
char *get_user_agent();
char *get_path_info();
char *get_query_string();
char *get_remote_addr();
char *get_method();
char *get_server_name();
char *get_server_port();

#endif
