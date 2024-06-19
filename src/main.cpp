#include "httplib.h"
#include <iostream>

int main(void) {
  std::cout << "Webserver started!" << std::endl;
  httplib::Server server;

  // Register static directory
  server.set_mount_point("/www-data", "app/www-data");

  server.Get("/", [&](const httplib::Request &req, httplib::Response &res) {
    res.set_content(
      "<html><head><title>Index page</title></head><body><h1>Hello, World!</h1></body></html>", 
      "text/html"
    );
  });

  server.Get("/test", [&](const httplib::Request &req, httplib::Response &res) {
    res.set_content("Test page: Hello, World!", "text/plain");
  });

  server.Get("/stop", [&](const httplib::Request& req, httplib::Response& res) {
    std::cout << "Webserver stopped!" << std::endl;
    server.stop();
    res.set_redirect("/");
  });

  server.listen("0.0.0.0", 8080);
}
