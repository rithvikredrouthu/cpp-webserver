#include "httplib.h"
#include "inja.hpp"
#include <iostream>

int main(void) {
  std::cout << "Webserver started!" << std::endl;
  httplib::Server server;

  // Register static directory
  server.set_mount_point("/www-data", "app/www-data");

  server.Get("/", [&](const httplib::Request &req, httplib::Response &res) {
    inja::Environment env;
    inja::Template tpl = env.parse_template("app/templates/index.html");

    inja::json page_data;
    page_data["page_title"] = "Hello, World!";
    page_data["code"] = "let x = 3;";

    res.set_content(
      env.render(tpl, page_data),
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
