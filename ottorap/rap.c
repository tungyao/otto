#include "rap.h"

void serve_forever() {
    init_handlers();
    while(FCGI_Accept() >= 0) {
        dispatch();
    }
    cleanup_handlers();
}
