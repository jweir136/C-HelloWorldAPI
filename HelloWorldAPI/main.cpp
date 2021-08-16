#include <iostream>
#include <string>
#include <served/served.hpp>

int main() {
    served::multiplexer mux;

    mux.handle("/").get([&] (served::response &res, const served::request &req) {
        std::string name = req.query["name"];
        res.set_header("content-type", "application/json");
        
        if (name.length() > 0)
            res << "{\"status\":200, \"content\":\"Hello, " << name << "\"}\n";
        else
            res << "{\"status\":200, \"content\":\"Hello, World\"}\n";
    });

    served::net::server server("localhost", "8080", mux);
    server.run(10);

    return 0;
}