/*******************************************************
- File Name: Server.cpp
*
- Author: Trennan "Mola RF" Tewksbury
*
- Purpose: HTTP server implementation driving Drawing actions
*
*******************************************************/

#include <string>
#include <iostream>

#include "../include/json.hpp"
#include "../include/httplib.h"
#include "../include/Server.hpp"

/*
using json = nlohmann::json;

Server::Server(int listenPort, Drawing& drawing)
    : 
    port(listenPort), drawingController(drawing) 
{
}

void Server::start() {
    httplib::Server svr;

    svr.Get("/health", [](const httplib::Request&, httplib::Response& res) {
        json body = { { "status", "ok" } };
        res.set_content(body.dump(), "application/json");
        });

    svr.Post("/command", [this](const httplib::Request& req, httplib::Response& res) {
        try {
            json payload = json::parse(req.body);
            std::string action = payload.at("action").get<std::string>();

            // Dispatch to drawingController based on action
            json reply = {
                { "status", "accepted" },
                { "action", action }
            };
            res.status = 200;
            res.set_content(reply.dump(), "application/json");
        }
        catch (const json::exception& e) {
            json err = {
                { "status", "error" },
                { "message", std::string("Invalid JSON or missing field: ") + e.what() }
            };
            res.status = 400;
            res.set_content(err.dump(), "application/json");
        }
        });

    std::cout << "Starting server on port " << port << "...\n";
    if (!svr.listen("0.0.0.0", port)) {
        std::cerr << "Failed to bind/listen on port " << port << "\n";
    }
}
*/