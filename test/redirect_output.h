#ifndef REDIRECT_OUTPUT_H_
#define REDIRECT_OUTPUT_H_

#include <iostream>
#include <streambuf>
#include <sstream>

namespace hackerrank {

  class RedirectOutput {
  public:
    RedirectOutput() : save_buffer_(std::cout.rdbuf()) {
      std::cout.rdbuf(buffer_.rdbuf());
    }
    virtual ~RedirectOutput() {
      std::cout.rdbuf(save_buffer_);
    }
    std::string str() {
      return buffer_.str();
    }
    void clear() {
      buffer_.str("");
    }

  private:
    std::stringstream buffer_;
    std::streambuf *save_buffer_;
  };

}

#endif // REDIRECT_OUTPUT_H_
