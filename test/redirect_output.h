#ifndef REDIRECT_OUTPUT_H_
#define REDIRECT_OUTPUT_H_

#include <iostream>
#include <streambuf>
#include <sstream>

namespace hackerrank {

  class RedirectOutput {
  public:
    RedirectOutput() : saveBuffer_(std::cout.rdbuf()) {
      std::cout.rdbuf(buffer_.rdbuf());
    }
    virtual ~RedirectOutput() {
      std::cout.rdbuf(saveBuffer_);
    }
    std::string str() {
      return buffer_.str();
    }

  private:
    std::stringstream buffer_;
    std::streambuf *saveBuffer_;
  };

}

#endif // REDIRECT_OUTPUT_H_
