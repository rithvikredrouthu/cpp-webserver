#include "httplib.h"
#include <iostream>
using namespace httplib;

int main(void) {
  std::cout << "Webserver started!" << std::endl;
  Server svr;

  svr.Get("/hi", [](const Request &, Response &res) {
    res.set_content("Hello World!", "text/plain");
  });

  svr.listen("0.0.0.0", 8080);
}
